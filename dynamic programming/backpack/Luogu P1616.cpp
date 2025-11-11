#include<iostream>
#include<algorithm>
#define P(A) A=-~A
#define NUMBER1 10000000
#define NUMBER2 10000
typedef std::pair<int,int> PII;
typedef long long LL;
int n,v;
PII a[NUMBER2+5];
LL f[NUMBER1+5];
signed main(){
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin>>v>>n;
	for(int i=1;i<=n;P(i))std::cin>>a[i].first>>a[i].second;
	for(int i=1;i<=n;P(i))
		for(int j=a[i].first;j<=v;P(j))
			f[j]=std::max(f[j-a[i].first]+a[i].second,f[j]);
	std::cout<<f[v];
	return 0;
}
