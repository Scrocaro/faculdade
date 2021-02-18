#include <stdio.h>

int string_clone(char *texto)
{
	char* txt = (char*) calloc(20, sizeof(char));
    for (int i = 0; i < 20; ++i)
    {
    	*(txt + i) = *(texto + i);
    }
    return txt;
}

int main()
{
    char str[20] = "ABC";
    char* copia = string_clone(str);
    printf("%s", copia); //"ABC"
}