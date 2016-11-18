//#include "../../stdc++.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define mp make_pair
#define snd second
#define fst first

using namespace std;

vector<int> col;
vector<vector<int>> adj;
vector<int> vis;
vector<int>cant;
vector<int> cambiados;

pair<int, int> dfs(int s){
	auto res=mp(1,col[s]);
	cambiados.pb(col[s]);
	cant[col[s]]++;
	vis[s]=1;

	for (int v:adj[s]){
		if(!vis[v]){
			auto cur=dfs(v);
			res.fst+=cur.fst;
			res.snd=(cant[res.snd]>=cant[cur.snd]?res.snd:cur.snd);
		}
	}

	return res;

}

int main() {

	int n,m,k;
	cin>>n>>m>>k;

	col=vector<int>(n,0);
	adj=vector<vector<int>> (n,vector<int> (0));
	vis=vector<int> (n,0);
	cant=vector<int> (k,0);
	forn(i,n){
		cin>>col[i];
		col[i]--;
	}
	forn(i,m){
		int a,b;
		cin>>a>>b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	int i=0;
	int res=0;
	while(i<n){

		auto cur=dfs(i);
		int curres=cur.fst-cant[cur.snd];
		res+=curres;
		for(auto j:cambiados){
			cant[j]=0;
		}
		cambiados.clear();

		while(i<n && vis[i]) i++;
	}

	cout<<res<<endl;

	return 0;
}
