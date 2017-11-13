#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct poly
{
    int coeff;
    int exp;
    struct poly *next;
}*head1=NULL,*head2=NULL,*head3=NULL,*head4=NULL,*temp,*ptr;

void main()
{
    int ch,coefficient,exponent;
    int listno;
    while(1)
    {
        clrscr();
        printf("\n1. Create First Polynomial.");
        printf("\n2. Create Second Polynomial.");
        printf("\n3. Display");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("first polynomial:");
                printf("coefficient?");
                scanf("%d",&coefficient);
                printf("Enter exponent?");
                scanf("%d",&exponent);
                makenode(coefficient,exponent);
                head1 = insertend(head1);
                break;
            case 2:
                printf("Second polynomial:");
                printf("coefficient?");
                scanf("%d",&coefficient);
                printf("Enter exponent?");
                scanf("%d",&exponent);
                makenode(coefficient,exponent);
                head1 = insertend(head1);
                break;
            case 3:
                display(head2);
                break;
        }
    }
}

void create()
{
    ptr=(struct poly *)malloc(sizeof(struct poly));
    if(ptr==NULL)
    {
        printf(“Memory Allocation Error!”);
        exit(1);
    }
}

void makenode(int c,int e)
{
    create();
    ptr->coeff = c;
    ptr->exp = e;
    ptr->next = NULL;
}

struct poly *insertend(struct poly *head)
{
    if(head==NULL)
        head = ptr;
    else
    {
        temp=head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
    return head;
}

void display(struct poly *head)
{
    if(head==NULL)
        printf(“List is empty!”);
    else
    {
        temp=head;
    while(temp!=NULL)
    {
        printf(“(%d,%d)->”,temp->coeff,temp->exp);
        temp=temp->next;
    }
    printf(“bb “);
}
