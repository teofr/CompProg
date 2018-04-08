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

struct node{
	int padre;
	long long int  valor, costo, costocamino;
	vector<int> hijos;
};

long long int dfscosto(int n, vector<node> & tree){
	long long int mini=tree[n].valor;
	
	for (auto h:tree[n].hijos){
		mini=min(mini, dfscosto(h, tree));
	}
	tree[n].costo=mini;
	return  mini;
}

long long int dfscamino(int n, vector<node> & tree, long long int sofar){
	tree[n].costocamino=sofar+tree[n].costo;
	
	for ( auto h:tree[n].hijos){
		dfscamino(h, tree, tree[n].costocamino);
	}
	return 0;
}

int main() {
	int n;
	cin>>n;
	
	node tipo{0,1, 1, 0, vector<int>(0)};
	vector<node> tree(n, tipo);

	forn (i,n-1){
		int pad;
		cin>>pad;
		tree[i].padre=pad-1;
		tree[pad-1].hijos.pb(i+1);
	}
	
	forn(i,n){
		cin>>tree[i].valor;
		tree[i].costo=tree[i].valor;
	}
	
	dfscosto(0, tree);
	dfscamino(0, tree, 0);
	
	for (auto h:tree){
		cout<<h.costocamino<<' ';
	}
	cout<<endl;
	
		
		
	return 0;
}
