//#include "../../stdc++.h"
#include <bits/stdc++.h>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define snd second
#define fst first

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//cout<<100000<<endl;
//
	//forn (i,100000){
	//	cout<<10000<<' ';
	//}
	//cout<<endl;

	//return 0;

	int n;
	cin>>n;

	vector<long long int> ad;
	ad.pb(0);

	forn (i,n){
		long long int te;
		cin>>te;

		ad.pb(ad[i]+te);
	}

	long long int mini=200000000;

	long long int dist=1;

	while(dist*dist<mini){
		forsn(i, dist+1, n+1){
			long long int sum=(ad[i]-ad[i-dist]);
			//cerr<<i<<endl;
			if (mini<sum*sum){
				//cerr<<"antes "<<i<<endl;
				i+=(sum*sum-mini)/100000000;
				//cerr<<"desp "<<i<<endl;

			}else{
				mini=min(mini, dist*dist+sum*sum);
			}


		}
		//cerr<<dist<<'\n';
		dist++;
	}

	cout<<mini<<endl;

	return 0;
}
