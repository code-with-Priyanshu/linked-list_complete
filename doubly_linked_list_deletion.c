#include<stdio.h>
#include<stdlib.h>

struct dlist{
    int data;
    struct dlist *next,*prev;
};
struct dlist *head=NULL,*p;
void create(){
    struct dlist *t;
    int ch=1,m;
    while(ch==1){
        printf("Enter data\n");
        scanf("%d",&m);
        p=(struct dlist *)malloc(sizeof(struct dlist));
        p->data=m;
        if(head==NULL){
            head=p;
            p->next=NULL;
            p->prev=NULL;
            t=p;
        }
        else{
            t->next=p;
            p->next=NULL;
            p->prev=t;
            t=p;
        }
        printf("Enter the choice 1/0");
        scanf("%d",&ch);
    }  
}  
void display()  {
    struct dlist *i,*j;
    i=head;
    j=p;
    printf("List in forward direction\n");
    while(i!=NULL){
        printf("%d is the data\t %x is the address\n",i->data,i);
        i=i->next;
    }
    printf("\n");
    printf("List in backward direction\n");
    while(j!=NULL){
        printf("%d is the data\t %x is the address\n",j->data,j);
        j=j->prev;
    }
}

void deleteAtBeginning(){
    
    head=head->next;
    head->prev=NULL;
}
void deleteAtEnd(){
    p=p->prev;
    p->next=NULL;
}
void deleteAtPosi(){
    struct dlist *previous;
    int pos,i;
    previous=head;
    printf("Enter the  position\n");
    scanf("%d",&pos);
    for(i=0;i<pos-1;i++){
        previous=previous->next;

    }
    previous->next=previous->next->next;
    previous->next->prev=previous;
}




void main(){
    int ch;
    create();
    display();
    printf("1->delete at beginning 2->delete at middle 3->delete at end\n");
    scanf("%d",&ch);
    switch(ch){
        case 1: deleteAtBeginning();
                break;
        case 2: deleteAtPosi();
                break;
        case 3: deleteAtEnd();
                break;

    }
    printf("List after deletion\n");
    display();

}