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
	ios::sync_with_stdio(0);
	cin.tie(0);
	tint n ,k , nn;
	cin >> n >> k;
	nn = n;

	string s, t;
	cin >> s >> t;
	if (k == 1){
		cout << n << endl;
		return 0;
	}

	tint idx = 0;
	tint ans = 0;





	while (n > 0 and s[idx] == t[idx]){
		idx++; n--; ans++;
	}

	if (n == 0){
		cout << ans << endl;
		return 0;
	}

	tint internas = 0;
	tint puestas = 0;
	ans += 2*n; k -= 2;
	idx++;
	const tint mod = 1e9 + 2;

	while(idx < nn){
		internas *= 2;
		if (s[idx] == 'a'){
			internas++;
		}
		if (t[idx] == 'b'){
			internas++;
		}
		internas = min(internas, mod);



		puestas += min(k - puestas, internas - puestas);
		ans += puestas;
		// debug(k);
		// debug(idx);
		// debug(internas);
		// debug(puestas);
		idx++;


	}
	cout << ans << endl;
	return 0;


}
