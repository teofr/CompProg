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
	tint n, k;
	cin >> n >> k;
	vector<tint> axor(n+1, 0);

	forsn(i, 1, n+1){
		cin >> axor[i];
		axor[i] = axor[i] ^ axor[i-1];
	}

	unordered_map<tint, tint> apps;

	tint ans = 0;
	tint xors = 0;

	for (int i = n; i > 0; i--){
		// if (xors){
			// apps[axor[i] ^ ((1ll << k) - 1)]++;
		// }else{
			apps[axor[i]]++;
		// }
		debug(i);
		debug(xors);
		debug(axor[i-1]);
		debug(axor[i-1] ^ ((1ll << k) - 1));

		tint asi = (n-i) - apps[axor[i-1]] + 1;
		tint asa = (n-i) - apps[axor[i-1] ^ ((1ll << k) - 1)] + 1;
		debug(asi); debug(asa);
		if (asi > asa){
			// apps[axor[i]]++;
			ans += asi;
			// if (xors){}
		}else{
			ans += asa;
			// apps[axor[i]]--; // guarda
			// apps[axor[i] ^ ((1ll << k) - 1)]++;
			axor[i-1] = axor[i-1] ^ ((1ll << k) - 1);
			// xors++;
			// xors %= 2;
		}
		debug(axor[i-1]);
	}

	cout << ans << endl;


	return 0;
}
