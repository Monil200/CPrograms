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
void enQ(struct node** queue,struct node* root,int *rear)
{queue[(*rear)++]=root;
}
struct node* deQ(struct node** queue,int *front)
{*front=*front+1;
return (queue[(*front)-1]);
}
int size(int *front,int* rear)
{return (*rear-*front);
}
void displayQ(struct node** queue,int *front,int* rear)
{int i;
for(i=*front;i<(*rear);i++)
                         printf("%d->",queue[i]->data);
}
void insertInCompleteBT(struct node* root,struct node** queue,int *front,int* rear,int k)
{if(root==NULL)
               return;
else
               {struct node* temp=NULL;
               while(size(front,rear)>0)
                                         {temp=deQ(queue,front);
                                         if(!temp->left)
                                                        {temp->left=newNode(k);
                                                        break;
                                                        }
                                         if(!temp->right)
                                                        {temp->right=newNode(k);
                                                        break;
                                                        }
                                         }
               printf("Node Inserted\n");
               print(root);
               }
}
void insertInCompleteBTWrapper(struct node* root,struct node** queue,int k)//fill in queue in level order
{if(root==NULL)
               return;
else
               {struct node* temp=root;
               int i=0;
               int front=0,rear=0;
               enQ(queue,root,&rear);
               while(temp)
                           {
                           if(temp->left)
                                         enQ(queue,temp->left,&rear);
                           if(temp->right)
                                         enQ(queue,temp->right,&rear);                           
                           temp=queue[++i];
                           }
               //displayQ(queue,&front,&rear);
               insertInCompleteBT(root,queue,&front,&rear,k);
               }
}
int main()
{struct node* root=NULL;
root=insert(root,6);
root=insert(root,4);
root=insert(root,8);
print(root);
printf("\n");
struct node** queue=(struct node**)malloc(sizeof(struct node*)*10);
insertInCompleteBTWrapper(root,queue,10);
insertInCompleteBTWrapper(root,queue,11);
getch();
return 0;
}
