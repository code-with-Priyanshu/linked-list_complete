#include<stdio.h>
#include<stdlib.h>

struct dlist{
    int data;
    struct dlist *next;
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
            t=p;
        }
        else{
            t->next=p;
            p->next=NULL;
            t=p;
        }

        printf("Enter the choice 1/0");
        scanf("%d",&ch);
    }  
    p->next=head;
}  
void display()  {
    struct dlist *i;
    i=head;
    printf("List in forward direction\n");
    do{
        printf("%d is the data\n",i->data);
        i=i->next;
    }while(i!=p);
    printf("%d is the data\n",i->data);
    printf("\n");
}


void insertAtBeginning(){
    struct dlist *new;
    int n;
    new=(struct dlist *)malloc(sizeof(struct dlist));
    printf("Enter the element\n");
    scanf("%d",&n);
    new->data=n;
    new->next=head;
    head=new;
    p->next=head;
}
void insertAtEnd(){
    struct dlist *new;
    new=(struct dlist *)malloc(sizeof(struct dlist));
    printf("Enter the element\n");
    scanf("%d",&new->data);
    new->next=p->next;
    p->next=new;
    p=new;

}
void insertAtPosi(){
    struct dlist *new,*previous;
    int pos;
    new=(struct dlist *)malloc(sizeof(struct dlist));
    previous=head;
    printf("Enter the element and position\n");
    scanf("%d%d",&new->data,&pos);
    for(int i=0;i<pos-1;i++){
        previous=previous->next;

    }
    new->next=previous->next;
    previous->next=new;

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