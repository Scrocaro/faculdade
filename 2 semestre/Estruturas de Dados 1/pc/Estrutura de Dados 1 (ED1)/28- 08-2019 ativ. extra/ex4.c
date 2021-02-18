#include <stdio.h>

int intercala_a(int* va, int tama, int* vb, int tamb)
{
    int i=0, j=0, t = tama + tamb ;
	printf("[");
	for(int k = 0; k < t; k++)
	{
	    if(i < tama)
	    {
	        printf("%d", va[i]);
	        i++;
	        if(k < t)  printf(",");
	    }
	    if(j < tamb)
	    {
    	    printf("%d", vb[j]);
    	    j++;
    	    if(k < t)
    	    {
    	        if(k != t - 1)
    	        {
    	            printf(",");
    	        }
    	    }
    	}
	}
	printf("]");
}



int main()
{
	int v1[3] = {2,4,6};
	int v2[4] = {3,5,7,9};
	int v3[7];
	int *v4;
	v4 = intercala_a(v1, 3, v2, 4);
	//intercala_b(v1, 3, v2, 4, v3);
}