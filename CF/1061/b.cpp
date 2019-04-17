#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define ii pair<tint,tint>
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define mp make_pair
#define fst first
#define snd second
#define pb push_back

#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	tint n,m;
	cin >> n >> m;
	vector<tint> a(n);
	map<tint, tint> ma;
	forn(i, n){
		cin >> a[i];
		ma[a[i]]++;
	}
	// ma[0] =

	sort(a.begin(), a.end());
	tint maxi = a[n-1];

	auto it = a.begin();
	tint ans = 0, maxsofar = 0;
	// while (it != a.end()){

	// }

	for (auto i : ma){
		maxsofar = min(i.fst, maxsofar + i.snd);
		ans += (i.fst - 1)*i.snd;
	}

	cout << ans - (maxi - maxsofar) << endl;


	return 0;
}
