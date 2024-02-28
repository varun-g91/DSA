#include <stdio.h>
#include <stdlib.h>
struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};
void createArray(struct myArray *a, int tsize, int usize)
{
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc(tsize * sizeof(int));
}
void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\t", (a->ptr)[i]);
    }
}
void take(struct myArray *a)
{ 
    int n;
    printf("Enter the elements of your abstract array:\n");
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d\n", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}
int main()
{
    struct myArray marks;
    int n;
    printf("Enter the size of your array:\n");
    scanf("%d", &n);
    createArray(&marks, 100, n);
    take(&marks);
    show(&marks);
    return 0;
}