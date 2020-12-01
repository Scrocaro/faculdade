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
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("OLX1508", 1, "CB1000", "Azul", 2, "Manual", "Gasolina", "LIVRE");

	INSERT
	INTO	REVISAO(placa_veiculo, data_revisao, gasto)
	VALUES		   ("OLX1508", '2019-04-24', 248.00);

	INSERT
	INTO	REVISAO(placa_veiculo, data_revisao, gasto)
	VALUES		   ("OLX1508", '2020-05-13', 456.00);
    
INSERT 
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("IFO2134", 1, "Kawasaki Ninja", "Verde", 2, "Manual", "Gasolina", "LIVRE");

INSERT 
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("AIQ1235", 1, "Hornet", "Preto", 2, "Manual", "Gasolina", "LIVRE");

	INSERT
	INTO	REVISAO(placa_veiculo, data_revisao, gasto)
	VALUES		   ("AIQ1235", '2020-05-13', 125.00);
    
INSERT 
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("DYO7904", 2, "Onix", "Branco", 5, "Manual", "Flex", "LIVRE");
	
	INSERT
	INTO	REVISAO(placa_veiculo, data_revisao, gasto)
	VALUES		   ("DYO7904", '2020-07-21', 308.00);

INSERT 
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("BOM9324", 2, "ix35", "Branco", 5, "Automático", "Flex", "LIVRE");

	INSERT
	INTO	REVISAO(placa_veiculo, data_revisao, gasto)
	VALUES		   ("BOM9324", '2020-11-13', 456.00);

INSERT 
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("SER5687", 2, "BMW 528i", "Preto", 5, "Automático", "Flex", "LIVRE");

	INSERT
	INTO	REVISAO(placa_veiculo, data_revisao, gasto)
	VALUES		   ("SER5687", '2019-09-20', 366.00);

	INSERT
	INTO	REVISAO(placa_veiculo, data_revisao, gasto)
	VALUES		   ("SER5687", '2020-09-29', 456.00);

INSERT 
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("TER7865", 2, "Civic", "Vermelho", 5, "Manual", "Gasolina", "LIVRE");

	INSERT
	INTO	REVISAO(placa_veiculo, data_revisao, gasto)
	VALUES		   ("TER7865", '2020-02-19', 127.00);

INSERT 
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("AFF0293", 2, "Doblò", "Cinza", 7, "Manual", "Álcool", "LIVRE");

	INSERT
	INTO	REVISAO(placa_veiculo, data_revisao, gasto)
	VALUES		   ("AFF0293", '2018-03-22', 142.00);
    
    INSERT
	INTO	REVISAO(placa_veiculo, data_revisao, gasto)
	VALUES		   ("AFF0293", '2019-03-29', 201.00);
    
    INSERT
	INTO	REVISAO(placa_veiculo, data_revisao, gasto)
	VALUES		   ("AFF0293", '2020-04-07', 267.00);

INSERT 
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("UBR3112", 3, "Hylux", "Vermelho", 5, "Automático", "Diesel", "LIVRE");

INSERT 
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("TAX9912", 3, "S10", "Cinza", 5, "Manual", "Diesel", "LIVRE");

	INSERT
	INTO	REVISAO(placa_veiculo, data_revisao, gasto)
	VALUES		   ("TAX9912", '2020-01-23', 127.00);

INSERT 
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("DIA1234", 3, "Frontier", "Branco", 5, "Automático", "Diesel", "LIVRE");

	INSERT
	INTO	REVISAO(placa_veiculo, data_revisao, gasto)
	VALUES		   ("DIA1234", '2020-06-21', 267.00);

/*------------ VEICULOS DE CARGA ------------*/

INSERT 
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("BEX1938", 4, "VW Delivery 8.160", "Branco", 3, "Manual", "Diesel", "LIVRE");

	INSERT
	INTO	VEICULO_CARGA(placa_veiculo, categoria_veiculo, peso_max_ton, altura, comprimento)
	VALUE                ("BEX1938", 4, (3.2), (2.5), (2.7));
    
	INSERT
	INTO	REVISAO(placa_veiculo, data_revisao, gasto)
	VALUES		   ("BEX1938", '2020-07-17', 541.00);

INSERT 
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("GLE5234", 4, "Cargo 816", "Preto", 3, "Manual", "Diesel", "LIVRE");

	INSERT
	INTO	VEICULO_CARGA(placa_veiculo, categoria_veiculo, peso_max_ton, altura, comprimento)
	VALUE                ("GLE5234", 4, (3.0), (2.5), (2.7));

INSERT 
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("DIX4576", 5, "FH 460", "Preto", 2, "Automático", "Diesel", "LIVRE");

	INSERT
	INTO	VEICULO_CARGA(placa_veiculo, categoria_veiculo, peso_max_ton, altura, comprimento)
	VALUE                ("DIX4576", 5, (36.0), (4.0), (7.1));

INSERT 
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("JAM9245", 5, "Scania R 450", "Preto", 2, "Automático", "Diesel", "LIVRE");

	INSERT
	INTO	VEICULO_CARGA(placa_veiculo, categoria_veiculo, peso_max_ton, altura, comprimento)
	VALUE                ("JAM9245", 5, (38.0), (4.0), (7.1));

INSERT 
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("GAL8204", 4, "VW Delivery 10.160", "Branco", 3, "Manual", "Diesel", "LIVRE");

	INSERT
	INTO	VEICULO_CARGA(placa_veiculo, categoria_veiculo, peso_max_ton, altura, comprimento)
	VALUE                ("GAL8204", 4, (3.2), (2.3), (2.6));
    
INSERT 
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("BLA2801", 4, "Accelo 1016", "Preto", 3, "Manual", "Diesel", "LIVRE");

	INSERT
	INTO	VEICULO_CARGA(placa_veiculo, categoria_veiculo, peso_max_ton, altura, comprimento)
	VALUE                ("BLA2801", 4, (3.1), (2.4), (2.5));

INSERT 
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("DIX5028", 4, "Accelo 815", "Vermelho", 3, "Automático", "Diesel", "LIVRE");

	INSERT
	INTO	VEICULO_CARGA(placa_veiculo, categoria_veiculo, peso_max_ton, altura, comprimento)
	VALUE                ("DIX5028", 4, (2.8), (2.2), (2.4));
    
INSERT 
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("VIU3451", 4, "Cargo F-4000", "Roxo", 3, "Manual", "Diesel", "LIVRE");

	INSERT
	INTO	VEICULO_CARGA(placa_veiculo, categoria_veiculo, peso_max_ton, altura, comprimento)
	VALUE                ("VIU3451", 4, (2.9), (2.6), (2.9));
    
INSERT 
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("TAB3402", 4, "VW Delivery 9.170", "Verde", 3, "Automático", "Diesel", "LIVRE");

	INSERT
	INTO	VEICULO_CARGA(placa_veiculo, categoria_veiculo, peso_max_ton, altura, comprimento)
	VALUE                ("TAB3402", 4, (2.6), (2.1), (2.2));
    
INSERT 
INTO     VEICULO(placa, categoria_veiculo, nome, cor, lugares, tipo_cambio, tipo_combustivel, disponibilidade)
VALUES          ("PIU6439", 4, "Daily 70C17", "Vermelho", 3, "Automático", "Diesel", "LIVRE");

	INSERT
	INTO	VEICULO_CARGA(placa_veiculo, categoria_veiculo, peso_max_ton, altura, comprimento)
	VALUE                ("PIU6439", 4, (2.8), (2.3), (2.6));
    


SELECT * FROM VEICULO;
SELECT * FROM REVISAO;
SELECT * FROM VEICULO_CARGA;

/*================================================================= CLIENTES =================================================================*/
/*------------ 1 -------------*/
INSERT 
INTO     CLIENTE(id, nome, telefone, email)
VALUES   		(1, "Janderson Farias", "+55 (17) 99786-4354", "jandersinho@gmail.com");

	INSERT 
	INTO     PESSOA_FISICA(id_cliente, cpf, rg, sexo, idade)
	VALUES   			  (1, "835.281.220-30", "30.494.946-2", "M", 23);
    
    INSERT
    INTO	ENDERECO_CLIENTE(id_cliente, cidade, uf, logradouro, numero, bairro)
    VALUES				    (1, "Auriflama", "SP",  "Rua Valdevino Nery dos Reis", 5478, "Centro");

/*------------ 2 -------------*/
INSERT 
INTO     CLIENTE(id, nome, telefone, email)
VALUES   		(2, "Transfelicios", "+55 (17) 98819-3068", "contato@transfelicios.com.br");

	INSERT 
	INTO     PESSOA_JURIDICA(id_cliente, cnpj, razao_social, tipo_organizacao)
	VALUES   				(2, "88.422.702/0001-04", "Irmaos Felicio Transportadora SA", "Transportadora");

	INSERT
    INTO	ENDERECO_CLIENTE(id_cliente, cidade, uf, logradouro, numero, bairro)
    VALUES				    (2, "Auriflama", "SP",  "Rua José Matarézio", 8745, "Cachopa");

/*------------ 3 -------------*/
INSERT 
INTO     CLIENTE(id, nome, telefone, email)
VALUES   		(3, "Transimoveis", "+55 (17) 99246-6791", "contato@transimoveis.com.br");

	INSERT 
	INTO     PESSOA_JURIDICA(id_cliente, cnpj, razao_social, tipo_organizacao)
	VALUES   				(3, "42.764.145/0001-09", "Imoveis Transportadora Auriflama ME", "Transportadora");

	INSERT
    INTO	ENDERECO_CLIENTE(id_cliente, cidade, uf, logradouro, numero, bairro)
    VALUES				    (3, "Auriflama", "SP",  "Rua João Federice", 6846, "Cachopa");
    
/*------------ 4 -------------*/
INSERT 
INTO     CLIENTE(id, nome, telefone, email)
VALUES   		(4, "Beatriz Souza", "+55 (17) 99767-9875", "biasou@gmail.com");

	INSERT 
	INTO     PESSOA_FISICA(id_cliente, cpf, rg, sexo, idade)
	VALUES   			  (4, "346.648.234-20", "16.534.345-2", "F", 19);

	INSERT
    INTO	ENDERECO_CLIENTE(id_cliente, cidade, uf, logradouro, numero, bairro)
    VALUES				    (4, "Auriflama", "SP",  "Rua Demétrio Barberá", 9468, "Ducelândia");
    
/*------------ 5 -------------*/
INSERT 
INTO     CLIENTE(id, nome, telefone, email)
VALUES   		(5, "Joaquim Medeiros", "+55 (17) 98136-6745", NULL);

	INSERT 
	INTO     PESSOA_FISICA(id_cliente, cpf, rg, sexo, idade)
	VALUES   			  (5, "123.512.425-12", "31.676.125-3", "M", 63);

	INSERT
    INTO	ENDERECO_CLIENTE(id_cliente, cidade, uf, logradouro, numero, bairro)
    VALUES				    (5, "Auriflama", "SP",  "Rua André Giantomassi", 5643, "Centro");
    
/*------------ 6 -------------*/
INSERT 
INTO     CLIENTE(id, nome, telefone, email)
VALUES   		(6, "Vitor Santos", "+55 (17) 99657-3546", "vitin123@gmail.com");

	INSERT 
	INTO     PESSOA_FISICA(id_cliente, cpf, rg, sexo, idade)
	VALUES   			  (6, "245.345.646-34", "57.987.654-5", "M", 26);

	INSERT
    INTO	ENDERECO_CLIENTE(id_cliente, cidade, uf, logradouro, numero, bairro)
    VALUES				    (6, "Auriflama", "SP",  "Rua José Barbosa", 4644, "Centro");
/*------------ 7 -------------*/
INSERT 
INTO     CLIENTE(id, nome, telefone, email)
VALUES   		(7, "Enzo Barnorde", "+55 (17) 98182-7584", "enzinhoofoda@gmail.com");

	INSERT 
	INTO     PESSOA_FISICA(id_cliente, cpf, rg, sexo, idade)
	VALUES   			  (7, "654.456.324-65", "45.645.785-7", "M", 18);

	INSERT
    INTO	ENDERECO_CLIENTE(id_cliente, cidade, uf, logradouro, numero, bairro)
    VALUES				    (7, "Auriflama", "SP",  "Rua Narciso Roman", 4567, "Centro");
    
/*------------ 8 -------------*/
INSERT 
INTO     CLIENTE(id, nome, telefone, email)
VALUES   		(8, "Kevin Vinil", "+55 (17) 99768-0215", "vinilkevin@gmail.com");

	INSERT 
	INTO     PESSOA_FISICA(id_cliente, cpf, rg, sexo, idade)
	VALUES   			  (8, "343.743.546-23", "65.524.654-2", "M", 34);

	INSERT
    INTO	ENDERECO_CLIENTE(id_cliente, cidade, uf, logradouro, numero, bairro)
    VALUES				    (8, "Auriflama", "SP",  "Rua Valdevino Nery dos Reis", 2354, "Cachopa");
    
/*------------ 9 -------------*/
INSERT 
INTO     CLIENTE(id, nome, telefone, email)
VALUES   		(9, "Irineu Souza", "+55 (17) 95467-2354", "vcnsabenemeu@gmail.com");

	INSERT 
	INTO     PESSOA_FISICA(id_cliente, cpf, rg, sexo, idade)
	VALUES   			  (9, "163.346.354-20", "12.645.865-7", "M", 46);

	INSERT
    INTO	ENDERECO_CLIENTE(id_cliente, cidade, uf, logradouro, numero, bairro)
    VALUES				    (9, "General Salgado", "SP",  "Rua Natal Mateus", 12405, "Condado 1");
    
/*------------ 10 -------------*/
INSERT 
INTO     CLIENTE(id, nome, telefone, email)
VALUES   		(10, "Bruna Trindade", "+55 (17) 94685-9657", "bruninha123@gmail.com");

	INSERT 
	INTO     PESSOA_FISICA(id_cliente, cpf, rg, sexo, idade)
	VALUES   			  (10, "645.955.123-12", "73.412.674-4", "F", 29);

	INSERT
    INTO	ENDERECO_CLIENTE(id_cliente, cidade, uf, logradouro, numero, bairro)
    VALUES				    (10, "General Salgado", "SP",  "Rua Augusto Miranda", 64351, "Condado 2");
    
/*------------ 11 -------------*/
INSERT
INTO	CLIENTE(id, nome, telefone, email)
VALUES  		   (11, "Alice Fazzato", "+55 (17) 98456-8754", "fazzatoalice@gmail.com");
	
    INSERT
	INTO	PESSOA_FISICA(id_cliente, cpf, rg, sexo, idade)
	VALUES  		   (11, "074.135.964-22", "52.675.335-8", 'F', 37);
    
    INSERT
    INTO	ENDERECO_CLIENTE(id_cliente, cidade, uf, logradouro, numero, bairro)
    VALUES				    (11, "General Salgado", "SP",  "Rua Augusto Miranda", 64351, "Condado 2");

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
INTO	FUNCIONARIO(cpf, id_cargo, rg, nome, idade, sexo)
VALUES  		   ("576.172.880-00", 2, "11.441.149-9", "Plínio Armani", 31, 'M');	

	INSERT
	INTO	DEPENDENTES(cpf_funcionario, nome, id_cargo_funcionario, idade, custo, relacionamento)
	VALUES			   ("576.172.880-00", "Janaina Armani", 2, 28, 200.00, "Esposa");    

/*------------ 2 -------------*/
INSERT
INTO	FUNCIONARIO(cpf, id_cargo, rg, nome, idade, sexo)
VALUES  		   ("381.032.450-70", 1, "27.400.590-6", "Ana Elena Bottazzo", 27, 'F');	

/*------------ 3 -------------*/
INSERT
INTO	FUNCIONARIO(cpf, id_cargo, rg, nome, idade, sexo)
VALUES  		   ("124.585.710-00", 2, "18.618.607-1", "Arlindo Toledo", 23, 'M');
	
    INSERT
	INTO	DEPENDENTES(cpf_funcionario, nome, id_cargo_funcionario, idade, custo, relacionamento)
	VALUES			   ("124.585.710-00", "Antônio Toledo", 2, 1, 150.00, "Filho");
    
/*------------ 4 -------------*/
INSERT
INTO	FUNCIONARIO(cpf, id_cargo, rg, nome, idade, sexo)
VALUES  		   ("773.601.444-26", 1, "39.657.339-3", "Vera Aline Martins", 45, 'F');
    
/*------------ 5 -------------*/
INSERT
INTO	FUNCIONARIO(cpf, id_cargo, rg, nome, idade, sexo)
VALUES  		   ("139.925.879-67", 2, "50.007.399-5", "João Antônio Pereira", 28, 'M');

	INSERT
	INTO	DEPENDENTES(cpf_funcionario, nome, id_cargo_funcionario, idade, custo, relacionamento)
	VALUES			   ("139.925.879-67", "Maria Souza", 2, 29, 200.00, "Esposa");
    
    INSERT
	INTO	DEPENDENTES(cpf_funcionario, nome, id_cargo_funcionario, idade, custo, relacionamento)
	VALUES			   ("139.925.879-67", "Antônio Souza", 2, 6, 150.00, "Filho");
    
    INSERT
	INTO	DEPENDENTES(cpf_funcionario, nome, id_cargo_funcionario, idade, custo, relacionamento)
	VALUES			   ("139.925.879-67", "Joaquina Toledo", 2, 4, 150.00, "Filha");
	
/*------------ 6 -------------*/
INSERT
INTO	FUNCIONARIO(cpf, id_cargo, rg, nome, idade, sexo)
VALUES  		   ("600.168.470-75", 3, "23.054.609-2", "Calebe Anderson Souza", 53, 'M');

	INSERT
	INTO	DEPENDENTES(cpf_funcionario, nome, id_cargo_funcionario, idade, custo, relacionamento)
	VALUES			   ("600.168.470-75", "Fátima da Silva", 3, 49, 200.00, "Esposa");

/*------------ 7 -------------*/
INSERT
INTO	FUNCIONARIO(cpf, id_cargo, rg, nome, idade, sexo)
VALUES  		   ("347.482.353-14", 2, "47.249.461-2", "Luana Melo", 23, 'F');

/*------------ 8 -------------*/
INSERT
INTO	FUNCIONARIO(cpf, id_cargo, rg, nome, idade, sexo)
VALUES  		   ("041.292.289-43", 3, "34.116.119-6", "Alice Carvalho", 21, 'F');

	INSERT
	INTO	DEPENDENTES(cpf_funcionario, nome, id_cargo_funcionario, idade, custo, relacionamento)
	VALUES			   ("041.292.289-43", "Gabriela Jardim", 3, 23, 200.00, "Esposa");
	
/*------------ 9 -------------*/
INSERT
INTO	FUNCIONARIO(cpf, id_cargo, rg, nome, idade, sexo)
VALUES  		   ("245.821.587-49", 2, "21.458.770-8", "Joana Porto", 49, 'F');

	INSERT
	INTO	DEPENDENTES(cpf_funcionario, nome, id_cargo_funcionario, idade, custo, relacionamento)
	VALUES			   ("245.821.587-49", "Hugo Carlos Leite", 2, 45, 200.00, "Marido");

    INSERT
	INTO	DEPENDENTES(cpf_funcionario, nome, id_cargo_funcionario, idade, custo, relacionamento)
	VALUES			   ("245.821.587-49", "Ester Porto", 2, 16, 150.00, "Filha");
	
/*------------ 10 -------------*/
INSERT
INTO	FUNCIONARIO(cpf, id_cargo, rg, nome, idade, sexo)
VALUES  		   ("594.980.208-09", 3, "37.455.238-1", "Fabiano Silveira", 31, 'M');

	INSERT
	INTO	DEPENDENTES(cpf_funcionario, nome, id_cargo_funcionario, idade, custo, relacionamento)
	VALUES			   ("594.980.208-09", "João Silveira", 3, 28, 200.00, "Marido");

/*------------ 11 -------------*/
INSERT
INTO	FUNCIONARIO(cpf, id_cargo, rg, nome, idade, sexo)
VALUES  		   ("354.785.469-01", 3, "12.034.576-2", "Otávio Ferreira", 71, 'M');

/*------------ 11 -------------*/
INSERT
INTO	FUNCIONARIO(cpf, id_cargo, rg, nome, idade, sexo)
VALUES  		   ("074.135.964-22", 2, "52.675.335-8", "Alice Fazzato", 37, 'F');


SELECT * FROM FUNCIONARIO;
SELECT * FROM DEPENDENTES;

/*================================================================= LOCACAO =================================================================*/
/*------------ 1 -------------*/
INSERT 
INTO	LOCACAO(id, id_cliente, cpf_funcionario, placa_veiculo, data_inicio, data_termino)
VALUES         (1, 1, "124.585.710-00", "OLX1508", '2020-11-01', '2020-11-12');

	UPDATE	VEICULO V
    SET 	V.disponibilidade = "ALUGADO"
    WHERE   placa = "OLX1508";

/*------------ 2 -------------*/
INSERT 
INTO	LOCACAO(id, id_cliente, cpf_funcionario, placa_veiculo, data_inicio, data_termino)
VALUES         (2, 2, "124.585.710-00", "BEX1938", '2020-11-06', '2020-12-06');

	UPDATE	VEICULO V
    SET 	V.disponibilidade = "ALUGADO"
    WHERE   placa = "BEX1938";

/*------------ 3 -------------*/
INSERT 
INTO	LOCACAO(id, id_cliente, cpf_funcionario, placa_veiculo, data_inicio, data_termino)
VALUES         (3, 2, "124.585.710-00", "GLE5234", '2020-04-13', '2021-03-12');

	UPDATE	VEICULO V
    SET 	V.disponibilidade = "ALUGADO"
    WHERE   placa = "GLE5234";
    
/*------------ 4 -------------*/
INSERT 
INTO	LOCACAO(id, id_cliente, cpf_funcionario, placa_veiculo, data_inicio, data_termino)
VALUES         (4, 3, "139.925.879-67", "JAM9245", '2020-06-16', '2021-01-21');

	UPDATE	VEICULO V
    SET 	V.disponibilidade = "ALUGADO"
    WHERE   placa = "JAM9245";
    
/*------------ 5 -------------*/
INSERT 
INTO	LOCACAO(id, id_cliente, cpf_funcionario, placa_veiculo, data_inicio, data_termino)
VALUES         (5, 4, "139.925.879-67", "TAX9912", '2020-03-07', '2020-12-06');

	UPDATE	VEICULO V
    SET 	V.disponibilidade = "ALUGADO"
    WHERE   placa = "TAX9912";
  
/*------------ 6 -------------*/
INSERT 
INTO	LOCACAO(id, id_cliente, cpf_funcionario, placa_veiculo, data_inicio, data_termino)
VALUES         (6, 4, "347.482.353-14", "DIA1234", '2020-08-14', '2020-12-18');

	UPDATE	VEICULO V
    SET 	V.disponibilidade = "ALUGADO"
    WHERE   placa = "DIA1234";

/*------------ 7 -------------*/
INSERT 
INTO	LOCACAO(id, id_cliente, cpf_funcionario, placa_veiculo, data_inicio, data_termino)
VALUES         (7, 5, "347.482.353-14", "AFF0293", '2020-11-16', '2020-12-01');

	UPDATE	VEICULO V
    SET 	V.disponibilidade = "ALUGADO"
    WHERE   placa = "AFF0293";
  
/*------------ 8 -------------*/
INSERT 
INTO	LOCACAO(id, id_cliente, cpf_funcionario, placa_veiculo, data_inicio, data_termino)
VALUES         (8, 6, "245.821.587-49", "TER7865", '2020-10-11', '2020-11-30');

	UPDATE	VEICULO V
    SET 	V.disponibilidade = "ALUGADO"
    WHERE   placa = "TER7865";
   
/*------------ 9 -------------*/
INSERT 
INTO	LOCACAO(id, id_cliente, cpf_funcionario, placa_veiculo, data_inicio, data_termino)
VALUES         (9, 7, "347.482.353-14", "UBR3112", '2020-09-29', '2020-12-09');

	UPDATE	VEICULO V
    SET 	V.disponibilidade = "ALUGADO"
    WHERE   placa = "UBR3112";
  
/*------------ 10 -------------*/
INSERT 
INTO	LOCACAO(id, id_cliente, cpf_funcionario, placa_veiculo, data_inicio, data_termino)
VALUES         (10, 8, "576.172.880-00", "SER5687", '2020-07-27', '2020-11-27');

	UPDATE	VEICULO V
    SET 	V.disponibilidade = "ALUGADO"
    WHERE   placa = "SER5687";
    
/*------------ 11 -------------*/
INSERT 
INTO	LOCACAO(id, id_cliente, cpf_funcionario, placa_veiculo, data_inicio, data_termino)
VALUES         (11, 9, "576.172.880-00", "IFO2134", '2020-09-08', '2020-10-08');

	UPDATE	VEICULO V
    SET 	V.disponibilidade = "ALUGADO"
    WHERE   placa = "IFO2134";
    
/*------------ 12 -------------*/
INSERT 
INTO	LOCACAO(id, id_cliente, cpf_funcionario, placa_veiculo, data_inicio, data_termino)
VALUES         (12, 10, "576.172.880-00", "IFO2134", '2020-10-15', '2020-11-20');

	UPDATE	VEICULO V
    SET 	V.disponibilidade = "ALUGADO"
    WHERE   placa = "IFO2134";
    
/*------------ 13 -------------*/
INSERT 
INTO	LOCACAO(id, id_cliente, cpf_funcionario, placa_veiculo, data_inicio, data_termino)
VALUES         (13, 11, "576.172.880-00", "IFO2134", '2020-11-22', '2020-12-11');

	UPDATE	VEICULO V
    SET 	V.disponibilidade = "ALUGADO"
    WHERE   placa = "IFO2134";
    
SELECT * FROM LOCACAO;
SELECT * FROM VEICULO;