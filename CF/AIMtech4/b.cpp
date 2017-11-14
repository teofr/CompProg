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

int main() {

	int n, m;
	cin>>n>>m;

	//vector<pair<int, int> > rows(n);
	//vector<pair<int, int> > cols(m);

	vector<vector<int> > tbl(n, vector<int> (m));
	forn(i,n){
		forn(j, m){
			cin>>tbl[i][j];
		}
	}

	long long res = -n*m;

	forn(i, n){
		int b = 0, w = 0;

		forn(j, m){
			if (tbl[i][j]) b++;
			else w++;
		}

		res += (((long long)1)<<b) - 1;
		res += (((long long)1)<<w) - 1;
	}

	forn(j, m){
		int b = 0, w = 0;

		forn(i, n){
			if (tbl[i][j]) b++;
			else w++;
		}

		res += (((long long)1)<<b) - 1;
		res += (((long long)1)<<w) - 1;
	}

	cout<<res<<endl;


	return 0;
}
