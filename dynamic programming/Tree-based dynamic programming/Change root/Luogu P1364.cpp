#include<iostream>
#define P(A) A=-~A
#define NUMBER1 100
typedef long long LL;
struct EDGE{
	int to;
	EDGE *next;
	EDGE(){next=nullptr;}
}e[(NUMBER1<<2)+5],*head[NUMBER1+5];
LL f[NUMBER1+5],ans(1e18),sum[NUMBER1+5],t[NUMBER1+5];
int n,tot(0);
inline void add(const int &u,const int &v){EDGE *p=&e[++tot];p->to=v,p->next=head[u];head[u]=p;}
void dfs1(int u,int fa,int len){
	sum[u]=t[u],f[1]+=len*t[u];
	for(EDGE *p=head[u];p;p=p->next)
		if(fa^p->to){
			dfs1(p->to,u,len+1);
			sum[u]+=sum[p->to];
		}
}
void dfs2(int u,int fa){
	for(EDGE *p=head[u];p;p=p->next)
		if(fa^p->to){
			f[p->to]=f[u]+sum[1]-(sum[p->to]<<1);
			ans=std::min(ans,f[p->to]);
			dfs2(p->to,u);
		}
}
signed main(){
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin>>n;
	for(int i=1,a,b;i<=n;P(i)){
		std::cin>>t[i]>>a>>b;
		if(a)add(a,i),add(i,a);
		if(b)add(b,i),add(i,b);
	}
	dfs1(1,0,0);
	ans=f[1];
	dfs2(1,0);
	std::cout<<ans;
	return 0;
}
