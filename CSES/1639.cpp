#include<bits/stdc++.h>

using namespace std;

const int N = 5005 ;

string a , b ;
int n , m , dp[N][N];

int solve(int i , int j){
    if(i == n && j == m){
        return dp[i][j] = 0 ;
    }
    if(i == n || j == m){
        return dp[i][j] = max(n - i , m - j) ;
    }
    if(dp[i][j] != -1){
        return dp[i][j] ;
    }

    if(a[i] == b[j]){
        return dp[i][j] = solve(i+1 , j+1) ;
    }
    int ans1 = 1 + solve(i , j+1) , // add
        ans2 = 1 + solve(i+1 , j) , // remove
        ans3 = 1 + solve(i+1 , j+1) ;  // replace

    return dp[i][j] = min({ans1 , ans2 , ans3});
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    memset(dp , -1 , sizeof(dp));

    cin >> a >> b ;
    n = a.length() , m = b.length() ;

    cout << solve(0 , 0) ;
}
