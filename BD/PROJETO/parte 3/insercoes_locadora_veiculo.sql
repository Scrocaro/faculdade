USE locadora_de_veiculos;

/*================================================================ CATEGORIAS ================================================================*/
-- multiplicações utilizadas para ilustração de como poderia funcionar o sistema de preços referentes à cada categoria.

INSERT
INTO	CATEGORIA_VEICULO (categoria, nome, preco_dia, combustivel, seguro)
VALUES  ("1", "Motocicleta", (100*0.5), (50*0.5), (50*0.5));

INSERT
INTO	CATEGORIA_VEICULO (categoria, nome, preco_dia, combustivel, seguro)
VALUES  ("2", "Carro", (100*1), (100*1), (50*1));

INSERT
INTO	CATEGORIA_VEICULO (categoria, nome, preco_dia, combustivel, seguro)
VALUES  ("3", "Caminhonete", (100*1.5), (100*1.5), (50*1.5));

INSERT
INTO	CATEGORIA_VEICULO (categoria, nome, preco_dia, combustivel, seguro)
VALUES  ("4", "Caminhão leve", (100*2), (100*2), (50*2));

INSERT
INTO	CATEGORIA_VEICULO (categoria, nome, preco_dia, combustivel, seguro)
VALUES  ("5", "Caminhão", (100*3), (100*3), (50*3));

SELECT * FROM CATEGORIA_VEICULO;

/*================================================================= VEICULOS =================================================================*/
/*------------ VEICULOS DE PASSEIO ------------*/
INSERT 
INTO     VEICULO(placa, categoria_v, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("OLX1508", 1, "CB1000", "Azul", 2, "Manual", "Gasolina", "LIVRE");

	INSERT
	INTO	REVISAO(placa_veiculo, data_revisao, gasto)
	VALUES		   ("OLX1508", '2020-05-13', 248.00);


INSERT 
INTO     VEICULO(placa, categoria_v, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("DYO7904", 2, "Onix", "Branco", 5, "Manual", "Flex", "LIVRE");

INSERT 
INTO     VEICULO(placa, categoria_v, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("UBR3112", 3, "Hylux", "Vermelho", 5, "Automático", "Diesel", "LIVRE");


/*------------ VEICULOS DE CARGA ------------*/

INSERT 
INTO     VEICULO(placa, categoria_v, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("BEX1938", 4, "VW Delivery 8.160", "Branco", 3, "Manual", "Diesel", "LIVRE");

	INSERT
	INTO	VEICULO_CARGA(placa_veiculo, categoria_v, peso_max_ton, altura, comprimento)
	VALUE                ("BEX1938", 4, (3.2), (2.5), (2.7));


INSERT 
INTO     VEICULO(placa, categoria_v, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("DIX4576", 5, "FH 460", "Preto", 2, "Automático", "Diesel", "LIVRE");

	INSERT
	INTO	VEICULO_CARGA(placa_veiculo, categoria_v, peso_max_ton, altura, comprimento)
	VALUE                ("DIX4576", 5, (38.0), (4.0), (7.1));


SELECT * FROM VEICULO;
SELECT * FROM REVISAO;
SELECT * FROM VEICULO_CARGA;

/*================================================================= CLIENTES =================================================================*/

/*------------ 1 -------------*/
INSERT 
INTO     CLIENTE(id, nome, telefone, email)
VALUES   (1, "Janderson Farias", "+55 (17) 99786-4354", "jandersinho@gmail.com");

	INSERT 
	INTO     PESSOA_FISICA(id_cliente, cpf, rg, sexo, data_nascimento)
	VALUES   (1, "835.281.220-30", "30.494.946-2", "M", '2000-01-27');
    
    INSERT
    INTO	ENDERECO_CLIENTE(id_cliente, cidade, uf, logradouro, numero, bairro)
    VALUES				    (1, "Auriflama", "SP",  "Rua Valdevino Nery dos Reis", 5478, "Centro");

/*------------ 2 -------------*/
INSERT 
INTO     CLIENTE(id, nome, telefone, email)
VALUES   (2, "Transfelicios", "+55 (17) 98819-3068", "contato@transfelicios.com.br");

	INSERT 
	INTO     PESSOA_JURIDICA(id_cliente, cnpj, razao_social, tipo_organizacao)
	VALUES   (2, "88.422.702/0001-04", "Irmaos Felicio Transportadora SA", "Transportadora");

	INSERT
    INTO	ENDERECO_CLIENTE(id_cliente, cidade, uf, logradouro, numero, bairro)
    VALUES				    (2, "Auriflama", "SP",  "Rua José Matarézio", 8745, "Cachopa");

SELECT * FROM CLIENTE;
SELECT * FROM PESSOA_FISICA;
SELECT * FROM PESSOA_JURIDICA;
SELECT * FROM ENDERECO_CLIENTE;

/*=============================================================== FUNCIONARIOS ===============================================================*/

/*------------ CARGOS ------------*/
INSERT
INTO	CARGO(id, nome, salario_hora)
VALUES  	 (1, "Gerente", 12), (2, "Atendente", 10), (3, "Faxineiro", 8);

SELECT * FROM CARGO;

/*------------ 1 -------------*/
INSERT
INTO	FUNCIONARIO(cpf_funcionario, id_cargo, rg, nome, idade, sexo)
VALUES  		   ("111.111.111-11", 3, "11.111.111-1", "Acrinio Armani", 31, 'M');	

	INSERT
	INTO	DEPENDENTES(cpf_funcion, nome, id_cargo_funcion, idade, custo, relacionamento)
	VALUES			   ("111.111.111-11", "Janaina Joana Armani", 3, 28, 200.00, "Esposa");    

/*------------ 2 -------------*/
INSERT
INTO	FUNCIONARIO(cpf_funcionario, id_cargo, rg, nome, idade, sexo)
VALUES  		   ("222.222.222-22", 1, "22.222.222-2", "Ana Elena Bottazzo", 27, 'F');	

/*------------ 3 -------------*/
INSERT
INTO	FUNCIONARIO(cpf_funcionario, id_cargo, rg, nome, idade, sexo)
VALUES  		   ("333.333.333-33", 2, "33.333.333-3", "Arlindo Toledo", 23, 'M');
	
    INSERT
	INTO	DEPENDENTES(cpf_funcion, nome, id_cargo_funcion, idade, custo, relacionamento)
	VALUES			   ("333.333.333-33", "Antônio Toledo", 2, 12, 150.00, "Filho");

SELECT * FROM FUNCIONARIO;
SELECT * FROM DEPENDENTES;

/*================================================================= LOCACAO =================================================================*/
/*------------ 1 -------------*/
INSERT 
INTO	LOCACAO(id, id_cliente, id_funcionario, placa_veiculo, data_inicio, data_termino)
VALUES         (1, 1, "111.111.111-11", "OLX1508", '2020-11-01', '2020-11-12');

	UPDATE	VEICULO V
    SET 	V.disponibilidade = "ALUGADO"
    WHERE   placa = "OLX1508";

/*------------ 2 -------------*/
INSERT 
INTO	LOCACAO(id, id_cliente, id_funcionario, placa_veiculo, data_inicio, data_termino)
VALUES         (2, 2, "222.222.222-22", "BEX1938", '2020-11-06', '2020-12-06');

	UPDATE	VEICULO V
    SET 	V.disponibilidade = "ALUGADO"
    WHERE   placa = "BEX1938";

SELECT * FROM LOCACAO;
SELECT * FROM VEICULO;
