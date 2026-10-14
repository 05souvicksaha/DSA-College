#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void insertbeginning(struct Node **head){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    //Insertion of the element at the Beginning
    printf("Enter the element to insert:\n");
    scanf("%d", &newNode->data);
    newNode -> next = *head;
    *head = newNode;
    printf("%d will be inserted at the front\n", newNode->data);
}
void insertend(struct Node **head, struct Node *temp){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    //Insertion of the element at the End
    printf("Enter the element to insert:\n");
    scanf("%d", &newNode->data);
    newNode->next = *head;
    for(temp = *head; temp -> next != NULL; temp = temp->next){
        
    }
}
int main(){
    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;
    

    //Creating 1st Node
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = 20;
    newNode -> next = NULL;
    head = newNode;

    //Creating 2nd Node
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = 30;
    newNode -> next = NULL;
    head->next = newNode;

    //Creating 3rd Node
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = 40;
    newNode ->next = NULL;
    head->next->next = newNode;

    printf("Display The Current Node: ");
    for(temp = head; temp != NULL;temp = temp->next){
        printf("%d -> ", temp->data);
    }
    printf("NULL\n");

    insertbeginning(&head);
    printf("Array after Insertion: ");
    for(temp = head; temp != NULL;temp = temp->next){
        printf("%d -> ", temp->data);
    }
    printf("NULL\n");

    return 0;
}