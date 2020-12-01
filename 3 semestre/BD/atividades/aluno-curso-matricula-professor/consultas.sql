-- exercicios errados *13, *14, 15, 19?, 20?, *24

/* 1 - Liste o nome de todos os departamentos. */
SELECT dept_nome AS Nome_Departamento 
FROM departamentos;

/* 2 - Liste todos os funcionários homens que hoje tenham 
mais de 60 anos. */
SELECT 	primeiro_nome
FROM 	funcionarios F
WHERE	F.genero = 'M'
		AND (datediff('2020-11-28', F.data_nascimento)/365) > 60;

/* 3 - Liste sem repetição todos os cargos dos funcionários.*/
SELECT DISTINCT cargo
FROM CARGOS;

/* 4 - Liste os funcionários que tenham o sobrenome “Brendel” 
  e o cargo atual "Senior Engineer".*/
SELECT	primeiro_nome, cargo
FROM	funcionarios F, cargos C
WHERE	F.emp_num = C.emp_num
		AND F.ultimo_nome = 'Brendel'
		AND C.cargo = 'Senior Engineer';

/* 5 - Mostre a média dos salários atuais para os funcionários 
   homens que estão alocados atualmente em um departamento. */
SELECT 	AVG(S.salario)
FROM 	funcionarios F, salarios S, dept_emp E
WHERE 	F.genero = 'M'
		AND E.ate_data is null
		AND F.emp_num = E.emp_num
        AND E.emp_num = S.emp_num;

/* 6 - Calcule a quantidade de mulheres que estiveram (mas 
   não estão mais) alocadas em um departamento. */
SELECT	COUNT(*)
FROM	funcionarios F, dept_emp E
WHERE	F.genero = 'F'
		AND F.emp_num = E.emp_num
        AND E.ate_data is not NULL;


/* 7 - Mostre a média de salário atual de um funcionario que 
  atualmente é  "Senior Engineer" nesta empresa.
  Obs: Se quiser fazer para todos os cargos, procure o Monitor!*/
SELECT 	AVG(S.salario)
FROM 	salarios S, funcionarios F, cargos C 
WHERE 	S.emp_num = F.emp_num
		AND F.emp_num = C.emp_num
        AND C.cargo = "Senior Engineer";

/* 8 - Mostre quantos gerentes trabalham atualmente
   nesta empresa e a soma dos salários atuais deles.*/
SELECT 	COUNT(G.emp_num), SUM(S.salario)
FROM	salarios S, funcionarios F, dept_gerente G
WHERE	S.emp_num = F.emp_num
		AND F.emp_num = G.emp_num
        AND G.ate_data IS NULL;

/* 9 - Mostre quantos funcionários tem atualmente o departamento "d001".*/ 
SELECT 	COUNT(F.emp_num)
FROM 	funcionarios F, dept_emp E
WHERE	F.emp_num = E.emp_num
		AND E.dept_num = 'd001'
        AND E.ate_data is null;


/* 10 - Sabendo que ninguém nesta empresa recebe dois salários,  
   liste soma dos salários, a média de salário e a quantidade de 
   funcionários que ainda trabalham nesta empresa. */ 

SELECT	SUM(S.salario), AVG(S.salario), COUNT(F.emp_num)
FROM 	salarios S, funcionarios F, dept_emp E
WHERE	F.emp_num = E.emp_num
		AND E.emp_num = S.emp_num
	 	AND E.ate_data is null;
        
        
/* 11 - Mostre a idade média dos funcionários que estão ou estiveram 
   o departamento de "Marketing".
   Obs: Se quiser fazer para todos os departamentos, procure o Monitor! */
SELECT 	AVG (datediff('2020-11-28', F.data_nascimento)/365) AS idadeMedia 
FROM	funcionarios F, departamentos D, dept_emp E
WHERE	D.dept_nome = "Marketing"
		AND E.dept_num = D.dept_num
		AND E.emp_num = F.emp_num;
        

/* 12 - Liste a quantidade de 'Senior' que a empresa possui  trabalhando 
   hoje na empresa e a média salarial destes trabalhadores.*/
SELECT	COUNT(F.emp_num)
FROM 	funcionarios F, dept_emp E, cargos C
WHERE	F.emp_num = E.emp_num
		AND E.emp_num = C.emp_num
		AND C.cargo LIKE 'Senior%'
        AND E.ate_data IS NULL;
        

/* 13 - Sabendo que ninguém nesta empresa recebe dois salários, liste a folha 
   salarial, a média de salário e a quantidade de funcionários que NÃO trabalham 
   mais nesta empresa.*/
SELECT	AVG(S.salario), COUNT(E.emp_num)
FROM 	salarios S, funcionarios F, dept_emp E
WHERE	F.emp_num = E.emp_num
		AND E.emp_num = S.emp_num
		AND E.emp_num NOT IN( 
							SELECT	E2.emp_num
							FROM	dept_emp E2
							WHERE	E2.ate_data IS NOT NULL
							);

SELECT 	F.primeiro_nome, S.salario
FROM 	funcionarios F, salarios S, dept_emp E
WHERE	F.emp_num = E.emp_num
		AND E.ate_data IS NOT NULL;
        

/* 14 - Liste o nome, o departamento e o salário de todos os funcionários,
   distintos, que ganham ou já ganharam mais do que algum gerente. */
SELECT 	DISTINCT F.primeiro_nome, F.ultimo_nome, D.dept_nome, S.salario
FROM	dept_emp E, funcionarios F, salarios S, departamentos D
WHERE	D.dept_num = E.dept_num
		AND F.emp_num = E.emp_num
		AND E.emp_num = S.emp_num
        AND S.salario > ANY(
							SELECT 	S2.salario 
                            FROM 	salarios S2, dept_gerente G
                            WHERE	G.emp_num = S2.emp_num
                            );
		

/* 15 - Liste o nome, o departamento e o salário de todos os funcionários, 
   distintos, que ganham ou já ganharam mais do que todos os gerente.*/
SELECT 	DISTINCT F.primeiro_nome, F.ultimo_nome, D.dept_nome, S.salario
FROM	dept_emp E, funcionarios F, salarios S, departamentos D
WHERE	D.dept_num = E.dept_num
		AND F.emp_num = E.emp_num
		AND E.emp_num = S.emp_num
        AND S.salario > ALL(
							SELECT 	S2.salario 
                            FROM 	salarios S2, dept_gerente G
                            WHERE	G.emp_num = S2.emp_num
                            );
   

/* 16 - Liste os dados e o cargo dos funcionários que NÃO são (ou 
   foram) "Senior".*/
SELECT	*
FROM	funcionarios F, cargos C
WHERE	F.emp_num = C.emp_num
		AND C.cargo <> 'Senior%'
UNION
SELECT	*
FROM	funcionarios F2, cargos C2
WHERE	F2.emp_num = C2.emp_num
		AND C2.cargo LIKE 'Senior%'
		AND C2.ate_data IS NOT NULL;


/* 17 - Selecione os funcionários que não trabalharam em mais nenhum 
   outro departamento que não seja o de "Marketing".*/
SELECT 	F.emp_num, F.primeiro_nome
FROM	funcionarios F, dept_emp E, departamentos D
WHERE	F.emp_num = E.emp_num
		AND E.dept_num = D.dept_num
        AND D.dept_nome = "Marketing"
EXCEPT
SELECT 	F1.emp_num, F1.primeiro_nome
FROM	funcionarios F1, dept_emp E1, departamentos D1
WHERE	F1.emp_num = E1.emp_num
		AND E1.dept_num = D1.dept_num
        AND D1.dept_nome <> "Marketing";


/* 18 - Liste, se tiver, os funcionários que trabalharam em todos os
   departamentos.*/
SELECT 	F.primeiro_nome
FROM 	funcionarios F
WHERE	NOT EXISTS((
					SELECT	D.dept_num
					FROM	departamentos D
					)
					EXCEPT
					(
						SELECT 	DISTINCT E.dept_num
						FROM 	dept_emp E, dept_gerente G
						WHERE 	(E.emp_num = F.emp_num OR G.emp_num = F.emp_num)
					));

/* 19 - Liste os dados dos funcionários que trabalharam apenas no departamento 
   de "Development", que atende pelo código "d005".*/
SELECT 	COUNT(*)
FROM 	funcionarios F, dept_emp E
WHERE	F.emp_num = E.emp_num
		AND E.dept_num = 'd005'
        AND E.dept_num IN(SELECT	E2.dept_num
							FROM	dept_emp E2
							WHERE	E2.emp_num = F.emp_num
									AND E2.dept_num <> 'd005');


/* 20 - Verifique se há algum funcionário que não está trabalhando em nenhum 
   departamento neste momento.*/
SELECT 	count(*)
FROM 	funcionarios F
WHERE	F.emp_num NOT IN(
					SELECT	E.emp_num
                    FROM	dept_emp E
                    WHERE	E.emp_num = F.emp_num);
                             

/* 21 - Calcule e mostre qual a média de salário de cada gênero. */
SELECT 	F.genero, AVG(S.salario)
FROM	funcionarios F, salarios S
WHERE	F.emp_num = S.emp_num
GROUP BY F.genero;
        

/* 22 - Mostre a média de salário de um cada cargo nesta empresa. */
SELECT 	C.cargo, AVG(S.salario)
FROM 	salarios S, cargos C, funcionarios F
WHERE	F.emp_num = C.emp_num
		AND C.emp_num = S.emp_num
GROUP BY C.cargo;


/* 23 - Liste a quantidade de funcionários de cada Departamento, que estão 
   trabalhando hoje na empresa. */
SELECT 	D.dept_nome, COUNT(E.emp_num) AS qtdFuncionarios
FROM 	dept_emp E, departamentos D, funcionarios F
WHERE	D.dept_num = E.dept_num
		AND E.emp_num = F.emp_num
		AND E.ate_data IS NULL
GROUP BY D.dept_num;

/* 24 - Lista em cada departamento a quantidade funcionários dos dois sexos 
   de forma ordenada por departamento.*/
-- ordena por sexo
SELECT 	D.dept_nome, F.genero, COUNT(*) AS qtdFuncion
FROM 	dept_emp E, departamentos D, funcionarios F
WHERE	D.dept_num = E.dept_num
		AND E.emp_num = F.emp_num
        AND F.genero = 'F'
		AND E.ate_data IS NULL
GROUP BY D.dept_num
UNION
SELECT 	D2.dept_nome, F2.genero, COUNT(E2.emp_num)
FROM 	dept_emp E2, departamentos D2, funcionarios F2
WHERE	D2.dept_num = E2.dept_num
		AND E2.emp_num = F2.emp_num
        AND F2.genero = 'M'
		AND E2.ate_data IS NULL
GROUP BY D2.dept_num;
   
-- ordena por departamento
SELECT 	D.dept_nome, F.genero, COUNT(*) AS qtdFuncion
FROM 	dept_emp E, departamentos D, funcionarios F
WHERE	D.dept_num = E.dept_num
		AND E.emp_num = F.emp_num
		AND E.ate_data IS NULL
GROUP BY D.dept_num, F.genero
ORDER BY D.dept_num













/*[1.0] - Escreva em SQL uma consulta que liste todos os filmes, juntamente com os ids dos DVDs, do gênero "Drama".
[1.5] - Escreva em SQL uma consulta que exiba os gêneros sem repetição dos filmes estreiados em 2020 com a participação do ator "Severino".
[1.5] - Escreva em SQL uma consulta que exiba a quantidade de DVDs por filmes.
[2.0] - Escreva em SQL uma consulta que liste os filmes estreiados em 2020, que não tiveram a participação do ator "Severino".
[2.0] - Escreva em SQL uma consulta que selecione os gêneros e a quantidade de filmes que foram estreiados em 2020.
[2.0] - Escreva em Álgebra Relacional uma consulta que liste os atores que participaram de filmes em 2020, mas não em 2019.
*/











