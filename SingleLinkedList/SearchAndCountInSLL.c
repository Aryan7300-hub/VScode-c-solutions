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
int CountAndSearch(struct Node* head, int val, int* count){
    struct Node* temp = head;
    int i = 1;

    while(temp){
        (*count)++;
        temp = temp->next;
    }
    temp = head;
    
    while(temp){
        if(temp->val == val)
            return i;
        i++;
        temp = temp->next;
    }

    return -1;
}
int main(){
    int n, count = 0;
    int val;


    printf("Enter the No. of Nodes: ");
    scanf("%d", &n);
    struct Node* head = Create(n);
    printf("\n");
    printLL(head);
    printf("\n\n");

    printf("Enter the value you want to Search: ");
    scanf("%d", &val);
    int idx = CountAndSearch(head, val, &count);

    printf("Number of Nodes: %d\n", count);
    printf("Index of search val: %d\n", idx);

    return 0;
}