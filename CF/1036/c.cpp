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
#define DEBUG
#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif


vector<vector<vector<vector<vector<vector<int>>>>>> memo;


int f(int v1, int p1, int v2, int p2, int v3, int p3){

	if (memo[v1][p1+3][v2][p2+3][v3][p3+3] == -1){
	
	if (p1 <= -1){
		return 0;
	} else if (p2 <= -1) {
		if (v1 > 1){
			memo[v1][p1+3][v2][p2+3][v3][p3+3] =   1 + (p1 - 2 >= 0 ? 8 : 0) + f(v1-1, p1, 9, p1 - 1, 1, p1 -2);
		} else {
			memo[v1][p1+3][v2][p2+3][v3][p3+3] =   1 + (p1 - 3 >= 0 ? 8 : 0) + f(9, p1-1, 9, p1-2, 1, p1-3);
		}
	} else if (p3 <= -1){
		if (v2 > 1){
			memo[v1][p1+3][v2][p2+3][v3][p3+3] =   1 + (p2-1 >= 0 ? 8 : 0) + f(v1, p1, v2-1, p2, 1, p2 -1);
		} else {
			memo[v1][p1+3][v2][p2+3][v3][p3+3] =   1 + (p2 - 2 >= 0 ? 8 : 0) + f(v1, p1, 9, p2-1, 1, p2-2);
		}
	} else{
		if (v3 > 1){
			memo[v1][p1+3][v2][p2+3][v3][p3+3] =   1 + f(v1, p1, v2, p2, v3-1, p3);
		} else {
			memo[v1][p1+3][v2][p2+3][v3][p3+3] =  1 + (p3 - 1 >= 0 ? 8 : 0) + f(v1, p1, v2, p2, 1, p3-1);
		}
	}
}
return memo[v1][p1+3][v2][p2+3][v3][p3+3];

}

tint caller(tint n){
	vector<tint> v (3, 0);
	vector<tint> p (3, -1);
	int cnt = 0;
	for (int i = 18; i >= 0; i--){
		debug(i);
		if (cnt == 3) break;
		if (n!= 0 and n / (tint)pow(10,i) != 0){
			debug(n / (tint)pow(10,i));

			p[cnt] = i;
			v[cnt] = n / (tint)(pow(10,(i)));
			n = n % (tint)(pow(10,(i)));
			cnt++;

		}
	}
	debug(v[0]);
	debug(p[0]);
	debug(v[1]);
	debug(p[1]);
	debug(v[2]);
	debug(p[2]);

	return (f(v[0], p[0], v[1], p[1], v[2], p[2]));
}

int main() {
	tint t;
	cin >> t;
	memo = vector<vector<vector<vector<vector<vector<int>>>>>> 
	(12, vector<vector<vector<vector<vector<int>>>>>
		(23, vector<vector<vector<vector<int>>>>
			(12, vector<vector<vector<int>>>
				(23, vector<vector<int>>
					(12, vector<int>(22, -1))))));


	forn(i, t){
		tint l, r;
		cin >> l >> r;


		debug(caller(r));
		debug(caller(l-1));
		 cout << caller(r) - caller(l-1) << endl;
	}


	return 0;
}
