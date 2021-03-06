#include <stdio.h>

int not(int x);
int or(int x, int y);
int and(int x, int y);
int nor(int x, int y);
int nand(int x, int y);
int xor(int x, int y);
int xnor(int x, int y);

int main(){
    int a, a2, b, b2, c, c2, d, d2;
    int temp1, temp2, temp3, temp4, temp5, temp6;
    a = 1;
    b = 0;
    c = 0;
    d = 0;
    na = not(a);
    nb = not(b);
    nc = not(c);
    nd = not(d);

    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    //ex1
    int m1 = a;
    int m2 = b;
    int m3 = or( and(nb,c), and( and(b,c),na) );

    temp1 = and(na, nb);
    temp2 = and( na, nc);
    temp3 = and(a, and(nb, nc));
    int m4 = and(d, or(temp1, or(temp2, temp3)) );

    printf("ex1: m1 = %d - m2 = %d - m3 = %d - m4 = %d\n", m1, m2, m3 , m4);

    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    //ex2
    int m1 = and( and(na,b), and(c,nd) );
    int m2 = and( and(a,nb), and(nc,d) );

    printf("ex2: md = %d - ms = %d\n", m1, m2);

    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    //ex3
    int m1 = or( and(na,b), and(b,and(c,d)) );

    printf("ex3: s = %d\n", m1);

    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    //ex4
    l0 = 1;
    l1 = 0;
    int m1 = or( and(na,l0), and(a,l1) );
    printf("ex4: s = %d\n", m1);

    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    //ex5
    temp1 = and( xor(a,b), c);
    temp2 = and( xnor(a,b), cn);
    int m1 = or(temp1, temp2);
    printf("ex5: s = %d\n", m1);

    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    //ex6
    printf("ex6: longo e trabalhoso, parecido com o ex5\n");

    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    //ex7
    int m1 = or( and(na,b), and(b,and(c,d)) );

    printf("ex7: s = %d\n", m1);

    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    //ex8
    int m1 = na;
    int m2 = and(b, nc);
    printf("ex8: ev = %d - bo = %d\n", m1, m2);

    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    //ex9
    int m1 = or( and(a,c), and(b,c) );
    printf("ex9: s = %d\n", m1);

    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    //ex10
    temp2 = and( na, and(nb,d) );
    temp3 = and( a, and(b,or(nc,nd)) );
    int m1 = or( and(nc,nd), or(temp2,temp3) );
    printf("ex10: s = %d\n", m1);

    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////
    //ex11
    temp1 = or( and(a,nc), and(b,c) );
    printf("ex11 = %d\n", temp1);


////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

int not(int x){
    if(x == 1) return 0;
    return 1;
}

int or(int x, int y){
    if(x == 1 || y == 1) return 1;
    return 0;
}

int and(int x, int y){
    if(x == 1 && y == 1) return 1;
    return 0;
}

int nor(int x, int y){
    if(x == 1 || y == 1) return 0;
    return 1;
}

int nand(int x, int y){
    int temp;
    if(x == 1 && y == 1) temp = 1;
    else temp = 0;

    if(temp == 1) return 0;
    else return 1;
}

int xor(int x, int y){
    if(x != y) return 1;
    else return 0;
}

int xnor(int x, int y){
    if(x == y) return 1;
    else return 0;
}
