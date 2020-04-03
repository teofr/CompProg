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
	
	tint n, m, ci, cp, ki, kp;
	ci = cp = ki = kp = 0;
	cin >> n >> m;
	forn(i, n){
		tint t; cin >> t;
		if (t%2 == 1){
			ci++;
		}else{
			cp++;
		}
	}

	forn(i, m){
		tint t; cin >> t;
		if (t%2 == 1){
			ki++;
		}else{
			kp++;
		}
	}

	cout << min(ki, cp) + min(kp, ci) << endl;


	return 0;
}
