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

	vector<int> a(n);
		vector<int> b(n);

	forn(i, n){
		char c;
		cin >> c;
		a[i] = (c == '0' ? 0 : 1);
	}

	forn(i, n){
		char c;
		cin >> c;
		b[i] = (c == '0' ? 0 : 1);
	}

	vector<int> dp(n + 1, -1);

	dp[n] = 0;
	dp[n-1] = (b[n-1] == a[n-1] ? 0 : 1);


	for (int i = n-2; i>=0; i--){
		if (a[i] == b[i]){
			dp[i] = dp[i+1];
		}else{
			if (a[i] == b[i+1] and b[i] == a[i+1]){
				dp[i] = min(1+dp[i+1], 1 + dp[i+2]);

			} else {
				dp[i] = dp[i+1] + 1;
				
			}
		}
		debug(dp[i]);
	}

	cout << dp[0] << endl;
	return 0;
}
