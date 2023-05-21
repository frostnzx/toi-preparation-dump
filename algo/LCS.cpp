#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int dp1[N][N];
bool vis[N][N];
char a[N], b[N];
int dp2[N][N];

// a[i] == a[j] : dp[i][j] = dp[i-1][j-1] + 1;
// dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

int solve(int i, int j){
    // base case
    if(i == 0 || j == 0) return 0;
    // reuse
    if(vis[i][j]) return dp1[i][j];
    vis[i][j] = true;
    // transition state
    if(a[i] == b[j])
        dp1[i][j] = solve(i-1, j-1) + 1;
    else
        dp1[i][j] = max(solve(i-1, j), solve(i, j-1));
    return dp1[i][j];
}

int main(){
    scanf("%s %s", a+1, b+1);
    int n=strlen(a+1), m=strlen(b+1);
    // printf("%d", solve(n, m));
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(a[i] == b[j])
                dp2[i][j] = dp2[i-1][j-1] + 1;
            else 
                dp2[i][j] = max(dp2[i-1][j], dp2[i][j-1]);
        }
    }
    printf("%d", dp2[n][m]);
    return 0;
}