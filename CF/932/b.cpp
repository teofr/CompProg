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

int f(int x){
	int res = 1;

	while (x){
		if (x%10 != 0){
			res *= (x%10);
		}
		x = x/10;
	}
	return res;
}


int main() {
	int to = 1000010;

	vector<vector<int> > dp(11, vector<int> (to, 0));
	vector<int> g(to, 0);
	g[0] = 0;
	g[1] = 1;
	forn (i, 10){
		g[i] = i;
	}

	forsn (i, 10, to){
		g[i] = g[f(i)];
		debug(i);
		debug(g[i]);
	}

	dp[0][0] = 1;
	forsn (i,1, to){
		forn (j, 10){
			dp[j][i] = dp[j][i-1];
		}

		dp[g[i]][i]++;
	}

	int q;
	cin >> q;

	forn (i, q){
		int l, r, k;
		cin >> l >> r >> k;
		cout << dp[k][r] - dp[k][l-1] << endl;
	}


	return 0;
}
