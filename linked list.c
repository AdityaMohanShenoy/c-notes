#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
}NODE;

NODE *insertfront(NODE *head,int ele);
void Display(NODE *head);
NODE *Deletefront(NODE *head,int *pele);
NODE *freeList(NODE *head);

int main()
{
   NODE *head = NULL;
   int ele;
   int opt;
   int *pele;
   printf("1:inertfornt 2: deleteFront 3:diplay 4:free list  ") ;
   scanf("%d",&opt);
do
{

   switch (opt)
   {
   case 1:
        printf("\nthe element you want to store : ");
        scanf("%d",&ele);
       head = insertfront(head,ele);

        break;
   
    case 2:
        head = Deletefront(head,pele);
        break;
    case 3:
        if(head!=NULL){
            void Display(NODE *head);
        }
        else
        {
            printf("THE LIST IS EMPTY");
        }
        break;
    case 4:        
        if(head!=NULL){
           head = freeList(head);
        }
        else
        {
            printf("THE LIST IS EMPTY");
        }
        break;


   } 
}while(opt<4);
}

NODE *createnewnode(NODE*head,int ele)
{
    NODE *newnode=malloc(sizeof(NODE));
    newnode->next=NULL;
    newnode->info=ele;
    return newnode;
}

NODE *insertfront(NODE *head,int ele)
{
    NODE *newnode = createnewnode(head,ele);
    newnode->next = head;
    head = newnode;
    return head;
}

NODE *Deletefront(NODE *head,int *pele)
{
    NODE *p = head;
    *pele=head->info;
    head = head->next;
    printf("the element freed is %d",pele);
    free(p);
}

void Display(NODE *head)
{
    NODE *p=head;
    while (p!=NULL)
    {
        printf("%d",p->info);
        p=p->next;
        }
    
}

NODE *freelist(NODE *head)
{
    NODE *p=head;
    while(head!=NULL)
    {
        printf("the nummber : %d",head->info);
        head =head->next;
        free(p);
        p=head;
    }
    return (head);
}

