#include<stdio.h>
#include<stdlib.h>
struct Node{
    int val;
    struct Node* next;
};
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
void push_front(struct Node** head, int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    if(!*head){
        *head = newNode;
        return;
    }
    
    newNode->next = *head;
    *head = newNode;
}
void push_back(struct Node** head, int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    if(!*head){
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertion(struct Node** head, int pos, int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;

    if(!*head || pos<1){
        *head = newNode;
        return;
    }
    if(pos == 1){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    for(int i = 1; i<pos-1 && temp; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Invalid pos\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

int main(){
    int n;
    struct Node* head;
    int k, pos;

    printf("Enter the size: ");
    scanf("%d", &n);
    
    head = CreateLL(n);
    printf("Value: ");
    printLLR(head);
    printf("\n");

    // printf("Enter the val to push front int Linked List Node: ");
    // scanf("%d", &k);
    // push_front(&head, k);
    // printLLR(head);

    // printf("Enter the val to push back int Linked List Node: ");
    // scanf("%d", &k);
    // push_back(&head, k);
    // printLLR(head);

    printf("Enter the pos and val: ");
    scanf("%d%d", &pos, &k);
    insertion(&head, pos, k);
    printLLR(head);

    return 0;
}
//g++ InsertioninSLL.c -o InsertioninSLL.exe
//./InsertioninSLL.exe