#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
       int data;
       struct node* left;
       struct node* right;
       bool isThreaded;
};

struct node* newNode(int val) {
       struct node* new=(struct node*)malloc(sizeof(struct node));
       new->data=val;
       new->left=NULL;
       new->right=NULL;
       new->isThreaded=false;
       return new;
}
struct node* insert(struct node* root,int val) {
       if(root==NULL)
                     return newNode(val);
       else {
            if(root->data>=val)
                               root->left=insert(root->left,val);
            else
                               root->right=insert(root->right,val);
       }
       return root;
}
void enQ(struct node** queue,struct node* node,int *rear) {
     queue[(*rear)++]=node;
}
struct node* deQ(struct node** queue,int *front) {
     return queue[(*front)++];
}
int sizeofQ(int *front,int* rear) {
    return (*rear-*front);
}
void displayQueue(struct node** queue,int *front,int *rear) {
     int i;
     for(i=*front;i<*rear;i++)
                              printf("%d->",queue[i]->data);
                         
}
struct node* leftMost(struct node* root) {
       while(root!=NULL && root->left!=NULL)
                        root=root->left;
       return root;
}
void createThreaded(struct node* root,struct node** queue,int* front, int* rear) {
     if(root==NULL)
                   return;
     else {
          int i=*front;
          int size=sizeofQ(front,rear);
          struct node* temp;
          while(i<*rear) {
              temp=deQ(queue,front);
              if(!temp->right && i<size) {
                              temp->isThreaded=true;
                              temp->right=queue[i+1];
              }
              i++;
          }
          //displaying the tree in threaded fashion
          printf("\n the threaded traversal is");
          temp=leftMost(root);
          while(temp!=NULL) {
                            printf("%d->",temp->data);
                            if(temp->isThreaded)
                                                temp=temp->right;
                            else
                                                temp=leftMost(temp->right);
          }
     }
}
void printInorder(struct node* root,struct node** queue,int *front,int* rear) {
     if(root==NULL)
                   return;
     else {
          printInorder(root->left,queue,front,rear);
          printf("%d->",root->data);
          enQ(queue,root,rear);
          printInorder(root->right,queue,front,rear);
     }
}
int main() {
    struct node* root=NULL;
    root=insert(root,4);
    root=insert(root,2);
    root=insert(root,6);
    struct node** queue=(struct node**)malloc(sizeof(struct node)*10);
    int front=0,rear=0;
    printInorder(root,queue,&front,&rear);
    printf("\n the contents of queue are \n");
    displayQueue(queue,&front,&rear);
    createThreaded(root,queue,&front,&rear);
    getch();
    return 0;
}
