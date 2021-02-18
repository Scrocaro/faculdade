#include <stdio.h>
int main(){
    float n1, n2, result;
    int op;
    printf("digite 2 números: ");
    scanf("%f%f", &n1, &n2);
    printf("Qual operação deseja realizar?\n [1] SOMA\n [2] SUBTRAÇÃO\n [3] MULTIPLICAÇÃO\n [4] DIVISÃO\n");
    scanf("%d", &op);
    switch (op){
        case 1: result=n1+n2;
                printf("resultado: %.1f\n", result);
                break;
        case 2: result=n1-n2;
                printf("resultado: %.1f\n", result);
                break;
        case 3: result=n1*n2;
                printf("resultado: %.1f\n", result);
                break;
        case 4:if(n2==0){
            		printf("erro.\n");
          		}else{
            		result=n1/n2;
            		printf("resultado: %.1f\n", result);
         		}
           		break;
        default:printf("erro\n");
        		return 1;
        		break;
    }
    if(result>=0){
        printf("positivo.\n");
    }else{
        printf("negativo.\n");
    }
    if(result == (int)result){
        printf("Inteiro.\n");
        if((int)result%2 == 0){
            printf("par\n");
        }else{
            printf("impar\n");
        }
    }else{
        printf("decimal.\n");
        printf("decimal não pode ser par ou impar\n");
    }
    return 0;
}
