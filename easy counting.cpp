
#include<bits/stdc++.h>
using namespace std;


int main(){

       #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    

    string s;
  cin>>s;

  int len = s.length();

  int hash[256] = {0};

  for(int i =0;i<len; i++){

  
      	hash[s[i]]++;
  }
 
 long long sum =0, mul =0;
  for(int i = 0;i<=255; i++){
  	 mul = hash[i] * hash[i];

  	 sum += mul;
  }

  cout<<sum;
    return 0;

}