#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traverseList(struct node *head)
{
    while (head != NULL)
    {
        printf("The element is: %d \n", head->data);
        head = head->next;
    }
}

struct node * deleteAtIndex(struct node* head, int index)
{
    struct node * p = head;
    struct node * q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

}
struct node *deleteFirstNode(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    struct node *newHead = head->next;
    free(head);
    return newHead;
}
struct node * deleteLastNode(struct node *head)
{
    struct node * p = head;
    struct node * q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
}
struct node * deleteGivenValue(struct node * head, int value)
{
    struct node * p = head;
    struct node * q = head->next;
    while(q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if(q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    int index, value;
    head = (struct node *)calloc(1, sizeof(struct node));
    second = (struct node *)calloc(1, sizeof(struct node));
    third = (struct node *)calloc(1, sizeof(struct node));
    fourth = (struct node *)calloc(1, sizeof(struct node));
    head->next = second;
    head->data = 9;
    second->next = third;
    second->data = 8;
    third->next = fourth;
    third->data = 22;
    fourth->next = NULL;
    fourth->data = 3;

   // printf("List before deletion\n");
   // traverseList(head);
//
   // printf("List after deletion:\n");
   // head = deleteFirstNode(head);
   // traverseList(head);
   //printf("Enter the list index of the node to be deleted:\n");
   //scanf("%d", &index);
   //printf("List before deletion\n");
   //traverseList(head);
   //deleteAtIndex(head, index);
   //printf("List after deletion:\n");
   //traverseList(head);
   //printf("List before deletion\n");
   //traverseList(head);
   //printf("List after deletion:\n");
   //deleteLastNode(head);
   //traverseList(head);
   
   printf("Enter the value at which you would like to perform deletion:\n");
   scanf("%d", &value);
   printf("List before deletion\n");
   traverseList(head);
   printf("List after deletion:\n");
   deleteGivenValue(head, value);
   traverseList(head);

    return 0;
}
