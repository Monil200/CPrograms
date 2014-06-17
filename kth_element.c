#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>
struct node{
int data;
struct node *left;
struct node *right;
};

struct node* newNode(int val)
{struct node *temp=(struct node *)malloc(sizeof(struct node));
temp->data=val;
temp->left=NULL;
temp->right=NULL;
return temp;
}
struct node* insert(struct node *root,int val)
{if(root==NULL)
               {return (newNode(val));
               }
else if(val<=root->data)
                        {root->left=insert(root->left,val);
                        }
else if(val>root->data)
                        {root->right=insert(root->right,val);
                        }
                        return root;
}

int size(struct node* root)
{if(root==NULL)
               return 0;
else
               return(1+size(root->left)+size(root->right));
}
struct node* kthElement(struct node* root,int k)
{struct node* kth=NULL;
if(size(root->left)==k-1)
                         {kth=root;
                         return (kth);
                         }
else if(size(root->left)>k-1)
                             {return (kthElement(root->left,k));
                             }
else if(size(root->left)<k-1)
                             {return (kthElement(root->right,k-size(root->left)-1));
                             }
}
int main()
{struct node *root=NULL;
root=insert(root,6);
root=insert(root,3);
root=insert(root,4);
root=insert(root,2);
root=insert(root,8);
root=insert(root,7);
root=insert(root,9);
printf("%d",size(root));
printf("kth element is %d",kthElement(root,3)->data);
getch();
return 0;
}
