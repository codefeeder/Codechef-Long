//https://www.codechef.com/SEPT17/problems/CHEFPDIG


#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin>>t;
		for (int i=0;i<t;i++){
			string str;
			cin>>str;
			int arr[100];
			for (int l=0;l<100;l++){
				arr[l]=0;
			}
			int a[10];
			for (int l=0;l<10;l++){
				a[l]=0;
			}
			for (int k=0;k<str.length();k++){
				int digit = str[k] - 48;
				a[digit]++;
			}
			for (int j=6;j<10;j++){
				if (a[j]>0){
					for (int t=0;t<10;t++){
						if (a[t]>0 && j!=t){
							int num = j*10+t;
							arr[num]++;
						}
						else if (a[t]>1){
							int num = j*10+t;
							arr[num]++;
						}
					}
				}
			}
			for (int o=65;o<=90;o++){
				if (arr[o]>0){
					char j=(char)(o);
					cout<<(j);
				}
			}
			cout<<endl;
		}
	return 0;
} 