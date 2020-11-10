/* 1 - Liste o nome de todos os departamentos. */
SELECT dept_nome AS Nome_Departamento FROM departamentos;

/* 2 - Liste todos os funcionários homens que hoje tenham 
mais de 60 anos. */
SELECT primeiro_nome
FROM funcionarios 
WHERE genero = 'M';

/* 3 - Liste sem repetição todos os cargos dos funcionários.*/
SELECT DISTINCT cargo
FROM CARGOS;

/* 4 - Liste os funcionários que tenham o sobrenome “Brendel” 
  e o cargo atual "Senior Engineer".*/
  SELECT primeiro_nome, ultimo_nome, cargo
  FROM funcionarios F, cargos C
  WHERE F.emp_num = C.emp_num
  AND F.ultimo_nome = 'Brendel'
  AND C.cargo = 'Senior Engineer';

/* 5 - Mostre a média dos salários atuais para os funcionários 
   homens que estão alocados atualmente em um departamento. */
   DELIMITER $
   BEGIN ;
		DECLARE @media_salarios INT;
        -- SELECT salario INTO media_salarios FROM FUNCIONARIOS F, DEPT_EMP E, SALARIO S WHERE E.emp_num = S.emp_num AND F.genero = 'M';
   END $
   DELIMITER ;

/* 6 - Calcule a quantidade de mulheres que estiveram (mas 
   não estão mais) alocadas em um departamento. */

/* 7 - Mostre a média de salário atual de um funcionario que 
  atualmente é  "Senior Engineer" nesta empresa.
  Obs: Se quiser fazer para todos os cargos, procure o Monitor!*/

/* 8 - Mostre quantos gerentes trabalham atualmente
   nesta empresa e a soma dos salários atuais deles.*/

/* 9 - Mostre quantos funcionários tem atualmente o departamento "d001".*/ 

/* 10 - Sabendo que ninguém nesta empresa recebe dois salários,  
   liste soma dos salários, a média de salário e a quantidade de 
   funcionários que ainda trabalham nesta empresa. */ 

/* 11 - Mostre a idade média dos funcionários que estão ou estiveram 
   o departamento de "Marketing".
   Obs: Se quiser fazer para todos os departamentos, procure o Monitor! */

/* 12 - Liste a quantidade de 'Senior' que a empresa possui  trabalhando 
   hoje na empresa e a média salarial destes trabalhadores.*/

