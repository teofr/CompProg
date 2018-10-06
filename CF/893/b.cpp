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

	for (int k = 20; k >= 0; k--){
		tint prueba = 1 << (k+1);
		prueba--;
		prueba *= 1 << k;
		if (n % prueba == 0){
			cout << prueba << endl;
			return 0;
		}
	}


	return 0;
}
