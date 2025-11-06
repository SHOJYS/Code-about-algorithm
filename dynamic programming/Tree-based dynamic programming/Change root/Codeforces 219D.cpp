#include<iostream>
#include<vector>
#include<algorithm>
#define P(A) A=-~A
#define NUMBER1 200000
typedef long long LL;
typedef std::pair<int,int> PII;
int n,tot(0),f[NUMBER1+5];
std::vector<std::vector<PII>>e;
void dfs1(int u,int fa){
	for(auto [v,w]:e[u])
		if(v^fa){
			dfs1(v,u);
			f[u]+=f[v]+w;
		}
}
void dfs2(int u,int fa){
	for(auto [v,w]:e[u])
		if(v^fa){
			f[v]=f[u]+(w?-1:1);
			dfs2(v,u);
		}
}
signed main(){
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin>>n;
	e.assign(n+1,std::vector<PII>());
	int md(1e9);
	for(int u,v,i(1);i<n;P(i)){
		std::cin>>u>>v;
		e[u].push_back({v,0});
		e[v].push_back({u,1});
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;P(i))md=std::min(md,f[i]);
	std::cout<<md<<'\n';
	for(int i=1;i<=n;P(i))
		if(md==f[i])std::cout<<i<<' ';
	return 0;
}
