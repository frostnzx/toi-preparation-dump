#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int a[N], dp1[N], dp2[N];
bool vis[N];

int suf(int n){
    // base case
    if(n == 1) return a[1];
    // reuse
    if(vis[n]) return dp1[n];
    vis[n] = true;
    // transition state
    dp1[n] = max(suf(n-1)+a[n], a[n]); 
    return dp1[n];
}

int mss(int n){
    if(n == 1) return a[1];
    return max(mss(n-1), suf(n));
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
        scanf("%d", &a[i]);
    // printf("%d", mss(n));

    // base case
    int ans = a[1];
    dp2[1] = a[1];
    // transition state
    for(int i=2; i<=n; ++i){
        dp2[i] = max(dp2[i-1]+a[i], a[i]);
        ans = max(ans, dp2[i]);
    }
    printf("%d", ans);
    return 0;
}