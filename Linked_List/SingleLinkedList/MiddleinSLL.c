#include<stdio.h>
#include<stdlib.h>
struct Node{
    int val;
    struct Node* next;
};
struct Node* Create(int n){
    if(n == 0)
        return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &newNode->val);
    newNode->next = Create(n-1);

    return newNode;

}
void printLL(struct Node* head){
    if(!head)
        return;
    printf("%d ", head->val);

    printLL(head->next);
}
int middleNode(struct Node* head){
    if(!head)
        return -1;
    struct Node* slow = head;
    struct Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->val;
}
int main(){
    int n;
    printf("Enter the Number of Nodes: ");
    scanf("%d", &n);

    struct Node* head = Create(n);
    printf("\n");
    printLL(head);
    printf("\n\n");

    int middle = middleNode(head);

    printf("Value of Middle Node: %d\n", middle);
    return 0;
}