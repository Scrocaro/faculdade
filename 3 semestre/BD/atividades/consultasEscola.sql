-- 1.Encontre os nomes de todos os Juniors (nível = JR) que estão matriculados em um curso ministrado por Ivana Teach.
SELECT distinct A.nomeAlun
FROM ALUNO A, CURSO C, MATRICULADO M, PROFESSOR P
WHERE A.nivel = 'JR'
	AND A.nroAlun = M.nroAlun
    AND C.nome = M.nomeCurso
    AND P.idProf = C.idProf
	AND P.nomeProf = 'Ivana Teach';

-- 2.Encontre a idade do aluno mais velho que é formado em History ou matriculado em um curso ministrado por Ivana Teach.
SELECT	DISTINCT A.idade
FROM	ALUNO A
WHERE	A.idade = 	(
					SELECT	MAX(A2.idade)
					FROM	CURSO C, PROFESSOR P, aluno A2, matriculado M
					WHERE	A2.formacao = 'History' OR (A2.nroAlun = M.nroAlun AND M.nomeCurso = C.nome AND C.idProf = P.idProf AND P.nomeProf = 'Ivana Teach')
					);
                        
                        
-- 3.Encontre os nome de todos os cursos que são ministrados na sala R128 ou que têm cinco ou mais alunos matriculados.
SELECT	C.nome, count(m.nroAlun)
FROM	curso C, matriculado M, aluno A
WHERE	(A.nroAlun = M.nroAlun AND M.nomeCurso = C.nome)
		OR (C.sala = 'R128')
GROUP BY M.nroAlun
HAVING count(*) >= 5;
	
SELECT  DISTINCT C.nome
FROM	curso C, aluno A
WHERE 	C.sala = 'R128'
		OR (SELECT 	C.nome
			FROM	matriculado M, curso C, aluno A
			WHERE	A.nroAlun = M.nroAlun
					AND M.nomeCurso = C.nome
			GROUP BY COUNT(M.nroAlun) >= 5);


-- 4.Encontre os nomes de todos os alunos que estão matriculados em dois cursos que são ministrados no mesmo horário.
SELECT 	DISTINCT A.nomeAlun
FROM	aluno A, matriculado M, curso C
WHERE	A.nroAlun = M.nroAlun
		AND M.nomeCurso = C.nome
        AND C.horario IN(
						SELECT 	C2.horario
						FROM	aluno A2, matriculado M2, curso C2
						WHERE	A2.nroAlun = M2.nroAlun
								AND M2.nomeCurso = C2.nome
						);


-- 5.Encontre os nomes dos professores que ministram cursos em todas as salas em que algum curso é ministrado.
--   Há uma solução mais simples usando EXCEPT, mas não é suportado pelo MySQL.

SELECT 	P.nomeProf
FROM 	PROFESSOR P
WHERE	NOT EXISTS (SELECT C.sala
					FROM CURSO C
					WHERE C.sala NOT IN (SELECT C.sala
										 FROM CURSO C
										 WHERE C.idProf = P.idProf));


-- 6.Encontre os nomes dos professores para os quais a lista de matriculados dos cursos que eles ministram é menor do que cinco.



-- 7.Imprima o nível e a idade média dos alunos desse nível, para cada nível.
SELECT A.nivel, AVG(A.idade)
FROM	aluno A
GROUP BY a.nivel;


-- 8.Imprima o nível e a idade média dos alunos desse nível, para todos os níveis exceto JR.
SELECT A.nivel, AVG(A.idade)
FROM	aluno A
WHERE 	A.nivel <> 'JR'
GROUP BY a.nivel;


-- 9.Para cada professor que ministra cursos apenas na sala R128, imprima seu nome e o número total de cursos que ele ou ela ministra.
-- 	 Há uma solução BEM mais simples usando o HAVING EVERY(C.SALA = ’R128’), mas o EVERY não é suportado pelo MySQL.
SELECT 	P.nomeProf
FROM	professor P, curso C
WHERE	P.idProf = C.idProf
GROUP BY P.idProf
HAVING EVERY (C.sala = 'R128');


-- 10.Encontre os nomes dos alunos matriculados no número máximo de cursos.

-- numero maximo de cursos?


-- 11.Encontre os nomes dos alunos não matriculados em nenhum curso.
SELECT	DISTINCT A.nomeAlun
FROM	aluno A, matriculado M
WHERE 	A.nroAlun <> M.nroAlun;
-- =
SELECT	DISTINCT A.nomeAlun
FROM	aluno A, matriculado M
WHERE 	A.nroAlun NOT IN(
						SELECT	DISTINCT A.nomeAlun
						FROM	aluno A, matriculado M
						WHERE 	A.nroAlun = M.nroAlun
						);


-- 12.Para cada valor de idade que aparece em Aluno, encontre o valor do nível que aparece com
--    mais frequência. Por exemplo, se houver mais alunos no nível FR com idade 18 do que
--    alunos com idade 18 dos níveis SR, JR ou SR, você deve imprimir o par (18, FR).
SELECT A1.idade, A1.nivel, count(*) AS frequencia
FROM ALUNO A1
GROUP BY A1.idade, A1.nivel
HAVING frequencia >= ALL(
						SELECT COUNT(*)
						FROM	ALUNO A2
						WHERE 	A1.idade = A2.idade);


