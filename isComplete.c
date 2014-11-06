#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>
struct node{
       int data;
       struct node* left;
       struct node* right;
};
struct node* newNode(int val) {
       struct node* new=(struct node*)malloc(sizeof(struct node));
       new->data=val;
       new->left=NULL;
       new->right=NULL;
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
            return root;
       }       
}
void printInorder(struct node* root) {
     if(root==NULL)
                   return;
     else {
          printInorder(root->left);
          printf("%d->",root->data);
          printInorder(root->right);
     }
}
int minValue(struct node* node) {
     if(node==NULL)
                   return 0;
     else {
          while(node->left!=NULL) {
                                  node=node->left;
          }
          return node->data;
     }
}
int maxValue(struct node* node) {
     if(node==NULL)
                   return 0;
     else {
          while(node->right!=NULL) {
                                  node=node->right;
          }
          return node->data;
     }
}
int size(struct node* root) {
    if(root==NULL)
                  return 0;
    else {
         return (size(root->left)+size(root->right)+1);
    }
}
int depth(struct node* root) {
    if(root==NULL)
                  return 0;
    else {
         int leftd=depth(root->left);
         int rightd=depth(root->right);
         if(leftd>=rightd)
                           return (leftd+1);
         else
                           return (rightd+1);
    }
}
void enQ(struct node** queue,struct node* node,int *rear){
     queue[(*rear)++]=node;
}
struct node* deQ(struct node** queue,int *front) {
            return (queue[(*front)++]);
}
void viewQ(struct node** queue,int *front,int *rear) {
     int i;
     printf("front=%d,rear=%d\n",*front,*rear);
     for(i=*front;i<*rear;i++) {
                                printf("%d->",queue[i]->data);
     }
     printf("\n");
}
int getSize(int *front,int *rear) {
     return *rear-*front;
}
int isComplete(struct node** queue,struct node* root) {
     struct node* temp;
     int front=0,rear=0;
     enQ(queue,root,&rear);
     int currentSize=getSize(&front,&rear);
     int levelExpectedSize=1;
     int missingChild=0;
     int d=depth(root);
     int currentLevel=0;
     while(currentSize>0) {
                       currentLevel++;
                       if(levelExpectedSize==currentSize || currentLevel==d) {  
                           while(currentSize>0) {                                           
                                                   temp=deQ(queue,&front);
                                                   printf("%d->",temp->data);
                                                   if((temp->left && missingChild==1) || (temp->right && missingChild==1))
                                                                  return 0;
                                                   else {
                                                       if(temp->left)
                                                                     enQ(queue,temp->left,&rear);
                                                       else
                                                                     missingChild=1;
                                                       if(temp->right)
                                                                      enQ(queue,temp->right,&rear);             
                                                       else
                                                                     missingChild=1;
                                                       currentSize--;
                                                   }                                           
                           }
                       }
                       else
                           return 0;
                       currentSize=getSize(&front,&rear);
                       levelExpectedSize*=2;
     }
     return 1;
}
int main() {    
    struct node* root=newNode(4);
    struct node** queue=(struct node**)malloc(sizeof(struct node)*size(root));
    root->left=newNode(2);
    root->right=newNode(6); //1=treu and 0=false     
    //root=insert(root,5);
    root=insert(root,1);
    root=insert(root,3);
    printInorder(root);
    printf("\n The size of the tree is -> %d \n",size(root));
    printf("The max depth of the tree is -> %d \n",depth(root));
    printf("Queue is level order traversal is \n");
    printf("The tree is Complete??->%d",isComplete(queue,root));
    getch();
    return 0;
}
