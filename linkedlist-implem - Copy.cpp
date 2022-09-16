#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};//user defined data type Node


int main(){
     struct Node* node1=(struct Node*)malloc(sizeof(struct Node));//dynamic memory allocates
     struct Node* node2=(struct Node*)malloc(sizeof(struct Node));
     struct Node* node3=(struct Node*)malloc(sizeof(struct Node));
     node1->data=4;
     node2->data=5;
     node3->data=6;
     
     node1->next=node2;
     node2->next=node3;
     
     printf("%d \n",node2->data);//just to test is linkelist is ready..
     
     //length of linkelist;
     
     int length=0;
     
     struct Node* t=node1;
     while(t!=0){
         t=t->next;
         ++length;
     }
     
     //we have generally given head in question
     
     
     printf("%d \n",length);
     
}