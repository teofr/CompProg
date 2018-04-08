#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <cassert>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define mp make_pair
#define snd second
#define fst first

using namespace std;
int n,m;
vector<vector<char> > v;

int walkback(int i, int j);

int keepwalking(int i, int j){
	if (i<0) return -1;
	//cerr<<"Entro a keep con i: "<<i<<" j: "<<j<<endl;

	// 01234
	// 01000
	int res=0;
	if (i==0){
		if (j) {
			while (j>0){
				if (v[i][j]=='1'){
					res=m+1-j;
				}
				j--;
			}
		}else {
			while (j<m+2){
				if (v[i][j]=='1'){
					res=j;
				}
				j++;
			}
		}
		//cerr<<"Salgo de keep i: "<<i<<" j: "<<j<<" con res: "<<res<<endl;

		return res;
	}
	if(j==0){
		j=m+1;
	}else{
		j=0;
	}

	res=m+1;
	res+=min(keepwalking(i-1, j), walkback(i-1, j))+1;
	//cerr<<"Salgo de keep i: "<<i<<" j: "<<j<<" con res: "<<res<<endl;
	return res;

}

int walkback(int i, int j){
	if (i<0) return -1;
	//cerr<<"Entro a walkback con i: "<<i<<" j: "<<j<<endl;

	int res=0;

	// 01234
	// 01000
	if (j>0) {
		while (j>0){
			if (v[i][j]=='1'){
				res=m+1-j;
			}
			j--;
		}
	}else {
		while (j<m+2){
			if (v[i][j]=='1'){
				res=j;
			}
			j++;
		}
	}
	res=res*2;
	if (j==0) j=m+1;
	else j=0;
	//j=(j==0?m+1:0);
	res+=min(keepwalking(i-1, j), walkback(i-1, j))+1;
	//cerr<<"Salgo de walk i: "<<i<<" j: "<<j<<" con res: "<<res<<endl;

	return res;


}

int main() {

	cin>>n>>m;
	v=vector<vector<char> > (n, vector<char> (m,'0'));

	forn(i,n){
		forn(j,m+2){
			char a;
			cin>>a;

			v[i][j]=a;
		}
	}

	int res=min(keepwalking(n-1,0), walkback(n-1,0));

	bool t=true;
	int last=0;
	forn (i,n){
		forn(j,m+2){
			t=t&(v[i][j]=='0');
		}
		if (t) last=i+1;
	}

	res-=last;
	res=max(res, 0);

	cout<<res<<endl;
	//00110
	//01000
	return 0;
}
