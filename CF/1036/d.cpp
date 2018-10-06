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

	tint n;
	cin >> n;

	vector<tint> a, b;
	a = vector<tint> (n+1, 0);
	a[0] = (0);

	forn(i, n){
		tint t;
		cin >> t;
		a[i+1] = (t + a[i]);
	}

	tint m;
	cin >> m;
	b = vector<tint> (m+1, 0);
	b[0] = (0);

	forn(i, m){
		tint t;
		cin >> t;
		b[i+1] = (t + b[i]);
	}

	if (a[n] != b[m]){
		cout << -1 << endl;
		return 0;
	}

	tint ans = 0;

	int na=1, nb=1;

	while (na <= n or nb <= m){
		if (a[na] == b[nb]){
			ans++;
			na++; nb++;
		}else if (a[na] < b[nb]){

			na++;
		}else{
			nb++;
		}


	}

	cout << ans << endl;
	return 0;
}
