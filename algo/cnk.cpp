#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e3+5;
const int MOD = 1e9+7;
int dp1[N][N];
int dp2[N][N];
// dp1 use for top-down
// dp2 use for bottom-up

int solve(int n, int k){
    // base case
    if(k == 0 || k == n) return 1;
    // reuse optimal substructure
    if(dp1[n][k] > 0) return dp1[n][k];
    // transition state
    dp1[n][k] = (solve(n-1, k-1)%MOD + solve(n-1, k)%MOD)%MOD;
    return dp1[n][k];
}

int main(){
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << " ";

    // // bottom-up
    // // base case
    for(int i=0; i<=n; ++i)
        dp2[i][0] = dp2[i][i] = 1;
    // // transition state
    for(int i=2; i<=n; ++i){
        for(int j=1; j<=n-1; ++j){
            dp2[i][j] = (dp2[i-1][j]%MOD + dp2[i-1][j-1]%MOD)%MOD;
        }
    }
    cout << dp2[n][k];
    return 0;
}