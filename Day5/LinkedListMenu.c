#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *start;
};

struct Node *head = NULL;

void insertSorted(int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->start = NULL;


    if (head == NULL || value < head->data) {
        newNode->start = head;
        head = newNode;
        return;
    }


    temp = head;

    while (temp->start != NULL && temp->start->data < value) {
        temp = temp->start;
    }

    newNode->start = temp->start;
    temp->start = newNode;
}


void deleteBeginning() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    head = head->start;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void deleteEnd() {
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->start == NULL) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->start != NULL) {
        prev = temp;
        temp = temp->start;
    }

    prev->start = NULL;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Sorted List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->start;
    }

    printf("NULL\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n----- SORTED LINKED LIST -----\n");
        printf("1. Insert\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);

                insertSorted(value);
                printf("Element inserted successfully.\n");
                break;

            case 2:
                deleteBeginning();
                break;

            case 3:
                deleteEnd();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
