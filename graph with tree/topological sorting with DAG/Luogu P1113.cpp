#include<iostream>
#include<vector>
#define P(A) A=-~A
typedef long long LL;
#define NUMBER1 10000
int n,f[NUMBER1+5],a[NUMBER1+5],ou[NUMBER1+5],ans(0);
std::vector<int>e[NUMBER1+5];
std::vector<int>node;
void dfs(int u){
	if(f[u])return;
	for(auto v:e[u]){
		dfs(v);
		f[u]=std::max(f[u],f[v]);
	}
	f[u]+=a[u];
	ans=std::max(ans,f[u]);
	return;
}
signed main(){
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin>>n;
	for(int i=1,v,u;i<=n;P(i)){
		std::cin>>v>>a[i]>>u;
		while(u){
			e[u].push_back(v);
			P(ou[v]);
			std::cin>>u;
		}
	}
	for(int i=1;i<=n;P(i))
		if(!ou[i])node.push_back(i);
	for(auto u:node)dfs(u);
	std::cout<<ans;
	return 0;
}
