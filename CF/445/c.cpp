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
	tint n;
	cin >> n;

	map<int, int> rep;

	forn(i, n){
		int t;
		cin >> t;
		rep[t]++;
	}

	int res = 1;

	for (auto p:rep){
		res += p.snd -1;
	}

	cout << res << endl;


	return 0;
}
