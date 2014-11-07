#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node {
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
       }
       return root;
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
struct node* cloneInorder(struct node* root,struct node* parent,bool isLeft,bool isRight,bool isRoot) {     
     if(root==NULL)
                   return NULL;
     else {
          struct node* croot=NULL;          
          if(isRoot)
                      croot=newNode(root->data);
          else if(isLeft)
                      parent->left=newNode(root->data);
          else if(isRight)
                      parent->right=newNode(root->data);
          cloneInorder(root->left,croot,true,false,false);
          //printf("%d->",root->data);
          cloneInorder(root->right,croot,false,true,false);
          return croot;
     }          
}

int main() {
    struct node* root=NULL;
    root=insert(root,4);
    root=insert(root,2);
    root=insert(root,6);
    printInorder(root);
    printf("\n the contents of cloned tree are \n");
    struct node* croot=cloneInorder(root,NULL,false,false,true);
    printInorder(croot);
    getch();
    return 0;
}
