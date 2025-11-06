#include<iostream>
#include<vector>
#define P(A) A=-~A
typedef long long LL;
int n,ans(1e9);
std::vector<std::vector<int>>e;
std::vector<int>sum,f;
void dfs1(int u,int fa,int len){
	f[1]+=len;
	for(auto v:e[u])
		if(v^fa){
			dfs1(v,u,len+1);
			sum[u]+=sum[v];
		}
}
void dfs2(int u,int fa){
	ans=std::min(ans,f[u]);
	for(auto v:e[u])
		if(v^fa){
			f[v]=f[u]+sum[1]-(sum[v]<<1);
			dfs2(v,u);
		}
}
signed main(){
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin>>n;
	sum.assign(n+1,1);
	sum[0]=0;
	e.assign(n+1,std::vector<int>());
	f.assign(n+1,0);
	for(int i=1,u,v;i<n;P(i)){
		std::cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1,0,0);
	dfs2(1,0);
	for(int i=1;i<=n;P(i))
		if(ans==f[i]){
			std::cout<<i<<' ';
			break;
		}
	std::cout<<ans;
	return 0;
}
