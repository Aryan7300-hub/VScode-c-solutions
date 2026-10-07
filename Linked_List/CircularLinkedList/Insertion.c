#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    struct Node* next;
};

struct Node* create(int n){
    struct Node* head = NULL;
    struct Node* temp = NULL;

    for(int i = 0; i < n; i++){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the val: ");
        scanf("%d", &newNode->val);
        if(!head){
            head = newNode;
        }else{
            temp->next = newNode;
        }
        temp = newNode;
    }
    temp->next = head;

    return head;
}
void printLL(struct Node* head, struct Node* start){
    if(head->next == start)
        return;
    
    printf("%d ", head->val);
    printLL(head->next, start);
}
int main(){
    int n;

    printf("Enter No. of Nodes: ");
    scanf("%d", &n);
    printf("\n");
    
    struct Node* head = create(n);
    printf("\nOriginal List: ");
    printLL(head, head);
    printf("\n");

    return 0;
}