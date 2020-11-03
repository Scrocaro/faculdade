CREATE DATABASE locadora_de_veiculos;
USE locadora_de_veiculos;


DROP TABLE IF EXISTS REVISAO;
DROP TABLE IF EXISTS LOCACAO;
DROP TABLE IF EXISTS DEPENDENTES;
DROP TABLE IF EXISTS FUNCIONARIO;
DROP TABLE IF EXISTS ENDERECO_CLIENTE;
DROP TABLE IF EXISTS PESSOA_FISICA;
DROP TABLE IF EXISTS PESSOA_JURIDICA;
DROP TABLE IF EXISTS CLIENTE;
DROP TABLE IF EXISTS VEICULO_CARGA;
DROP TABLE IF EXISTS VEICULO;
DROP TABLE IF EXISTS CATEGORIA_VEICULO;

CREATE TABLE CATEGORIA_VEICULO(
    categoria VARCHAR(1),
    nome VARCHAR(200),
    preco_dia DECIMAL(10, 2),
    combustivel DECIMAL(10, 2),
    seguro DECIMAL(10, 2),
    PRIMARY KEY (categoria)
);

CREATE TABLE VEICULO(
    placa VARCHAR(9),
    categoria_v VARCHAR(1),
    nome VARCHAR(50),
    cor VARCHAR(20),
    lugares INTEGER,
    tipo_cambio VARCHAR(11),
    tipo_combustivel VARCHAR(20),
    disponibilidade VARCHAR(8),
    PRIMARY KEY (placa),
	FOREIGN KEY (categoria_v) REFERENCES CATEGORIA_VEICULO (categoria)
);

CREATE TABLE VEICULO_CARGA(
    placa_veiculo VARCHAR(9),
    categoria_v VARCHAR(1),
	peso_max_ton DECIMAL(10,2),
    altura DECIMAL(10,2),
	comprimento DECIMAL(10,2),
    PRIMARY KEY (placa_veiculo, categoria_v, peso_max_ton),
	FOREIGN KEY (placa_veiculo) REFERENCES VEICULO (placa),
    FOREIGN KEY (categoria_v) REFERENCES CATEGORIA_VEICULO (categoria)
);

CREATE TABLE CLIENTE(
	id INTEGER,	
    nome VARCHAR(200),
    telefone VARCHAR(20),
    email VARCHAR(50),
    PRIMARY KEY (id)
);

CREATE TABLE PESSOA_FISICA(
	id_cliente INTEGER,
	cpf VARCHAR(50),
    rg VARCHAR(50),
    sexo VARCHAR(1),
    data_nascimento DATE,
    PRIMARY KEY (id_cliente, cpf),
    FOREIGN KEY (id_cliente) REFERENCES CLIENTE (id) 
);

CREATE TABLE PESSOA_JURIDICA(
	id_cliente INTEGER,
	cnpj VARCHAR(50),
    razao_social VARCHAR(50),
    tipo_organizacao VARCHAR(50),
    PRIMARY KEY (id_cliente, cnpj),
	FOREIGN KEY (id_cliente) REFERENCES CLIENTE (id) 
);

CREATE TABLE FUNCIONARIO(
	cpf_funcionario VARCHAR(50),
    rg VARCHAR(50),
    nome VARCHAR(200),
    idade VARCHAR(3),
    sexo VARCHAR(1),
    salario_hora DECIMAL(10, 2),
    PRIMARY KEY (cpf_funcionario)
);

CREATE TABLE DEPENDENTES(
	cpf_funcion VARCHAR(50),
    nome VARCHAR(200),
	idade VARCHAR(3),
    custo DECIMAL(10, 2),
    relacionamento VARCHAR(20),
    PRIMARY KEY (cpf_funcion, nome),
    FOREIGN KEY (cpf_funcion) REFERENCES FUNCIONARIO (cpf_funcionario) ON DELETE CASCADE
);

CREATE TABLE REVISAO(
	placa_veiculo VARCHAR(9),
    data_revisao DATE,
    gasto DECIMAL(10 ,2),
    PRIMARY KEY (placa_veiculo, data_revisao),
    FOREIGN KEY (placa_veiculo) REFERENCES VEICULO(placa) ON DELETE CASCADE
);

CREATE TABLE ENDERECO_CLIENTE(
	id_cliente INTEGER,
    cidade VARCHAR(50),
    uf VARCHAR(2),
    logradouro VARCHAR(50),
    numero INTEGER,
    bairro VARCHAR(50),
    PRIMARY KEY (id_cliente, cidade),
    FOREIGN KEY (id_cliente) REFERENCES CLIENTE (id) ON DELETE CASCADE
);

CREATE TABLE LOCACAO(
	id INTEGER,
    id_cliente INTEGER,
    id_funcionario VARCHAR(50),
	placa_veiculo VARCHAR(9),
    data_inicio DATE,
    data_termino DATE,
    PRIMARY KEY (id, id_cliente, id_funcionario, placa_veiculo),
	FOREIGN KEY (id_cliente) REFERENCES CLIENTE(id),
    FOREIGN KEY (id_funcionario) REFERENCES FUNCIONARIO(cpf_funcionario),
    FOREIGN KEY (placa_veiculo) REFERENCES VEICULO(placa)
);
