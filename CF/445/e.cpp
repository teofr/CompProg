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

#define MOD 1000000007

int main() {
	tint n, k;
	cin >> n >> k;

	tint res = 0;

	for (int h = 1; h < n; h++){
		//si h es la respuesta
		tint formas = 0;
		if (h - 1 >= k) formas += comb[h-1][k];

		// cualquier perm de esos
		formas = (formas * fact[k]) % MOD;

		// me quedan h - 1 - k sobre los cuales elegir
		// para cada subconjunto que mande a cada lado, tengo las permutaciones
		formas = (formas * ) % MOD;
		formas = (formas * (1 << (h-1-k))) % MOD;
	}


	return 0;
}
