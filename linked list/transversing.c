#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void print_data(struct node * head){
    if(head==NULL)
    printf("Linked list is empty");
    struct node *ptr=NULL; 
    ptr=head;//ptr=1000;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->link;
    }

}

int main(){
    struct node* head=malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node*current=malloc(sizeof(struct node));
    current->data=98;
    current->link=NULL;
    head->link=current;

    current=malloc(sizeof(struct node));
    current->data=3;
    current->link=NULL;
    head->link->link=current;
    print_data(head);
    return 0;
}