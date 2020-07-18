
#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> &v, int val){

  if(v.size() == 0 || v[v.size()-1] <= val)
    v.push_back(val);
  return;

  int temp = v[v.size()-1];
  v.pop_back();

  insert(v, val);

  v.push_back(temp);

}


void recsort(vector<int> &v){

  if(v.size() == 1)
    return;

  int val = v[v.size() - 1];
  v.pop_back();
    recsort(v);

insert(v, val);



}

int main(){

//        #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

vector<int> v{1,0,5,2};

recsort(v);

for(int x : v)
cout<<x<<" ";

return 0;

}