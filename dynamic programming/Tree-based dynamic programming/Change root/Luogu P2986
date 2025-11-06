#include<iostream>
#include<vector>
#include<algorithm>
#define NUMBER1 100000
#define P(A) A=-~A
typedef long long LL;
struct EDGE{
	int to;
	LL w;
	EDGE *next;
	EDGE(){next=nullptr;}
}e[(NUMBER1<<1)+5],*head[NUMBER1+5];
int tot(0),n;
LL f[NUMBER1+5],sum[NUMBER1+5],c[NUMBER1+5],num(0);
inline void add(const int &u,const int &v,const int &w){EDGE *p=&e[++tot];p->to=v,p->w=w,p->next=head[u];head[u]=p;}
void dfs1(int u,int fa,LL len){
	sum[u]=c[u],f[1]+=len*c[u];
	for(EDGE *p=head[u];p;p=p->next)
		if(p->to^fa){
			dfs1(p->to,u,len+p->w);
			sum[u]+=sum[p->to];
		}
}
void dfs2(int u,int fa){
	for(EDGE *p=head[u];p;p=p->next)
		if(p->to^fa){
			f[p->to]=f[u]-sum[p->to]*p->w+(num-sum[p->to])*(p->w);
			dfs2(p->to,u);
		}
}
signed main(){
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin>>n;
	LL ans(9223372036854775807);
	for(int i=1;i<=n;P(i))std::cin>>c[i],num+=c[i];
	for(int i=1,u,v,w;i<n;P(i)){
		std::cin>>u>>v>>w;
		add(u,v,w);add(v,u,w);
	}
	dfs1(1,0,0);
	dfs2(1,0);
	for(int i=1;i<=n;P(i))ans=std::min(ans,f[i]);
	std::cout<<ans;
	return 0;
}
