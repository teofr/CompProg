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

int main() {
	int n, k;
	cin>>k>>n;

	int four, twos;
	four=k;
	twos=2*k;

	vector<int> sold (n);

	forn(i,n){
		cin>>sold[i];
	}

	//me saco los de 4
	forn (i,n){
		if (sold[i] >= 4){
			if (four){
				int cnt = sold[i] / 4;
				sold[i] -= min(cnt*4, four*4);
				four -= min(cnt, four);
			}
			if (sold[i]>=4 && twos){
				int cnt = sold[i] / 4;
				cnt *= 2;
				sold[i] -= min(2*cnt, 2*twos);
				twos -= min(cnt, twos);
			}

		}
	}

	//me saco los de 3
	forn (i,n){
		if (sold[i] == 3){
			if (four){
				four--;
				sold[i] = 0;
			}else if (twos){
				twos--;
				sold[i] -= 2;
			}else{
				//ya no quedan rows
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}

	//me saco los de 2
	//si puedo los meto en cositos de 2, sino, en lugares de 4 y incremento 1row
	int ones=0;

	forn(i,n){
		if (sold[i]==2){
			if (twos){
				twos--;
				sold[i] = 0;
			}else if (four){
				four--;
				ones++;
				sold[i]=0;
			}else if (ones){
				ones--;
				sold[i]--;
			}else{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}

	//me saco los de 1
	// se podria hacer viendo si entran, pero fue

	forn(i, n){
		if (sold[i]){
			if (ones){
				ones--;
				sold[i] = 0;
			}else if (twos){
				twos--;
				sold[i] = 0;
			}else if (four){
				four--;
				ones++;
				sold[i] = 0;
			}else{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}

	cout<<"YES"<<endl;

	return 0;
}
