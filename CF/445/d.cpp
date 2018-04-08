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


int main() {
	tint n;
	cin >> n;

	map<char, char> next;

	map<char, int> starters;



	forn(i,n){
		string s;
		cin >> s;

		forn (i, s.size()-1){
			char c = s[i];
			if ((next[c] != 0 and next[c] != 1) and next[c] != s[i+1]){
				cout << "NO" << endl;
				return 0;
			}
			next[c] = s[i+1];
			starters[s[i+1]] = 1;

		}
		if (next[s[s.size()-1]] == 0) next[s[s.size()-1]] = 1;
	}

	stringstream ss;

	for (auto p = next.begin(); p!= next.end(); p++){
		//debug(p)
		if (p->snd != 0 and starters[p->fst] != 1){
			auto cur = p;
			ss << cur->fst;
			while (cur != next.end()){

				if (cur->snd != 1) ss << cur->snd;
				debug(cur->fst);
				debug(cur->snd);
				//if (cur->snd == 0) break;
				char temp = cur->snd;
				cur->snd = 0;
				cur = next.find(temp);

			}
		}
	}

	for (auto p = next.begin(); p!= next.end(); p++){
		if (p->snd != 0){
			cout << "NO" << endl;
			return 0;
		}
	}

	map<char, int> app;

	string res = ss.str();

	forn(i, res.size()){
		if (app[res[i]] > 0){
			cout << "NO" << endl;
			return 0;
		}
		app[res[i]]++;
	}

	cout << res << endl;


	return 0;
}
