#include<bits/stdc++.h>

#define ll long long

using namespace std;

const ll MOD = 1e9+7 ; 

int q ; 

ll exp(ll a,ll b){
    if(b==0)return 1 ; 

    ll tmp ; 
    tmp = exp(a,b/2)%MOD;

    if(b%2==0) return (tmp*tmp)%MOD;
    else return (a*((tmp*tmp)%MOD))%MOD ; 
}

int main(){
    cin >> q ; 

    while(q--){
        ll a,b ; 
        cin >> a >> b ; 
        ll ans = exp(a,b)%MOD;

        cout << ans << "\n" ; 
    }
}