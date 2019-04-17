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

	ans += 2*n; k -= 2;

	idx++;
	while (k > 0 and idx < s.size()){
		if (k > 1 and s[idx] == 'a' and t[idx] == 'b'){
			tint nnn = nn - idx;
			// tint cant = 1 << (nn - idx - 1);
			// tint sumans = (1 << (nn - idx)) - 1;
			// debug(cant);
			// debug(sumans);
			// if (k >= cant){
				// k -= cant;
				// ans += sumans;
			// }else{

			ans += 2*nnn;
			k-=2;
			nnn--;
			tint pot = 2;
			while (k > 0 and nnn > 0){
				debug(nnn);
				ans += min(k, pot)*nnn;
				k = max(0ll, k - pot);
				pot *= 2;
				// if (pot == 0) pot = 1;

				nnn--;
			}
			debug(nnn);
			idx++;
			continue;
		}
		if (s[idx] == 'a'){
			tint nnn = nn - idx;
			// tint cant = 1 << (nn - idx - 1);
			// tint sumans = (1 << (nn - idx)) - 1;
			// debug(cant);
			// debug(sumans);
			// if (k >= cant){
				// k -= cant;
				// ans += sumans;
			// }else{
				ans += nnn;
				k--;
				nnn--;
				tint pot = 1;
				while (k > 0 and nnn > 0){
					debug(nnn);
					ans += min(k, pot)*nnn;
					k = max(0ll, k - pot);
					pot *= 2;
					// if (pot == 0) pot = 1;

					nnn--;
				}
				debug(nnn);
			// }
		}

		if (k > 0 and t[idx] == 'b'){
			tint nnn = nn - idx;
			// tint curr = nn - idx - 1ll;
			// tint cant = 1ll << (nn - idx - 1ll);
			// tint sumans = (1ll << (nn - idx)) - 1ll;
			// debug(cant);
			// debug(sumans);
			// if (k >= cant){
				// k -= cant;
				// ans += sumans;
			// }else{
				ans += nnn;
				k--;
				nnn--;
				tint pot = 1;
				while (k > 0 and nnn > 0){
					debug(nnn);
					ans += min(k, pot)*nnn;
					k = max(0ll, k - pot);
					pot *= 2;
					// if (pot == 0) pot = 1;

					nnn--;
				}
				debug(nnn);
			// }
		}
		idx++;

	}

	cout << ans << endl;




	return 0;
}
