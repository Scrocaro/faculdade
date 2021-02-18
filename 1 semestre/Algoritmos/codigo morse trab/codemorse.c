#include <stdio.h>
#include <string.h>

int main(){
	int i;
    char vet[1024], cod[1024] = "";

    FILE *arq;
    arq = fopen("decodificado.txt", "r");
    fscanf(arq, " %[^\n]", vet);
    fclose(arq);

    for(i=0; i<strlen(vet); i++){
        if(vet[i] == 'a' || vet[i] == 'A')	     strcat(cod, ".- ");
        else if(vet[i] == 'b' || vet[i] == 'B')  strcat(cod, "-... ");
        else if(vet[i] == 'c' || vet[i] == 'C')  strcat(cod, "-.-. ");
        else if(vet[i] == 'd' || vet[i] == 'D')  strcat(cod, "-.. ");
        else if(vet[i] == 'e' || vet[i] == 'E')  strcat(cod, ". ");
        else if(vet[i] == 'f' || vet[i] == 'F')  strcat(cod, "..-. ");
        else if(vet[i] == 'g' || vet[i] == 'G')  strcat(cod, "--. ");
        else if(vet[i] == 'h' || vet[i] == 'H')  strcat(cod, ".... ");
        else if(vet[i] == 'i' || vet[i] == 'I')  strcat(cod, ".. ");
        else if(vet[i] == 'j' || vet[i] == 'J')  strcat(cod, ".--- ");
        else if(vet[i] == 'k' || vet[i] == 'K')  strcat(cod, "-.- ");
        else if(vet[i] == 'l' || vet[i] == 'L')  strcat(cod, ".-.. ");
        else if(vet[i] == 'm' || vet[i] == 'M')  strcat(cod, "-- ");
        else if(vet[i] == 'n' || vet[i] == 'N')  strcat(cod, "-. ");
        else if(vet[i] == 'o' || vet[i] == 'O')  strcat(cod, "--- ");
        else if(vet[i] == 'p' || vet[i] == 'P')  strcat(cod, ".--. ");
        else if(vet[i] == 'q' || vet[i] == 'Q')  strcat(cod, "--.- ");
        else if(vet[i] == 'r' || vet[i] == 'R')  strcat(cod, ".-. ");
        else if(vet[i] == 's' || vet[i] == 'S')  strcat(cod, "... ");
        else if(vet[i] == 't' || vet[i] == 'T')  strcat(cod, "- ");
        else if(vet[i] == 'u' || vet[i] == 'U')  strcat(cod, "..- ");
        else if(vet[i] == 'v' || vet[i] == 'V')  strcat(cod, "...- ");
        else if(vet[i] == 'w' || vet[i] == 'W')  strcat(cod, ".-- ");
        else if(vet[i] == 'x' || vet[i] == 'X')  strcat(cod, "-..- ");
        else if(vet[i] == 'y' || vet[i] == 'Y')  strcat(cod, "-.-- ");
        else if(vet[i] == 'z' || vet[i] == 'Z')  strcat(cod, "--.. ");
        else if(vet[i] == ' ')				     strcat(cod, " \\ ");
        else if(vet[i] == '1') 				     strcat(cod, ".---- ");
        else if(vet[i] == '2')                   strcat(cod, "..--- ");
        else if(vet[i] == '3')				     strcat(cod, "...-- ");
        else if(vet[i] == '4')				     strcat(cod, "....- ");
        else if(vet[i] == '5')				     strcat(cod, "..... ");
        else if(vet[i] == '6')                   strcat(cod, "-.... ");
        else if(vet[i] == '7')                   strcat(cod, "--... ");
        else if(vet[i] == '8')                   strcat(cod, "---.. ");
        else if(vet[i] == '9')                   strcat(cod, "----. ");
        else if(vet[i] == '0')                   strcat(cod, "----- ");
    }

    printf("Mensagem decodificada: %s\n", vet);
    printf("Mensagem codificada: %s\n", cod);

    FILE *p;
    p = fopen("codificado.txt", "w");
    fwrite(&cod, sizeof(cod), 1, p);
    fclose(p);
}
