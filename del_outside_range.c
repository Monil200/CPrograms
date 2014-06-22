#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

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
               int rightd=maxDepth(root->left);
               if(leftd>=rightd)
                                 return leftd+1;
               else
                                 return rightd+1;
               }
}
struct node * delOutsideRange(struct node *root,int min,int max)
{if(root==NULL)
               return NULL; // this NULL is important
root->left=delOutsideRange(root->left,min,max);
root->right=delOutsideRange(root->right,min,max);
if(root->data < min)
              {struct node *temp=root->right;
              free(root);
              root=NULL;              
              return temp;
              }
else if(root->data >max)
              {struct node *temp1=root->left;
              free(root);
              root=NULL;              
              return temp1;
              }
return root;
}
int main()
{struct node *root=NULL;
root=insert(root,6);
root=insert(root,7);
root=insert(root,3);
root=insert(root,4);
root=insert(root,1);
root=insert(root,11);
root=insert(root,10);
root=insert(root,9);
printTreeInorder(root);
minValue(root);
printf("\n The max depth of the tree is->%d",maxDepth(root));
printf("\n tree after removing elements not in range is \n");
root=delOutsideRange(root,7,10);
printTreeInorder(root);
getch();
return 0;
}


