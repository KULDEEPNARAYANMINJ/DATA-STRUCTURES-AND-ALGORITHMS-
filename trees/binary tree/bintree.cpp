#include<bits/stdc++.h>
using namespace std;


struct node{
     int data;
     node* left;
     node* right;
};
  node* root =NULL;

node* createnode(int val)
{
    node* newtemp = new node();
    newtemp->data =  val;
    newtemp->left = newtemp->right = NULL;
    return newtemp;
}


void insert(node* &root, int val)
{
    if(root == NULL)
       root = createnode(val);
       

       else if(val < root->data)
       {
           insert(root->left,val);
           
       }

       else
       {
            insert(root->right,val);
           
       }
     
}

void inorder(node* root)
{
    if(root!= NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void isFullTree (node* root)
{
//add code here.

   isFullTree(root->left);
   isFullTree(root->right);
   
   if((root->left != NULL && root->right == NULL) || (root->right != NULL && root->left == NULL))
   return 0;
   
   else return 1;
   
}



int main()
{

    int arr[10] = {10,5,40,3,115,78,5,60,43,7};
int i=0;
int n=10;
    while(n--)
    {
        
      
     insert(root,arr[i++]);
        
    }

cout<<" your binary search tree is "<<" ";
    inorder(root);

    cout<<endl<<endl;
    cout<<isFullTree(root)<<endl;

    return 0;
}