#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* prev;
    int val;
    struct Node* next;
};

struct Node* create(int n){
   struct Node dummy = {NULL, -1, NULL};
   struct Node* p = &dummy;
   
   for(int i = 0; i < n; i++){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the val: ");
        scanf("%d", &newNode->val);
    
        newNode->prev = p;
        newNode->next = NULL;

        p->next = newNode;
        p = newNode;
   }

   return dummy.next;
}
void printLL(struct Node* head){
    if(!head)
        return;
    printf("%d ", head->val);

    printLL(head->next);
}
void pop_front(struct Node** head){
    if(!*head)
        return ;
    
    struct Node* del = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;

    free(del);
}
void pop_back(struct Node** head){
    if(!head)
        return;
    
    struct Node* temp = *head;

    while(temp->next)
        temp = temp->next;
    
    struct Node* del = temp;
    temp = temp->prev;
    temp->next = NULL;

    free(del);
}
void deletion(struct Node** head, int n, int pos){
    if(pos<=0 || pos>n || !head){
        printf("Invalid");
        return;
    }
    if(pos == 1)
        pop_front(head);
    
    struct Node* temp = *head;

    for(int i = 1; i<pos-1 && temp ; i++)
        temp = temp->next;
    
    if(!temp || !temp->next)
        return;
    
    struct Node* del = temp->next;
    if(del->next)
        del->next->prev = temp;
        
    temp->next = del->next;

    free(del);
}
int main(){
    int n;
    int pos;

    printf("Enter the number of Nodes: ");
    scanf("%d", &n);
    printf("\n");
    struct Node* head = create(n);
    printf("\nOriginal List: ");
    printLL(head);
    printf("\n");

    // pop_front(&head);
    // printf("After del Node from front: ");
    // printLL(head);
    // printf("\n");

    // pop_back(&head);
    // printf("After del  Node from last: ");
    // printLL(head);
    // printf("\n");

    printf("Enter the pos to del: ");
    scanf("%d", &pos);

    deletion(&head, n, pos);
    printf("After del Node: ", pos);
    printLL(head);

    return 0;
}