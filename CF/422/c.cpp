//#include "../../stdc++.h"
#include <bits/stdc++.h>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define snd second
#define fst first
#define debug(a) cerr<< #a <<': '<<a<<endl

using namespace std;

struct intval{
	int dur;
	int l;
	int r;
	int cost;

	bool operator <(const intval& y) {
    return std::tie(dur, l, r, cost) < std::tie(y.dur, y.l, y.r, y.cost);
}
};

typedef intval tipo;


struct RMQ{
	#define LVL 20
	tipo vec[LVL][1<<(LVL+1)];
	tipo &operator[](int p){return vec[0][p];}
	int get(int i, int j) {//intervalo [i,j)
		int p = 31-__builtin_clz(j-i);
		return min((vec[p][i]).cost,(vec[p][j-(1<<p)]).cost);
	}
	void build(int n) {//O(nlogn)
		int mp = 31-__builtin_clz(n);
		forn(p, mp) forn(x, n-(1<<p))
		vec[p+1][x] = (vec[p][x].cost < vec[p][x+(1<<p)].cost ? vec[p][x] : vec[p][x+(1<<p)]);
}};



int main() {
	int n, x;
	cin>>n>>x;

	vector<intval> values;

	forn (i,n){
		int l, r, c;
		cin>>l>>r>>c;
		values.pb({r-l+1, l, r, c});
	}

	sort(values.begin(), values.end());

	RMQ rmvalues;

	forn (i, values.size()){
		rmvalues[i] = values[i];
	}

	values.clear();
	rmvalues.build(n);



	return 0;
}
