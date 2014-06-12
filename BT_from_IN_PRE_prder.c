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
{struct node *temp=(struct node*)malloc(sizeof(struct node));
temp->data=val;
temp->left=NULL;
temp->right=NULL;
return temp;
}

struct node * insert(struct node *root,int val)
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

void printTreeInorder(struct node *head)
{if(head==NULL)
               return;
else
               {printTreeInorder(head->left);
               printf("%d->",head->data);
               printTreeInorder(head->right);
               }
}
int searchInorder(int preorder[],int val,int start,int end)
{int i;
for(i=start;i<=end;i++)
                       {if(preorder[i]==val)
                                            {return i;
                                            break;
                                            }
                       }
                       return -1;
}
struct node* createTree(int inorder[],int preorder[],int startIndex,int endIndex)
{static int preIndex=0;
if(startIndex>endIndex)
                        return NULL;
struct node* temp=(struct node*)malloc(sizeof(struct node));
if(temp)
        {temp->data=preorder[preIndex++];
        if(startIndex==endIndex)
                        return temp;
        int index=searchInorder(inorder,temp->data,startIndex,endIndex);
        temp->left=createTree(inorder,preorder,startIndex,index-1);
        temp->right=createTree(inorder,preorder,index+1,endIndex);
        return temp;    
        }
return NULL;
}
/*int search_inorder(int inorder[], int elem, int start, int end){
 
        int i;
        for(i=start;i<=end; i++){
                if(inorder[i]== elem)
                        return i;
        }
        return -1;
}
struct node * create_tree(int inorder[], int preorder[],
              int startIndex, int endIndex){
 
   static int preIndex =0;
 
   int i =0;
   if(startIndex > endIndex)
         return NULL;
   struct node * temp =  (struct node *)malloc(sizeof(struct node));
   if(temp){   
       temp->data = preorder[preIndex++];
     if(startIndex == endIndex) 
                   return temp ;  
     int index = search_inorder(inorder,temp->data,startIndex, endIndex);
     temp->left = create_tree(inorder, preorder,startIndex, index-1 );
     temp->right  = create_tree(inorder, preorder, index+1, endIndex );
     return temp;
    }
    return NULL;
}*/
int main()
{struct node* root=NULL;
root=insert(root,6);
root=insert(root,4);
root=insert(root,8);
printTreeInorder(root);
int inorder[]={1,2,3};
int preorder[]={2,1,3};
//root=createTree(inorder,preorder,0,2);
//printf("%d",root->data);
//printf("%d",root->left->data);
//printf("%d",root->right->data);
    getch();
    return 0;
}


