#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 5e5+5 ;

ll n , pnt[N] , box[N] , ans1 , ans2 = 1e9 , mn = 1e9 ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1;i<=n;i++){
        cin >> box[i] ;
        mn = min(mn , box[i]);
    }

    for(int i=1;i<=n;i++){
        cin >> pnt[i] ;
    }

    for(int j=1;j<=n;j++){
        ll want = pnt[j] , sum = 0 ;
        for(int i=1;i<=n;i++){
            if(want <= pnt[i]){
                sum += pnt[i] - want ;
            }
            else {
                sum += pnt[i] + (box[i] - want) ;
            }
        }
        if(sum < ans2){
            ans1 = want , ans2 = sum ;
        }
    }
    cout << ans1 << " " << ans2 ;
}
