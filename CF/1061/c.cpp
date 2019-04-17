#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define ii pair<tint,tint>
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i=(tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define mp make_pair
#define fst first
#define snd second
#define pb push_back

#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

const tint mod = 1e9 + 7;
#define tipo tint

//Dado un arreglo y una operacion asociativa con neutro, get(i, j) opera
// sobre el rango [i, j).
#define MAXN 100100
// #define operacion(x, y) max(x, y)
tint operacion(tint x, tint y){
	return ((x * y) % mod);
};
const tint neutro=1;
struct RMQ{
	int sz;
	tipo t[4*MAXN];

	tipo &operator[](int p){return t[sz+p];}
	void init(int n){//O(nlgn)
		sz = 1 << (32-__builtin_clz(n));
		forn(i, 2*sz) t[i]=0;
	}
	void updall(){//O(n)
	dforn(i, sz) t[i]=operacion(t[2*i], t[2*i+1]);}

	tipo get(int i, int j){return get(i,j,1,0,sz);} // [i,j) !

	tipo get(int i, int j, int n, int a, int b){//O(lgn)
	if(j<=a || i>=b) return neutro;
	if(i<=a && b<=j) return t[n];
	int c=(a+b)/2;
	return operacion(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
	}
	void set(int p, tipo val){//O(lgn)
	for(p+=sz; p>0 && t[p]!=val;){
	t[p]=val;
	p/=2;
	val=operacion(t[p*2], t[p*2+1]);
	}
	}
}rmq;
//Usage:
// cin >> n; rmq.init(n); forn(i, n) cin >> rmq[i]; rmq.updall();

#define MAXP 1000100 //no necesariamente primo
tint criba[MAXP+1];
void crearcriba(){
tint w[] = {4,2,4,2,4,6,2,6};
for(tint p=25;p<=MAXP;p+=10) criba[p]=5;
for(tint p=9;p<=MAXP;p+=6) criba[p]=3;
for(tint p=4;p<=MAXP;p+=2) criba[p]=2;
for(tint p=7,cur=0;p*p<=MAXP;p+=w[cur++&7]) if (!criba[p])
for(tint j=p*p;j<=MAXP;j+=(p<<1)) if(!criba[j]) criba[j]=p;
}

map<tint,tint> fact2(tint n){ //O (lg n)
	map<tint,tint> ret;
	while (criba[n]){
		ret[criba[n]]++;
		n/=criba[n];
	}
	if(n>1) ret[n]++;
	return ret;
}
//Usar asi: divisores(fac, divs, fac.begin()); NO ESTA ORDENADO
void divisores(const map<tint,tint> &f, vector<tint> &divs, map<tint,tint>::iterator it, tint n=1){
	if(it==f.begin()) divs.clear();
	if(it==f.end()) { divs.pb(n); return; }
	tint p=it->fst, k=it->snd; ++it;
	forn(_, k+1) divisores(f, divs, it, n), n*=p;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	crearcriba();
	debug(mod);
	tint n;
	cin >> n;
	vector<tint> a(n);
	forn(i, n)
		cin >> a[i];

	// vector<pair<tint, tint>> dp(n+1, {0, 0});
	// const int mod = 1e9 + 7;

	// forsn(i, 1, n+1){
	// 	tint maxi = dp[i-1].fst + 1;
	// 	tint val = a[i-1];
	// 	tint cnt = val == 1 ? 0 : 1;
	// 	// if (maxi)
	// 	bool succ = (val % maxi == 0);
	// 	while (criba[val]){
	// 		if (criba[val] <= maxi)
	// 			cnt++;
	// 		if (criba[val] == maxi)
	// 			succ = true;
	// 		debug(criba[val]);
	// 		debug(val);
	// 		val = val/criba[val];
	// 		debug(val);
	// 	}
	// 	if (val <= maxi)
	// 		cnt++;
	// 	if (val == maxi)
	// 		succ = true;
	// 	debug(cnt);
	// 	debug((succ ? maxi : maxi - 1));
	// 	debug((dp[i-1].snd + cnt) % mod);
	// 	dp[i] = {(succ ? maxi : maxi - 1), (dp[i-1].snd + cnt) % mod};
	// }

	// vector<tint> dp(n+1, 0); dp[0] = 1;
	rmq.init(n+10); rmq.set(0, 1);
	tint idx = 1;
	tint ans = 0;
	// set<int> divs;
	for (auto val : a){
		// dp[1]++;

		vector<tint> divs;
		auto fac = fact2(val);
		divisores(fac, divs, fac.begin());
		sort(divs.begin(), divs.end());

		dforn(i, divs.size()){
			// debug(divs[i]);
			if (divs[i] <= idx ){
				// dp[val]++;
				// debug(rmq.get(0, divs[i]));

				ans += rmq.get(0, divs[i]);
				ans %= mod;
				if (rmq.get(0, divs[i]) > 0)
					rmq.set(divs[i], rmq.get(divs[i], divs[i]+1) + 1ll);
			}
			// if (criba[val])
				// val = val / criba[val];
		}
		idx++;
	}

	// tint acum = 1;
	// tint ans = 0;
	// for (auto d : dp){
	// 	debug(d);
	// 	acum = (acum * d) % mod;
	// 	ans += acum;
	// 	ans %= mod;
	// }

	cout << ans % mod << endl;


	return 0;
}
