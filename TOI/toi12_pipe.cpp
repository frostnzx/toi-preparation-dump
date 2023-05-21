#include<bits/stdc++.h>
#define DEBUG 0

using namespace std;

const int N = 15005 ;

using pii = pair<int,int> ;

struct Edge{
    int u , v , w ;

    bool operator<(const Edge &other) const {
        return w > other.w ;
    }
};

int n , k , p[N];

pii house[N] ;
priority_queue<Edge> pq ;

int root(int u){
    if(p[u] == u){
        return u ;
    }
    else return p[u] = root(p[u]) ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k ;

    for(int i=1 ,x, y;i<=n;i++){
        cin >> x >> y ;
        house[i] = {x , y} ;
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            pq.push({i , j , abs(house[i].first - house[j].first) + abs(house[i].second - house[j].second)}) ;
        }
    }

    for(int i=1;i<=n;i++){
        p[i] = i ;
    }

    int compo = n , ans = 0 , i = 0 ;
    while(compo > k && !pq.empty()){
        auto [u , v , w] = pq.top() ;
        pq.pop();

        int pu = root(u) , pv = root(v) ;
        if(pu == pv){
            continue ;
        }
        ans += w ;
        compo--;
        p[pu] = p[pv] ;
        i++;
    }

    cout << ans ;
}

//in this case heapsort is faster than quicksort because of big input
//so use pq instead of vector
//always kruskal with pq or if dense graph just use prim instead
