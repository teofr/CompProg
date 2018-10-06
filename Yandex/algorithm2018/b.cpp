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

	vector<vector<int> > mat (n, vector<int> (n, 0));

	map<int, pair<int, int> > app;

	forn(i, 2*n){
		vector<int> row(n);

		int r = 0,c = 0;

		forn(j,n){
			cin >> row[j];
			if (app.find(row[j]) != app.end()){
				r = app.find(row[j]).fst;
				c = app.find(row[j]).snd;
			}
		}

		int vert = 0;

		int k = 0;

		while (r - k >= 0){
			if (mat[r-k] == 0){
				vert = 1;
			}
			k++;
		}

		k=0;

		while (r+k < n){
			if (mat[r+k] == 0){
				vert = 1;
			}
			k++;
		}

		if (vert){
			forn(j, n){
				
			}
		}


	}


	return 0;
}
