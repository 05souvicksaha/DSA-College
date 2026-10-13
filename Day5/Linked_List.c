#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int main(){
    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = 10;
    newNode -> next = NULL;
    head = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = 20;
    newNode -> next = NULL;
    head->next = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = 30;
    newNode -> next = NULL;
    head->next->next = newNode;

    for(temp = head; temp != NULL; temp = temp->next){
        printf("%d -> ", temp->data);
    }
    printf("NULL\n");
    return 0;
}