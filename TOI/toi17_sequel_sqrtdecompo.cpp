#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 1e5+5 ;

ll n , q , v[N] , qs[505][N] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q ;
    for(int i=1;i<=n;i++){
        cin >> v[i] ;
    }

    int rootN = sqrt(n) + 1 ;
    for(int i=1;i<=rootN;i++){
        for(int j=1;j<=n;j++){
            qs[i][j] = qs[i][max(0 , j-i)] + v[j] ;
        }
    }

    while(q--){
        int l , m , r ;
        ll ans = 0 ;
        cin >> l >> m >> r ;
        if(m <= rootN){
            int ed = l + m*((r-l)/m) ;
            ans = qs[m][ed] - qs[m][max(0 , l - m)] ;
        }
        else {
            for(int i=l;i<=r;i+=m){
                ans += v[i] ;
            }
        }
        cout << ans << " " ;
    }
}


// keypoint : naive preprocessing takes O(n^2) which is too much
// we assume that if preprocessing takes O(n*sqrt(n)) it will be fine
// because we only preprocessing m from 1 to sqrt(n) and if m is more than sqrt(n)
// brute force solution of it will only cost O(sqrt(n)) which is more than the naive solution
// that only cost O(1) but we instead reduce time complexity of preprocessing which is much more
// than the O(Q *sqrt(N)) when we query each q query

