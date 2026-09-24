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
void reverseLL(struct Node** head){
    struct Node* curr = *head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
int main(){
    int n;
    
    printf("Enter size: ");
    scanf("%d", &n);

    struct Node* head = CreateLL(n);

    printf("Original Linked List: ");
    printLLR(head);
    printf("\n");
    

    reverseLL(&head);
    printf("Reverse Linked List: ");
    printLLR(head);

    return 0;
}