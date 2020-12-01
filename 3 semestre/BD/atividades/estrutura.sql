--  Sample employee database 
--  See changelog table for details
--  Copyright (C) 2007,2008, MySQL AB
--  
--  Original data created by Fusheng Wang and Carlo Zaniolo
--  http://www.cs.aau.dk/TimeCenter/software.htm
--  http://www.cs.aau.dk/TimeCenter/Data/employeeTemporalDataSet.zip
-- 
--  Current schema by Giuseppe Maxia 
--  Data conversion from XML to relational by Patrick Crews
-- 
-- This work is licensed under the 
-- Creative Commons Attribution-Share Alike 3.0 Unported License. 
-- To view a copy of this license, visit 
-- http://creativecommons.org/licenses/by-sa/3.0/ or send a letter to 
-- Creative Commons, 171 Second Street, Suite 300, San Francisco, 
-- California, 94105, USA.
-- 
--  DISCLAIMER
--  To the best of our knowledge, this data is fabricated, and
--  it does not correspond to real people. 
--  Any similarity to existing people is purely coincidental.
-- 

DROP DATABASE IF EXISTS FUNCIONARIOS;
CREATE DATABASE IF NOT EXISTS FUNCIONARIOS;
USE FUNCIONARIOS;

DROP TABLE IF EXISTS DEPT_EMP,
                     DEPT_GERENTE,
                     CARGOS,
                     SALARIOS,
                     FUNCIONARIOS, 
                     DEPARTAMENTOS;


CREATE TABLE FUNCIONARIOS (
    emp_num             INT             NOT NULL,
    data_nascimento     DATE            NOT NULL,
    primeiro_nome       VARCHAR(14)     NOT NULL,
    ultimo_nome         VARCHAR(16)     NOT NULL,
    genero              ENUM ('M','F')  NOT NULL,    
    data_contrato       DATE            NOT NULL,
    PRIMARY KEY (emp_num)
);

CREATE TABLE DEPARTAMENTOS (
    dept_num    CHAR(4)         NOT NULL,
    dept_nome   VARCHAR(40)     NOT NULL,
    PRIMARY KEY (dept_num),
    UNIQUE  KEY (dept_nome)
);

CREATE TABLE DEPT_GERENTE (
   emp_num       INT             NOT NULL,
   dept_num      CHAR(4)         NOT NULL,
   de_data       DATE            NOT NULL,
   ate_data      DATE            NULL,
   FOREIGN KEY (emp_num)  REFERENCES FUNCIONARIOS  (emp_num)  ON DELETE CASCADE,
   FOREIGN KEY (dept_num) REFERENCES DEPARTAMENTOS (dept_num) ON DELETE CASCADE,
   PRIMARY KEY (emp_num, dept_num)
); 

CREATE TABLE DEPT_EMP (
    emp_num     INT             NOT NULL,
    dept_num    CHAR(4)         NOT NULL,
    de_data     DATE            NOT NULL,
    ate_data    DATE            NULL,
    FOREIGN KEY (emp_num)  REFERENCES FUNCIONARIOS  (emp_num)  ON DELETE CASCADE,
    FOREIGN KEY (dept_num) REFERENCES DEPARTAMENTOS (dept_num) ON DELETE CASCADE,
    PRIMARY KEY (emp_num, dept_num)
);

CREATE TABLE CARGOS (
    emp_num   INT             NOT NULL,
    cargo     VARCHAR(50)     NOT NULL,
    de_data   DATE            NOT NULL,
    ate_data     DATE	NULL,
    FOREIGN KEY (emp_num) REFERENCES FUNCIONARIOS (emp_num) ON DELETE CASCADE,
    PRIMARY KEY (emp_num, cargo, de_data)
); 

CREATE TABLE SALARIOS (
    emp_num   INT             NOT NULL,
    salario    INT             NOT NULL,
    de_data   DATE            NOT NULL,
    ate_data     DATE            NULL,
    FOREIGN KEY (emp_num) REFERENCES FUNCIONARIOS (emp_num) ON DELETE CASCADE,
    PRIMARY KEY (emp_num, de_data)
); 
