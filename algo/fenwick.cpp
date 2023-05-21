#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+5 ;

int n , fw[N] ;

int sum(int k){
    int s = 0 ;
    while(k >= 1){
        s += fw[k] ;
        k -= k&-k ;
    }
    return s ;
}

void add(int k , int x){
    while(k <= n){
        fw[k] += x ;
        k += k&-k ;
    }
}

int main(){
    cin >> n ;
    for(int i=1 , x;i<=n;i++){
        cin >> x ;
        add(i , x) ;
    }


    int q ;
    cin >> q ;
    while(q--){
        int l , r ;
        cin >> l >> r ;

        cout << sum(r) - sum(l-1) << "\n" ;
    }
}
