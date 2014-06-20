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
struct node* sortedArrayToBST(int arr[],int start,int end)
{if(start>end)
              return NULL;
else
    {int mid=(start+end)/2;
    struct node* root=newNode(arr[mid]);
    root->left=sortedArrayToBST(arr,start,mid-1);
    root->right=sortedArrayToBST(arr,mid+1,end);
    return root;
    }
    
}
int main()
{int arr[]={1,2,3,4,5};
int size=sizeof(arr)/sizeof(arr[0]);
struct node* root=sortedArrayToBST(arr,0,size-1);
print(root);
getch();
return 0;
}
