#include<stdio.h>
#include<stdlib.h>

struct stack {
    char *exp;
    int top, size;
};

int isEmpty(struct stack *ptr) {
    if(ptr->top == -1) {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr) {
    if(ptr->top == ptr->size - 1) {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, char val) {
    if(isFull(ptr)) {
        printf("STACK OVERFLOW! Element %c cannot be pushed into the stack\n", val);
    }
    else {
        ptr->top++;
        ptr->exp[ptr->top] = val;
    }
}

char pop(struct stack *ptr) {
    if(isEmpty(ptr)) {
        printf("STACK UNDERFLOW! Could not perform pop\n");
        return '\0';
    }
    else {
        char val = ptr->exp[ptr->top];
        ptr->top--;
        return val;
    }
}

int paranthesisMatching(char *exp) {
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->exp = (char *)malloc(sizeof(char) * sp->size);
    
    for(int i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '(') {
            push(sp, '(');
        }
        else if(exp[i] == ')') {
            if(isEmpty(sp)) {
                free(sp->exp);
                free(sp);
                return 0;
            }
            pop(sp);
        }
    }
    
    if(isEmpty(sp)) {
        free(sp->exp);
        free(sp);
        return 1; // Expression is valid
    }
    else {
        free(sp->exp);
        free(sp);
        return 0; // Expression is not valid
    }
}

int main() {
    char *exp = (char *)malloc(sizeof(char) * 100);
    printf("Enter the expression: ");
    scanf("%s", exp);
    
    if(paranthesisMatching(exp)) {
        printf("The expression is valid\n");
    }
    else {
        printf("The expression is not valid\n");
    }
    
    free(exp);
    return 0;
}
