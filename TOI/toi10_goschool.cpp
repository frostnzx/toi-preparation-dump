#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 55 ;

int n , m , o ;
ll G[N][N] , dp[N][N] ;

ll solve(int y , int x){
    if(y == 1 && x == 1){
        return dp[y][x] = 1 ;
    }
    if(dp[y][x] != -1){
        return dp[y][x] ;
    }

    ll ways = 0 ;
    if(y-1 >= 1 && G[y-1][x] == 0){
        ways += solve(y-1 , x) ;
    }
    if(x-1 >= 1 && G[y][x-1] == 0){
        ways += solve(y  , x-1) ;
    }

    return dp[y][x] = ways ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n >> o ;
    for(int i=1 , x,  y;i<=o;i++){
        cin >> x >> y ;
        G[y][x] = 1 ;
    }
    memset(dp , -1 , sizeof(dp));

    cout << solve(n ,m) ;

}

