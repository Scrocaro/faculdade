#include <stdio.h>
#include <string.h>

int main()
{
    char vet[1024], decod[1024] = "";
	int i, j;

    FILE *arq;
    arq = fopen("codificado.txt", "r");
    fscanf(arq, " %[^\n]", vet);
    fclose(arq);

    printf("Mensagem codificada: %s\n", vet);
    for(i=0; i<strlen(vet); i++)
	{
        int cont=0;
        char morse[8];
        if(vet[i] != '.' && vet[i] != '-') //Checa se existe um codigo morse nesta casa.
        {
		    if(vet[i] != ' ') strcat(decod, " ");
        }
        else
		{
            for(j=i; j<strlen(vet); j++) // Conta quantas casas tem o código morse
            {
			    if(vet[j] != '.' && vet[j] != '-') break;
                cont++;
            }
            for(j=0; j<(cont); j++) // Pega a quantidade de casas e passa pra string 'morse'
            {
			    morse[j] = vet[i+j];
                morse[j+1] = '\0';
            }
            i = i+cont; //Faz o i pular pra proxima palavra.
            if(strcmp(morse, ".") == 0){                   strcat(decod, "E");						}
            else if(strcmp(morse, "-") == 0){              strcat(decod, "T");						}
            else if(strcmp(morse, ".-") == 0){             strcat(decod, "A");						}
            else if(strcmp(morse, "..") == 0){             strcat(decod, "I");						}
            else if(strcmp(morse, "--") == 0){             strcat(decod, "M");						}
            else if(strcmp(morse, "-.") == 0){             strcat(decod, "N");						}
            else if(strcmp(morse, "-..") == 0){            strcat(decod, "D");   					}
            else if(strcmp(morse, "--.") == 0){            strcat(decod, "G");						}
            else if(strcmp(morse, "-.-") == 0){            strcat(decod, "K");						}
            else if(strcmp(morse, "---") == 0){            strcat(decod, "O");						}
            else if(strcmp(morse, ".-.") == 0){            strcat(decod, "R");						}
            else if(strcmp(morse, "...") == 0){            strcat(decod, "S");						}
            else if(strcmp(morse, "..-") == 0){            strcat(decod, "U");						}
            else if(strcmp(morse, ".--") == 0){            strcat(decod, "W");						}
            else if(strcmp(morse, "-...") == 0){           strcat(decod, "B");						}
            else if(strcmp(morse, "-.-.") == 0){           strcat(decod, "C");						}
            else if(strcmp(morse, "..-.") == 0){           strcat(decod, "F");						}
            else if(strcmp(morse, "....") == 0){           strcat(decod, "H");						}
            else if(strcmp(morse, ".---") == 0){           strcat(decod, "J");						}
            else if(strcmp(morse, ".-..") == 0){           strcat(decod, "L");						}
            else if(strcmp(morse, ".--.") == 0){           strcat(decod, "P");						}
            else if(strcmp(morse, "--.-") == 0){           strcat(decod, "Q");						}
            else if(strcmp(morse, "...-") == 0){           strcat(decod, "V");						}
            else if(strcmp(morse, "-..-") == 0){           strcat(decod, "X");						}
            else if(strcmp(morse, "-.--") == 0){           strcat(decod, "Y");						}
            else if(strcmp(morse, "--..") == 0){           strcat(decod, "Z");						}
            else if(strcmp(morse, ".----") == 0){          strcat(decod, "1");						}
            else if(strcmp(morse, "..---") == 0){          strcat(decod, "2");						}
            else if(strcmp(morse, "...--") == 0){          strcat(decod, "3");						}
            else if(strcmp(morse, "....-") == 0){          strcat(decod, "4");						}
            else if(strcmp(morse, ".....") == 0){          strcat(decod, "5");						}
            else if(strcmp(morse, "-....") == 0){          strcat(decod, "6");						}
            else if(strcmp(morse, "--...") == 0){          strcat(decod, "7");						}
            else if(strcmp(morse, "---..") == 0){          strcat(decod, "8");						}
            else if(strcmp(morse, "----.") == 0){          strcat(decod, "9");						}
            else if(strcmp(morse, "-----") == 0){          strcat(decod, "0");						}
            else if(strcmp(morse, "-..-.") == 0){          strcat(decod, "/");						}
            else if(strcmp(morse, "-.--.") == 0){          strcat(decod, "(");						}
            else if(strcmp(morse, ".-...") == 0){          strcat(decod, "&");						}
            else if(strcmp(morse, "-...-") == 0){          strcat(decod, "=");						}
            else if(strcmp(morse, ".-.-.-") == 0){         strcat(decod, ".");						}
            else if(strcmp(morse, "--..--") == 0){         strcat(decod, ",");						}
            else if(strcmp(morse, "..--..") == 0){         strcat(decod, "?");						}
            else if(strcmp(morse, "-.-.--") == 0){         strcat(decod, "!");						}
            else if(strcmp(morse, "-.--.-") == 0){         strcat(decod, ")");						}
            else if(strcmp(morse, "---...") == 0){         strcat(decod, ":");						}
            else if(strcmp(morse, "-.-.-.") == 0){         strcat(decod, ";");						}
            else if(strcmp(morse, "-....-") == 0){         strcat(decod, "-");						}
            else if(strcmp(morse, "..--.-") == 0){         strcat(decod, "_");						}
            else if(strcmp(morse, ".--.-.") == 0){         strcat(decod, "@");						}
            else if(strcmp(morse, "...-..-") == 0){        strcat(decod, "$");						}
        }
    }
    printf("Mensagem decodificada: %s\n", decod);

    FILE *p;
    p = fopen("decodificado.txt", "w");
    fwrite(&decod, sizeof(decod), 1, p);
    fclose(p);
}
