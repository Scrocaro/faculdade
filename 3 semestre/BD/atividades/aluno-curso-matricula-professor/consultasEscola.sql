-- 1.Encontre os nomes de todos os Juniors (nível = JR) que estão matriculados em um curso ministrado por Ivana Teach.
SELECT distinct A.nomeAlun
FROM ALUNO A, CURSO C, MATRICULADO M, PROFESSOR P
WHERE A.nivel = 'JR'
	AND A.nroAlun = M.nroAlun	-- n sei se precisa, provavelmente sim, porem a Nancy Allen n deve ter matricula feita...
    AND P.idProf = C.idProf
	AND P.nomeProf = 'Ivana Teach';
    
-- testes
SELECT A.nomeAlun, A.nivel, C.nome
FROM ALUNO A, professor P, CURSO C
WHERE P.idProf = C.idProf
	AND P.nomeProf = 'Ivana Teach';

SELECT * 
FROM ALUNO A, MATRICULADO M, Curso C
WHERE nomeAlun = 'Nancy Allen'
	AND A.nroAlun = M.nroAlun;

-- 2.Encontre a idade do aluno mais velho que é formado em History ou matriculado em um curso ministrado por Ivana Teach.
SELECT	A.idade
FROM	ALUNO A
WHERE	A.idade >= ALL (
						SELECT	*
						FROM	CURSO C, PROFESSOR P
						WHERE	A.formacao = 'History' OR P.nomeProf = 'Ivana Teach'
                        );
                        
                        
-- 3.Encontre os nome de todos os cursos que são ministrados na sala R128 ou que têm cinco ou mais alunos matriculados.
-- 4.Encontre os nomes de todos os alunos que estão matriculados em dois cursos que são ministrados no mesmo horário.
-- 5.Encontre os nomes dos professores que ministram cursos em todas as salas em que algum curso é ministrado.
--   Há uma solução mais simples usando EXCEPT, mas não é suportado pelo MySQL.
-- 6.Encontre os nomes dos professores para os quais a lista de matriculados dos cursos que eles ministram é menor do que cinco.
-- 7.Imprima o nível e a idade média dos alunos desse nível, para cada nível.
-- 8.Imprima o nível e a idade média dos alunos desse nível, para todos os níveis exceto JR.
-- 9.Para cada professor que ministra cursos apenas na sala R128, imprima seu nome e o número total de cursos que ele ou ela ministra.
--   Há uma solução BEM mais simples usando o HAVING EVERY(C.SALA = ’R128’), mas o EVERY não é suportado pelo MySQL.
-- 10.Encontre os nomes dos alunos matriculados no número máximo de cursos.
-- 11.Encontre os nomes dos alunos não matriculados em nenhum curso.
-- 12.Para cada valor de idade que aparece em Aluno, encontre o valor do nível que aparece com
--    mais frequência. Por exemplo, se houver mais alunos no nível FR com idade 18 do que
--    alunos com idade 18 dos níveis SR, JR ou SR, você deve imprimir o par (18, FR).