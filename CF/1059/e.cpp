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

struct lift{
		tint node;
		tint s;
	};
struct node{
	tint w;
	vector<int> ady;

	

	vector<lift> l;
};


vector<node> g;

lift lift(int node, int up){
	// while(node == -1);
	if (up == 0){
		return {node, 0};
	}
	int z =  31 - __builtin_clz(up);

	// while (-1 ==  g[node].l[z].node);

	assert(z < g[node].l.size());

	auto res = lift(g[node].l[z].node, up ^ (1 << z));
	res.s += g[node].l[z].s;

	return res;
}

tint cnt = 0;
tint n, l, s;

int dfs(int node, int p, tint lev){
	int up = 2;
	g[node].l.pb({p, g[node].w});
	while(up - 1 <= lev){
		g[node].l.pb(lift(p, up-1));
		g[node].l.back().s += g[node].w;
		up = up << 1;
	}

	int maxup = 0;
	for(auto n : g[node].ady){
		int val = dfs(n, node, lev+1) - 1;
		// if (val > 0 and maxup > 0) cnt++;
		maxup = max(maxup, val);
	}

	// cnt += max(0, (int)g[node].ady.size() - 1);

	if (!maxup){
		cnt++;
		int lo = 1, hi = min(l, lev+1)+1;

		while(lo + 1 < hi){
			int m = (lo + hi)/2;
			auto li = lift(node, m);
			debug(m);
			debug(li.s);

			if (s < li.s){
				hi = m -1;
			}else{
				lo = m;
			}


		}

		maxup = lo;
			debug(node);
	debug(p);
	debug(lev);
	debug(lo);		
		return lo;
	}
	debug(node);
	debug(p);
	debug(lev);
	debug(maxup);
	return maxup;

}

int main() {
	cin >> n >> l >> s;

	g = vector<node>(n);

	forn(i, n){
		cin >> g[i].w;
		if (g[i].w > s){
			cout << -1 << endl;
			return 0;
		}
	}

	forsn(i, 1, n){
		int p;
		cin >> p;
		p--;
		g[p].ady.pb(i);
	}

	dfs(0, -1, 0);

	forn(i, n){
		debug(i);
		for(auto l : g[i].l){
			debug(l.s);
			debug(l.node);
		}
	}

	cout << cnt << endl;


	return 0;
}
