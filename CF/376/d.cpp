//#include "../../stdc++.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define mp make_pair
#define snd second
#define fst first
typedef long long ll;
using namespace std;

int mini, maxi,c;
vector<vector<int>> h;

void intersecar(int mi, int ma){
	if(mi>=ma){
		mini=maxi=0;
		return;
	}
	if(ma<=mini || mi>=maxi){
		mini=maxi=0;
	}else{
		mini=max(mini, mi);
		maxi=min(maxi, ma);
	}
}


void analyze(int start, int end, int prof){ //Intervalo [start, end)
	int salto=-1;

	int j=start;
	while(j<end && h[j][prof]==0){
		j++;
	}

	forsn(i, j+1, end){
		if(h[i][prof]==0){
			mini=maxi=0;
		}else{
			if(h[i][prof]<h[i-1][prof]){
				if(salto!=-1 || h[i][prof]>=h[j][prof]){
					mini=maxi=0;
					salto=i;
				}else{
					salto=i;
					intersecar(c-h[j][prof]+1, c-h[end-1][prof]+1);
				}
			}
		}
	}

	if(salto==-1){
		intersecar(0, c-h[end-1][prof]+1);
	}

	forsn(i, j, end){
		int g=i;
		while(g<end && h[g][prof]==h[i][prof]) g++;

		analyze(i,g, prof+1);
		i=g;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin>>n>>c;
	mini=0; maxi=c;

	h=vector<vector<int>> (n);

	forn(i,n){
		int l;
		cin>>l;
		forn(j,l){
			int a; cin>>a;
			h[i].pb(a);
		}
		h[i].pb(0);
	}

	analyze(0, n, 0);

	cout<<(mini<maxi?mini:-1)<<endl;



	return 0;
}
