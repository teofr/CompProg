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
#define MOD 1000000007

struct UnionFind{
	vector<int> f;//the array contains the parent of each node
	vector<int> szz;//el tamano de cada padre
	vector<int> jss;//joins
	void init(int n){
		f.clear();
		szz.clear();
		jss.clear();
		f.insert(f.begin(), n, -1);
		szz.insert(szz.begin(), n, 1);
		jss.insert(jss.begin(), n, 0);
	}
	int comp(int x){
		return (f[x]==-1?x:f[x]=comp(f[x]));
	}//O(1)
	int sz(int x){
		return szz[comp(x)];
	}
	int js(int x){
		return jss[comp(x)];
	}
	bool isRep(int x){
		return f[x]==-1;
	}
	bool join(int i, int j) {
		bool con=comp(i)==comp(j);
		if(!con) {
			//cerr << "join "<<i<<' '<<j<<endl;
			szz[comp(j)] += szz[comp(i)];
			szz[comp(i)] = 0;
			jss[comp(j)] += jss[comp(i)] + 1;
			jss[comp(i)] = 0;
			f[comp(i)] = comp(j);
		}else{
			jss[comp(i)] += 1;
		} //pa no romper la super complejidad
		return con;
	}
};

int id(int a){
	return a+100000*2+2;
}

int main() {
	int n;
	cin>>n;

	UnionFind uf;
	uf.init(4*100000 + 100);



	set<int> check;

	forn(i, n){
		int a, b;
		cin>>a>>b;
		check.insert(a); check.insert(id(b));
		if (a!=b){
			//debug(uf.sz(a));
			uf.join(a,id(b));
			//debug(uf.sz(a));
		}
		uf.join(a,id(a));
	}

	tint res = 1;

	set<int> vis;

	for(auto i:check){
		if ( vis.find(uf.comp(i)) == vis.end()){
			vis.insert(uf.comp(i));
			//debug(uf.comp(i));
			//debug(uf.sz(i));
			//debug(uf.js(i));
			if (uf.sz(i) & 1){
				res *= (uf.sz(i) + 1)/2;
				res = res % MOD;
			}else if(uf.js(i) == uf.sz(i)){
				res *= 2;
				res = res % MOD;
			}

			//debug(res);
		}

	}


	cout<<res<<endl;


	return 0;
}
