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


//Dado un arreglo y una operacion asociativa con neutro, get(i, j) opera sobre el rango [i, j).
typedef int Elem;//Elem de los elementos del arreglo
typedef int Alt;//Elem de la alteracion

#define operacion(x,y) x+y

const Elem neutro=0; const Alt neutro2=0;

#define MAXN 100010

struct RMQ{
    int sz;
    Elem t[4*MAXN];
    Alt dirty[4*MAXN];//las alteraciones pueden ser de distinto Elem

    Elem &operator[](int p){
        return t[sz+p];
    }

    void init(int n){//O(nlgn)
        sz = 1 << (32-__builtin_clz(n));
        forn(i, 2*sz) t[i]=neutro;
        forn(i, 2*sz) dirty[i]=neutro2;
    }

    void updall(){//O(n)
        dforn(i, sz) t[i]=operacion(t[2*i], t[2*i+1]);
    }

    void opAltT(int n,int a,int b){//altera el valor del nodo n segun su dirty y el intervalo que le corresponde.
        t[n] = dirty[n]*(b-a); //en este caso la alteracion seria sumarle a todos los elementos del intervalo [a,b) el valor dirty[n]
    }

    void opAltD(int n ,Alt val){
        dirty[n] = val;
    }//actualiza el valor de Dirty "sumandole" val. podria cambiar el valor de dirty dependiendo de la operacion que se quiera al actualizar un rango. Ej:11402.cpp
    
    void push(int n, int a, int b){//propaga el dirty a sus hijos
        if(dirty[n]!=neutro2){
            //t[n]+=dirty[n]*(b-a);//altera el nodo
            opAltT(n,a,b);
            if(n<sz){
                opAltD(2*n,dirty[n]);//dirty[2*n]+=dirty[n];
                opAltD(2*n+1,dirty[n]);//dirty[2*n+1]+=dirty[n];
            }
            dirty[n]=neutro2;
        }
    }

    Elem get(int i, int j, int n, int a, int b){//O(lgn)
        if(j<=a || i>=b) return neutro;
        push(n, a, b);//corrige el valor antes de usarlo
        if(i<=a && b<=j) return t[n];
        int c=(a+b)/2;
        return operacion(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
    }

    Elem get(int i, int j){
        return get(i,j,1,0,sz);
    }

    //altera los valores en [i, j) con una alteracion de val
    void alterar(Alt val, int i, int j, int n, int a, int b){//O(lgn)
        push(n, a, b);
        if(j<=a || i>=b) return;
        if(i<=a && b<=j){
            opAltD(n ,val);//actualiza el valor de Dirty por val.
            push(n, a, b);
            return;//este nodo esta totalmente contenido por el intervalo a alterar, no es necesario que se lo pases a los hijos.. por ahora ..
        }
        int c=(a+b)/2;
        alterar(val, i, j, 2*n, a, c), alterar(val, i, j, 2*n+1, c, b);
        t[n]=operacion(t[2*n], t[2*n+1]);//por esto es el push de arriba
    }

    void alterar(Alt val, int i, int j){
        alterar(val,i,j,1,0,sz);
    }
};


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	tint t;
	cin >> t;

	forn(caso, t){
		tint n, k; cin >> n >> k;
	

        RMQ rmq;
        rmq.init(n);

		vector<tint> ch(n, 0);
		vector<tint> de(n, 0);

        map<tint, tint> decCH;
        map<tint, tint> decDE; // (b, a) desde a hasta el prox par, el max es b

        tint ans = 0;

        

		forn(i, n){
			cin >> ch[i];
		}

		forn(i, n){
			cin >> de[i];
		}

        forsn(i, 1, n+1){
            // fijo R == i
            // busco la cant de cosos con [L, R)
            auto valCH = ch[i-1];
            int idxCH;

            for (auto it = decCH.begin(); it != decCH.end() and it->fst <= valCH; decCH.erase(it++)){
                idxCH = it->snd;
            }

            auto valDE = de[i-1];
            int idxDE;

            for (auto it = decDE.begin(); it != decDE.end() and it->fst <= valDE; decDE.erase(it++)){
                idxDE = it->snd;
            }

            rmq.alterar(1 ? abs(valCH - valDE) <= k : 0, max(idxCH, idxDE), i);

            // 0 ---- min(idxCH, idxDE) ---- max(idxDE, idxCH) ---- R
            //  queda igual |||    el de ind mas chico ||  ya lo hice
            //                   es constante, a lo sumo
            //                   es 1 en un pedacito y 0 
            //                   en las puntas

            if (idxCH < idxDE){
                // aca idxCH es cte
                tint masChico = valCH - k;
                tint masGrande = valCH + k;

                // auto idx = decD
            }

            if (idxDE < idxCH){
                // [idxCH, npos) vale 1 sii valCH - valDE < K
                
            }
        }

		tint ans = 0;

		forsn(l, 1, n+1){
			forsn(r, 1, n+1){
				tint maxc = ch.get(l, r+1);
				tint maxd = de.get(l, r+1);

				if (abs(maxc - maxd) <= k)
					ans+=1;
			}
		}

		cout << "Case #" << caso+1 << ": " << ans << endl;
	}




	return 0;
}
