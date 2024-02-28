#include <stdio.h>


int fibonacci(int n)
{
    if(n<=1)
    return n;
    else
    return fibonacci(n-1)+fibonacci(n-2);
}
int printSeries(int n, int current)
{
    if(current < n)
    {
        printf("%d", fibonacci(current));
        printSeries(n, current+1);
    }
  
}
int main()
{
    int n;
    printf("Enter the nth term to print the series:\n");
    scanf("%d", &n);
    printf("The series till %d is:\n", n);
    printSeries(n, 0);
}
