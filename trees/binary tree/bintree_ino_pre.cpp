#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;

};
int preindex =0;
    node* createnode(int val)
    {
        node* temp = new node();
        temp->data = val;
         temp->left = NULL;
        temp->right = NULL;
        return temp;
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

int search(int in[], int start, int end, int val)
{
    for(int i=start; i<=end; i++)
    {
        if(in[i] == val)
        return i;
    }
    return 0;
}

node* buildtree(int in[] , int pre[] ,int instart, int inend)
{
    if(instart > inend)
    return NULL;

    node* temp = createnode(pre[preindex++]);

    if(instart == inend)
    return temp;

    int rootindex = search(in, instart, inend, temp->data);

    temp->left = buildtree(in, pre, instart, rootindex-1);
    temp->right = buildtree(in, pre, rootindex+1, inend);
    return temp;
}

int main()
{
    int t; cin>>t;

    while(t--)
    {
        int n; cin>>n;
        int in[n], pre[n], preindex =0;

        for(int i=0;i<n;i++)
        cin>>in[i];

        for(int i=0;i<n;i++)
        cin>>pre[i];

        node* root = NULL;

       root = buildtree(in, pre, 0, n-1);

      postorder(root);
    }
}