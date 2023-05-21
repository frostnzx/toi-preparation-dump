#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 2e6+5 ;

int n ;
ll cats[N] , mx = -1e9 ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1;i<=n;i++){
        cin >> cats[i] ;
        mx = max(mx , cats[i]) ;
    }

    ll l=0 , r=mx , ans ;

    while(l <= r){
        ll mid = (l+r)/2 , pv = 0 ;

        bool valid = true ;

        for(int i=1;i<=n;i++){
            if(cats[i] <= mid){
                continue ;
            }
            if(pv == 0){
                pv = cats[i] ;
            }
            else if(cats[i] == pv){
                pv = 0 ;
            }
            else if(cats[i] != pv){
                valid = false ;
                break;
            }
        }
        if(valid){
            r = mid-1 ;
            ans = mid ;
        }
        else {
            l = mid+1 ;
        }
    }

    cout << ans ;
}

//keypoint : binary search on ans
// if cats[i] <= mid means that this cat and  its pair can be move to left side of sequence
// without any problem , but if cats[i] > mid we'll have to check if others that can't move already
// in their right places because if it's not we can't do anything

//reminder : โจทย์ optimize อย่าลืมลอง binary search
