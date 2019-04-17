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

vector<int> a(30, -1), b(30, -1);

int form(int aa, int idx = -1){
	int ans = 0;
	if (aa){
		auto it = a.rbegin();
		while(it != a.rend()){
			ans = ans << 1;
			if (*it)
				ans += 1;
			it++;
		}
	}else{
		auto it = b.rbegin();
		while(it != b.rend()){
			ans = ans << 1;
			if (*it)
				ans += 1;
			it++;
		}
	}

	if (idx >= 0) ans += 1 << idx;
	return ans;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	a = vector<int> (30, 0);
	b = vector<int> (30, 0);
	vector<int> iguales(30, 0);

	int aa = 1;

	int cnt = 0;
	cout << "? 0 0" << endl;
	cnt++;
	int ans;
	cin >> ans;
	if (ans == -1){
		aa = 0;
	}

	int idx = 29;


	while(idx >= 0){
		int tans;
		cout << "? " << form(1, idx) << " " << form(0, idx) << endl;
		cnt++;
		cin >> tans;
		if (tans == ans){
			iguales[idx] = 1;
			debug(iguales[idx]);
			debug(idx);
		}else{
			if (ans == 1){
				a[idx] = 1;
				b[idx] = 0;
			}else{
				a[idx] = 0;
				b[idx] = 1;
			}
			cout << "? " << form(1) << " " << form(0) << endl;
			cnt++;
			cin >> tans;
			if (ans != tans){
				// aa = 1- aa;
				ans = tans;
			}
		}
		idx--;
	}


	forn(i, 30){
		if (iguales[i]){
			cout << "? " << form(1, i) << " " << form(0, -1) << endl;
			cnt++;
			int tans; cin >> tans;
			if (tans == 1){
				a[i] = 0; b[i] = 0;
			}else{
				a[i] = b[i] = 1;
			}
		}
	}

	debug(form(1));
	debug(form(0));
	cout << "! " << form(1)<<" " << form(0) << endl;
	debug(cnt);



	return 0;
}
