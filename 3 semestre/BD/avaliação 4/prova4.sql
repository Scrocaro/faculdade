DROP DATABASE IF EXISTS prova;
CREATE DATABASE prova;
USE prova;

CREATE TABLE GENERO (
    descricao VARCHAR(50) PRIMARY KEY
);

CREATE TABLE ATOR(
    nomeReal VARCHAR(100) PRIMARY KEY,
    sexo CHAR(1)
);

CREATE TABLE FILME(
    id INTEGER PRIMARY KEY,
    nome VARCHAR(100),
    anoEstreia INTEGER,
    descricaoGenero VARCHAR(50) NOT NULL,
    FOREIGN KEY (descricaoGenero) REFERENCES GENERO(descricao)
);

CREATE TABLE DVD(
    id INTEGER PRIMARY KEY,
    idFilme INTEGER NOT NULL,
    FOREIGN KEY (idFilme) REFERENCES FILME(id)
);

CREATE TABLE ELENCO(
    idFilme INTEGER,
    nomeAtor VARCHAR(100),
    PRIMARY KEY (idFilme, nomeAtor),
    FOREIGN KEY (idFilme) REFERENCES FILME(id),
    FOREIGN KEY (nomeAtor) REFERENCES ATOR(nomeReal)
);
/*
[1.0] -  liste todos os filmes, juntamente com os ids dos DVDs, do gênero "Drama".
[1.5] - que exiba os gêneros sem repetição dos filmes estreiados em 2020 com a participação do ator "Severino".
[1.5] - que exiba a quantidade de DVDs por filmes.
[2.0] - que liste os filmes estreiados em 2020, que não tiveram a participação do ator "Severino".
[2.0] - que selecione os gêneros e a quantidade de filmes que foram estreiados em 2020.
[2.0] - Escreva em Álgebra Relacional uma consulta que liste os atores que participaram de filmes em 2020, mas não em 2019.*/


-- 1 liste todos os filmes, juntamente com os ids dos DVDs, do gênero "Drama".
SELECT	F.nome, D.id
FROM	FILME F, DVD D, GENERO G
WHERE	D.idFilme = F.id
		AND F.descricaoGenero = G.descricao
        AND G.descricao = 'Drama'
GROUP BY D.id; -- filme pode estar em mais de 1 dvd
        
-- 2 exiba os gêneros sem repetição dos filmes estreiados em 2020 com a participação do ator "Severino".
SELECT DISTINCT F.descricaoGenero
FROM filme F, elenco E, genero G, ator A
WHERE A.nomeReal = E.nomeAtor
      AND E.idFilme = F.id
      AND F.descricaoGenero = G.descricao
      AND F.anoEstreia = 2020
      AND A.nomeReal LIKE "Severino%";
      
-- 3 exiba a quantidade de DVDs por filmes.
SELECT	COUNT(D.id) AS qtdDVDsPorFilmes
FROM 	DVD D, FILME F
WHERE 	D.idFilme = F.id
GROUP BY F.id;

-- 4 liste os filmes estreiados em 2020, que não tiveram a participação do ator "Severino".
SELECT	DISTINCT F.nome
FROM	filme F, elenco E, ator A
WHERE	A.nomeReal NOT LIKE "Severino"
		AND A.nomeReal = E.nomeAtor
		AND E.idFilme = F.id
		AND F.anoEstreia = 2020;
-- ------ ou ------
SELECT	DISTINCT F.descricaoGenero
FROM	filme F
WHERE	F.anoEstreia = 2020

EXCEPT

SELECT DISTINCT F2.descricaoGenero
FROM filme F2, elenco E2, genero G2, ator A2
WHERE A2.nomeReal = E2.nomeAtor
      AND E.idFilme = F.id
      AND F.descricaoGenero = G.descricao
      AND A.nomeReal LIKE 'Severino';
        
-- 5 selecione os gêneros e a quantidade de filmes que foram estreiados em 2020.
SELECT 	G.descricao AS genero, count(F.id) AS qtdFilmesEstr2020
FROM 	genero G, filme F
WHERE	G.descricao = F.descricaoGenero
		AND F.anoEstreia = 2020
GROUP BY G.descricao

-- 6 liste os atores que participaram de filmes em 2020, mas não em 2019 (algebra relacional)
