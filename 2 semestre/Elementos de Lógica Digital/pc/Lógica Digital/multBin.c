//Alexandre A. Scrocaro Junior      R.A.:2135485
#include <stdio.h>
#define N 4

int main()
{
    int m[N] = {0, 0, 1, 0}, q[N] = {0, 0 , 1, 1}, a[N] = {0, 0, 0, 0}, c = 0, p[N*2];
    int cout = 0, cin = 0, i, j, k, l, x, temp, tempc, tempA, saidaDesloca = 0;

    //SOMA
    for(i = 0; i<N; i++)
    {
        if(q[3] == 1)
        {
            if(i==0)
            {
                for(x = 0; x < N; x++)
                {
                    a[x] = m[x];
                }
            }
            else
            {
                cin=0;
                for(j = N - 1; j >= 0; j--)
                {
                    if(c == 0)
                    {
                        a[j] = a[j] + m[j];
                        
                        if(a[j] == 0)
                        {
                            a[j] = a[j] + cin;
                            cout = 0;
                        }
                        else if(a[j] == 1)
                        {
                            a[j] = a[j] + cin;
                            if(a[j] == 2)
                            {
                                a[j] = 0;
                                cout = 1;
                            }
                            else
                            {
                                a[j] = 1;
                                cout = 0;
                            }
                        }
                        else if(a[j] == 2)
                        {
                            cout = 1;
                            a[j] = 0;
                        }
                    }
                    if(j == 0 && cout == 1)
                    {
                        c = 1;
                    }
                    else if(c == 1)
                    {
                        tempc = c + m[j];
                        if(tempc == 1)
                        {
                            cout = 1;
                            a[j] = 0 + a[j];
                        }
                        else
                        {
                            a[j] = tempc + a[j];
                            cout = 0;
                        }
                    }
                    if(j == 0 && cout == 1)
                    {
                        c = 1;
                    }
                    cin = cout;
                }
            }
        }
        /*
        printf("ANTES\ni = %d\n", i);
        printf("c = %d\nm = ", c);
        for(l = 0; l < N; l++)
        {
            printf("%d, ", m[l]);
        }
        printf("\na = ");
        for(l = 0; l < N; l++)
        {
            printf("%d, ", a[l]);
        }
        printf("\nq = ");
        for(l = 0; l < N; l++)
        {
            printf("%d, ", q[l]);
        }
        printf("\n\n");
        */

        //DESLOCA
        tempA = a[3];
        
        for(k = N-1; k >= 0; k--)
        {
            if(k == 0)
            {
                q[0] = tempA;
                if(c == 1){
                    a[0] = 1;
                    c = 0;
                }
                else
                {
                    a[0] = 0;
                }
                break;
            }
            a[k] = a[k-1];
            q[k] = q[k-1];
        }
        /*
        printf("DEPOIS\ni = %d\n", i);
        printf("c = %d\nm = ", c);
        for(l = 0; l < N; l++)
        {
            printf("%d, ", m[l]);
        }
        printf("\na = ");
        for(l = 0; l < N; l++)
        {
            printf("%d, ", a[l]);
        }
        printf("\nq = ");
        for(l = 0; l < N; l++)
        {
            printf("%d, ", q[l]);
        }
        printf("\n\n");
        */
    }
        printf("%d,\n", c);
        for(l = 0; l < N; l++)
        {
            printf("%d, ", a[l]);
        }
        printf("\n");
        for(l = 0; l < N; l++)
        {
            printf("%d, ", q[l]);
        }
}