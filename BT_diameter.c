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

void printTreeInorder(struct node *head)
{if(head==NULL)
               return;
else
               {printTreeInorder(head->left);
               printf("%d->",head->data);
               printTreeInorder(head->right);
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
void diameter(struct node *root,int *d)
{if(root==NULL)
               return;
int lheight=maxDepth(root->left);
int rheight=maxDepth(root->right);
printf("\n%d",lheight,rheight);
int currmax=lheight+rheight+1;
if(*d<currmax)
              {*d=currmax;
              }              
              diameter(root->left,d);
              diameter(root->right,d);
}
void wrapperDiameter(struct node *root)
{int d=0;
diameter(root,&d);
printf("->%d",d);

}

int main()
{struct node* root=newNode(6);
root->left=newNode(9);
root->right=newNode(4);

root->left->left=newNode(1);
root->left->right=newNode(3); //this is BT

printTreeInorder(root);
printf("\n%d",maxDepth(root));
printf("\n The diameter is \n");
wrapperDiameter(root);
getch();
return 0;
}


