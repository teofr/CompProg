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
	int a,b;
	cin>>a>>b;

	int mini=min(a,b);

	a=1;
	while (mini){
		a*=mini;
		mini--;
	}

	cout<<a<<endl;

	return 0;
}
