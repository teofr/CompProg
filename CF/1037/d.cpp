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
vector<int> pos;

vector<int> res, test;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	tint n;
	cin >> n;

	adj = vector<vector<int>> (n, vector<int>());
	pos = vector<int> (n, -1);

	forn(i, n-1){
		int x, y;
		cin >> x>> y;
		x--; y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	forn(i, n){
		int x; cin >> x;
		x--;

		test.pb(x);

		pos[x] = i;
	}

	// sort using a custom function object
    struct {
        bool operator()(int a, int b) const
        {   
            return pos[a] < pos[b];
        }   
    } customLess;

    forn(i,n){
    	sort(adj[i].begin(), adj[i].end(), customLess);
    }

    queue<int> q;
    q.push(0);

    vector<int> vis (n, 0);
    vis[0] = 1;

    while (not q.empty()){
    	int next = q.front(); q.pop();
    	res.pb(next);

    	for (auto p:adj[next]){
    		if (not vis[p]){
    			q.push(p);
    			vis[p] = 1;
    		}
    	}
    }

    forn(i,n){
    	if (test[i] != res[i]){
    		cout << "No" << endl;
    		return 0;
    	}
    }

    cout << "Yes" << endl;

	return 0;
}
