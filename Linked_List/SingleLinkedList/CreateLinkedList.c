#include<stdio.h>
#include<stdlib.h>
struct Node{
    int val;
    struct Node* next;
};
struct Node* Create(int n){
    
    struct Node* head = NULL;
    struct Node* temp = NULL;
    for(int i = 0; i<n; i++){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if(newNode == NULL) return NULL;

        newNode->next = NULL;

        printf("Enter the value: ");
        scanf("%d", &newNode->val);
        
        if(head == NULL){
            head = newNode;
            temp = newNode;
        }else{
        temp->next = newNode;
        temp = newNode;
        }
    }
    temp->next = NULL;
    return head;
}
struct Node* CreateLL(int n){
    struct Node dummy = {-1, NULL};
    struct Node* p = &dummy;
    for(int i = 0; i<n; i++){
        p->next = (struct Node*)malloc(sizeof(struct Node));
        p = p->next;
        printf("Enter Value: ");
        scanf("%d", &p->val);
        p->next = NULL;
    }
    return dummy.next;
}
void printLLR(struct Node* head){
    if(!head) return;
    printf("%d ", head->val);
    printLLR(head->next);
}
void printLL(struct Node* head){
    printf("Value: ");
    while(head){
        printf("%d", head->val);
        head = head->next;
    }
    printf("\n");
}
int main(){
    int n;
    struct Node* head;

    printf("Enter the size: ");
    scanf("%d", &n);
    
    head = CreateLL(n);
    printf("Value: ");
    printLLR(head);

    return 0;
}
//g++ CreateLinkedList.c -o CreateLinkedList.exe
//./CreateLinkedList.exe