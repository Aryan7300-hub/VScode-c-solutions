#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node* next;
};
struct node* top = NULL;
int isempty(){
    if(top)
        return 0;
    else
        return 1;
}
void push(int val){
    struct node* newNode = malloc(sizeof(struct node*));
    newNode->val = val;
    newNode->next = NULL;

    if(isempty()){
        top = newNode;
        return;
    }

    newNode->next = top;
    top = newNode;
}
int pop(){
    if(isempty()){
        return -1;
    }
    struct node* del = top;
    top = top->next;
    int val = del->val;

    free(del);

    return val;
}
void print(){
    struct node* temp = top;
    printf("The stack elements: ");
    while(temp){
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    int data, choice;
    while(1){
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
        printf("4. Quit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
            case 1:{
                printf("Enter the Element to push: ");
                scanf("%d", &data);
                push(data);
                break;
            }
            case 2:{
                int val = pop();
                printf("Deleted Element is %d", val);
                break;
            }
            case 3:{
                print();
                break;
            }
            case 4:{
                return 0;
            }
            default :
                printf("Invalid Choice\n");
        }
    }

    return 0;
}