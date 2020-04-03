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

map<tuple<tint, tint, int>, tint> memo;

const tint mod = 1e9 + 7;

tint solve(tint i, tint j, int np){
	// Matching maximo para el subarbol que tiene i chabones abiertos,
	// que puede abrir j más y si el nodo raíz está ocupado
	if (i < 0 or j < 0) return -np;
	if (i == 0 and j == 0) return 0;
	auto it = memo.find(tuple<tint, tint, int>(i, j, np));
	if (it != memo.end()){
		return it->snd;
	}
	tint ans;
	if (np){
		ans =  solve(i-1, j, 0) + solve(i+1, j-1, 0);
	}else{
		// Uso alguna de las dos opciones
		ans = 1 + max(solve(i-1, j, 0) + solve(i+1, j-1, 1),
					solve(i-1, j, 1) + solve(i+1, j-1, 0));
		// no uso ninguna
		ans = max(ans, solve(i-1, j, 0) + solve(i+1, j-1, 0));
	}
	memo[tuple<tint, tint, int>(i, j, np)] = ans % mod;
	return ans % mod;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	tint n;
	cin >> n;

	cout << solve(0, n, 0) << endl;


	return 0;
}
