//#include "../../stdc++.h"
#include <bits/stdc++.h>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define snd second
#define fst first
#define debug(a) cerr<< #a <<': '<<a<<endl

using namespace std;

vector<vector<int> > adj;

double dfs (int start, int father){
	int roads = (int) adj[start].size() - 1;
	if (father == -1) roads++;

	if (not roads){
		return 0.0;
	}

	double res = 0;

	for (auto x : adj[start]){
		if (x != father){
			res += (1.0+dfs(x, start)) / ((double) roads);
		}
	}

	return res;
}


int main() {

	int n;
	cin>>n;
	adj = vector<vector<int> > (n,vector<int> ());

	forn (i,n-1){
		int a, b;
		cin>>a>>b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	cout.precision(7);

	cout<<fixed<<dfs(0, -1)<<endl;

	return 0;
}
