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



#define zero(v) memset(v, 0, sizeof(v))



const int MAXN= 100010;
int n, m;
vector<int> G[MAXN];

struct edge {
	int u,v, comp;
	bool bridge;
};
vector<edge> e;
void addEdge(int u, int v) {
	G[u].pb(e.size()), G[v].pb(e.size());
	e.pb((edge){u,v,-1,false});
}
//V[i]=id de la dfs
//L[i]=lowest id reachable from i
int V[MAXN], L[MAXN], qV;
int nbc;//cant componentes
int comp[MAXN];//comp[i]=cant comp biconexas a la cual pertenece i
void initDfs(int n) {
	zero(G), zero(comp);
	e.clear();
	forn(i,n) V[i]=-1;
	nbc = qV = 0;
}
stack<int> st;
void dfs(int u, int pe) {//O(n + m)
    L[u] = V[u] = qV++;
	comp[u] = (pe != -1);
    for(auto &ne: G[u]) if (ne != pe){
		int v = e[ne].u ^ e[ne].v ^ u; // x ^ y ^ x = y!
		if (V[v] == -1) { // todavia no se lo visito
			st.push(ne);
			dfs(v,ne);
			if (L[v] > V[u]){// bridge => no pertenece a ninguna comp biconexa
				e[ne].bridge = true; 
			}
			if (L[v] >= V[u]){ // art
				int last;
				do { //todas las aristas que estan entre dos puntos de articulacion pertenecen a la misma componente biconexa
					last = st.top(); st.pop();
					e[last].comp = nbc;
				} while (last != ne); 
				nbc++;
				comp[u]++;
			}
			L[u] = min(L[u], L[v]);
		}
		else if (V[v] < V[u]) { // back edge
			st.push(ne);
			L[u] = min(L[u], V[v]);
		}
	}
}

set<int> C[2*MAXN];
int compnodo[MAXN];
int ptoart;
void blockcuttree(){
	ptoart = 0;
	forn(i,2*MAXN) C[i].clear();
    for(auto &it: e){
		int u = it.u, v = it.v;
		if(comp[u] == 1) compnodo[u] = it.comp;
        else{
			if(compnodo[u] == 0){ compnodo[u] = nbc+ptoart; ptoart++;}
			C[it.comp].insert(compnodo[u]);
			C[compnodo[u]].insert(it.comp);
		}
		if(comp[v] == 1) compnodo[v] = it.comp;
        else{
			if(compnodo[v] == 0){ compnodo[v] = nbc+ptoart; ptoart++;}
			C[it.comp].insert(compnodo[v]);
			C[compnodo[v]].insert(it.comp);
		}
    }
}    

int main() {
	while(cin >> n >> m){
		initDfs(n);
		forn(i, m){
			int a,b; 
			cin >> a >> b;
			a--;
			b--;
			addEdge(a,b);
		}

		forn(i, n){
			if (V[i] != -1) continue;
	        dfs(i,-1);		
		}
        //forn(i, n) cout << "comp[" << i << "] = " <<  comp[i] << endl;
		//for(auto &ne: e) cout << ne.u << "->" << ne.v << " en la comp. " << ne.comp << endl;
		//cout << "Cant. de componentes biconexas = " << nbc << endl;

        map<int, pair<int, set<int> > > comps; // cant de ejes, cant de nodos

        for (auto& ne : e){
        	comps[ne.comp].fst++;
        	comps[ne.comp].snd.insert(ne.u);
        	comps[ne.comp].snd.insert(ne.v);
        }

        vector<int> printy;
        forn(i, m){
        	if (comps[e[i].comp].fst == comps[e[i].comp].snd.size()){
        		printy.pb(i+1);
        	}
        }

        cout << printy.size() << endl;

        if (printy.size() > 0){
        	forn(i, printy.size()){
        		cout << printy[i] ;
        		if (i+1 != printy.size()) cout << ' ' ;
        	}
        	cout << endl;
        }

		return 0;
	}
    return 0;
}







/*

int main() {
	tint n;
	cin >> n;


	return 0;
}
*/