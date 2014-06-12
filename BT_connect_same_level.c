#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>
struct node{
       int data;
       struct node* left;
       struct node* right;
       struct node* next;
};
struct node* newNode(int val)
{struct node* temp=(struct node*)malloc(sizeof(struct node));
temp->left=NULL;
temp->right=NULL;
temp->data=val;
return temp;
}
struct node* insert(struct node* root,int val)
{if(root==NULL)
               return (newNode(val));
else
               {if(val<=root->data)
                                   root->left=insert(root->left,val);
               else if(val>root->data)
                                   root->right=insert(root->right,val);
               return(root);
               }               
}
int height(struct node* root)
{if(root==NULL)
               return 0;
else
               {int ldepth=height(root->left);
               int rdepth=height(root->right);
               if(ldepth>=rdepth)
                                 return (ldepth+1);
               else
                                 return (rdepth+1);
               }
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
void connectLevel(struct node* root,int level,struct node**temp)
{if(root==NULL)
               return;
else
               {if(level==1)
                            {root->next=*temp;
                            *temp=root;
                            }
               else
                            {connectLevel(root->right,level-1,temp);
                            connectLevel(root->left,level-1,temp);
                            }
               }
}
void connectLevelWrapper(struct node* root)
{int ht=height(root);
int i;
for(i=1;i<=ht;i++)
                      {struct node* temp=NULL;
                      connectLevel(root,i,&temp);
                      }
printf("\nprinting data LL wise\n");
struct node* current=root;
while(current)
              {struct node* temp=current;
              while(temp!=NULL)
                         {printf("%d->",temp->data);
                         temp=temp->next;
                         }
              current=current->left;
              }

}
int main()
{struct node* root=NULL;
root=insert(root,6);
root=insert(root,4);
root=insert(root,8);
root=insert(root,2);
root=insert(root,5);
root=insert(root,7);
print(root);
printf("\n height=%d",height(root));
connectLevelWrapper(root);
    getch();
return 0;
}

