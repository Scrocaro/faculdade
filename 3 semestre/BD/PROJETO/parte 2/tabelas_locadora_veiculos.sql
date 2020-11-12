DROP DATABASE IF EXISTS locadora_de_veiculos;
CREATE DATABASE locadora_de_veiculos;
USE locadora_de_veiculos;

CREATE TABLE CATEGORIA_VEICULO(
    categoria VARCHAR(1),
    nome VARCHAR(100),
    preco_dia DECIMAL(10, 2),
    combustivel DECIMAL(10, 2),
    seguro DECIMAL(10, 2),
    PRIMARY KEY (categoria)
);

CREATE TABLE VEICULO(
    placa VARCHAR(9),
    categoria_veiculo VARCHAR(1),
    nome VARCHAR(50),
    cor VARCHAR(20),
    lugares INTEGER,
    tipo_cambio VARCHAR(11),
    tipo_combustivel VARCHAR(20),
    disponibilidade VARCHAR(8),
    PRIMARY KEY (placa),
	FOREIGN KEY (categoria_veiculo) REFERENCES CATEGORIA_VEICULO (categoria)
);

CREATE TABLE VEICULO_CARGA(
    placa_veiculo VARCHAR(9),
    categoria_veiculo VARCHAR(1),
	peso_max_ton DECIMAL(10,2),
    altura DECIMAL(10,2),
	comprimento DECIMAL(10,2),
    PRIMARY KEY (placa_veiculo, categoria_veiculo),
	FOREIGN KEY (placa_veiculo) REFERENCES VEICULO (placa),
    FOREIGN KEY (categoria_veiculo) REFERENCES CATEGORIA_VEICULO (categoria)
);

CREATE TABLE CLIENTE(
	id INTEGER,	
    nome VARCHAR(100),
    telefone VARCHAR(20),
    email VARCHAR(50),
    PRIMARY KEY (id)
);

CREATE TABLE PESSOA_FISICA(
	id_cliente INTEGER,
	cpf VARCHAR(15),
    rg VARCHAR(15),
    sexo ENUM ('M', 'F', 'O'),	-- Masculino, Feminino, Outro
    idade VARCHAR(3),
    PRIMARY KEY (id_cliente, cpf),
    FOREIGN KEY (id_cliente) REFERENCES CLIENTE (id) 
);

CREATE TABLE PESSOA_JURIDICA(
	id_cliente INTEGER,
	cnpj VARCHAR(20),
    razao_social VARCHAR(50),
    tipo_organizacao VARCHAR(50),
    PRIMARY KEY (id_cliente, cnpj),
	FOREIGN KEY (id_cliente) REFERENCES CLIENTE (id) 
);

CREATE TABLE CARGO(
	id INTEGER,
    nome VARCHAR(100),
    salario_hora DECIMAL(10, 2),
	PRIMARY KEY (id)
);

CREATE TABLE FUNCIONARIO(
	cpf VARCHAR(15),
    id_cargo INTEGER,
    rg VARCHAR(15),
    nome VARCHAR(100),
    idade VARCHAR(3),
    sexo ENUM ('M', 'F', 'O'),		
    PRIMARY KEY (cpf),
    FOREIGN KEY (id_cargo) REFERENCES CARGO (id)
);

CREATE TABLE DEPENDENTES(
	cpf_funcionario VARCHAR(15),
    id_cargo_funcionario INTEGER,
    nome VARCHAR(100),
	idade VARCHAR(3),
    custo DECIMAL(10, 2),
    relacionamento VARCHAR(20),
    PRIMARY KEY (cpf_funcionario, nome),
    FOREIGN KEY (id_cargo_funcionario) REFERENCES FUNCIONARIO (id_cargo),
    FOREIGN KEY (cpf_funcionario) REFERENCES FUNCIONARIO (cpf) ON DELETE CASCADE
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
    cpf_funcionario VARCHAR(15),
	placa_veiculo VARCHAR(9),
    data_inicio DATE,
    data_termino DATE,
    PRIMARY KEY (id, id_cliente, cpf_funcionario, placa_veiculo),
	FOREIGN KEY (id_cliente) REFERENCES CLIENTE(id),
    FOREIGN KEY (cpf_funcionario) REFERENCES FUNCIONARIO(cpf),
    FOREIGN KEY (placa_veiculo) REFERENCES VEICULO(placa)
);