USE locadora_de_veiculos;

/*================================================================ CATEGORIAS ================================================================*/

INSERT
INTO	CATEGORIA_VEICULO (categoria, nome)
VALUES  ("1", "Motocicleta");

INSERT
INTO	CATEGORIA_VEICULO (categoria, nome)
VALUES  ("2", "Carro");

INSERT
INTO	CATEGORIA_VEICULO (categoria, nome)
VALUES  ("3", "Caminhonete");

INSERT
INTO	CATEGORIA_VEICULO (categoria, nome)
VALUES  ("4", "Caminhão leve");

INSERT
INTO	CATEGORIA_VEICULO (categoria, nome)
VALUES  ("5", "Caminhão");

SELECT * FROM CATEGORIA_VEICULO;

/*================================================================= VEICULOS =================================================================*/

INSERT 
INTO     VEICULO(placa, categoria, nome, cor, lugares, tipo_cambio, tipo_combustivel)
VALUES          ("OLX1508", 1, "CB1000", "Azul", 2, "Manual", "Gasolina");

INSERT 
INTO     VEICULO(placa, categoria, nome, cor, lugares, tipo_cambio, tipo_combustivel)
VALUES          ("DYO7904", 2, "Onix", "Branco", 5, "Manual", "Flex");

INSERT 
INTO     VEICULO(placa, categoria, nome, cor, lugares, tipo_cambio, tipo_combustivel)
VALUES          ("UBR3112", 3, "Hylux", "Vermelho", 5, "Automático", "Diesel");

INSERT 
INTO     VEICULO(placa, categoria, nome, cor, lugares, tipo_cambio, tipo_combustivel)
VALUES          ("BEX1938", 4, "VW Delivery 8.160", "Branco", 2, "Manual", "Diesel");

INSERT 
INTO     VEICULO(placa, categoria, nome, cor, lugares, tipo_cambio, tipo_combustivel)
VALUES          ("DIX4576", 5, "FH 460", "Preto", 2, "Automático", "Diesel");

SELECT * FROM VEICULO;

/*================================================================= CLIENTES =================================================================*/

INSERT 
INTO     CLIENTE(id, nome, telefone, email)
VALUES   (1, "Janderson Farias", "+55 (17) 99786-4354", "jandersinho@gmail.com");

INSERT 
INTO     PESSOA_FISICA(id_cliente, cpf, rg, sexo, data_nascimento)
VALUES   (1, "111.222.333-44", "11.222.333-4", "M", '2000-01-27');

SELECT * FROM CLIENTE;
SELECT * FROM PESSOA_FISICA;

/*================================================================= CLIENTES =================================================================*/

INSERT
INTO	FUNCIONARIO(cpf, rg, nome )