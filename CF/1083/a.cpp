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


vector<vector<pair<tint, tint>>> g;

vector<tint> w;


tint best;

tint dfs(int n, int p = -1){
	tint lbest1 = w[n], lbest2 = 0;
	for (auto h : g[n]){
		if (h.fst != p){
			tint res = dfs(h.fst, n) - h.snd + w[n];
			if (res  >= lbest1){
				lbest2 = lbest1;
				lbest1 = res ;
			}else if (res  > lbest2){
				lbest2 = res ;
			}

		}
	}

	best = max(best, lbest1);

	best = max(best, lbest1 + lbest2 - w[n]);

	return lbest1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	tint n;
	cin >> n;
	w.resize(n);
	g.resize(n);

	forn(i, n){
		cin >> w[i];
	}

	best = -1000;

	forn(i, n - 1){
		tint u, v, c;
		cin >> u >> v >> c;
		u--; v--;
		g[u].pb({v, c});
		g[v].pb({u, c});
	}

	dfs(0);

	cout << best << endl;



	return 0;
}
