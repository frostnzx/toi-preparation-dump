#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 2e5+5 ;

ll n , q , fw[N] ;

void add(int k , ll x){
    while(k <= n){
        fw[k] += x ;
        k += k&-k ;
    }
}
ll sum(int k){
    ll s = 0 ;
    while(k >= 1){
        s += fw[k] ;
        k -= k&-k ;
    }
    return s ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q ;
    for(int i=1 , x;i<=n;i++){
        cin >> x ;
        add(i , x) , add(i+1 , -x) ;
    }

    int a , b , u ;
    while(q--){
        int ty ; cin >> ty ;

        if(ty == 1){
            cin >> a >> b >> u ;
            add(a , u) ;
            add(b+1 , -u) ;
        }
        else {
            cin >> a ;
            cout << sum(a) << "\n" ;
        }
    }
}
