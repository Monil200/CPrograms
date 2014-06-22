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
void printAllAncestors(struct node* root,int path[],int length,int k)
{if(root==NULL)
               return;
else
               {path[length++]=root->data;
               if(root->data==k)
                                 {int i;
                                 for(i=0;i<length-1;i++)
                                                     printf("%d->",path[i]);
                                 //return length;
                                 }
               //return (printAllAncestors(root->left,path,length,k)+printAllAncestors(root->right,path,length,k)-1);
               printAllAncestors(root->left,path,length,k);
               printAllAncestors(root->right,path,length,k);
               //return 0;
               }
}
int main()
{struct node* root=NULL;
root=insert(root,6);
root=insert(root,4);
root=insert(root,8);
root=insert(root,7);
root=insert(root,9);
root=insert(root,3);
print(root);
printf("\n");
int path[10];
//printf("\n returned-->%d",printAllAncestors(root,path,0,7));
printAllAncestors(root,path,0,7);
getch();
return 0;
}
