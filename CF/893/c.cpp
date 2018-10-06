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

vector<int> _cl;



int cla(int i) { return (_cl[i] == -1 ? i : _cl[i] = cla(_cl[i])); }
void join(int i, int j) { if(cla(i)!=cla(j)) _cl[cla(i)] = cla(j); }

void ini(int n) { _cl.clear(); _cl.insert(_cl.begin(), n, -1); }



int main() {
	tint n, m;
	cin >> n >> m;

	vector<tint> gold(n);
	forn(i,n){
		cin >> gold[i];
	}

	//cl = vector<int> (n, -1);
	ini(n);

	forn(i, m){
		int a, b;
		cin >> a>> b;
		a--; b--;
		join(a, b);
	}

	map<int,tint> cost;

	forn(i, n){
		if (cost.find(cla(i)) == cost.end()){
			cost[cla(i)] = gold[i];
		}else{
			cost[cla(i)] = min (cost[cla(i)], gold[i]);
		}
	}

	tint sum = 0;

	for (auto it = cost.begin(); it != cost.end(); it++){
		sum += it->snd;
	}

	cout << sum << endl;


	return 0;
}
