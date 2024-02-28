#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
  
};
void traverseList(struct node* head)
{
    while(head!=NULL)
    {
        printf("The element is: %d and its address is: %p\n", head->data, &head->data);
        head = head->next;
    }
}
struct node * insertAtFirst(struct node* head, int data)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct node * insertAtIndex(struct node* head, int data, int index)
{
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    struct node * p = head;
    int i = 0;
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct node * insertAfterNode(struct node* head, struct node* prevNode, int data)
{
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    
    head = (struct node*)calloc(1, sizeof(struct node));
    second = (struct node*)calloc(1, sizeof(struct node));
    third = (struct node*)calloc(1, sizeof(struct node));
    fourth = (struct node*)calloc(1, sizeof(struct node));
    //Reading values for nodes
    /*printf("Enter the data in node 1:");
    scanf("%d", &head->data);
    printf("Enter the data in node 2:");
    scanf("%d", &second->data);
    printf("Enter the data in node 3:");
    scanf("%d", &third->data);
    printf("Enter the data in node 4:");
    scanf("%d", &fourth->data);*/
    //Linking nodes together
    head->next = second;
    head->data = 9;
    second->next = third;
    second->data = 8;
    third->next = fourth;
    third->data = 22;
    fourth->next = NULL;
    fourth->data = 3;
    //call traversal function
    traverseList(head);
    printf("\n");
   // head = insertAtFirst(head, 888);
  //  traverseList(head);
   // insertAtIndex(head, 33, 3);
   // traverseList(head);
    head = insertAfterNode(head, third, 897);
    traverseList(head);
    return 0;


    

}