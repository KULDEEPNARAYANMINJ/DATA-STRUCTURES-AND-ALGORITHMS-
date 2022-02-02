// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

    
    struct node
    {
        int val;
        node* next;
        node* prev;
    };
    
    int SizeOfMap;
    map<int, node*>mp;
    node* head = NULL;
    node* tail = NULL;

    
    void InsertNewHead(int key, int value)
    {
        node* NewCache = new node();
            NewCache->val = value;
            
            mp[key] = NewCache;
        
        if(head == NULL)
        {
            head = NewCache;
            head->next = NULL;
            tail = head;
            tail->prev = NULL;
            
            return;
        }
            
            head->next = NewCache;
            NewCache->prev = head;
            head = NewCache;
            head->next = NULL;
    }
    
    void ReArrangeDL(node* temp)
    {
        
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        head->next = temp;
        temp->prev = head;
        head = temp;
        head->next = NULL;
    }
    
    
    
//     LRUCache(int capacity) {
        
//         SizeOfMap = capacity;
        
        
//     }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(mp.find(key) == mp.end())
        {
            return -1;
        }
        
        ReArrangeDL(mp[key]);
        
        return mp[key]->val;
    }
    
    //Function for storing key-value pair.
    void put(int key, int value)
    {
        // your code here   
         if(mp.find(key) != mp.end())
        {
            mp[key] ->val =  value;
            
            ReArrangeDL(mp[key]);

        }
        else
        {
                  
            if(mp.size() < SizeOfMap)
            {
                cout<<"we are here"<<endl;
                InsertNewHead(key, value);
            }
            else
            {
                // erase tail from both hashmap and Doubly link list
                
                int TailVal = tail->val;
                mp.erase(TailVal);
                
                tail = tail->next;
                tail->prev = NULL;

                InsertNewHead(key, value);

            }
        }
        
    }


void printDL()
{
    node* temp = tail;
    
    while(temp != NULL)
    {
        cout<<temp->val<<"->";
        temp = temp->next;
    }
}

void printHashMap()
{
    for(auto x : mp)
    {
        cout<<x.first<<" , "<<x.second->val<<endl;
    }
}



int main()
{
   
    cout<<get(1);
    
    put(1,1);
    put(2,2);
    put(3,3);
    put(4,4);
    
    printDL();
    cout<<endl;
    
//     printHashMap();

    cout<<"get is = "<<get(2)<<endl;
    
     printDL();
    cout<<endl;
    
    
    put(5,5);
         printDL();
    cout<<endl;
    put(6,6);
         printDL();
    cout<<endl;
    put(2,200);
    
//     printHashMap();
    
    
    printDL();
    return 0;
}



