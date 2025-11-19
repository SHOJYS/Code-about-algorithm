#include<iostream>
#include<algorithm>
#include<vector>
#define P(A) A=-~A
typedef long long LL;
#define NUMBER1 100000
std::vector<int>e[NUMBER1+5];
int n,m,f[NUMBER1+5];
bool visit[NUMBER1+5];
void dfs(int u,int md){
	if(visit[u])return;
	visit[u]=true,f[u]=md;
	for(auto v:e[u])
		dfs(v,md);
}
signed main(){
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin>>n>>m;
	for(int i=1,u,v;i<=m;P(i)){
		std::cin>>u>>v;
		e[v].push_back(u);
	}
	for(int i=n;i;--i)dfs(i,i);
	for(int i=1;i<=n;P(i))std::cout<<f[i]<<' ';
	return 0;
}
