//https://www.codechef.com/SEPT17/problems/FILLMTR


#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
 
 
 
int main() {
	int d;
	cin>>d;
	for (int w=0;w<d;w++){
		vector<pair<int,pair<int,int>>> v;
		int n,q;
		cin>>n>>q;
		for (int i=0;i<q;i++){
			int l,r,val1;
			
			cin>>l>>r>>val1;
			
			v.push_back({l,{r,val1}});
			
			v.push_back({r,{l,val1}});
		}
		sort(v.begin(),v.end());
		int arr[n+1];
		for (int i=0;i<n+1;i++){
			arr[i]=-1;
		}
		int counter=0;
		int x=v.size();
		for (int i=0;i<x;i++){
			
 
			if(arr[v[i].f]!=-1 && arr[v[i].s.f]!=-1){
				int val =abs( arr[v[i].f] - arr[v[i].s.f] );
			/*	if (val<0)
				val=val*(-1);
			*/	if(val!=v[i].s.s){
			//	cout<<"no"<<endl;
				counter++;
			//	break;
 
				}
 
			}else if(arr[v[i].s.f]!=-1){
				int toput = abs(v[i].s.s-arr[v[i].s.f]);
			/*	if (toput<0)
				toput = toput * (-1) ;
			*/	arr[v[i].f] = toput;
 
			}else if(arr[v[i].f]!=-1){
				int toput1 = abs(v[i].s.s-arr[v[i].f]);
			/*	if (toput1<0)
				toput1 = toput1 * (-1) ;
			*/	arr[v[i].s.f] = toput1;
 
			}else{
 
				arr[v[i].f] = 1;
 
				if(v[i].s.s==0){
 
					arr[v[i].s.f] = 1;
 
				}else{
 
					arr[v[i].s.f] = 0;
 
				}
 
			}
 
			
 
		}
		if (counter==0){
		cout<<"yes"<<endl;
}
else{
	cout<<"no"<<endl;
}
counter=0;		
	}
	return 0;
} 