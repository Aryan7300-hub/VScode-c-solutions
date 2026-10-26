#include <stdio.h>

#define Size 5

int queue[Size];
int top = -1;
int rear = -1;

void push(int val) {
    if ((rear + 1) % Size == top) {
        printf("Queue Overflow\n");
        return;
    }

    if (top == -1) {
        top = rear = 0;
    } else {
        rear = (rear + 1) % Size;
    }

    queue[rear] = val;
}

int pop() {
    if (top == -1) {
        printf("Queue Underflow\n");
        return -1;
    }

    int del = queue[top];

    if (top == rear) {
        top = rear = -1;
    } else {
        top = (top + 1) % Size;
    }

    return del;
}

void display() {
    if (top == -1) {
        printf("Empty Queue\n");
        return;
    }

    printf("Queue: ");

    int i = top;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % Size;
    }

    printf("\n");
}

int main() {
    push(54);
    push(45);
    push(50);
    push(455);
    push(60);

    display();

    push(70);

    printf("Delete Value: %d\n", pop());
    printf("Delete Value: %d\n", pop());

    display();

    push(70);
    push(80);

    display();

    return 0;
}