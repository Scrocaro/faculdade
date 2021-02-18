//CONTA BANCO

#include <stdio.h>
#include <string.h>
#define N 7


void cadastraCliente(int pos);
void listaTodosCliente();
void listaCliente (int pos);
void inicializaVetor();
int buscaPosicaoVazia();
int menu();
int buscaCPF (long cpf);
void buscaNome (char str[]);
void removeCliente (int pos);
int submenu();


struct REGISTRO{
  long ag, conta, cpf;
  char nome[51];
  int id, flag;
  float saldo;
};
struct REGISTRO cliente[N];


void inicializaVetor(){
for (int i=0; i<N; i++)
    cliente[i].flag=0;
}

int menu(){
  printf("\nMENU PRINCIPAL:\n");
  int op;
  printf(" 1 - Cadastrar cliente\n 2 - Lista todos clientes\n 3 - Lista um cliente\n 4 - remover um cliente\n 0 - Sair\n ");
  scanf("%d", &op);
  return op;
}


int submenu(){
    int opsub;
    printf("1 - busca por nome\n");
    printf("2 - busca por cpf\n");
    printf("opção: ");
    scanf("%d", &opsub);
    return opsub;
}


void cadastraCliente(int pos){
  printf("Digite a Agência: ");
  scanf("%ld", &cliente[pos].ag);
  printf("Digite a conta: ");
  scanf("%ld", &cliente[pos].conta);
  printf("Nome: ");
  scanf(" %[^\n]", cliente[pos].nome);
  printf("CPF: ");
  scanf("%ld", &cliente[pos].cpf);
  cliente[pos].id=pos;
  cliente[pos].flag=1;
  cliente[pos].saldo=0;

  printf("Cliente cadastrado\n");
}


void listaCliente (int pos){
    printf("Cliente ID: %d\n", cliente[pos].id);
    printf("Agencia: %ld\n", cliente[pos].ag);
    printf("Conta: %ld\n", cliente[pos].conta);
    printf("Nome: %s\n", cliente[pos].nome);
    printf("CPF: %ld\n", cliente[pos].cpf);
    printf("Saldo: R$ %.2f\n", cliente[pos].saldo);
    printf("\n -------------------- \n");
}


void listaTodosCliente(){
    int cont=0;
    for (int i=0; i<N; i++){
        if (cliente[i].flag == 1){
            printf("Cliente ID: %d\n", cliente[i].id);
            printf("Agencia: %ld\n", cliente[i].ag);
            printf("Conta: %ld\n", cliente[i].conta);
            printf("Nome: %s\n", cliente[i].nome);
            printf("CPF: %ld\n", cliente[i].cpf);
            printf("Saldo: R$ %.2f\n", cliente[i].saldo);
            printf("\n -------------------- \n");
            cont++;
        }
    }
    if (cont==0){
        printf("Não há clientes registrados\n");
    }
}


int buscaPosicaoVazia(){
    for (int i=0; i<N; i++){
        if (cliente[i].flag == 0){
            return i;
        }
    }
    return -1;
}


int buscaCPF(long cpf){
    for (int i=0; i<N; i++){
        if (cpf == cliente[i].cpf && cliente[i].flag == 1)
            return i;
    }
    return -1;
}


void buscaNome (char str[]){
    int retorno, cont=0;
    for (int i=0; i<N; i++){
      retorno = strcmp(cliente[i].nome, str);
      if(retorno == 0 && cliente[i].flag == 1)
          listaCliente(i);
          cont++;
    }
    if (cont == 0)
        printf("Cliente não cadastrado\n");
}


void removeCliente (int pos){
    long cpfr;
    if (cliente[pos].flag != 0){
        printf("Digite o cpf do cliente para confirmar a remoção: ");
        scanf("%ld", &cpfr);
        if (cpfr == cliente[pos].cpf){
            cliente[pos].flag = 0;
            printf("O cliente de id %d foi removido\n", pos);
        }
        else
            printf(" CPF incorreto\n Operação cancelada.\n");
    }
    else
        printf("Cliente não registrado");
}


int main(){
    int a, op, p, pos;
    long cpfBusca;
    char nomeBusca[51];
    inicializaVetor();
    do{
        op = menu();
        switch (op) {
          case 1: a = buscaPosicaoVazia();
                  if (a != -1)
                      cadastraCliente(a);
                  else
                      printf("Erro!\nVetor cheio!\n");
                  break;
          case 2: listaTodosCliente();
                  break;
          case 3: a = submenu();
                  if (a == 1){
                      printf("Busca nome: ");
                      scanf("%s", &nomeBusca);
                      buscaNome(nomeBusca);
                  }
                  else if(a == 2){
                      printf("busca cpf: ");
                      scanf("%ld", &cpfBusca);
                      p = buscaCPF(cpfBusca);
                      if (p != -1)
                          listaCliente(p);
                      else
                          printf("Cliente não localizado\n");
                  }
                  else
                      printf("Opção inválida.\n");
                  break;
          case 4: printf("Digite o id do cliente a ser removido: ");
                  scanf("%d", &pos);
                  removeCliente(pos);
                  break;
          case 0: printf("Programa finalizado.\n");
                  break;
          default: printf("Opção inválida.\n");
        }
  }while(op != 0);

  return 0;
}
