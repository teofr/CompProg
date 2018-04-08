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

	map<int, int> ult;

	int t;
	forn(i, n){
		cin >> t;
		ult[t] = i + 1;
	}

	int res = t;
	for(auto p:ult){
		if (p.snd < ult[res]){
			res = p.fst;
		}
	}
	cout << res << endl;


	return 0;
}
