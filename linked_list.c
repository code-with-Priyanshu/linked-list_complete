#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void traverse(struct node *head){
    struct node *cur;
    cur=head;
    while(cur!=NULL){
        printf("%d ",cur->data);
        cur=cur->next;
    }
    printf("\n");
}

void insertion(struct node *head,int pos,int ins){
    struct node *new;
    struct node *prev;
    new=malloc(sizeof(struct node *));
    new->data=ins;
    prev=head;
    if(pos==0){
        new->next=head;
        head=new;
    }
    for(int i=0;i<(pos-1);i++){
        prev=prev->next;
    }
    new->next=prev->next;
    prev->next=new;
    
    printf("After insertion\n");
    traverse(head);

}

void deletion(struct node *head,int pos){
    struct node *prev;
    prev=head;
    if(pos==0){
        head=head->next;
    }
    for(int i=0;i<pos-1;i++){
        prev=prev->next;
    }
    prev->next=prev->next->next;
    printf("List after deletion\n");
    traverse(head);

}


void main(){
    struct node *prev,*head,*p;
    int n,i;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    head=NULL;
    for(i=0;i<n;i++){
        p=malloc(sizeof(struct node *));
        printf("Enter the node data");
        scanf("%d",&p->data);
        p->next=NULL;
        if(head==NULL){
            head=p;
        }
        else{
            prev->next=p;
        }
        prev=p;

    }
    printf("Original list\n");
    traverse(head);
    //insertion(head,2,90);
    deletion(head,2);


}