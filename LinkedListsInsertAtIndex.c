
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
  
};
struct node * insertAtIndex(struct node* head, int data, int index)
{
   struct node * ptr = (struct node*)malloc(sizeof(struct node));
   struct node *p = head;
   int i = 0;
   while(i<index-1){
    p = p->next;
   }
   p->next = ptr;
   ptr->data = data;
   
}