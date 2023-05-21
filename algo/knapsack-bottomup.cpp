#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105;
const int MAX_W = 1e5 + 5;
const long long llINF = 1e18 + 7;

int w[MAX_N], v[MAX_N];
long long dp[MAX_N][MAX_W];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, W;
    cin >> N >> W;

    for(int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j - w[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[N][W];
    return 0;
}