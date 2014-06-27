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
}
struct node* insert(struct node* node,int data)
{if(node==NULL)
               {return(newNode(data));
               }
else
               {if(data<=node->data)
                                    node->left=insert(node->left,data);
               if(data>node->data)
                                    node->right=insert(node->right,data);   
               return (node);                                       
               }
               
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
int minValue(struct node *root)
{struct node *temp=root;
while(temp->left!=NULL)
                       {temp=temp->left;
                       }
return temp->data;

}
int maxValue(struct node *root)
{struct node *temp=root;
while(temp->right!=NULL)
                       {temp=temp->right;
                       }
return temp->data;
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
int isBST(struct node *root)
{if(root==NULL)
               return 1;
if(root->left!=NULL && maxValue(root->left)>root->data)
                    return 0;
if(root->right!=NULL && minValue(root->right)<=root->data)
                     return 0;
if(!isBST(root->left) || !isBST(root->right))
                      return 0;
return 1;
}
int isBST1(struct node *root)
{if(root==NULL)
               return 1;
if(root->left!=NULL && root->data<root->left->data)
                    return 0;
if(root->right!=NULL && root->data>root->right->data)
                     return 0;
if(!isBST(root->left) || !isBST(root->right))
                      return 0;
return 1;
}
int main()
{struct node* root=NULL;
struct node* root1=NULL;
root=insert(root,4);
root=insert(root,2);
root=insert(root,1);
root=insert(root,3);
root=insert(root,5);
//===========
root1=insert(root1,4);
root1=insert(root1,2);
root1=insert(root1,1);
root1=insert(root1,3);
root1=insert(root1,5);
//=====
struct node* r=newNode(100);
r->right=newNode(101);
r->left=newNode(999);
printTreeInorder(root);
printf("Min value %d->\n",minValue(root));
printf("Max value %d->\n",maxValue(root));
printf("The max depth of the tree is->%d \n",maxDepth(root));
printf("\n is BST?? %d \n",isBST1(r));

printTreeInorder(root);
getch();
return 0;
}


