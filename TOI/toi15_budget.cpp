#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

using pii = pair<ll,ll> ;

struct Edge{
    int u , v ;
    ll w ;
    bool operator<(const Edge &other) const {
        return w < other.w ;
    }
};
const int N = 3005 , P = 3e5+5 ;

int n , m , p , par[N] ;
vector<Edge> G ;

ll ans ;

int root(int u){
    if(u == par[u])return u ;
    else {
        return par[u] = root(par[u]);
    }
}

vector<ll> query ;
pii pg[P] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;

    for(int i=0;i<n;i++){
        par[i] = i ;
    }
    for(int i=1 , u , v , r;i<=m;i++){
        ll w ;
        cin >> u >> v >> w >> r ;
        if(r == 1){
            par[root(u)] = par[root(v)] ;
        }
        else {
            G.push_back({u , v , w});
        }
    }

    cin >> p ;
    for(int i=1;i<=p;i++){
        cin >> pg[i].second >> pg[i].first ;
    }

    sort(pg+1 , pg+p+1);
    for(int i=1;i<=p;i++){
        pg[i].second = max(pg[i].second , pg[i-1].second) ;
    }

    sort(G.begin() , G.end());
    for(auto [u , v , w] : G){
        int pu = root(u) , pv = root(v) ;
        if(pu == pv){
            continue ;
        }
        par[root(pu)] = par[root(pv)] ;
        query.push_back(w);
    }


    for(ll now : query){
        ll l = 1 , r = p , use ;
        while(l <= r){
            ll mid = (l+r)/2 ;
            if(pg[mid].second >= now){
                use = pg[mid].first ;
                r = mid-1 ;
            }
            else {
                l = mid+1 ;
            }
        }
        ans += use ;
    }
    cout << ans ;
}
//keypoint : ตอนจะต่อหัวกับหัว อย่าลืมใช้ p[root(u)] = p[root(v)]

//bnsearch โดยปรับให้ pg เป็น monotonic เพราะ แพคเกจที่ใช้เงินมากกว่า ก็สามารถไปใช้แพคเกจที่ถูกกว่าแต่ ได้ระยะมากกว่าได้
// เป็นเทคนิคการปรับ array ให้เป็น monotonic เพื่อจะได้ bnsearch ได้คล้ายๆ toi14_nbk48
