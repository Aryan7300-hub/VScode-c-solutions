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
void push_front(struct Node** head, int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->prev = NULL;

    if(!*head){
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}
void push_back(struct Node** head, int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;

    if(!*head){
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while(temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}
void insertion(struct Node** head, int n, int pos, int val){
    if(pos<=0 || pos>n+1){
        printf("Invalid");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    if(pos == 1){
        push_front(head, val);
    }
    if(!head){
        printf("Invalid");
        return;
    }
    struct Node* temp = *head;
    for(int i =1; i<pos-1 && temp; i++)
        temp = temp->next;
    
    if(!temp)
        return;
    
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;

}
int main(){
    int n;
    int val;
    int pos;

    printf("Enter the Number of Node: ");
    scanf("%d", &n);

    struct Node* head = create(n);

    printf("\nOriginal Linked List: ");
    printLL(head);
    

    //printf("\nEnter the to Insert: ");
    //scanf("%d", &val);

    // push_front(&head, val);
    // printf("After Insertion: ");
    // printLL(head);

    //push_back(&head, val);
    //printf("After Insertion: ");
    // printLL(head);

    printf("\nEnter the pos and val to insert: ");
    scanf("%d%d", &pos, &val);
    insertion(&head, n, pos, val);
    printf("After Insertion: ");
    printLL(head);



    return 0;
}