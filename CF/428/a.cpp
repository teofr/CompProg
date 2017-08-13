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
	int n,k;
	cin>>n>>k;

	int stash = 0;
	int bran = 0;

	for (int i = 0; i<n; i++){
		int temp;
		cin>>temp;

		stash+=temp;

		bran += min(stash, 8);
		stash -= min(stash, 8);

		if (bran>=k){
			cout<<i+1<<endl;
			return 0;
		}
	}

	cout<<-1<<endl;

	return 0;
}
