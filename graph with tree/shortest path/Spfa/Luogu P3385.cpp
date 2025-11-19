#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define P(A) A=-~A
typedef std::pair<int,int> PII;
typedef long long LL;
inline void solve(){
	int n,m;
	std::cin>>n>>m;
	std::vector<std::vector<PII>>e;
	std::vector<bool>visit;
	std::vector<LL>dis;
	std::vector<int>cnt;
	e.assign(n+1,std::vector<PII>());
	visit.assign(n+1,false);
	dis.assign(n+1,1e18);
	cnt.assign(n+1,0);
	for(int u,v,w;m--;){
		std::cin>>u>>v>>w;
		e[u].push_back({v,w});
		if(w>=0)e[v].push_back({u,w});
	}
	std::queue<int>q;
	q.push(1);
	visit[1]=true,dis[1]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		visit[u]=false;
		for(auto [v,w]:e[u]){
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!visit[v]){
					cnt[v]=cnt[u]+1;
					if(cnt[v]>=n)return std::cout<<"YES\n",void(0);
					q.push(v),visit[v]=true;
				}
			}
		}
	}
	std::cout<<"NO\n";
}
signed main(){
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	int T;
	std::cin>>T;
	while(T--)solve();
	return 0;
}
