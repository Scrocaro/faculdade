//CONTA BANCO

#include <stdio.h>
#include <string.h>


void cadastraCliente ();
void listaTodosCliente ();
void listaCliente ();
void inicializa ();
int buscaPosicaoVazia ();
int menu ();
int buscaCPF (long cpf);
void buscaNome (char str[]);
void removeCliente (int pos);
int submenu ();
void deposito (float money, int conta, int ag, int cont);
int saque ();

int id = 0;

struct REGISTRO
{
  long ag, conta, cpf;
  char nome[51];
  int id, flag;
  float saldo;
};
struct REGISTRO cliente;


void inicializa()
{
    FILE *arq;
    arq = fopen("testeArq.bin", "ab+");
    if (arq == NULL)
        printf("Erro na abertura do arquivo!\n");
    else
        fclose(arq);
}


int menu ()
{
  printf("\nMENU PRINCIPAL:\n");
  int op;
  printf(" 1 - Cadastrar cliente\n 2 - Lista todos clientes\n 3 - Lista um cliente\n 4 - remover um cliente\n 5 - fazer um deposito\n 0 - Sair\n ");
  scanf("%d", &op);
  return op;
}


int submenu ()
{
    int opsub;
    printf("1 - busca por nome\n");
    printf("2 - busca por cpf\n");
    printf("opção: ");
    scanf("%d", &opsub);
    return opsub;
}


void cadastraCliente()
{
    struct REGISTRO c;
        printf("Digite a Agência: ");
        scanf("%ld", &c.ag);
        printf("Digite a conta: ");
        scanf("%ld", &c.conta);
        printf("Nome: ");
        scanf(" %[^\n]", c.nome);
        printf("CPF: ");
        scanf("%ld", &c.cpf);
        c.id = id++;
        c.flag = 1;
        c.saldo = 0;
        printf("Cliente cadastrado\n");

        FILE *arq;
        arq = fopen("testeArq.bin", "ab+");
        if (arq == NULL)
            printf("Erro!\nArquivo não pode ser aberto!\n");
        else
        {
            fwrite(&c, sizeof(c), 1, arq);
            fclose(arq);
        }
}

/*
void listaCliente (int pos)
{
    printf("Cliente ID: %d\n", cliente[pos].id);
    printf("Agencia: %ld\n", cliente[pos].ag);
    printf("Conta: %ld\n", cliente[pos].conta);
    printf("Nome: %s\n", cliente[pos].nome);
    printf("CPF: %ld\n", cliente[pos].cpf);
    printf("Saldo: R$ %.2f\n", cliente[pos].saldo);
    printf("\n -------------------- \n");
}
*/

void listaTodosCliente ()
{
    int cont=0;
    struct REGISTRO ccc;
    FILE *arq;
    arq = fopen("testeArq.bin", "rb+");
    if (arq == NULL)
        printf("Erro na abertura do arquivo!\n");
    else
    {
        while(fread(&ccc, sizeof(ccc), 1, arq))
        {
            if (ccc.flag == 1)
            {
                printf("Cliente ID: %d\n", ccc.id);
                printf("Agencia: %ld\n", ccc.ag);
                printf("Conta: %ld\n", ccc.conta);
                printf("Nome: %s\n", ccc.nome);
                printf("CPF: %ld\n", ccc.cpf);
                printf("Saldo: R$ %.2f\n", ccc.saldo);
                printf("\n -------------------- \n");
                cont++;
              }
        }
        printf("Há %d clientes\n", cont);
        if (cont==0)
            printf("Não há clientes registrados\n");
    }
    if (ferror(arq))
        printf("Erro na gravação!\n");

    fclose(arq);
}

/*
int buscaPosicaoVazia ()
{
    for (int i=0; i<N; i++)
    {
        if (cliente[i].flag == 0)
        {
            return i;
        }
    }
    return -1;
}
*/
/*
int buscaCPF (long cpf)
{
    for (int i=0; i<N; i++)
    {
        if (cpf == cliente[i].cpf && cliente[i].flag == 1)
            return i;
    return -1;
    }
}
*/
/*
void buscaNome (char str[])
{
    int retorno, cont=0;
    for (int i=0; i<N; i++)
    {
      retorno = strcmp(cliente[i].nome, str);
      if(retorno == 0 && cliente[i].flag == 1)
      {
          cont++;
          listaCliente(i);
      }
    }
    if (cont == 0)
        printf("Cliente não cadastrado\n");
}
*/
/*
void removeCliente (int pos)
{
    long cpfr;
    if (cliente[pos].flag != 0)
    {
        printf("Digite o cpf do cliente para confirmar a remoção: ");
        scanf("%ld", &cpfr);
        if (cpfr == cliente[pos].cpf)
        {
            cliente[pos].flag = 0;
            printf("O cliente de id %d foi removido\n", pos);
        }
        else
            printf(" CPF incorreto\n Operação cancelada.\n");
    }
    else
        printf("Cliente não registrado");
}
*/
/*
void deposito (float money, int conta, int ag, int cont)
{
    int x = 0;
    cont = 0;
    printf("Digite a quantidade a ser depositada: ");
    scanf("%f", &money);
    printf("Digite a conta: ");
    scanf("%d", &conta);
    printf("Digite a agencia: ");
    scanf("%d", &ag);
    for (int i=1; i<=N; i++)
    {
        if (cliente[i].conta == conta)
            cont++;
            if (cliente[i].ag == ag)
            {
                cont++;
                i = x;
            }
    }
    if (cont == 2)
        cliente[x].saldo = money;
    else
        printf("Cliente não localizado");

}
*/

int main()
{
    int a, op, p, pos, conta, ag, contdep;
    long cpfBusca;
    char nomeBusca[51];
    float money;
    inicializa();
    do{
        op = menu();
        switch (op)
        {
          case 1: cadastraCliente();
                  break;
          case 2: listaTodosCliente();
                  break;
          //case 3: a = submenu();
            //      if (a == 1)
              //    {
                //      printf("Busca nome: ");
                  //    scanf("%s", &nomeBusca);
                    //  buscaNome(nomeBusca);
                //  }
                //  else if(a == 2)
                //  {
                  //    printf("busca cpf: ");
                  //    scanf("%ld", &cpfBusca);
                //      p = buscaCPF(cpfBusca);
                //      if (p != -1)
              //            listaCliente(p);
              //        else
              //            printf("Cliente não localizado\n");
              //    }
              //    else
              //        printf("Opção inválida.\n");
              //    break;
          //case 4: printf("Digite o id do cliente a ser removido: ");
          //        scanf("%d", &pos);
          //        removeCliente(pos);
        //          break;
        //  case 5: deposito(money, conta, ag, contdep);
        //          break;
          case 0: printf("Programa finalizado.\n");
                  break;
          default: printf("Opção inválida.\n");
        }
  }while(op != 0);
  return 0;
}
