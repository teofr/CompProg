#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i = (tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define debug(v) cerr << #v << " = " << (v) << endl;
#define pb push_back
#define mp make_pair

int main() {
	int n;
	cin>>n;
	vector<vector<double> > p (1<<n, vector<double> (1<<n, 0.0));
	forn(i, 1<<n){
		forn(j, 1<<n){
			cin>>p[i][j];
			p[i][j] = p[i][j]/100.0;
		}
	}

	vector<vector<double> > dp (1<<n, vector<double> (n+1, 0.0));
	vector<vector<double> > llegar (1<<n, vector<double> (n+1, 0.0));

	forn(i, 1<<n){
		llegar[i][0] = 1.0;
	}

	forsn (j, 1, n+1){
		forn(i, 1<<n){
			int desde = ((i>>(j-1)) ^ 1)<<(j-1);
			int hasta = desde + (1<<(j-1));
			//debug(i); debug(j);

			forsn (c, desde, hasta){
				llegar[i][j] += llegar[c][j-1]*p[i][c];
			}
			llegar [i][j] *= llegar[i][j-1];
			//debug(llegar[i][j]);
		}
	}

	double res = 0;

	forsn (j, 1, n+1){
		forn(i, 1<<n){
			int desde = ((i>>(j-1)) ^ 1)<<(j-1);
			int hasta = desde + (1<<(j-1));
			//debug(i);
			//debug(j);

			//debug(desde);
			//debug(hasta);
			double mejCon = 0.0;

			forsn (c, desde, hasta){
				dp[i][j] += (1<<(j-1))*p[i][c]*llegar[i][j-1]*llegar[c][j-1];
				mejCon = max(mejCon, dp[c][j-1]);
			}
			dp[i][j] += mejCon + dp[i][j-1];
			//debug(dp[i][j]);

			if (j == n){
				res = max(res, dp[i][j]);
			}
		}
	}

	cout<<setprecision(12) << fixed << res<<endl;
	return 0;
}
