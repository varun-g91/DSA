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
int linearSearch(int element, struct myArray *a)
{
    int found = 1;
    printf("\nPerorming linear search!\n");
    for (int i = 0; i < (a->used_size); i++)
    {
        if ((a->ptr)[i] == element)
        {
            printf("The element %d was found in index %d\n", element, i);
            found = 0;
            break;
        }
    }
    if (found != 0)
    {
        printf("The element was not found in the array!\n");
    }
    else
        return 1;
}
int binarySearch(struct myArray *a, int element)
{
    int found = 1, low = 0, high = (a->used_size) - 1, mid;
    printf("Performing Binary Search!\n");
    while (low <= high)
    {
        int mid = high + low / 2;
        if ((a->ptr)[mid] == element)
        {
            return mid;
        }
        if ((a->ptr)[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
}
// int insertion(struct myArray *a, int element, int size, int capacity, int index)
// {
//     if (size >= capacity)
//         printf("Maximum capacity reached!\n");
//     else
//     {
//         for (int i = size - 1; i >= index; i--)
//         {
//             (a->ptr)[i + 1] = (a->ptr)[i];
//         }
//         (a->ptr)[index] = element;
//         a->used_size+=1;
//         return 1;
//     }
// }
// int deletion(struct myArray *a, int size, int indexD)
//{
//    if (indexD < 0 || indexD >= size)
//    {
//        printf("Invalid index for deletion\n");
//        return -1;
//    }
//    int last = (a->ptr)[size-1];
//    for (int i = indexD; i < size - 1; i++)
//    {
//        (a->ptr)[i] = (a->ptr)[i + 1];
//    }
//     a->used_size--;
//
//    return 1;
//}

int main()
{
    struct myArray marks;
    int n, element, indexS, indexD, find;
    printf("Enter the size of your array:\n");
    scanf("%d", &n);
    createArray(&marks, 100, n);
    take(&marks);
    show(&marks);
    // printf("\nEnter the index at which you want to insert the element:\n");
    // scanf("%d", &indexS);
    // printf("Enter the element you want to insert:\n");
    // scanf("%d", &element); // Use the same variable here
    // insertion(&marks, element, n, 100, indexS);
    // show(&marks);
    // printf("\nThe array before deletion:\n");
    // show(&marks);
    // printf("\nEnter the index of the item you want to delete:\n");
    // scanf("%d", &indexD);
    // deletion(&marks, n, indexD);
    // printf("The array after deletion:\n");
    // show(&marks);
    printf("\nEnter the element you want to search in the array:\n");
    scanf("%d", &find);
    linearSearch(find, &marks);
    //int foundIndex = binarySearch(&marks, find);
    //printf("The element %d, was found at index %d\n", find, foundIndex);

    return 0;
}
