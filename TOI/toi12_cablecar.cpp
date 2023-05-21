#include<bits/stdc++.h>

using namespace std;

const int N = 2505 ;

int n , m , par[N] , s , d , p;

struct Edge{
    int u , v , w ;
    bool operator<(const Edge &other) const {
        return w > other.w ;
    }
};

vector<Edge> G ;

int root(int u){
    if(par[u] == u){
        return u ;
    }
    else return par[u] = root(par[u]) ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1 , u , v , w;i<=m;i++){
        cin >> u >> v >> w ;
        G.push_back({u , v , w});
    }
    cin >> s >> d >> p ;

    for(int i=1;i<=n;i++){
        par[i] = i ;
    }

    sort(G.begin() , G.end());

    int ans ;
    for(auto [u , v , w] : G){
        int pu = root(u) , pv = root(v) ;
        if(pu == pv){
            continue;
        }
        par[pu] = par[pv] ;
        ans = w - 1 ;
        if(root(s) == root(d)){
            break;
        }
    }
    cout << (p + ans - 1) / ans ;
}

//keypoint : sort จากมากไปน้อย พยายามเลือกแต่เส้นที่มากๆไปเรื่อยๆจนกว่า s กับ d จะเชื่อมกันด้วยเส้นที่น้อยที่สุด
