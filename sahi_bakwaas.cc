#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct{
	int x;
	int y;
}Point;

int n,m;

int rock[50][50];

int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};

int Solve(int step){
	Point* queue=new Point[100000];
	bool in_queue[51][51];
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			in_queue[i][j] = false;
		}
	}
	bool visited[50][50];
	for(int i=0;i<50;i++){
		for(int j=0;j<50;j++){
			visited[i][j]=false;
		}
	}
	int front=-1,rear=-1;
	bool reached = false;
	Point start;
	start.x=n-1;
	start.y=0;
	queue[++rear]=start;
	in_queue[start.x][start.y] = true;
	while(front!=rear && !reached){
		Point cur;
		cur=queue[++front];
		visited[cur.x][cur.y]=true;
		for(int i=0;i<4;i++){
			Point next;
			next.y=cur.y+dy[i];
			for(int j=1;j<=step;j++){
				next.x=cur.x+dx[i]*j;
				if(next.x>=0 && next.x<n && next.y>=0 && next.y<m && rock[next.x][next.y]==3){
					reached=true;
					break;
				}
				else if(next.x>=0 && next.x<n && next.y>=0 && next.y<m && rock[next.x][next.y]==1 && visited[next.x][next.y]==false && !in_queue[next.x][next.y]){
					queue[++rear]=next;
					in_queue[next.x][next.y] = true;
				}
				else continue;
			}
		}
	}
	if(reached){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	int T;
	cin>>T;
	for(int k=1;k<=T;k++){
		cin>>n>>m;
		for(int i=0;i<50;i++){
			for(int j=0;j<50;j++){
				rock[i][j]=-1;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>rock[i][j];
			}
		}
		int s=1;
		bool found=false;
		while(found==false){
			if(s == n) break;
			int possible;
			possible=Solve(s);
			if(possible==1){
				found=true;
				break;
			}
			else
				s++;
		}
		if(s == n) cout << "Not possible" << endl;
		else cout<<"#"<<k<<" "<<s<<endl;
	}
	return 0;
}
