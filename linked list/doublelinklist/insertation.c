#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void createDLL() {
    int choice = 1; // Initialize choice to enter the loop at least once
    while (choice == 1) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        printf("Do you want to continue? Press 1 for yes and 0 for no: ");
        scanf("%d", &choice);
    }
}

void display() {
    struct node *temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertatbegin(){
     struct node *newnode;
     newnode=(struct node*)malloc(sizeof(struct node));
     printf("Enter data that you want to show in begins : ");
     scanf("%d",&newnode->data);
     newnode->prev=0;
     newnode->next=0;
     head->prev=newnode;
     newnode->next=head;
     head=newnode;

}
void inseratend(){
    
}


int main() {
    createDLL();
    insertatbegin();
    display();
    return 0;
}
