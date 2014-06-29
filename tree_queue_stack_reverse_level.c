#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#define SIZE 500

struct node
{int data;
struct node *left,*right;
};
struct node* newNode(int val)
{struct node *new=(struct node*)malloc(sizeof(struct node));
new->data=val;
new->left=NULL;
new->right=NULL;
return new;
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
void enQ(struct node* root,struct node** queue,int *rear)
{queue[(*(rear))++]=root;
}
struct node* deQ(struct node** queue,int *front)
{*front=(*front)+1;
return (queue[(*front)-1]);

}
void push(struct node* root,struct node** stack,int *top)
{*top=(*top)+1;
stack[*top]=root;
}
struct node* pop(struct node** stack,int *top)
{*top=(*top)-1;
return stack[(*top)+1];
}
void readStack(struct node** stack,int *top)
{if(*top==-1)
             {printf("Stack empty");
             return;
             }
else
             {int i;
             printf("\n");
             for(i=*top;i>=0;i--)
                                 printf("%d->",*(stack[i]));
             }
}
void printLevel(struct node* root,struct node** queue,struct node** stack)
{struct node* temp=root;
int front=0,rear=0;
int top=-1;
               while(temp)
                          {//printf("\n data->%d",temp->data);
                          push(temp,stack,&top);
                          //printf("\n front=%d, rear=%d",*front,*rear);
                          if(temp->left)
                                        {printf("\nroot->left front=%d, rear=%d, data->%d, top->%d",front,rear,temp->left->data,*stack[top]);
                                        enQ(temp->left,queue,&rear);
                                        //push(temp->left,stack,&top);
                                        }
                          if(temp->right)
                                        {printf("\nroot->right front=%d, rear=%d, data->%d, top->%d",front,rear,temp->right->data,*stack[top]);
                                        enQ(temp->right,queue,&rear);
                                        //push(temp->right,stack,&top);
                                        }
                          temp=deQ(queue,&front);
                          }              
               readStack(stack,&top);
}
int main()
{
  struct node *root = NULL;
  root=insert(root,10);
  root=insert(root,8);
  root=insert(root,12);
  root=insert(root,6);
  root=insert(root,9);
  root=insert(root,14);
  root=insert(root,11);
    root=insert(root,4);
      root=insert(root,16);
        
  //print(root);  
  struct node** queue=(struct node**)malloc(sizeof(struct node*)*10);
  struct node** stack=(struct node**)malloc(sizeof(struct node*)*10);
  //struct node** stack2=(struct node**)malloc(sizeof(struct node*)*10);
  printLevel(root,queue,stack);
  /*queue[0]=root;
  queue[1]=root->left;
  printf("\n root %d",*(queue[0]));
  printf("\n %d",*(queue[1]));  */
  
 
  getchar();
  return 0;
}
