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
	int n, a, b, c, d, start, len;
	cin >> n >> a >> b >> c >> d >> start >> len;

	vector<ii> ev(n);
	forn(i, n){
		int t, q;
		cin >> t >> q;
		ev[i] = {t, q};
	}

	int left = 0, right = 0;

	int sofar = 0;
	while(right < n and ev[right].fst <= len){
		sofar +=
	}

	return 0;
}
