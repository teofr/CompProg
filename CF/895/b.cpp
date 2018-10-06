#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
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

using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;


int main() {
	tint n,x,k;
	cin >> n >> x >> k;
	vector<tint> a(n);
	forn(i, n){
		cin >> a[i];
	}

	ordered_set<pair<tint, int>> s;
	
	tint res = 0;
	forn(i,n){
		s.insert(mp(a[i], i));
		tint times = a[i]/x;
		if (k==0 and a[i]%x != 0){
			tint a = x*(times) + 1;
			tint b = x*(times+1);

			tint reps = s.order_of_key(mp(b, -1)) - s.order_of_key(mp(a, -1));
			res += reps;
		}else if (k!= 0 or a[i]%x != 0){
			if (times + 1 >= k){
				tint a = x*(times - k) + 1;
				tint b = x*(times - k +1) +1;
				tint reps = s.order_of_key(mp(b, -1)) - s.order_of_key(mp(a, -1));
				res += reps;
				
			}
			
		}
		debug(i);
		debug(a[i]);

		debug(res);
		debug(times);
	}

	ordered_set<pair<tint, int>> t;

	for(int i = n-1; i >= 0; i--){
		tint times = a[i]/x;
		if (k==0 and a[i]%x != 0){
			tint a = x*(times) + 1;
			tint b = x*(times+1);

			tint reps = t.order_of_key(mp(b, -1)) - t.order_of_key(mp(a, -1));
			res += reps;
		}else  if (k!=0 or a[i]%x != 0) {
			if (times + 1 >= k){
				tint a = x*(times - k) + 1;
				tint b = x*(times - k +1) +1;
				tint reps = t.order_of_key(mp(b, -1)) - t.order_of_key(mp(a, -1));
				res += reps;
				
			}
			
		}
		t.insert(mp(a[i], i));
		debug(i);
		debug(a[i]);
		debug(res);
		debug(times);

	}

	cout << res<< endl;


	return 0;
}
