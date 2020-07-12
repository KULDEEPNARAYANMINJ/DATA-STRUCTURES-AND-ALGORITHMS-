#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* createnode(int val)
{
    node* temp = new node();
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void preorder(node* root)
{
    if(root != NULL)
    {
        cout<< root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
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

void postorder(node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}



node* buildtree(string s)
{
  if(s.length() == 0 || s[0] == 'N')
  return NULL;

    stringstream iss(s);
   vector <string> a;
   while(iss >> s)
   a.push_back(s);

   node* root = createnode(stoi(a[0]));
   queue <node*> q;
   q.push(root);

int i=1;

   while(!q.empty() && i < a.size())
   {
       node* curnode = q.front();
        q.pop();
       
       string curval = a[i];

       if(curval != "N")
       {
       
           curnode->left = createnode(stoi(curval));
           q.push(curnode->left);
           
       }
       i++;
       if(i >= a.size())
       break;
       
       curval = a[i];

       if(curval != "N")
       {
         
           curnode->right = createnode(stoi(curval));
           q.push(curnode->right);
       }
       i++;
   }     
   return root;                                  
}

int main()
{
    
        string s;
        getline(cin,s);

      node* root = buildtree(s);


cout<<"preorder traversal"<<endl;
        preorder(root);

        cout<<endl;
        cout<<"inorder traversal"<<endl;
        inorder(root);

        cout<<endl;
        cout<<"post order traversal" <<endl;
        postorder(root);
        cout<<endl;
    
}