estudo prova 3 BD (PDF "EXERCICIOS_FORMAS_NORMAIS")

1) PROCESSO SELETIVO DE UMA INSTITUIÇÃO DE UM CANDIDATO

1FN E 2FN JA CERTOS.


3FN? não, há dependencia transitiva    

CURSO
    cod_cur (PK)
    nome_cur

TURNO
    cod_t (PK)
    nome_t

CANDIDATO
    inscricao_can (PK)
    dataInscricao_can
    nome_can
    telefone_can
    celular_can
    email_can
    resp_can 
    bairro_can
    cidade_can
    cep_can
    cod_cur FK referencia CURSO(cod_cur)
    cod_t FK referencia TURNO(cod_t)



2) HISTORICO DE ALUNO

1FN? nao, composto e multivalorado

ALUNO
    nome_c
    cod_c
    nome_a
    matricula_a    (PK)
    status_a

HISTORICO
    matricula_a
    nome_d
    cod_d
    nome_p
    cod_p
    nota_a_d
    faltas_a_d
    situacao_a_d
    PK (matricula_a, cod_d)



2FN? sim

3FN? nao, dependecia transitiva


CURSO
    cod_c   (PK)
    nome_c

PROFESSOR
    cod_p
    nome_p

DISCIPLINA
    cod_d   (PK)
    nome_d
    cod_p   FK referencia PROFESSOR(cod_p)

ALUNO
    matricula_a    (PK)
    nome_a
    status_a
    cod_c   FK referencia CURSO(cod_c)

HISTORICO
    matricula_a    FK referencia ALUNO(cod_a)
    cod_d   FK referencia DISCIPLINA(cod_d)
    nota_a_d
    faltas_a_d
    situacao_a_d
    PK(matricula_a, cod_d)
