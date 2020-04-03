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
#define tipo tint
struct RMQ{
	// LVL >= ceil(logn)
	// 
	#define LVL 10
	tint vec[LVL][1<<(LVL+1)];
	tint &operator[](int p){
		return vec[0][p];
	}
	tint get(int i, int j) {//intervalo [i,j)
		int p = 31-__builtin_clz(j-i);
		return max(vec[p][i],vec[p][j-(1<<p)]);
	}
	void build(int n) {//O(nlogn)
		int mp = 31-__builtin_clz(n);
		forn(p, mp) forn(x, n-(1<<p))
		vec[p+1][x] = max(vec[p][x], vec[p][x+(1<<p)]);
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	tint t;
	cin >> t;

	forn(caso, t){
		tint n, k; cin >> n >> k;
	

		RMQ ch;
		RMQ de;

		forn(i, n){
			cin >> ch[i];
		}
		ch.build(n);

		forn(i, n){
			cin >> de[i];
		}
		de.build(n);

		tint ans = 0;

		forsn(l, 0, n){
			forsn(r, l+1, n+1){
				tint maxc = ch.get(l, r);
				tint maxd = de.get(l, r);

				if (abs(maxc - maxd) <= k)
					ans+=1;
			}
		}

		cout << "Case #" << caso+1 << ": " << ans << endl;
	}




	return 0;
}
