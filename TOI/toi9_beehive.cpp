#include<bits/stdc++.h>

using namespace std;
using i3 = tuple<int,int,int> ;

const int N = 1005 ;

int n , m , dp[N][N] , G[N][N] ;

map<i3 , int> mp ;

int solve(int y , int x){
     if(y == n+1){
        return dp[y][x] = 0 ;
     }
     if(dp[y][x] != -1){
        return dp[y][x] ;
     }
     int ans = -1e9  ;
     if(y%2 == 0){
        if(x != m){
            ans = max(ans , solve(y+1 , x+1) + G[y][x]);
            if(y+1 == n+1){
                mp[i3(y , x , dp[y+1][x+1] + G[y][x])] = 1 ;
            }
            else mp[i3(y , x , dp[y+1][x+1] + G[y][x])] += mp[i3(y+1 , x+1 , dp[y+1][x+1])] ;
        }
     }
     else {
        if(x != 1){
            ans = max(ans , solve(y+1 , x-1) + G[y][x]);
            if(y+1 == n+1){
                mp[i3(y,x,dp[y+1][x-1]+G[y][x])] = 1 ;
            }
            else mp[i3(y,x,dp[y+1][x-1]+G[y][x])] += mp[i3(y+1 , x-1 , dp[y+1][x-1])] ;
        }
     }
    ans = max(ans , solve(y+1 , x) + G[y][x]);
    if(y+1 == n+1){
        mp[i3(y , x , dp[y+1][x] + G[y][x])] = 1;
    }
    else mp[i3(y , x , dp[y+1][x] + G[y][x])] += mp[i3(y+1 , x , dp[y+1][x])] ;
    return dp[y][x] = ans ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> G[i][j] ;
        }
    }
    memset(dp , -1 , sizeof(dp));

    int ans = -1e9 , cnt = 0  ;
    for(int i=1;i<=m;i++){
        ans = max(ans , solve(1 , i));
    }

    for(int i=1;i<=m;i++){
        cnt += mp[i3(1 , i , ans)];
    }
    cout << ans << " " << cnt ;

}
