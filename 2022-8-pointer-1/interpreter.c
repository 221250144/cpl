#include<stdio.h>

int main()
{
    int X;
    scanf("%x",&X);
    printf("%d\n%u\n%f\n%.3e\n",X,X,*((float*)&X),*((float*)&X));

    return 0;
}