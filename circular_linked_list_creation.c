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
    t->next=head;
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
