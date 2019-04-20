/*include here*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
/*define here*/
using namespace std;

/*function&class*/
struct node{
    int data;
    struct node *next;
};
struct node *head,*p=(struct node *)malloc(sizeof(struct node)),*q=(struct node *)malloc(sizeof(struct node));


//entry
int main() {
    p->data=10;
    head=p;
    q->data=20;
    q->next=NULL;
    p->next=q;
    return 0;
}
/*
created by a_little_rubbish
have a nice day : )
*/
