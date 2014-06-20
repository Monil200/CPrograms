#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>
struct node
{int data;
struct node *left;
struct node *right;
};
struct node* newNode(int val)
{struct node *new=(struct node*)malloc(sizeof(struct node));
new->data=val;
new->left=NULL;
new->right=NULL;
return new;
}
//no insert procedure as we are in BT not BST..
struct node* insert(struct node *root,int val)
{if(root==NULL)
               return(newNode(val));
if(val<=root->data)
                   root->left=insert(root->left,val);
else if(val>root->data)
     root->right=insert(root->right,val);
return root;
}
void printTreeInorder(struct node *head)
{if(head==NULL)
               return;
else
               {printTreeInorder(head->left);
               printf("%d->",head->data);
               printTreeInorder(head->right);
               }
               
}
void minValue(struct node *root)
{if(root->left==NULL)
               printf("\n The lowest value is->%d",root->data);
else
               {minValue(root->left);
               }
}
int maxDepth(struct node *root)
{if(root==NULL)
               return 0;
else
               {int leftd=maxDepth(root->left);
               int rightd=maxDepth(root->right);
               if(leftd>=rightd)
                                 return leftd+1;
               else
                                 return rightd+1;
               }
}

void range(struct node *root,int l,int u)
{if(root==NULL)
               return;
if(root->data>=l && root->data<=u)
                    {                                          
                    printf("->%d",root->data);
                    range(root->left,l,u);
                    range(root->right,l,u);
                    }
else if(root->data<l)
                    range(root->right,l,u);
else if(root->data>u)
                     range(root->left,l,u);
}

int main()
{struct node *root=NULL;
root=insert(root,6);
root=insert(root,7);
root=insert(root,3);
root=insert(root,4);
root=insert(root,1);
root=insert(root,8);
root=insert(root,9);
root=insert(root,9);
printTreeInorder(root);
printf("\n");
range(root,8,15);

getch();
return 0;
}


