#include<stdio.h>

#define n 5
int stack_arr[n];
int top = -1;

int isFull(){
    if(top == n-1)
        return 1;
    else
        return 0;
}
int isEmpty(){
    if(top == -1)
        return 1;
    else
        return 0;
}
void push(int val){
    if(isFull()){
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack_arr[top] = val;
    
}
int pop(){
    if(isEmpty()){
        printf("Stack underflow\n");
        return -1;
    }

    int val = stack_arr[top];
    top--;
    
    return val;
}
void print(){
    if(top == -1){
        printf("Stack underflow\n");
        return;
    }

    for(int i = top; i>=0; i--){
        printf("%d ", stack_arr[i]);
    }
    printf("\n");
}

int up(){
    if(top == -1){
       printf("Stack underflow\n");
       return -1;
    }

    return stack_arr[top];
}
int main(){
    int val;
    int choice;
    while(1){
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top element\n");
        printf("4. Print all the elements\n");
        printf("5. Quit\n\n");

        printf("Please enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
            case 1 : {
                printf("Enter the element to be pushed: ");
                scanf("%d", &val);
                push(val);
                break;
            }
            case 2: {
                printf("Deleted element is %d", pop());
                break;
            }
            case 3 : {
                printf("The topmost element of the stack is %d\n", up());
                break;
            }
            case 4 : {
                print();
                break;
            }
            case 5 : {
                return -1;
            }
            default :{
                printf("Invalid Choice");

                
            }
        }
    }

    return 0;
}