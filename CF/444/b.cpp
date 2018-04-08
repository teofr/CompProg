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

	vector<vector<int> > cubes(3, vector<int> (6, 0));

	map<int, int> app;
	forn(i, n){
		forn(j, 6){
			cin >> cubes[i][j];
			app[cubes[i][j]] = 1;
		}
	}

	forn(i, 6){
		if (n >= 2){
			forn(j, 6){
				if (cubes[0][i] != 0){
					app[cubes[0][i]*10 + cubes[1][j]] = 1;
					if (n >= 3) app[cubes[0][i]*10 + cubes[2][j]] = 1;
				}
				if (cubes[1][i] != 0){
					app[cubes[1][i]*10 + cubes[0][j]] = 1;
					if (n >= 3) app[cubes[1][i]*10 + cubes[2][j]] = 1;
				}
				if (n >= 3 and cubes[2][i] != 0){
					app[cubes[2][i]*10 + cubes[1][j]] = 1;
					app[cubes[2][i]*10 + cubes[0][j]] = 1;
				}

			}
		}
	}


	forn(i, 6){
		if (n >= 2){
			forn(j, 6){
				if (n >=3){
					forn(h, 6){
						app[cubes[0][i]*100 + cubes[1][j]*10 + cubes[2][h]] = 1;
						app[cubes[0][i]*100 + cubes[2][j]*10 + cubes[1][h]] = 1;
						app[cubes[1][i]*100 + cubes[0][j]*10 + cubes[2][h]] = 1;
						app[cubes[1][i]*100 + cubes[2][j]*10 + cubes[0][h]] = 1;
						app[cubes[2][i]*100 + cubes[0][j]*10 + cubes[1][h]] = 1;
						app[cubes[2][i]*100 + cubes[1][j]*10 + cubes[0][h]] = 1;
					}
				}
			}
		}
		//app[res] = 1;
	}

	auto cur = app.find(1);

	int largest = 0;
	while(cur != app.end() and cur->fst == largest+1){
		debug(cur->fst);
		largest = cur->fst;
		cur++;
	}

	cout << largest << endl;


	return 0;
}
