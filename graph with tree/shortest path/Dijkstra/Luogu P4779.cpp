#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#define P(A) A=-~A
typedef long long LL;
#define NUMBER1 100000
struct NODE{
	int v;
	LL w;
	bool operator<(const NODE &A)const{return w>A.w;}
};
std::vector<NODE>e[NUMBER1+5];
std::priority_queue<NODE>q;
int n,m,s;
LL dis[NUMBER1+5];
bool visit[NUMBER1+5];
void bfs(){
	memset(dis,0x7f7f,sizeof(dis));
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		int u=q.top().v;
		q.pop();
		if(visit[u])continue;
		visit[u]=true;
		for(auto [v,w]:e[u]){
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!visit[v])q.push({v,dis[v]});
			}
		}
	}
	for(int i=1;i<=n;P(i))std::cout<<dis[i]<<' ';
}
signed main(){
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin>>n>>m>>s;
	for(int u,v,w;m--;){
		std::cin>>u>>v>>w;
		e[u].push_back({v,w});
	}
	bfs();
	return 0;
}
