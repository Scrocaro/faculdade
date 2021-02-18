#include <stdio.h>
#include <string.h>

int main(){
    char vet[1024];
    printf("Escreva a mensagem codificada: ");
    scanf(" %[^\n]", vet);

    for(int i=0; i<strlen(vet); i++){
        int cont=0;
        char morse[8];

        if(vet[i] != '.' && vet[i] != '-')                    //Checa se existe um codigo morse nesta casa.
        {
            if(vet[i] != ' ')
                printf(" ", vet[i]);
        }
        else{
            for(int j=i; j<strlen(vet); j++)                  // Conta quantas casas tem o c�digo morse
            {
                if(vet[j] != '.' && vet[j] != '-') break;
                cont++;
            }

            for(int j=0; j<(cont); j++)                       // Pega a quantidade de casas e passa pra string 'morse'
            {
                morse[j] = vet[i+j];
                morse[j+1] = '\0';
            }
            i = i+cont;                                       //Faz o i pular pra proxima palavra.

            if(strcmp(morse, ".") == 0)            printf("E");
            else if(strcmp(morse, "-") == 0)            printf("T");
            else if(strcmp(morse, ".-") == 0)            printf("A");
            else if(strcmp(morse, "..") == 0)            printf("I");
            else if(strcmp(morse, "--") == 0)            printf("M");
            else if(strcmp(morse, "-.") == 0)            printf("N");
            else if(strcmp(morse, "-..") == 0)            printf("D");
            else if(strcmp(morse, "--.") == 0)            printf("G");
            else if(strcmp(morse, "-.-") == 0)            printf("K");
            else if(strcmp(morse, "---") == 0)            printf("O");
            else if(strcmp(morse, ".-.") == 0)            printf("R");
            else if(strcmp(morse, "...") == 0)            printf("S");
            else if(strcmp(morse, "..-") == 0)            printf("U");
            else if(strcmp(morse, ".--") == 0)            printf("W");
            else if(strcmp(morse, "-...") == 0)            printf("B");
            else if(strcmp(morse, "-.-.") == 0)            printf("C");
            else if(strcmp(morse, "..-.") == 0)            printf("F");
            else if(strcmp(morse, "....") == 0)            printf("H");
            else if(strcmp(morse, ".---") == 0)            printf("J");
            else if(strcmp(morse, ".-..") == 0)            printf("L");
            else if(strcmp(morse, ".--.") == 0)            printf("P");
            else if(strcmp(morse, "--.-") == 0)            printf("Q");
            else if(strcmp(morse, "...-") == 0)            printf("V");
            else if(strcmp(morse, "-..-") == 0)            printf("X");
            else if(strcmp(morse, "-.--") == 0)            printf("Y");
            else if(strcmp(morse, "--..") == 0)            printf("Z");
            else if(strcmp(morse, ".----") == 0)            printf("1");
            else if(strcmp(morse, "..---") == 0)            printf("2");
            else if(strcmp(morse, "...--") == 0)            printf("3");
            else if(strcmp(morse, "....-") == 0)            printf("4");
            else if(strcmp(morse, ".....") == 0)            printf("5");
            else if(strcmp(morse, "-....") == 0)            printf("6");
            else if(strcmp(morse, "--...") == 0)            printf("7");
            else if(strcmp(morse, "---..") == 0)            printf("8");
            else if(strcmp(morse, "----.") == 0)            printf("9");
            else if(strcmp(morse, "-----") == 0)            printf("0");
            else if(strcmp(morse, "-..-.") == 0)            printf("/");
            else if(strcmp(morse, "-.--.") == 0)            printf("(");
            else if(strcmp(morse, ".-...") == 0)            printf("&");
            else if(strcmp(morse, "-...-") == 0)            printf("=");
            else if(strcmp(morse, ".-.-.-") == 0)            printf(".");
            else if(strcmp(morse, "--..--") == 0)            printf(",");
            else if(strcmp(morse, "..--..") == 0)            printf("?");
            else if(strcmp(morse, ".----.") == 0)            printf("'");
            else if(strcmp(morse, "-.-.--") == 0)            printf("!");
            else if(strcmp(morse, "-.--.-") == 0)            printf(")");
            else if(strcmp(morse, "---...") == 0)            printf(":");
            else if(strcmp(morse, "-.-.-.") == 0)            printf(";");
            else if(strcmp(morse, "-....-") == 0)            printf("-");
            else if(strcmp(morse, "..--.-") == 0)            printf("_");
            else if(strcmp(morse, ".-..-.") == 0)            printf("%c", '"');
            else if(strcmp(morse, ".--.-.") == 0)            printf("@");
            else if(strcmp(morse, "...-..-") == 0)            printf("$");

        }
    }

}
