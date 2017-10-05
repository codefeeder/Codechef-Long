//https://www.codechef.com/SEPT17/problems/CHEFSUM

#include<bits/stdc++.h>
 
using namespace std;
int main(){
int t;
cin>>t;
for (int i=0;i<t;i++){
int n;
cin>>n;
int arr[n];
long long int min = 10000000;
int index=0;
for (int j=0;j<n;j++){
cin>>arr[j];
if (arr[j]<min){
min=arr[j];
index=j;
}
}
cout<<index+1<<endl;
 
}
 
 
return 0;
}  