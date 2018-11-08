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

string starti[300][300];
tint endi[300][300];
tint idx[300][300];


int main() {
	tint n, m;
	cin >> n >>m;
	stringstream ans;
	tint cnt = 0;



	forn(i, n){
		forn(j, m){
			cin >> starti[i][j];
			idx[i][j] = starti[i][j].size() - 1;
		}
	}

	vector<int> unos(m, 0), ceros(m, 0);

	forn(i, n) forn(j, m){
		if (i == 0){
			tint otro = 0;
			if (otro == j) otro++;
			for(int idx = starti[i][j].size() - 1; idx >= 0; idx--){
				if (starti[i][j][idx] == '0'){
					ceros[otro]++;
					ans << i+1 << ' ' << j+1 << ' ' << i+1 << ' ' << otro+1   << '\n';
					cnt++;
				}else{
					unos[j]++;
					cnt++;
					ans << i+1 << ' ' << j+1 << ' ' << 2 << ' ' << j+1   << '\n';
				}
			}

		}else if (i == 1){
			tint otro = 0;
			if (otro == j) otro++;
			for(int idx = starti[i][j].size() - 1; idx >= 0; idx--){
				if (starti[i][j][idx] == '0'){
					ceros[j]++;
					cnt++;
					ans << i+1 << ' ' << j+1 << ' ' << 1 << ' ' << j+1   << '\n';
				}else{
					unos[j]++;
					cnt++;
					ans << i+1 << ' ' << j+1 << ' ' << 2 << ' ' << otro+1   << '\n';
				}
			}


		}else{
			for(int idx = starti[i][j].size() - 1; idx >= 0; idx--){
				if (starti[i][j][idx] == '0'){
					ceros[j]++;
					cnt++;
					ans << i+1 << ' ' << j+1 << ' ' << 1 << ' ' << j+1   << '\n';
				}else{
					unos[j]++;
					cnt++;
					ans << i+1 << ' ' << j+1 << ' ' << 2 << ' ' << j+1   << '\n';
				}
			}
		}
	}

	vector<string> necesito(m);

	forn(i, n)
	forn(j, m){
		string t;
		cin >> t;
		if(i==n-1) reverse(t.begin(), t.end());
		endi[i][j] = t.size();
		necesito[j] += t;
	}

	int tiene1, tiene0;
	tiene1 = tiene0 = 0;

	while(tiene1 < unos.size() and unos[tiene1] == 0 ) tiene1++;
	while(tiene0 < ceros.size() and ceros[tiene0] == 0 ) tiene0++;

	forn(j, m){
		reverse(necesito[j].begin(), necesito[j].end());

		for (int idx = necesito[j].size() - 1; idx >=0; idx--){
			if (necesito[j][idx] == '0'){
					while(tiene0 < ceros.size() and ceros[tiene0] == 0 ) tiene0++;
					cnt++;
					cnt++;
					ans << 1 << ' ' << tiene0+1 << ' ' << 1 << ' ' << j+1   << '\n';
					ceros[tiene0]--;
					ans << 1 << ' ' << j+1 << ' ' << n << ' ' << j+1   << '\n';

			}else{
				while(tiene1 < unos.size() and unos[tiene1] == 0 ) tiene1++;

				ans << 2 << ' ' << tiene1+1 << ' ' << 2 << ' ' << j+1   << '\n';
					cnt++;
					cnt++;
					unos[tiene1]--;
					ans << 2 << ' ' << j+1 << ' ' << n << ' ' << j+1   << '\n';

			}
		}
	}


	forn(j, m) forn(i, n-1){
		forn(x, endi[i][j]){
			ans << n << ' ' << j+1 << ' ' << i+1 << ' ' << j+1   << '\n';

		}

	}

	cout << cnt << endl;

	cout << ans.str();




	return 0;
}
