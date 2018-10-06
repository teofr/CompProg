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
	tint n, a, b;
	cin >> n >> a>> b;

	tint ma, mi;
	ma = max(a, b);
	mi = min(a, b);

 	tint seated = 0;
	forn(i,n){
		char t ;
		cin >> t;


		while(t == '.' and i < n){
			if (ma != 0){
				ma--;
				seated++;

			}
			a = ma;
			ma = mi;
			mi = a;
			i++;
			if (i<n)	cin >> t;
		}

		a = ma;
		ma = max(mi, ma);
		mi = min(mi, a);
	}
	cout<< seated << endl;


	return 0;
}
