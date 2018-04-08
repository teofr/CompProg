#include <bits/stdc++.h>

using namespace std;

#define debug(v) cerr << #v << ": " << v << endl;

/*
    El tema es que tengo que hacer algo un toque mejor
    Deberia tener un objeto version, que guarda un valor, que es o frente o espalda
    y un puntero a otra version
    cuando pusheo es trivial
    cuando popeo, tengo que tener cuidado
    pero aca deberia meterme hasta encontrar el del fondo, me gustaria tener acceso mas directo

    cada version podria acordarse el primero y el ultimo
    es decir V := null | val | val - V - val
    guardo el doble de valores??

    como val es entero no importa, pero como se podria mejorar?


*/

struct pdeq{
    struct node{
        // tipo = 0 es el vacio
        // tipo = 1 tiene un solo elemento
        // tipo >=2 tiene version anterior
        int tipo;
        int prev;
        int front, back;
    };

    vector<node> vers;

    void push_front(int vs, int val){
        node next = {vers[vs]+1, vs, val,  (vers[vs].tipo ? vers[vs].back : val)};
        vers.push_back(next);
    }

    void push_back(int vs, int val){
        node next = {vers[vs]+1, vs, (vers[vs].tipo ? vers[vs].front : val), val};
        vers.push_back(next);
    }

    int pop_front(int vs){
        node next;
        next.tipo = vers[vers[vs].prev]
        return vers[vs].front;
    }

    int pop_back(int vs){
        debug(vers[vs].first);
        debug(vers[vs].first->val);
        debug(vers[vs].second);
        debug(vers[vs].second->val);
        vers.push_back({(vers[vs].first == NULL or vers[vs].first->prev == NULL ? NULL : vers[vs].first), (vers[vs].second == NULL ? NULL : vers[vs].second->prox) });
        return vers[vs].second->val;
    }
};


int main(){
    int q;
    cin>>q;

    pdeq que;
    que.vers.push_back({0, NULL, 0, 0});

    for(int i = 0; i<q; i++){
        char c;
        int v;
        cin >> c >> v;
        if (c == 'B'){
            int x;
            cin >> x;
            que.push_front(v, x);
        }
        if (c == 'E'){
            int x;
            cin >> x;
            que.push_back(v, x);
        }
        if (c == '<'){
            cout << que.pop_front(v) << endl;
        }
        if (c == '>'){
            cout << que.pop_back(v) << endl;
        }
    }

    return 0;
}
