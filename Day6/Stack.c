#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data; 
    struct stack *next;
};

struct stack *top = NULL;
struct stack *push(struct stack *top, int val);
struct stack *display(struct stack *);
struct stack *pop(struct stack *);

struct stack *push(struct stack *top, int val){
    struct stack *ptr;
    ptr = (struct stack*)malloc(sizeof(struct stack));
    ptr -> data = val;
    if(top == NULL){
        ptr -> next = NULL;
        top = ptr;
    }
    else{
        ptr -> next = top;
        top = ptr;
    }
    return top;
}
struct stack *display (struct stack *top){
    struct stack *ptr;
    ptr = top;
    ptr = (struct stack*)malloc(sizeof(struct stack));
    if(top = NULL){
        printf("The Stack is empty\n");
    }
    else{
        while(ptr != NULL){
            printf("\n%d ", ptr->data);
            ptr = ptr -> next;
        }
    }
    return top;
}
struct stack *pop(struct stack *top){
    struct stack *ptr;
    ptr = top;
    if (top == NULL)
    printf("UNDERFLOW\n");
    else{
        top = top -> next;
        printf("Value deleted is: %d\n",  ptr -> data);
    }
    return top;
}
int peek(struct stack *top){
    if(top == NULL)
    return -1;
    else { 
            printf("The last element entered is: %d\n", top->data);
    }
}
int main(){
    struct stack *top = NULL;
    int val, choice;
        printf("----MENU----\n");
        printf("1. Enter the element\n");
        printf("2. Pop the element\n");        
        printf("3. Peek the element\n");
        printf("4. Display the element\n");
        printf("5. Exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                printf("Enter the value: \n");
                scanf("%d", &val);
                top = push(top, val);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                peek(top);
                break;
            case 4:
                display(top);
                break;
            case 5: 
                printf("Exiting the program...\n");
                return 0;
            default: 
                printf("Error! Invalid Choice.\n");
        }
    }
    
}