#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct node *head;
void push();
void pop();
void display();

int main()
{
    push();
    push();
    pop();
    push();
    display();
}

void push()
{
    int val;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));   
    if(ptr == NULL){
        printf("Overflow\n");
    }
    else{
        printf("Enter value: ");
        scanf("%d",&val);
        if(head == NULL){
            ptr -> val = val;
            ptr -> next = NULL;
            head = ptr;
        }   
        else{
            ptr->val = val;  
            ptr->next = head;  
            head = ptr;
        }
    }  
}  
  
void pop()
{
    int item;
    struct node *ptr;  
    if (head == NULL){
        printf("Underflow\n");  
    }  
    else{
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
    }
}

void display()
{  
    int i;
    struct node *ptr;
    ptr = head;
    if(ptr == NULL){
        printf("Stack is empty\n");
    }  
    else{
        while(ptr != NULL){
            printf("%d\n",ptr->val);
            ptr = ptr->next;
        }
    }
}