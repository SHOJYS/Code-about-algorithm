#include<iostream>
#include<vector>
#include<queue>
#define P(A) A=-~A
typedef long long LL;
#define NUMBER1 5000
std::vector<int>e[NUMBER1+5];
const int mod=80112002;
int in[NUMBER1+5],out[NUMBER1+5],f[NUMBER1+5];
signed main(){
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	int n,m,ans(0);
	std::cin>>n>>m;
	for(int u,v;m--;){
		std::cin>>u>>v;
		e[u].push_back(v);
		P(out[u]);P(in[v]);
	}
	std::vector<int>end;
	std::queue<int>q;
	for(int i=1;i<=n;P(i)){
		if(!in[i])q.push(i),f[i]=1;
		else if(!out[i])end.push_back(i);;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:e[u]){
			if(!(--in[v]))q.push(v);
			f[v]=(f[u]+f[v])%mod;
		}
	}
	for(auto x:end)ans=(ans+f[x])%mod;
	std::cout<<ans;
	return 0;
}
