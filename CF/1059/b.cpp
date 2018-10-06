#include <bits/stdc++.h>
using namespace std;
#define tint long long
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

int firma[1005][1005];
int pinta[1005][1005];

int main() {
	tint n, m;
	cin >> n >> m;

	forn(i, n+3) forn(j, m+3) firma[i][j] = 0;
	forn(i, n+3) forn(j, m+3) pinta[i][j] = 0;

	forsn(i, 1, n+1){
		forsn(j, 1, m+1){
			char a;
			cin >> a;
			if (a == '#') firma[i][j]++;

			// if (firma[i][j] > 0){
			// 	if (i + 2 < n and j + 2 < m){
			// 		forn(ii, 3){

			// 			forn(jj, 3){
			// 				firma[i+ii][j+jj]--;
			// 			}
			// 		}
			// 		firma[i+1][j+1]++;
			// 	}else{
			// 		cout << "NO" << endl;
			// 		return 0;
			// 	}
			// }

		}
	}

	vector<int> dx = {1, 1, 1, 0, 0, -1, -1, -1};
	vector<int> dy = {1, 0, -1, 1, -1, 1, 0, -1};

	forsn(i, 1, n+1){
		forsn(j, 1, m+1){
			bool out = true;
			forn(k, 8){
				if (firma[i + dx[k]][j + dy[k]] < 1){
					out = false;
					break;
				}	
			}

			if (out){
				debug(i);
				debug(j);
				forn(k, 8){
					pinta[i + dx[k]][j + dy[k]]++;
				}
			}
			

			// if (firma[i][j] > 0){
			// 	if (i + 2 < n and j + 2 < m){
			// 		forn(ii, 3){

			// 			forn(jj, 3){
			// 				firma[i+ii][j+jj]--;
			// 			}
			// 		}
			// 		firma[i+1][j+1]++;
			// 	}else{
			// 		cout << "NO" << endl;
			// 		return 0;
			// 	}
			// }

		}
	}
	forsn(i, 1, n+1){
		forsn(j, 1, m+1){
			debug(firma[i][j]);
		}
	}

	forsn(i, 1, n+1){
		forsn(j, 1, m+1){
			debug(pinta[i][j]);
		}
	}

	forsn(i, 1, n+1){
		forsn(j, 1, m+1){
			if (firma[i][j] > 0 and pinta[i][j] < 1){
				debug(i);
				debug(j);
				cout << "NO" << endl;
				return 0;
			}
		}
	}


cout << "YES" << endl;

	return 0;
}
