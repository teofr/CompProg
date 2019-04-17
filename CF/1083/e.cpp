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
#define sz(c) ((int)c.size())

#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

typedef tint tipo;

struct Line{tipo m,h;};
tipo inter(Line a, Line b){
    // guarda que se rompe con paralelas
    // ni idea con misma linea
    tipo x=b.h-a.h, y=a.m-b.m;
    return x/y+(x%y?!((x>0)^(y>0)):0);//==ceil(x/y)
}
struct CHT {
	vector<Line> c;
	bool mx;
	int pos;
	CHT(bool mx=0):mx(mx),pos(0){}//mx=1 si las query devuelven el max
    //Creo que te da la iesima con m mas grande
	inline Line acc(int i){return c[c[0].m>c.back().m? i : sz(c)-1-i];}
	inline bool irre(Line x, Line y, Line z){
		return c[0].m>z.m? inter(y, z) <= inter(x, y)
                         : inter(y, z) >= inter(x, y);
	}
	void add(tipo m, tipo h) {//O(1) amortizado, los m tienen que entrar ordenados
        if(mx) m*=-1, h*=-1;
		Line l=(Line){m, h};
        if(sz(c) && m==c.back().m) { l.h=min(h, c.back().h), c.pop_back(); if(pos) pos--; }
        while(sz(c)>=2 && irre(c[sz(c)-2], c[sz(c)-1], l)) { c.pop_back(); if(pos) pos--; }
        c.pb(l);
	}
	inline bool fbin(tipo x, int m) {return inter(acc(m), acc(m+1))>x;}//esta x en el bin m o antes?
	tipo eval(tipo x){
		int n = sz(c);
		//query con x no ordenados O(lgn)
		// int a=-1, b=n-1;
		// while(b-a>1) { int m = (a+b)/2;
		// 	if(fbin(x, m)) b=m;
		// 	else a=m;
		// }
		// return (acc(b).m*x+acc(b).h)*(mx?-1:1);
        //query O(1) amorrtizado
		while(pos>0 && fbin(x, pos-1)) pos--;
		while(pos<n-1 && !fbin(x, pos)) pos++;
		return (acc(pos).m*x+acc(pos).h)*(mx?-1:1);
	}
} ch;

// dp[i] = max j (dp[j] + xi*yi - ai - yi*xj)
//       = xi*yi - ai + max j (dp[j] - yi*xj)
//		 = xi*yi - ai - min j (yi*xj - dp[j])

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	tint n;
	cin >> n;

	CHT ch(0);

	// tint maxx = 0;
	tint ans = 0;

	vector<pair<pair<tint, tint>, tint>> a(n);
	forn(i, n){
		tint x, y, c; cin >> x >> y >> c;
		a[i] = {{x, -y}, c};
	}

	sort(a.begin(), a.end());
	// forn(i, n-1){
	// 	debug(a[i].fst.fst);
	// 	debug(a[i+1].fst.fst);
	// 	debug(a[i].fst.snd);
	// 	debug(a[i+1].fst.snd);
	// 	assert(a[i].fst.fst <= a[i+1].fst.fst);
	// 	assert(-a[i].fst.snd >= -a[i+1].fst.snd);
	// 	assert((a[i].fst.fst != a[i+1].fst.fst) or 
	// 		(a[i].fst.snd != a[i+1].fst.snd));
	// }

	vector<tint> dp(n+1, 0);
	ch.add(0, 0);
	int best = 0;

	forn(i, n){
		a[i].fst.snd = -a[i].fst.snd;
		tint are = a[i].fst.fst*a[i].fst.snd - a[i].snd;
		dp[i+1] = are - ch.eval(a[i].fst.snd);
		ch.add(a[i].fst.fst, - dp[i+1]);
		ans = max(ans, dp[i+1]);
	}

	// for(auto ai : a){
	// 	debug(ai.fst.fst);
	// 	tint c = ai.snd;
	// 	tint are = ai.fst.fst * ai.fst.snd;
	// 	are -= maxx * ai.fst.snd;

	// 	if (are - c > 0){
	// 		ans += are - c;
	// 		maxx = ai.fst.fst;
	// 	}
	// }

	cout << ans << endl;


	return 0;
}
