void levelOrder(Node* node)
{
queue<node*>q;
q.push(node);
while(!q.empty())
{
struct Node *temp = q.front();
cout << temp->data << " ";
q.pop();
if(temp->left!=NULL)
q.push(temp->left);
if(temp->right!=NULL)
q.push(temp->right);
}
}


void levelOrder(Node* node)
{
  //Your code here
  queue<node*> q;
  q.push(node);
  
  while(!q.empty())
  {
      Node* current = q.front();
      cout<<current->data<<" ";
      
      if(current->left != NULL)
      q.push(current->left);
      
      if(current->right != NULL)
      q.push(current ->right);
      
      q.pop();
  }
}