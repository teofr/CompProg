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


	int n,m;

	cin>>n>>m;

	vector<vector<int> > mat;


	forn(i,n){
		mat.pb(vector<int> (0));

		forn(j,m){
			int t;
			cin>>t;
			mat[i].pb(t);
		}
	}

	int ans=0;

	forn(i,n){
		forsn(j,i+1,n){
			int m1=0; int m2=0;
			if(min(mat[i][1], mat[j][1])>min(mat[j][0], mat[i][0])){
				m1=1;
			}else{
				m2=1;
			}

			forsn(h,2,m){
					int cur=min(mat[i][h], mat[j][h]);
					//cerr<<"cur "<<cur<<endl;
					if(cur>min(mat[i][m1], mat[j][m1])){
						//cerr<<"nuevo m2 "<<h<<endl;
						m2=m1;
						m1=h;
					}else if(cur>min(mat[i][m2], mat[j][m2])){
						//cerr<<"nuevo m1 "<<h<<endl;

						m2=h;
					}
			}
			//cerr<<m1<<' '<<m2<<endl;
			ans=max(ans, min(min(mat[i][m1], mat[j][m1]),min(mat[i][m2], mat[j][m2])));
		}
	}

	cout<<ans<<endl;

	return 0;
}
