#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
  
};
struct node * insertAtIndex(struct node * head, int data, int index)
{
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    struct node * p = (struct node*)malloc(sizeof(struct node));
    ptr = head;
    p = head->next;

    while(ptr != index-1)
    {
        ptr = ptr->next;
        p = p->next;
    }



   
}
int main()
{
	struct node * head; 
    struct node * second; 
    struct node * third; 
    struct node * fourth;
head = (struct node*)calloc(1, sizeof(struct node));
second = (struct node*)calloc(1, sizeof(struct node));
third = (struct node*)calloc(1, sizeof(struct node));
fourth = (struct node*)calloc(1, sizeof(struct node));

head->next = second;
head->data = 9;
second->next = third;
second->data = 8;
third->next = fourth;
third->data = 22;
fourth->next = head;
fourth->data = 3;
    return 0;
}
