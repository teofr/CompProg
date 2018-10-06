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

bool issub(string a, string of){
	bool ans = true;

	int ai, oi;
	ai = a.size() - 1;
	oi  = of.size() -1;
	while(ai >= 0 and oi >= 0){
		if (a[ai] == of[oi]){
			ai--;
			oi--;
		}else{
			oi--;
		}
		/*if (ai == a.size()-1){
			while(oi >= 0 and of[oi] == '0'){
				oi--;
			}
		}*/
	}
	if (ai < 0){
		return true;
	}
	return false;
}

int main() {
	string n;
	cin >> n;

	map<tint, string> squares;

	tint pos = 1;
	while (pos*pos <= 2*1000000000){
		squares[pos*pos] = to_string(pos*pos);
		pos++;
	}

	//cout << issub("hola", "hooollaaaa") << endl << issub("chau", "cchhaaaaag") << endl;

	tint mini = -1;
	for (auto it = squares.rbegin(); it != squares.rend(); it++){
		if (issub(it->snd, n)){
			tint temp = n.size() - it->snd.size();
			if (mini > temp || mini == -1){
				mini = temp;
			}
		}
	}

	cout << mini << endl;


	return 0;
}
