#include<iostream>
#include <cstdlib>
#include<cstring>

#define INF 1000000000

using namespace std;

int gate[6][3] = {{1,2,3},{1,3,2},{2,3,1},{2,1,3},{3,1,2},{3,2,1}};

int stream[4];
int men[4];
int min_dist=0;

void nearest(bool *vis, int s, int *arr, int n){
	int i,j;
	for(i=s;i>=1;i--){
		if(vis[i]==false)
			break;
	}
	for(j=s;j<=n;j++){
		if(vis[j]==false)
			break;
	}
	int d1=s-i;
	int d2=j-s;
	if(d1<d2 || (i==s && j ==s) || (j == (n+1))){
		arr[0]=1;
		arr[1]=i;
		arr[2]=0;
	}
	else if(d2<d1 || i == 0){
		arr[0]=1;
		arr[1]=j;
		arr[2]=0;
	}
	else{
		arr[0]=2;
		arr[1]=i;
		arr[2]=j;
	}
}

int Solve(int n, int i, int j, bool *vis, int ans, int k){
	if(j==3){
		return ans;
	}
		int s = stream[gate[i][j]];
		int arr[3];
		cout << "Premutation: " << gate[i][0] << " " << gate[i][1] << " " << gate[i][2] << endl;
		cout << "Gate no: " << j << endl;
		for(int m=1; m<=n; m++) {
			cout << vis[m] << " ";
		}
		cout << endl;
		while((k)>0){
			cout << "Number of men remaining at current gate: " << k << endl;
			nearest(vis, s, arr, n);
			if(arr[0]==1){
				cout << "Going to stream no. " << arr[1] << endl;
				ans+=1+abs(s-arr[1]);
				vis[arr[1]]=true;
				(k)--;
				continue;
			}
			else{
				cout << "Stream no. " << arr[1] << " and " << arr[2] << " are equally far" << endl;
				(k)--;
				vis[arr[1]]=true;
				int ans1=1+abs(s-arr[1])+Solve(n,i,j,vis,ans,k);
				vis[arr[1]]=false;
				vis[arr[2]]=true;
				int ans2=1+abs(s-arr[2])+Solve(n,i,j,vis,ans,k);
				vis[arr[2]]=false;
				if(ans1<ans2){
					cout << "Going to stream no. " << arr[1] << endl;
					vis[arr[1]=true];
					ans+=ans1;
				}
				else{
					cout << "Going to stream no. " << arr[2] << endl;
					vis[arr[2]]=true;
					ans+=ans2;
				}
			}
		}
		Solve(n,i,j+1,vis,ans,men[gate[i][j+1]]);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		int ans;
		int min=INF;
		cin >> n;
		bool vis[n+1];
		int dist[n+1];
		for(int i=1;i<=n;i++){
			vis[i]=false;
		}
		for(int i=1;i<=n;i++){
			dist[i]=0;
		}
		for(int i=1;i<=3;i++){
			cin>> stream[i] >> men[i];
		}
		for(int i=0;i<6;i++){
			memset(vis, false, sizeof vis);
			ans = Solve(n, i, 0, vis, 0, men[gate[i][0]]);
			cout <<"galat answer: " <<  ans << endl;
			if(ans<min){
				min=ans;
			}
		}
		cout << min;
	}
}
