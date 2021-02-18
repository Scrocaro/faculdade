/*4.1 Decodiﬁca¸c˜ao da mensagem de co´digo morse em alfanumerico
Em um programa chamado “decodemorse.c” e utilizando as tabelas de convers˜ao, faca um algoritmo que decodiﬁca mensagens de Codigo Morse, transformando-as
em texto puro. O algoritmo deve ler a mensagem codiﬁcada de um arquivo (codiﬁcado.txt) e imprimir na tela tanto a mensagem codiﬁcada quanto
o texto decodiﬁcado. A mensagem decodiﬁcada em morse deve ser gravada em outro arquivo (decodiﬁcado.txt)*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*char local[]=”c:\\exemplos\arquivo.txt”; */
void decod();

void decod()
{
    int tamanho;
    char msgdecod[256];
    printf("Escreva a mensagem codificada em morse: ");
    scanf("%[^\n]", msgdecod);
    tamanho = strlen(msgdecod);
}

int main()
{
    char msgdecod[256];
    int tamanho, cont = 0;
    decod();
    printf("\n %d \n", tamanho);

        printf("\n %d \n", tamanho);
        switch (msgdecod)
        {
            case 'a': printf(".- ");
                      cont++;
                break;
            case 'b': printf("-... ");
                      cont++;
                break;
            case 'c': printf("-.-. ");
                      cont++;
                break;
            case 'd': printf("-.. ");
                      cont++;
                break;
            case 'e': printf(". ");
                      cont++;
                break;
            case 'f': printf("..-. ");
                      cont++;
                break;
            case 'g': printf("--. ");
                      cont++;
                break;
            case 'h': printf(".... ");
                      cont++;
                break;
            case 'i': printf(".. ");
                      cont++;
                break;
            case 'j': printf(".--- ");
                      cont++;
                break;
            case 'k': printf("-.- ");
                      cont++;
                break;
            case 'l': printf(".-.. ");
                      cont++;
                break;
            case 'm': printf("-- ");
                      cont++;
                break;
            case 'n': printf("-. ");
                      cont++;
                break;
            case 'o': printf("--- ");
                      cont++;
                break;
            case 'p': printf(".--. ");
                      cont++;
                break;
            case 'q': printf("--.- ");
                      cont++;
                break;
            case 'r': printf(".-. ");
                      cont++;
                break;
            case 's': printf("... ");
                      cont++;
                break;
            case 't': printf("- ");
                      cont++;
                break;
            case 'u': printf("..- ");
                      cont++;
                break;
            case 'v': printf("...- ");
                      cont++;
                break;
            case 'w': printf(".-- ");
                      cont++;
                break;
            case 'x': printf("-..- ");
                      cont++;
                break;
            case 'y': printf("-.-- ");
                      cont++;
                break;
            case 'z': printf("--.. ");
                      cont++;
                break;
            case ' ': printf(" / ");
                      cont++;
                break;
            case 1: printf(".----");
                      cont++;
                break;
            case 2: printf("..---");
                      cont++;
                break;
            case 3: printf("...--");
                      cont++;
                break;
            case 4: printf("....-");
                      cont++;
                break;
            case 5: printf(".....");
                      cont++;
                break;
            case 6: printf("-....");
                      cont++;
                break;
            case 7: printf("--...");
                      cont++;
                break;
            case 8: printf("---..");
                      cont++;
                break;
            case 9: printf("----.");
                      cont++;
                break;
            case 0: printf("-----");
                      cont++;
                break;

    }
}
