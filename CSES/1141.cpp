#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+5 ; 
const int INF = 1e9+7 ; 

int n , a[N] ; 
unordered_map<int,int> mp ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1;i<=n;i++)
        cin >> a[i] ; 

    int l=1 , r=1 , cnt = 0 , ans = -INF ;
    while(l <= n && r <= n){
        if(!mp[a[r]])
            cnt++ ;
        mp[a[r]]++;
        while(mp[a[r]] > 1){
            if(mp[a[l]]-1 == 0)
                cnt--;
            mp[a[l]]--;
            l++;
        }

        ans = max(ans , cnt);
        r++;
    }
    cout << ans ; 
}