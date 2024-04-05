#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void printmenu() {
    printf("\nMenu:\n");
    printf("1. Insert at first\n");
    printf("2. Insert at nth position\n");
    printf("3. Insert at last\n");
    printf("4. Delete at first\n");
    printf("5. Delete at nth position\n");
    printf("6. Delete at last\n");
    printf("7. Display\n");
    printf("8. Exist\n");
    printf("Enter your choice: ");
}

void create() {
    int choice = 1;
    struct node *newnode, *temp;
    
    while(choice) {
        printf("Enter data: ");
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        
        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        
        printf("Do you want to continue? (1 for continue, 0 to exit): ");
        scanf("%d", &choice);
    }
}

void display() {
    struct node *temp = head;
    
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertatbegin(){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data that you want to show in begins : ");
    scanf("%d", &newnode->data);
    newnode->next = head; // Linking new node to the current head
    head = newnode; // Making the new node as the head
}
void insertAtPosition(int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data for the new node: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (position == 1) { // Special case: insert at the beginning
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;
    int count = 1;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    } 

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void insertAtEnd() {
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data for the new node: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) { // If the list is empty, make the new node as head
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
}
void deleteFirstNode() {
    if (head == NULL) {
        printf("List is already empty. Nothing to delete.\n");
        return;
    }

    struct node *temp = head;
    head = head->next; // Update head to point to the second node (or NULL if list has only one node)
    free(temp); // Free memory of the first node
}
void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;
    int count = 1;

    // Traverse the list to find the (n-1)th node
    while (temp != NULL && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    // If the node to be deleted is the head node
    if (prev == NULL) {
        head = temp->next;
    } else {
        // Link the previous node to the next node, skipping the current node
        prev->next = temp->next;
    }

    // Free memory of the node to be deleted
    free(temp);
}
void deleteAtLast() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    // Traverse the list until the last node
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // If there is only one node in the list
    if (prev == NULL) {
        free(head);
        head = NULL;
    } else {
        // Update the second-to-last node's next pointer to NULL
        prev->next = NULL;
        free(temp); // Free memory of the last node
    }
}


int main() {
    int ch;
    create();
    do {
        
        printmenu();
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Insert at first\n");
                insertatbegin();
                break;
            case 2:
                printf("Insert at nth position\n");
                insertAtPosition(2);
                break;
            case 3:
                printf("Insert at last\n");
                insertAtEnd();
                break;
            case 4:
                printf("Delete at first\n");
                deleteFirstNode();
                break;
            case 5:
                printf("Delete at nth position\n");
                deleteAtPosition(2);
                break;
            case 6:
                printf("Delete at last\n");
                deleteAtLast();
                break;
            case 7:
                printf("Displaying .......... \n");
                display();
                break;
            case 8:
                printf("you are out of loop bye!");
                break;
               
            default:
                printf("Invalid choice, please try again\n");
        }
    } while (ch !=8);
    return 0;
}
