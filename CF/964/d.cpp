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


vector<vector<int>> adj;
vector<int> deg;
vector<int> prop;
vector<int> v;

int main() {
	tint n;
	cin >> n;

	adj = vector<vector<int> > (n, vector<int> (0));
	v = deg = prop = vector<int> (n, 0);

	forn(i, n){
		int pi;
		cin >> pi;
		if (pi != 0){
			pi--;
			adj[i].pb(pi);
			adj[pi].pb(i);
			deg[i]++;
			deg[pi]++;
		}
	}

	set<int> valen;

	forn(i,n){
		int propiedad = 2;
		for (auto n : adj[i]){
			if (deg[n] > 1){
				propiedad--;
			}
		}

		if (propiedad > 0 and deg[i]%2 == 0){
			prop[i] = 1;
			valen.insert(i);
		}
	}

	vector<int> ans;

	while (not valen.empty()){
		int tmp = *valen.begin();
		valen.erase(valen.begin());
		ans.pb(tmp);
		v[tmp] = 1;
		for(auto n :adj[tmp]){
			if (v[n] == 1) continue;

			deg[n]--;
		}

		for (auto n : adj[tmp]){
			if (v[n] == 1) continue;

			int propiedad = 2;
			for (auto m : adj[n]){
				if (v[m]) continue;
				if (deg[m] > 1){
					propiedad--;
				}
			}

			if (propiedad > 0 and deg[n]%2 == 0){
				prop[n] = 1;
				valen.insert(n);
			}else{
				prop[n] = 0;
				valen.erase(n);
			}

		}
	}

	if (ans.size() == n){
		cout << "YES" << endl;
		for (auto n : ans){
			cout << n+1 << endl;
		}
	}else{
		cout << "NO" << endl;
	}



	return 0;
}
