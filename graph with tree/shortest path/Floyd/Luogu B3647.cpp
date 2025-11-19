#include<iostream>
#define P(A) A=-~A
typedef long long LL;
#define NUMBER1 100
const int INF=1e9;
int f[NUMBER1+5][NUMBER1+5];
signed main(){
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	int n,m;
	std::cin>>n>>m;
	for(int i=1;i<=n;P(i))
		for(int j=1;j<=n;P(j))
			if(i^j)f[i][j]=INF;
	for(int u,v,w;m--;){
		std::cin>>u>>v>>w;
		f[u][v]=std::min(f[u][v],w);
		f[v][u]=std::min(f[v][u],w);
	}
	for(int k=1;k<=n;P(k))
		for(int i=1;i<=n;P(i))
			for(int j=1;j<=n;P(j))
				if(f[i][k]^INF&&f[k][j]^INF)
					f[i][j]=std::min(f[i][j],f[i][k]+f[k][j]);
	for(int i=1;i<=n;P(i))
		for(int j=1;j<=n;P(j))
			std::cout<<f[i][j]<<" \n"[n==j];
	return 0;
}
