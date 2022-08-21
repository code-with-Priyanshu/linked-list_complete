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

void insertAtBeginning(){
    struct dlist *new;
    int n;
    new=(struct dlist *)malloc(sizeof(struct dlist));
    printf("Enter the element to enter\n");
    scanf("%d",&n);
    new->data=n;
    new->next=head;
    head->prev=new;
    new->prev=NULL;
    head=new;
}
void insertAtEnd(){
    struct dlist *new;
    int n;
    new=(struct dlist *)malloc(sizeof(struct dlist));
    printf("Enter the element to enter\n");
    scanf("%d",&n);
    new->data=n;
    p->next=new;
    new->next=NULL;
    new->prev=p;
    p=new;
}
void insertAtPosi(){
    struct dlist *new,*previous;
    int n,pos,i;
    previous=head;
    new=(struct dlist *)malloc(sizeof(struct dlist));
    printf("Enter the element to enter and its position\n");
    scanf("%d%d",&n,&pos);
    new->data=n;
    for(i=0;i<pos-1;i++){
        previous=previous->next;

    }
    new->next=previous->next;
    previous->next=new;
    new->prev=previous;
    new->next->prev=new;

}




void main(){
    int ch;
    create();
    display();
    printf("1->insert at beginning 2->insert at middle 3->insert at end\n");
    scanf("%d",&ch);
    switch(ch){
        case 1: insertAtBeginning();
                break;
        case 2: insertAtPosi();
                break;
        case 3: insertAtEnd();
                break;

    }
    printf("List after insertion\n");
    display();

}