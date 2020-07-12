#include<bits/stdc++.h>
using namespace std;

int main()

{
   string s = "4545,23adsfsldmfl,d,fs,df,,,df  4534 345 23 42 4 adf,asd,f,34,23";

   stringstream iss(s);
   
int num;

vector<string> a;
while(iss >> s)
{
a.push_back(s);
}
int size = a.size();

for(int i=0;i<size;i++)
  {
     cout<<endl;
      cout<<a[i]<<"       "<<endl;
  }
    return 0;
}