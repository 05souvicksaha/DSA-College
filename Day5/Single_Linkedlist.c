#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node
{
int data;
struct Node *next;
};

// Function declarations
struct Node* createList(struct Node *head);
void display(struct Node head);
struct Node insertBeginning(struct Node head);
struct Node insertEnd(struct Node head);
struct Node insertBefore(struct Node head);
struct Node insertAfter(struct Node head);
struct Node deleteBeginning(struct Node head);
struct Node deleteEnd(struct Node head);
struct Node deleteGiven(struct Node head);
struct Node deleteAfter(struct Node head);
struct Node deleteEntire(struct Node *head);
void sortList(struct Node *head);

int main()
{
struct Node *head = NULL;
int option;

do
{
printf("\n\n========== MAIN MENU ==========\n");
printf("\n1. Create a list");
printf("\n2. Display the list");
printf("\n3. Add a node at the beginning");
printf("\n4. Add a node at the end");
printf("\n5. Add a node before a given node");
printf("\n6. Add a node after a given node");
printf("\n7. Delete a node from the beginning");
printf("\n8. Delete a node from the end");
printf("\n9. Delete a given node");
printf("\n10. Delete a node after a given node");
printf("\n11. Delete the entire list");
printf("\n12. Sort the list");
printf("\n13. EXIT");

printf("\n\nEnter your option: ");
scanf("%d", &option);

switch(option)
{
case 1:
head = createList(head);
break;

case 2:
display(head);
break;

case 3:
head = insertBeginning(head);
break;

case 4:
head = insertEnd(head);
break;

case 5:
head = insertBefore(head);
break;

case 6:
head = insertAfter(head);
break;

case 7:
head = deleteBeginning(head);
break;

case 8:
head = deleteEnd(head);
break;

case 9:
head = deleteGiven(head);
break;

case 10:
head = deleteAfter(head);
break;

case 11:
head = deleteEntire(head);
break;

case 12:
sortList(head);
break;

case 13:
printf("\nExiting program...");
break;

default:
printf("\nInvalid option!");
}

} while(option != 13);

return 0;
}

// 1. CREATE A LIST
struct Node* createList(struct Node *head)
{
int n, i, value;
struct Node *newNode, *temp;

printf("\nEnter number of nodes: ");
scanf("%d", &n);

// If a list already exists
if(head != NULL)
{
head = deleteEntire(head);
}

for(i = 1; i <= n; i++)
{
newNode = (struct Node*)malloc(sizeof(struct Node));

printf("Enter data for node %d: ", i);
scanf("%d", &value);

newNode->data = value;
newNode->next = NULL;

if(head == NULL)
{
head = newNode;
}
else
{
temp = head;

while(temp->next != NULL)
{
temp = temp->next;
}

temp->next = newNode;
}
}

printf("\nList created successfully.");

return head;
}

// 2. DISPLAY THE LIST
void display(struct Node *head)
{
struct Node *temp;

if(head == NULL)
{
printf("\nList is empty.");
return;
}

temp = head;

printf("\nList: ");

while(temp != NULL)
{
printf("%d -> ", temp->data);
temp = temp->next;
}

printf("NULL");
}

// 3. INSERT AT BEGINNING
struct Node* insertBeginning(struct Node *head)
{
struct Node *newNode;
int value;

newNode = (struct Node*)malloc(sizeof(struct Node));

printf("\nEnter data: ");
scanf("%d", &value);

newNode->data = value;
newNode->next = head;

head = newNode;

printf("\nNode inserted at beginning.");

return head;
}

// 4. INSERT AT END
struct Node* insertEnd(struct Node *head)
{
struct Node *newNode, *temp;
int value;

newNode = (struct Node*)malloc(sizeof(struct Node));

printf("\nEnter data: ");
scanf("%d", &value);

newNode->data = value;
newNode->next = NULL;

if(head == NULL)
{
head = newNode;
}
else
{
temp = head;

while(temp->next != NULL)
{
temp = temp->next;
}

temp->next = newNode;
}

printf("\nNode inserted at end.");

return head;
}

// 5. INSERT BEFORE A GIVEN NODE
struct Node* insertBefore(struct Node *head)
{
struct Node *newNode, *temp, *prev;
int value, key;

if(head == NULL)
{
printf("\nList is empty.");
return head;
}

printf("\nEnter the value before which to insert: ");
scanf("%d", &key);

printf("Enter new node data: ");
scanf("%d", &value);

newNode = (struct Node*)malloc(sizeof(struct Node));

newNode->data = value;

// If inserting before first node
if(head->data == key)
{
newNode->next = head;
head = newNode;

printf("\nNode inserted successfully.");

return head;
}

temp = head;
prev = NULL;

while(temp != NULL && temp->data != key)
{
prev = temp;
temp = temp->next;
}

if(temp == NULL)
{
printf("\nGiven node not found.");
free(newNode);
return head;
}

newNode->next = temp;
prev->next = newNode;

printf("\nNode inserted successfully.");

return head;
}

// 6. INSERT AFTER A GIVEN NODE
struct Node* insertAfter(struct Node *head)
{
struct Node *newNode, *temp;
int value, key;

if(head == NULL)
{
printf("\nList is empty.");
return head;
}

printf("\nEnter the value after which to insert: ");
scanf("%d", &key);

temp = head;

while(temp != NULL && temp->data != key)
{
temp = temp->next;
}

if(temp == NULL)
{
printf("\nGiven node not found.");
return head;
}

printf("Enter new node data: ");
scanf("%d", &value);

newNode = (struct Node*)malloc(sizeof(struct Node));

newNode->data = value;
newNode->next = temp->next;
temp->next = newNode;

printf("\nNode inserted successfully.");

return head;
}

// 7. DELETE FROM BEGINNING
struct Node* deleteBeginning(struct Node *head)
{
struct Node *temp;

if(head == NULL)
{
printf("\nList is empty.");
return head;
}

temp = head;
head = head->next;

free(temp);

printf("\nFirst node deleted.");

return head;
}

// 8. DELETE FROM END
struct Node* deleteEnd(struct Node *head)
{
struct Node *temp, *prev;

if(head == NULL)
{
printf("\nList is empty.");
return head;
}

// If only one node exists
if(head->next == NULL)
{
free(head);
head = NULL;

printf("\nLast node deleted.");

return head;
}

temp = head;
prev = NULL;

while(temp->next != NULL)
{
prev = temp;
temp = temp->next;
}

prev->next = NULL;
free(temp);

printf("\nLast node deleted.");

return head;
}

// 9. DELETE A GIVEN NODE
struct Node* deleteGiven(struct Node *head)
{
struct Node *temp, *prev;
int key;

if(head == NULL)
{
printf("\nList is empty.");
return head;
}

printf("\nEnter the value to delete: ");
scanf("%d", &key);

// If first node contains the value
if(head->data == key)
{
temp = head;
head = head->next;
free(temp);

printf("\nNode deleted successfully.");

return head;
}

temp = head;
prev = NULL;

while(temp != NULL && temp->data != key)
{
prev = temp;
temp = temp->next;
}

if(temp == NULL)
{
printf("\nGiven node not found.");
return head;
}

prev->next = temp->next;
free(temp);

printf("\nNode deleted successfully.");

return head;
}

// 10. DELETE NODE AFTER A GIVEN NODE
struct Node* deleteAfter(struct Node *head)
{
struct Node *temp, *deleteNode;
int key;

if(head == NULL)
{
printf("\nList is empty.");
return head;
}

printf("\nEnter the value after which node should be deleted: ");
scanf("%d", &key);

temp = head;

while(temp != NULL && temp->data != key)
{
temp = temp->next;
}

if(temp == NULL)
{
printf("\nGiven node not found.");
return head;
}

if(temp->next == NULL)
{
printf("\nThere is no node after the given node.");
return head;
}

deleteNode = temp->next;
temp->next = deleteNode->next;

free(deleteNode);

printf("\nNode deleted successfully.");

return head;
}

// 11. DELETE ENTIRE LIST
struct Node* deleteEntire(struct Node *head)
{
struct Node *temp;

while(head != NULL)
{
temp = head;
head = head->next;

free(temp);
}

printf("\nEntire list deleted.");

return NULL;
}

// 12. SORT THE LIST
void sortList(struct Node *head)
{
struct Node *i, *j;
int temp;

if(head == NULL)
{
printf("\nList is empty.");
return;
}

for(i = head; i->next != NULL; i = i->next)
{
for(j = i->next; j != NULL; j = j->next)
{
if(i->data > j->data)
{
temp = i->data;
i->data = j->data;
j->data = temp;
}
}
}

printf("\nList sorted successfully.");

display(head);
}