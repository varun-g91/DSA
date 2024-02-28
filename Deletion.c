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
struct node * deleteFirstNode(struct node* head)
{
    struct node * p = head;
    head = head->next;
    free(p);
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
    deleteFirstNode(head);
    traverseList(head);
   // head = insertAtFirst(head, 888);
  //  traverseList(head);
   // insertAtIndex(head, 33, 3);
   // traverseList(head);
    //head = insertAfterNode(head, third, 897);
   // traverseList(head);
    return 0;


    

}