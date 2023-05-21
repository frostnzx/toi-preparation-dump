#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 2e5+5 ;

struct DATA{
    ll x , y ;

    bool operator<(const DATA &other) const {
        return y < other.y ;
    }
};

ll n , fen1[N] , fen2[N] , a[N] , ans ;
vector<DATA> ab ;

void add(ll k , ll x , ll ty){
    while(k <= N){
        if(ty == 1){
            fen1[k] += x ;
        }
        else fen2[k] += x ;
        k += k&-k ;
    }
}

ll sum(ll k , ll ty){
    ll s = 0 ;
    while(k >= 1){
        if(ty == 1){
            s += fen1[k] ;
        }
        else s += fen2[k] ;
        k -= k&-k ;
    }
    return s ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1 , x , y;i<=n;i++){
        cin >> x >> y ;
        ab.push_back({x , y});
    }
    sort(ab.begin() , ab.end());
    int idx = 1 ;
    for(auto [x , y] : ab){
        a[idx++] = x ;
    }

    for(int i=1;i<=n;i++){
        ans += (sum(N , 1) - sum(a[i] , 1)) + 1ll*((sum(N , 2) - sum(a[i] , 2))*a[i]) ;
        add(a[i] , a[i] , 1) , add(a[i] , 1 , 2) ;
    }

    cout << ans ;
}
