#include<stdio.h>
#define Size 5
int queue[Size];
int top = -1;
int rear = -1;
void push(int val){
    if(rear == -1){
        top = rear = 0;
        queue[rear] = val;
        return;
    }
    
    if(rear == Size-1){
        printf("Queue Overflow");
        return;
    }
    rear++;
    queue[rear] = val;
}
int pop(){
    if(top == -1 || top > rear){
        printf("Queue Underflow");
        return -1;
    }
    int del = queue[top];
    top++;

    return del;
}
void display(){
    int t = top;
    if(t == -1){
        printf("Empty Queue");
        return;
    }
    printf("Queue: ");

    while(t<=rear){
        printf("%d ", queue[t]);
        t++;
    }
    printf("\n");
}
int main(){
    push(54);
    push(45);
    push(50);
    display();
    push(455);

    display();

    printf("Delete Value: %d\n", pop());
    printf("Delete Value: %d\n", pop());

    display();

    return 0;
}