#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void printmenu() {
    printf("\nMenu:\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at nth position\n");
    printf("3. Insert at end\n");
    printf("4. Delete at beginning\n");
    printf("5. Delete at nth position\n");
    printf("6. Delete at end\n");
    printf("7. Display\n");
    printf("8. Exit\n");
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
            head->next = head; // Pointing to itself for circularity
            temp = newnode;
        } else {
            temp->next = newnode;
            newnode->next = head; // Pointing back to head to form circular list
            temp = newnode;
        }
        
        printf("Do you want to continue? (1 for continue, 0 to exit): ");
        scanf("%d", &choice);
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void insertAtBeginning() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data to insert at the beginning: ");
    scanf("%d", &newnode->data);
    
    if (head == NULL) {
        head = newnode;
        head->next = head; // Pointing to itself for circularity
    } else {
        struct node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }
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

    if (position == 1) {
        if (head == NULL) {
            head = newnode;
            head->next = head; // Pointing to itself for circularity
        } else {
            struct node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
            head = newnode;
        }
        return;
    }

    temp = head;
    int count = 1;
    while (temp->next != head && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp->next == head && count < position - 1) {
        printf("Position out of range!\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void insertAtEnd() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data for the new node: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        head->next = head; // Pointing to itself for circularity
        return;
    }

    struct node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node *temp = head;
    if (temp->next == head) { // Only one node in the list
        head = NULL;
    } else {
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
    }
    free(temp);
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

    do {
        prev = temp;
        temp = temp->next;
        count++;
    } while (temp != head && count < position);

    if (temp == head && count < position) {
        printf("Position out of range.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    if (temp->next == head) { // Only one node in the list
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
}

int main() {
    int ch;
    create();
    do {
        printmenu();
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Insert at beginning\n");
                insertAtBeginning();
                break;
            case 2:
                printf("Insert at nth position\n");
                insertAtPosition(2);
                break;
            case 3:
                printf("Insert at end\n");
                insertAtEnd();
                break;
            case 4:
                printf("Delete at beginning\n");
                deleteAtBeginning();
                break;
            case 5:
                printf("Delete at nth position\n");
                deleteAtPosition(2); // Change position as needed
                break;
            case 6:
                printf("Delete at end\n");
                deleteAtEnd();
                break;
            case 7:
                printf("Display\n");
                display();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
        }
    } while (ch != 8);
    return 0;
}

          