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
	cin >> n >> a >> b;
	vector<int> c (n);
	forn(i, n){
		cin >> c[i];
	}

	tint ans = 0;
	forn(i, n/2){
		if (c[i] == 0){
			if (c[n-i-1] == 1){
				cout << -1 << endl;
				return 0;
			} else if (c[n-i-1] == 2){
				ans += a;
			}
		}else if (c[i] == 1){
			if (c[n-i-1] == 0){
				cout << -1 << endl;
				return 0;
			} else if (c[n-i-1] == 2){
				ans += b;
			}
		}else {
			if (c[n-i-1] == 0){
				ans += a;
			} else if (c[n-i-1] == 2){
				ans += 2*min(a, b);
			} else {
				ans += b;

			}
		}
	}

	if (n%2 == 1 and c[n/2] == 2){
		ans += min(a,b);
	}

	cout << ans << endl;

	return 0;
}
