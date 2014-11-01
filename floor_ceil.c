#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<limits.h>
struct node {
  int data;
  struct node* left;
  struct node* right; 
  int hd;   
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
            if(root->data >val) 
                          root->left=insert(root->left,val);
            else
                          root->right=insert(root->right,val);
            return root;
       }
}
void print(struct node* root) {
     if(root==NULL)
                   return;
     else {
          print(root->left);
          printf("%d->",root->data);                    
          print(root->right);          
     }
}

int size(struct node* root) {
     if(root==NULL)
                   return 0;
     else
                   return(size(root->left)+size(root->right)+1);
                   
}
int findCeil(struct node* root,int key) {
    if(root==NULL)
                  return 0;
    else {
         if(root->data==key)
                            return root->data;
         if(root->data<key)
                           return (findCeil(root->right,key));
         else if(root->data>key) {
                                 int ceil=findCeil(root->left,key);
                           return ((ceil>=key) ? ceil: root->data);
         }
    }
}
int findFloor(struct node* root,int key) {
    if(root==NULL)
                  return 0;
    else {
         if(root->data==key)
                            return root->data;
         if(root->data>key)
                           return (findFloor(root->left,key));
         else if(root->data<key) {
                                 int floor=findFloor(root->right,key);
                           return ((floor!=0) ? floor: root->data);
         }
    }
}
int main() {
    struct node* root=NULL;
    root=insert(root,4);
    root=insert(root,2);
    root=insert(root,6);
    root=insert(root,8);
    print(root);
    printf("\n The ceil val is %d",findCeil(root,7));
    printf("\nThe floor val is %d",findFloor(root,7));
    getch();    
    return 0;
}
