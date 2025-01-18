#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n;
    int arr[n];
    int pos = 0;
    int neg = 0;
    int sum = 0;
    for(int i=0;i<n-1;i++){
     cin>>arr[i];
     if(arr[i]<0)neg+=arr[i];
     else pos+=arr[i];
     sum+=arr[i];
    }
    if(pos>=abs(neg)){
      cout<<sum<<endl;
    }
    else cout<<-sum<<endl;
    
  }
}