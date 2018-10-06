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

vector<set<int> > ady;
vector<int> col;
vector<int> expe;


int dfs(int cur, int free=0){
	int ans = 0;
	if (expe[cur] != free){
		ans++;
		free = expe[cur];
	}

	col[cur] = expe[cur];

	for (auto n:ady[cur]){
		if (col[n] == 0){
			ans += dfs(n, free);
		}
	}
	return ans;
}

int main() {
	tint n;
	cin >> n;
	ady = vector<set<int> > (n, set<int> ());
	forn(i, n-1){
		int pi;
		cin >> pi;
		pi--;
		ady[i+1].insert(pi);
		ady[pi].insert(i+1);
	}
	debug(n);
	col = vector<int> (n, 0);
	expe = vector<int> (n, 0);
	forn(j, n){
		int c;
		cin >> c;
		expe[j] = c;
	}
	debug(n);

	cout << dfs(0, 0) << endl;

	return 0;
}
