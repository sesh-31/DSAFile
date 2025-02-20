#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
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
    printf("7. Display \n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}

void create() {
    int choice = 1;
    struct node *newnode, *temp;
    
    while (choice) {
        printf("Enter data: ");
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        
        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
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


void insertAtFirst() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data that you want to insert at the beginning: ");
    scanf("%d", &newnode->data);
    
    newnode->next = head;
    newnode->prev = NULL;
    if (head != NULL) {
        head->prev = newnode;
    }
    head = newnode;
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
    newnode->prev = NULL;

    if (position == 1) {
        newnode->next = head;
        if (head != NULL) {
            head->prev = newnode;
        }
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
    newnode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

void insertAtLast() {
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data for the new node: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
}

void deleteFirstNode() {
    if (head == NULL) {
        printf("List is already empty. Nothing to delete.\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
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
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

void deleteAtLast() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
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
                printf("Insert at first\n");
                insertAtFirst();
                break;
            case 2:
                printf("Insert at nth position\n");
                insertAtPosition(2); // Change position as needed
                break;
            case 3:
                printf("Insert at last\n");
                               insertAtLast();
                break;
            case 4:
                printf("Delete at first\n");
                deleteFirstNode();
                break;
            case 5:
                printf("Delete at nth position\n");
                deleteAtPosition(2); // Change position as needed
                break;
            case 6:
                printf("Delete at last\n");
                deleteAtLast();
                break;
            case 7:
                printf("Displaying ...\n");
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

