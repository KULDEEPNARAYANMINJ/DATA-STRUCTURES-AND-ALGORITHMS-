#include<bits/stdc++.h>
using namespace std;

struct node{
   int data;
   node* left;
   node* right;
};

node* root = NULL;

node* createnode(int val)
{
    node* temp = new node();
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void insert(node*& root , int val)
{
    if(root == NULL)
    root = createnode(val);

    else if(val < root->data)
    insert(root->left , val);

    else
    insert(root->right , val);
    
}

bool isfulltree(node* root)
{
    // to check null root
    if(root == NULL)
    return true;

    else if(root->left == NULL && root->right == NULL)
    return true;

    else if((root->left) && (root->right))
    return (isfulltree(root->left) && isfulltree(root->right));

    else
    return false;
    
}

void inorder(node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main()
{
    int arr[10] = {10,20,40,400,500,50,200,100,30,1000};
  int n = 10,i=0;
    while(n--)
    {
        insert(root,arr[i]);
        i++;
    }

inorder(root);

cout<<endl<<endl;
   if(isfulltree(root))
     cout<<" this tree is a full binary tree"<<endl;

     else
     {
         cout<<"not full binary tree"<<endl;
     }
     

   return 0;
}