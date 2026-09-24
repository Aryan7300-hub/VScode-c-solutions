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
    printf("\n");
    return dummy.next;
}
void printLLR(struct Node* head){
    if(!head) return;
    printf("%d ", head->val);
    printLLR(head->next);
}
void deleteNode(struct Node** head, int pos, int n ){
    if(pos<1 || pos>n){
        printf("Invalid Position\n");
        return;
    }
    if(!head)
        return;
    if(pos == 1){
        struct Node* p = *head;
        *head = (*head)->next;
        free(p);
        return;
    }
    struct Node* temp = *head;

    for(int i = 1; i<pos-1 && temp; i++){
        temp = temp->next;
    }
    if(!temp || !temp->next){
        return;
    }
    struct Node* p = temp->next;
    temp->next = p->next;
    free(p);

}
int main(){
    int n;
    int pos;
    
    printf("Enter the no. of node: ");
    scanf("%d", &n);

    struct Node* head = CreateLL(n);
    printLLR(head);
    printf("\n");
    
    printf("Enter the index of value you want to delete: ");
    scanf("%d", &pos);
    deleteNode(&head, pos, n);
    printLLR(head);
    
    return 0;
}