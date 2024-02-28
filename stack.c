#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size, top;
    int* arr;
};

int isEmpty(struct stack * ptr)
{
    if(ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack * ptr)
{
    if(ptr->top == ptr->size-1)
    {
        return 1;
    }
    return 0;
  
}
void push(struct stack * ptr, int val){
    if(isFull(ptr)){
        printf("STACK OVERFLOW! Element %d cannot be pushed into the stack\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
       
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("STACK UNDERFLOW! Could not perform pop\n");
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack *sp, int i){
    int arrIndex = sp->top-i +1;
    if(sp->top-i+1 < 0){
        printf("The position is not valid, please renter proper position");
        return -1;
    }
    else{
        return sp->arr[arrIndex];
    }
}
int stackTop(struct stack * sp){
    return sp->arr[sp->top];
}
int stackBottom(struct stack * sp){
    return sp->arr[0];
}
int main()
{
    struct stack * s;
    s->size = 10;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));

    if(isEmpty(s)){
        printf("The stack is empty\n");
    }
    else{
        printf("The stack is not empty\n");
    }
        if(isFull(s)){
        printf("The stack is full\n");
    }
    else{
        printf("The stack is not full\n");
    }
    push(s, 22);
    push(s, 90);
    push(s, 123);
    push(s, 4);
    push(s, 32);
    push(s, 66);
    push(s, 39);
    push(s, 12);
    push(s, 52);
    push(s, 43);
   
    
    
    
    



    
       if(isEmpty(s)){
        printf("The stack is empty\n");
    }
    else{
        printf("The stack is not empty\n");
    }
        if(isFull(s)){
        printf("The stack is full\n");
    }
    else{
        printf("The stack is not full\n");
    }

 

    for (int i = 0; i < s->size; i++)
    {
        printf("Element at index %d: %d\n",i, peek(s, i));
    }

    printf("The element at the top of the stack is: %d\n", stackTop(s));
    printf("The element at the bottom of the stack is: %d\n", stackBottom(s));

    


    return 0;
}