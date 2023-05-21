#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 2e5+5 ;
const int D = 35 ; // log(10^9)

// max is query distance is 10^9 parent level above
// so maximum query in binary form would be log(10^9)

int q , n , m ;

int p[N][D] ; // parent matrix

int jump(int node , int dist){
    for(int i=0;i<D;i++){
        if(dist & (1LL << i)) {
            node = p[node][i] ;
        }
    }
    return node ;
}

// binary jumping on graph

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q ;
    for(int i=1;i<=n;i++){
        cin >> p[i][0] ; // 1 (2^0) level above i parent
    }

    // pre process the query
    for(int d=1;d<D;d++){
        for(int i=1;i<=n;i++){
            p[i][d] = p[p[i][d-1]][d-1] ;
            // goes to exactly 2^d level above ;
        }
    }

    while(q--){
        int base , dist ;
        cin >> base >> dist ;

        cout << jump(base , dist) << "\n" ;
    }
}
