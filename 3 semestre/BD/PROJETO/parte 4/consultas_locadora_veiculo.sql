USE locadora_de_veiculos;

-- *(os funcionarios têm a mesma carga horaria)
-- 1. nome de todas mulheres (funcionarias) que ganham mais do que qualquer homem.
SELECT 	F.nome
FROM	funcionario F, cargo C
WHERE	F.sexo = 'F'
		AND F.id_cargo = C.id
        AND C.salario_hora > ANY(
								SELECT 	C2.salario_hora 
								FROM 	cargo C2, funcionario F2
                                WHERE	C2.id = F2.id_cargo
										AND F2.sexo = 'M'
								);


-- 2. nome de todas mulheres (funcionarias) que ganham mais do que todos homens.
SELECT 	F.nome
FROM	funcionario F, cargo C
WHERE	F.sexo = 'F'
		AND F.id_cargo = C.id
        AND C.salario_hora > ALL(
								SELECT 	C2.salario_hora 
								FROM 	cargo C2, funcionario F2
                                WHERE	C2.id = F2.id_cargo
										AND F2.sexo = 'M'
								);


-- 3. encontra funcionarios mais velhos do que qualquer cliente
SELECT	F.nome, F.idade
FROM	funcionario F
WHERE	F.idade > ANY(
					  SELECT	PF.idade
					  FROM		pessoa_fisica PF, cliente C
                      WHERE		PF.id_cliente = C.id
					 );


-- 4. encontra funcionarios mais velhos do que todos cliente
SELECT	F.nome, F.idade
FROM	funcionario F
WHERE	F.idade > ALL(
					  SELECT	PF.idade
					  FROM		pessoa_fisica PF, cliente C
                      WHERE		PF.id_cliente = C.id
					 );
                
 
-- 5. nome dos funcionarios que recebem salario maior do que um funcionario que tenha Alice no nome
SELECT	F.nome
FROM	funcionario F, cargo C
WHERE	F.id_cargo = C.id
		AND C.salario_hora > ANY(
								SELECT	C2.salario_hora
								FROM	funcionario F2, cargo C2
								WHERE	F2.nome LIKE '%Alice%'
										AND F2.id_cargo = C2.id
								);


-- 6. nome dos funcionarios que recebem salario maior do que todas pessoas que têm Alice no nome
SELECT	F.nome
FROM	funcionario F, cargo C
WHERE	F.id_cargo = C.id
		AND C.salario_hora > ALL(
								SELECT	C2.salario_hora
								FROM	funcionario F2, cargo C2
								WHERE	F2.nome LIKE '%Alice%'
										AND F2.id_cargo = C2.id
								);
                                
                                
-- 7. clientes que alugaram automoveis brancos e automoveis pretos
SELECT	C.nome
FROM	cliente C
WHERE	C.id IN((
				SELECT	L.id_cliente
				FROM	veiculo V, Locacao L
				WHERE	L.placa_veiculo = V.placa
						AND V.cor = 'branco'
				)
				INTERSECT
                (
				SELECT	L2.id_cliente
				FROM	veiculo V2, Locacao L2
				WHERE	L2.placa_veiculo = V2.placa
						AND V2.cor = 'preto'
				));
                
                
-- 8. todos veiculos que ja foram alugados por um funcionario
SELECT	V.nome, V.placa
FROM 	veiculo V, locacao L
WHERE 	V.placa = L.placa_veiculo
		AND L.id_cliente IN (
							SELECT 	C.id
							FROM	cliente C, funcionario F, pessoa_fisica PF
							WHERE	C.id = PF.id_cliente
									AND PF.cpf = F.cpf
							);
                
                
-- 9. todos clientes da cidade de "Auriflama" que já alugaram algum veiculo
SELECT  C.nome, C.id
FROM	cliente C, endereco_cliente EC
WHERE 	C.id = EC.id_cliente
		AND EC.cidade = "Auriflama"
        AND C.id IN (
					SELECT  L.id_cliente
                    FROM	locacao L, veiculo V
                    WHERE 	C.id = L.id_cliente
							AND L.placa_veiculo = V.placa
					);
                    
                    
-- 10. Seleciona os dados de todos clientes que já alugaram algum veículo de carga, com peso maximo de carga maior de que 30 toneladas.
SELECT	*
FROM 	cliente C
WHERE	C.id IN (
				SELECT 	L.id_cliente
				FROM	locacao L, veiculo V
                WHERE 	L.placa_veiculo = V.placa
						AND V.categoria_veiculo >= 4
                        AND V.placa IN  (
										SELECT	VC.placa_veiculo
                                        FROM	veiculo_carga VC
                                        WHERE	VC.peso_max_ton > 30
										)
				);
                
                
-- 11. lista os funcionarios que não possuem um cônjuge dependente
SELECT	*
FROM 	funcionario F
WHERE	F.cpf NOT IN(
					SELECT 	F2.cpf
					FROM	funcionario F2, dependentes D
					WHERE 	F2.cpf = D.cpf_funcionario
							AND (D.relacionamento = "Marido" OR D.relacionamento = "Esposa")
					);
                
-- 12. nome das pessoas que alugaram o veiculo de placa IFO2134											
SELECT	DISTINCT C.nome
FROM	cliente C
WHERE 	EXISTS  (
				SELECT	*
				FROM	locacao L, veiculo V
				WHERE	L.placa_veiculo = "IFO2134" 
						AND L.placa_veiculo = V.placa
                        AND C.id = L.id_cliente
				);
                    
                    
-- 13. todos funcionarios que possuem mais de 1 dependentes
SELECT	F.nome
FROM	funcionario F, dependentes D
WHERE	F.cpf = D.cpf_funcionario
GROUP BY F.cpf
HAVING	count(*) > 1;


-- 14. quantos dependentes existem registrados na empresa para cada cargo
SELECT 	C.nome, count(F.cpf)
FROM	funcionario F, cargo C, dependentes D
WHERE	D.cpf_funcionario = F.cpf
		AND F.id_cargo = C.id
GROUP BY C.id;


-- 15. todos veiculos que ja foram alugados por empresas
SELECT	V.nome, EMP.nome as nome_PJ
FROM 	veiculo V, locacao L,   (	-- subselect a seguir pega todos clientes que sejam empresas (PJ)
								SELECT 	C.id, C.nome
								FROM	cliente C, pessoa_juridica PJ
								WHERE	C.id = PJ.id_cliente
								) AS EMP
WHERE 	V.placa = L.placa_veiculo
		AND L.id_cliente = EMP.id;


-- 16. seleciona o funcionario mais velho e o funcionario mais novo por ordem de idade
SELECT	F.nome, F.idade
FROM	funcionario F
WHERE	F.idade = (
					SELECT MAX(F2.idade)
					FROM funcionario F2
				  )
UNION

SELECT	F3.nome, F3.idade
FROM	funcionario F3
WHERE	F3.idade = (
					SELECT MIN(F4.idade)
					FROM funcionario F4
				  );
                  
                  