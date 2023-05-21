#include<bits/stdc++.h>

using namespace std;

using pii = pair<float,int> ;

const int N =2e5+5 ;
const int D[2] = {-1 , 1} ;

int m , n , k , val[N];

set<pii> G[N] ;

int ans = -1e9 ;

void solve(int u , float h , bool use){

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> k ;
    for(int i=1;i<=n;i++){
        cin >> val[i] ;
    }

    for(int i=1;i<=k;i++){
        int a,b ; cin >> a >> b ;
        G[a].insert({b , a+1});
        G[a+1].insert({b , a});
    }
    int x ; cin >> x ;



}
