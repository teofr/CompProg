#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i = (tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define debug(v) cerr << #v << " = " << (v) << endl;
#define pb push_back
#define mp make_pair

int gcd(int a, int b){
	if (b==0)
		return a;
	return gcd(b, a%b);
}

int main() {
	int n;
	cin>>n;
	int i = 1;
	auto ans = mp(1,n-1);
	n--;

	while (i<n){
		if (gcd(i, n) == 1){
			ans = mp(i, n);
		}
		i++;
		n--;
	}
	cout<<ans.fst<<' '<<ans.snd<<endl;
	return 0;
}
