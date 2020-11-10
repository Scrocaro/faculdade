CREATE database prova2_bd1_ex1;
USE prova2_bd1_ex1;

DROP TABLE IF EXISTS ENTIDADEA;
DROP TABLE IF EXISTS ENTIDADEA_TEM_ENTIDADEA;

CREATE TABLE ENTIDADEA(
    atributo_a1 INTEGER NOT NULL,
    atributo_a2 INTEGER,
    PRIMARY KEY (atributo_a1)
);

CREATE TABLE ENTIDADEA_TEM_ENTIDADEA(
    atributo_a1 INTEGER NOT NULL,
    atributo_a2 INTEGER,
    PRIMARY KEY (atributo_a1),
    FOREIGN KEY (atributo_a1, atributo_a2) REFERENCES ENTIDADEA(atributo_a1, atributo_a2)
);

CREATE database prova2_bd1_ex2;
USE prova2_bd1_ex2;

DROP TABLE IF EXISTS ENTIDADEA;
DROP TABLE IF EXISTS ENTIDADEB;
DROP TABLE IF EXISTS ENTIDADEC;

CREATE TABLE ENTIDADEA(
    atributo_a1 INTEGER NOT NULL,
    atributo_a2 INTEGER,
    PRIMARY KEY (atributo_a1)
);

CREATE TABLE ENTIDADEB(
    atributo_b1 INTEGER NOT NULL,
    atributo_b2 INTEGER,
    atributo_a_fk INTEGER,
    PRIMARY KEY (atributo_b1, atributo_a_fk),
    FOREIGN KEY (atributo_a_fk) REFERENCES ENTIDADEA (atributo_a1) ON DELETE CASCADE
);

CREATE TABLE ENTIDADEC(
    atributo_c1 INTEGER NOT NULL,
    atributo_c2 INTEGER,
    atributo_b_fk INTEGER,
    PRIMARY KEY (atributo_c1, atributo_b_fk),
    FOREIGN KEY (atributo_b_fk) REFERENCES ENTIDADEB (atributo_b1) ON DELETE CASCADE
);