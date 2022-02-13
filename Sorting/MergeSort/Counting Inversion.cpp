#include<bits/stdc++.h>
using namespace std;

int finalArray[100005];
int counts = 0;
void solve(int l, int mid, int r)
{
    
int arSize1 = mid-l+1;
int arSize2 = r - mid;
    
int ar1[arSize1];
int ar2[arSize2];

    
for(int i = 0;i<arSize1;i++) ar1[i] = finalArray[l+i];
for(int i = 0;i<arSize2;i++) ar2[i] = finalArray[mid+1+i];

int i = 0, j = 0;
while(i < arSize1 && j < arSize2)
    {
        if(ar1[i] <= ar2[j])
        {
           finalArray[l] = ar1[i];
            i++;
            l++;
        }
      else if(ar2[j] < ar1[i])
      {
       finalArray[l] = ar2[j];
        j++;
        l++;

        counts = counts + arSize1 - i;
      }

    }

    while(i < arSize1)
    {
     finalArray[l] = ar1[i];
     i++;
     l++;
    }
    while(j  < arSize2)
    {
     finalArray[l] = ar2[j];
     j++;
     l++;
    }
    
}


void mergeSort(int l, int r)
{
    if(l >= r) return;
    
    int mid = (l+r)/2;
    
    mergeSort(l,mid);
    mergeSort(mid+1, r);
    
    solve(l,mid,r);

}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        
    int n; cin>>n;
    for(int i = 0;i<n;i++) cin>>finalArray[i];
        
        counts = 0;
    mergeSort(0,n-1);
        
        cout<<counts<<endl;
    }
}
