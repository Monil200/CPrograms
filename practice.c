#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>

struct node 
{int data;
struct node *left;
struct node *right;       
};
struct dll
{int val;
struct dll *prev;
struct dll *next;
};
//-===============
struct node* newNode(int val)
{struct node* new=(struct node*)malloc(sizeof(struct node));
new->data=val;
new->left=NULL;
new->right=NULL;
return new;
}
//-===============
struct node* insert(struct node *root,int val)
{if(root==NULL)
               return(newNode(val));
if(val<=root->data)
                   root->left=insert(root->left,val);
else if(val>root->data)
     root->right=insert(root->right,val);
return root;
}
void printInorder(struct node *root,int arr[],int *length)
{if(root==NULL)
              return;
else
              {printInorder(root->left,arr,length);
              arr[*length]=root->data;
              (*length)++;
              printInorder(root->right,arr,length);
              }
}

void wrapperTraverse(struct node *root)
{int arr[100];
int length=0;
printInorder(root,arr,&length);
int i;
for(i=0;i<length;i++)
                     printf(" %d->",arr[i]);
}
int height(struct node *root)
{if(root==NULL)
               return 0;
else
               {int ldepth=height(root->left);
               int rdepth=height(root->right);
               if(ldepth>=rdepth)
                                 return ldepth+1;
               else
                                 return rdepth+1;
               }

}
void levelTraverse(struct node *root,int level)
{
if(root==NULL)
               return;
if(level==1)
            {printf(" %d->",root->data);
            
            }
else
            {levelTraverse(root->left,level-1);
            levelTraverse(root->right,level-1);
            }

}
void wrapperLevel(struct node *root)
{int depth=height(root);
int i;
for(i=1;i<=depth;i++)
                      levelTraverse(root,i); ////level order from up
//for(i=depth;i>=1;i--)
                      //levelTraverse(root,i); //level order from down
}
int max(int a,int b) {return (a>b)? a:b;}
int oddDeepest(struct node *root,int level)
{if(root==NULL)
               return 0;
if(root->left==NULL && root->right==NULL && (level)%2==1)
{return level;
}
else
    {return max(oddDeepest(root->left,level+1),oddDeepest(root->right,level+1));
    }
}
void wrapperDeepest(struct node *root)
{int level=1;
printf("\n the deepest leaf odd level is %d->",oddDeepest(root,level));
}
//-===============
int oddEvenDiff(struct node *root)
{if(root==NULL)
               return 0;
else
    return (root->data-oddEvenDiff(root->left)-oddEvenDiff(root->right));
}
//-===============
void leaves(struct node *root)
{if(root==NULL)
               return;
if(root->left==NULL && root->right==NULL)
                    printf("%d->",root->data);
else
                    {leaves(root->left);
                    leaves(root->right);
                    }
}
//-===============
void noSibling(struct node *root)
{if(root==NULL)
               return;
if(root->left==NULL && root->right!=NULL)
                    printf("%d->",root->right->data);
else if(root->right==NULL && root->left!=NULL)
                    printf("%d->",root->left->data);
else
                    {noSibling(root->left);
                    noSibling(root->right);
                    }
}
//-===============
bool allLeafSameLevel(struct node *root,int level,int depth)
{if(root==NULL)
               return;
if(root->left==NULL && root->right==NULL && level==depth)
                    return true;
else
                    return (allLeafSameLevel(root->left,level+1,depth) && allLeafSameLevel(root->right,level+1,depth));
}
//-================
void leftView(struct node *root)
{if(root==NULL)
               return;
if(root->left)
              {printf("->%d->%d",root->data,root->left->data);}
              leftView(root->left);
              leftView(root->right);
              
}
//-===============
void push(struct dll** head, int data)
{
  struct dll *new=(struct dll*)malloc(sizeof(struct dll));
  new->val=data;
  new->prev=NULL;
  new->next=*head;
  if((*head)!=NULL)
                   (*head)->prev=new;
  *head=new;
}
void printDLL(struct dll **head)
{struct dll *temp=*head;
     while(temp!=NULL)
                 {printf(" %d ",temp->val);
                 temp=temp->next;
                 }
}
void extractLeaftoDLL(struct node *root,struct dll **head)
{if(root==NULL)
               return;
if(root->left==NULL && root->right==NULL)
                    {printf("%d->",root->data);
                    push(head,root->data);
                    //free(root);
                    root=NULL;                    
                    }
else
                    {extractLeaftoDLL(root->left,head);
                    extractLeaftoDLL(root->right,head);
                    }
}
//-===============
void deepestLeft(struct node *root,int level,bool isLeft,int *maxl,struct node **res) //sending res was imp
{if(root==NULL)
               return;
if(isLeft && root->left==NULL && root->right==NULL && level>(*maxl))//for odd level--> && level%2==0)
          {*res=root;
          *maxl=level;
          }
else
          {deepestLeft(root->left,level+1,true,maxl,res);
          deepestLeft(root->right,level+1,false,maxl,res);
          }
}

void wrapperDeepestLeft(struct node *root)
{int maxl=0;
struct node *res=NULL;
deepestLeft(root,0,false,&maxl,&res);
printf("\nthe deepmost level for left node is ->%d",maxl);
printf("\nthe deepmost level for left node value is ->%d",res->data);
}
//============
int pathSum(struct node *root,int val)
{if(root==NULL)
               return;
val=val*10+root->data;
if(root->left==NULL && root->right==NULL)
                    {printf("the number is %d /n",val);
                    return val;
                    }
                    return (pathSum(root->left,val)+pathSum(root->right,val));
                    
}
int main()
{struct node *root=NULL;
struct dll *head=NULL;
root=insert(root,6);
root=insert(root,7);
root=insert(root,3);
root=insert(root,4);
root=insert(root,1);
root=insert(root,11);
root=insert(root,10);
root=insert(root,9);
printf("\n the inorder is");
//printInorder(root);
wrapperTraverse(root);
printf("\n the height is %d->",height(root));
printf("\n the level reading is");
wrapperLevel(root);
wrapperDeepest(root);
printf("the diff of odd and even levels is %d",oddEvenDiff(root));    
printf("\n The leaves of the tree are");
leaves(root);
printf("\n these are the nodes with no siblings");
noSibling(root);
int depth=height(root);
if(allLeafSameLevel(root,0,depth))
                                       printf("\n all leaf at same level");
else
                                       printf("\n all leaf are NOT at same level");
printf("\n the left view is are");
leftView(root);
printf("\n the leaves are deleted ");
extractLeaftoDLL(root,&head);
wrapperTraverse(root);
printf("\n the DLL is ");
printDLL(&head);
wrapperDeepestLeft(root);
printf("\n The sum of all paths is %d\n",pathSum(root,0));
    getch();
    return 0;
}
