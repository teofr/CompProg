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
#define debug(v) //cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif


int main() {
	tint q;
	cin >> q;

	forn(i, q){
		tint n, m ,k;
		cin >> n >> m >> k;

		tint mind, minh;
		mind = min(n, m);
		minh = max(n, m) - mind;
		debug(mind);
		mind += (minh >> 1) << 1;
		minh = minh % 2;
		debug(mind);
		debug(minh);

		k -= mind + minh;
		if (k < 0){
			cout << -1 << endl;
			continue;
		}
		debug(mind);

		mind += (k>>1)<<1;
		k = k%2;
		if (k == 1){
			if (minh > 0){

			mind++;
			} else {
				mind--;
			}
		} 

		cout << mind << endl;


	}


	return 0;
}
