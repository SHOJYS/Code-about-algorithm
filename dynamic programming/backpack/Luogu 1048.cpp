#include<iostream>
#include<algorithm>
typedef std::pair<int,int> PII;
#define P(A) A=-~A
typedef long long LL;
#define NUMBER1 1000
#define NUMBER2 400
int n,f[NUMBER1+5],v;
PII a[NUMBER2+5];
signed main(){
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin>>v>>n;
	for(int i=1;i<=n;P(i))std::cin>>a[i].first>>a[i].second;
	for(int i=1;i<=n;P(i))
		for(int j=v;j>=a[i].first;--j)f[j]=std::max(f[j],f[j-a[i].first]+a[i].second);
	std::cout<<f[v];
	return 0;
}
