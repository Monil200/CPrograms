#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

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
void push(struct node* root,struct node** stack,int *top)
{stack[++(*top)]=root;
}
struct node* pop(struct node** stack,int *top)
{*top=(*top)-1;
return stack[(*top)+1];
}
bool isEmpty(int *top)
{if(*top==-1)
             return 1;
else
             return 0;
}
void inorderTraversal(struct node* root,struct node** stack)
{int top=-1;
/*push(root,stack,&top);
printf("\n top->%d",top);
printf("\n popped->%d",pop(stack,&top)->data);
printf("\n top->%d",top);
printf("\n isEMpty->%d",isEmpty(&top));*/
struct node* temp=root;
while(!isEmpty(&top) || temp)
                     {if(temp)
                              {push(temp,stack,&top);
                              temp=temp->left;
                              }
                     else
                              {temp=pop(stack,&top);
                              printf("%d->",temp->data);
                              temp=temp->right;
                              }
                     }
}
void preorderTraversal(struct node* root,struct node** stack)
{int top=-1;
struct node* temp=root;
push(temp,stack,&top);
while(!isEmpty(&top))
                     {temp=pop(stack,&top);
                     printf("%d->",temp->data);
                     if(temp->right)
                                    push(temp->right,stack,&top);
                     if(temp->left)
                                    push(temp->left,stack,&top);
                     }
}
int main()
{
  struct node *root = NULL;
  root=insert(root,5);
  root=insert(root,2);
  root=insert(root,1);
  root=insert(root,6);
  root=insert(root,3);    
  print(root);
  struct node** stack=(struct node**)malloc(sizeof(struct node*)*10);
  printf("\n");
  inorderTraversal(root,stack);
  printf("\n");
  preorderTraversal(root,stack);
  getchar();
  return 0;
}
