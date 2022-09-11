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


void deleteAtBeginning(){
    
    struct dlist *t;
    t=head;
    head=head->next;
    p->next=head;
    free(t);
}
void deleteAtEnd(){
    struct dlist *c,*previous;
    c=head;
    previous=head;
    while(c->next!=p){
        previous=previous->next;
        c=c->next;
    }
    previous->next=head;
    p=previous;
    


}
void deleteAtPosi(){
    struct dlist *previous;
    int pos;
    previous=head;
    printf("Enter the  position\n");
    scanf("%d",&pos);
    for(int i=0;i<pos-1;i++){
        previous=previous->next;

    }
    previous->next=previous->next->next;

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