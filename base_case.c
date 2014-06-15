#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
int data;
struct node *left;
struct node *right;
};
struct node* newNode(int val)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
temp->data=val;
temp->left=NULL;
temp->right=NULL;
return temp;
}
void print(struct node* root)
{if(root==NULL)
              return;
else
              {print(root->left);
              printf("%d->",root->data);
              print(root->right);
              }
}
struct node* insert(struct node* root,int val)
{if(root==NULL)
               return (newNode(val));
else
               {if(val<=root->data)
                                   root->left=insert(root->left,val);
               if(val>root->data)
                                   root->right=insert(root->right,val);
               return root;
               }
}
int main()
{struct node* root=NULL;
root=insert(root,6);
root=insert(root,4);
root=insert(root,8);
print(root);
getch();
return 0;
}
