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

struct fun{
	tint m, b;
	inline tint operator()(tint x){return x*m + b;}
};

struct node;

vector<node> seg;

struct node{
	tint from, to;
	int l, r;
	fun f;
	node(){
		from = 0;
		to = 1ll << 30ll;
		l = r = -1;
		f = {0, 0};
	}
	inline int left(){
		if (l == -1){
			l = seg.size();
			seg.push_back(node());
			seg.back().from = from;
			seg.back().to = (from+to)/2;
		}
		return l;
	}
	inline int right(){
		if (r == -1){
			r = seg.size();
			seg.push_back(node());
			seg.back().to = to;
			seg.back().from = (from+to)/2;
		}
		return r;
	}
};

tint maxn;

void init(tint n, tint _maxn){
	maxn = _maxn;
	seg.reserve(n);
	seg.push_back(node());
	debug(seg.back().l);
	debug(seg.back().r);
	seg.back().to = maxn;
	seg.back().f = {0, 0};
}

void add(tint m, tint b, int curr = 0){
	debug("===ADD===");
	debug(curr);
	debug(m);
	debug(b);
	// int curr = 0;
	tint cl = seg[curr].from, cr = seg[curr].to;
	tint med = (cl+cr)/2;
	fun f;
	f.m = m; f.b = b;
	tint c1 = seg[curr].f(cl),
		 c2 = seg[curr].f(med),
		 n1 = f(cl),
		 n2 = f(med);
	int lado = 0; // de que lado esta la inters
	if (n2 == c2){
		lado = 1;
	}else if ( (c1 < n1 and c2 < n2) or (c1 > n1 and c2 > n2)){
		lado = 1;
	}
	debug(lado);
	if (lado){
		if (c1 > n1){
			m = seg[curr].f.m;
			b = seg[curr].f.b;
			seg[curr].f = f;
			f.m = m; 
			f.b = b;
		}

		if (seg[curr].r == -1){
			seg[seg[curr].right()].f = f;
			debug(seg[curr].r);
		}else{
			debug(seg[curr].r);
			add(m, b, seg[curr].right());
		}
	}else{
		if (c2 > n2){
			m = seg[curr].f.m;
			b = seg[curr].f.b;
			seg[curr].f = f;
			f.m = m; 
			f.b = b;
		}

		if (seg[curr].l == -1){
			debug(seg[curr].l);
			seg[seg[curr].left()].f = f;
		}else{
			debug(seg[curr].l);
			add(m, b, seg[curr].left());
		}
	}

}

tint search(tint x, int curr = 0){
	tint ans = seg[curr].f(x);
	tint med = (seg[curr].from + seg[curr].to)/2;
	if (x < med and seg[curr].l != -1){
		ans = min(ans, search(x, seg[curr].l));
	}else if (x >= med and seg[curr].r != -1){
		ans = min(ans, search(x, seg[curr].r));
	}
	return ans;
}

inline tint search2(tint x, int curr = 0){
	tint ans = seg[curr].f(x);
	tint cfrom = seg[curr].from, cto = seg[curr].to;
	tint med = (cfrom + cto)/2;

	while(cto - cfrom > 1){
		med = (cfrom+cto)/2;
		if (x < med){
			if (seg[curr].l == -1){
				return ans;
			}
			curr = seg[curr].l;
			ans = min(ans, seg[curr].f(x));
			cto = med;
		}else{
			if (seg[curr].r == -1){
				return ans;
			}
			curr = seg[curr].r;
			ans = min(ans, seg[curr].f(x));
			cfrom = med;
		}
	}

	return ans;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	tint n;
	cin >> n;

	init(n+10, 1ll << 30);


	vector<pair<pair<tint, tint>, tint>> a(n);
	forn(i, n){
		tint x, y, c; cin >> x >> y >> c;
		a[i] = {{x, -y}, c};
	}

	sort(a.begin(), a.end());

	// vector<tint> dp(n+1, 0);
	int best = 0;
	tint ans = 0;

	forn(i, n){
		a[i].fst.snd = -a[i].fst.snd;
		tint are = a[i].fst.fst*a[i].fst.snd - a[i].snd;
		tint este = are - search2(a[i].fst.snd);
		// debug(search(a[i].fst.snd));
		add(a[i].fst.fst, -este);
		ans = max(ans, este);
	}

	cout << ans << endl;


	return 0;
}
