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
int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}
void print(struct node* root,int nodes[],int *length)
{if(root==NULL)
              return;
else
              {print(root->left,nodes,length);
//              printf("%d->",root->data);
              nodes[(*length)++]=root->data;
              print(root->right,nodes,length);
              }
}
void printOnly(struct node* root)
{if(root==NULL)
              return;
else
              {printOnly(root->left);
              printf("%d->",root->data);
              printOnly(root->right);
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
void BTtoBST(struct node* root,int nodes[],int *index)
{if(root==NULL)
               return;
else
    {    
    BTtoBST(root->left,nodes,index);
    root->data=nodes[(*index)++];
    BTtoBST(root->right,nodes,index);
    }

}
int main()
{struct node* root=NULL;
/*root=insert(root,6);
root=insert(root,4);
root=insert(root,8);
print(root);*/
root=newNode(6);
root->left=newNode(8);
root->right=newNode(4);
root->left->right=newNode(7);

int nodes[10];
int length=0;
print(root,nodes,&length);
int i;
for(i=0;i<length;i++)
                     printf("%d->",nodes[i]);
qsort (nodes, length, sizeof(nodes[0]), compare);
printf("\nsorted\n");
for(i=0;i<length;i++)
                printf("%d->",nodes[i]);
int index=0;
printf("\n the new tree is\n");
BTtoBST(root,nodes,&index);
printOnly(root);
    getch();
    return 0;
}
