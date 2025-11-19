#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#define P(A) A=-~A
typedef long long LL;
#define NUMBER1 100000
bool visit[NUMBER1+5];
std::vector<int>e[NUMBER1+5];
int n,m;
void dfs(int u){
	if(visit[u])return;
	visit[u]=true;
	std::cout<<u<<' ';
	for(auto v:e[u])
		dfs(v);
}
void bfs(int u){
	memset(visit,false,sizeof(visit));
	std::queue<int>q;
	q.push(u);
	visit[u]=true;
	std::cout<<u<<' ';
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:e[u])
			if(!visit[v]){
				q.push(v),visit[v]=true;
				std::cout<<v<<' ';
			}
	}
}
signed main(){
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin>>n>>m;
	for(int u,v,i(1);i<=m;P(i)){
		std::cin>>u>>v;
		e[u].push_back(v);
	}
	for(int i=1;i<=n;P(i))std::sort(e[i].begin(),e[i].end());
	dfs(1);
	std::cout<<'\n';
	bfs(1);
	return 0;
}
