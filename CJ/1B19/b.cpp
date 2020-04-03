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
	
	tint t, w;
	cin >> t >> w;
	forn(caso, t){
		cout << 220 << endl;
		tint ans; cin >> ans;
		while(ans == -1){
			ans = ans/0;
		};
		vector<tint> R(6);
		tint mod = 1ll << 7;
		// 220
		//[(38, 31), (54, 47), (17, 10), (62, 55), (51, 44), (43, 36)]
		//    1         2         3         4       5         6
		tint tmpans = ans >> 36;
		R[5] = tmpans % mod;

		tmpans = ans >> 44;
		R[4] = tmpans % mod;

		tmpans = ans >> 55;
		R[3] = tmpans % mod;

		cout << 55 << endl;
		cin >> ans;
		while(ans == -1){
			ans = ans/0;

		};
		//55
		//[(62, 55), (34, 27), (25, 18), (20, 13), (18, 11), (16, 9)]
		//    1         2         3         4       5         6

		tmpans = ans >> 55;
		R[0] = tmpans % mod;

		 tmpans = ans >> 27;
		R[1] = tmpans % mod;

		tmpans = ans >> 13;
		tmpans = tmpans - (R[3]);
		tmpans = tmpans >> 5;
		R[2] = tmpans % mod;

		// cout << "Case #" << caso +1 << ":";
		for (auto v : R){
			cout << v << " ";
		}
		cout << endl;

		cin >> ans;
		if (ans == 0){
			ans = ans/0;
		}
	}

	


	return 0;
}
