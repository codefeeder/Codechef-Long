//https://www.codechef.com/SEPT17/problems/SEACO


#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define MAX 10000000
#define mod 1000000007
class lazytree{
 int tree[MAX];  
int lazy[MAX] ;  
 public:
 lazytree(){
 	for (int i=0;i<MAX;i++){
 	tree[i]=0;
 	lazy[i]=0;}
 }
void updateRangeUtil(int si, int ss, int se, int us,
                     int ue, int diff)
{
    if (lazy[si] != 0)
    {
       tree[si] = (tree[si]%mod + ( (se - ss + 1) * lazy[si])%mod)%mod;
         if (ss != se)
        {
           	lazy[si * 2 + 1] = (lazy[si*2 +1]%mod +  lazy[si]%mod)%mod;
    	lazy[si * 2 + 2] = (lazy[si*2 +2]%mod +  lazy[si]%mod)%mod;
        }
        lazy[si] = 0;
    }
    if (ss>se || ss>ue || se<us)
        return ;
    if (ss>=us && se<=ue)
    {
       tree[si] =(tree[si]%mod + ((se - ss + 1) * diff)%mod)%mod;
    			if (ss != se) {
    				lazy[si * 2 + 1] =(lazy[si * 2 + 1]%mod +  diff%mod)%mod;
    				lazy[si * 2 + 2] =(lazy[si * 2 + 2]%mod +  diff%mod)%mod;
    			}
    			return;
       
    }
    int mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);
    	tree[si] = (tree[si * 2 + 1]%mod + tree[si * 2 + 2]%mod)%mod;
}
void updateRange(int n, int us, int ue, int diff)
{
   updateRangeUtil(0, 0, n-1, us, ue, diff);
}
int getSumUtil(int ss, int se, int qs, int qe, int si)
{
    if (lazy[si] != 0)
    {
       	tree[si] = ( tree[si]%mod +  ((se - ss + 1) * lazy[si])%mod)%mod;
        if (ss != se)
        {
           	lazy[si * 2 + 1] = (lazy[si * 2 + 1]%mod + lazy[si]%mod)%mod;
    	lazy[si * 2 + 2] = (lazy[si * 2 + 2]%mod + lazy[si]%mod)%mod;
        }
       lazy[si] = 0;
    }
     if (ss>se || ss>qe || se<qs)
        return 0;
    if (ss>=qs && se<=qe)
        return tree[si];
    int mid = (ss + se)/2;
    return getSumUtil(ss, mid, qs, qe, 2*si+1) + getSumUtil(mid+1, se, qs, qe, 2*si+2);
}
int getSum(int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return getSumUtil(0, n-1, qs, qe, 0);
}
void constructSTUtil(int arr[], int ss, int se, int si)
{
    if (ss > se)
        return ;
    if (ss == se)
    {
        tree[si] = arr[ss];
        return;
    }
    int mid = (ss + se)/2;
    constructSTUtil(arr, ss, mid, si*2+1);
    constructSTUtil(arr, mid+1, se, si*2+2);
 
    tree[si] = (tree[si * 2 + 1]%mod + tree[si * 2 + 2]%mod)%mod;
}
void constructST(int arr[], int n)
{
    constructSTUtil(arr, 0, n-1, 0);
}
 
}; 
int main(){
	int t;
	cin>>t;
	for (int w=0;w<t;w++)
{	int n,m;
	cin>>n>>m;
	vector<pair<pair<int,int>,pair<int,int>>> v1;
	vector<pair<pair<int,int>,pair<int,int>>> v2;
	for (int i=0;i<m;i++){
		int val,l,r;
		cin>>val>>l>>r;
		int x=l-1;
		int y=r-1;
		v2.pb({{x,y},{i,val}});		
		if (val==1){
		v1.pb({{x,y},{i,val}});	
		}
				
		
	}
	/*for (int i=0;i<v1.size();i++){
		cout<<v1[i].f.f<<" "<<v1[i].f.s<<" "<<v1[i].s.f<<" "<<v1[i].s.s;
		cout<<endl;
	}
	for (int i=0;i<v2.size();i++){
		cout<<v2[i].f.f<<" "<<v2[i].f.s<<" "<<v2[i].s.f<<" "<<v2[i].s.s;
		cout<<endl;
	}*/
	int a1[n]={0};
	int a2[m];
	for (int i=0;i<m;i++){
		a2[i]=1;
	}
	lazytree t1,t2;
	t1.constructST(a1,n);
	t2.constructST(a2,m);
	/*	for (int i = 0; i < m; i++) {
    			cout<<t2.getSum(m, i, i)<<" ";
    		}
    		cout<<endl;
    			for (int i = 0; i < n; i++) {
    			cout<<t1.getSum(n, i, i)<<" ";
    		}
    		cout<<endl;*/
	for (int i = v2.size() - 1; i >= 0; i--) {
    		if (v2[i].s.s==2)
    		{t2.updateRange(m,v2[i].f.f, v2[i].f.s,t2.getSum(m, i, i));
    		
    			
    		}}
    		for (int i = v1.size() - 1; i >= 0; i--) {
    t1.updateRange(n,v1[i].f.f , v1[i].f.s, t2.getSum(m,v1[i].s.f ,v1[i].s.f));
    		}
    		for (int i = 0; i < n; i++) {
    			cout<<t1.getSum(n, i, i)<<" ";
    		}
    		cout<<endl;
}
	return (0);
} 