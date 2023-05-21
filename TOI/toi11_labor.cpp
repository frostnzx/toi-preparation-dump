#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 1e6+5 ;

ll n , k , v[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k ;

    ll mn = 1e9 , mx = -1e9 ;
    for(int i=1;i<=n;i++){
        cin >> v[i] ;
        mn = min(mn , v[i]);
        mx = max(mx , v[i]);
    }

    sort(v+1 , v+n+1);

    ll l=mn , r=1e12 , ans ;
    while(l <= r){
        ll mid = (l+r)/2 ;

        ll cnt = 0 ;
        for(int i=1;i<=n;i++){
            cnt += (mid / v[i]);
        }
        if(cnt >= k){
            ans = mid ;
            r = mid-1 ;
        }
        else l = mid+1 ;
    }

    cout << ans ;
}

//CSES factory machine
//Keypoint : binary search จากเวลาที่จะใช้ แล้วเอาเวลาที่แต่ละอันใช้ ไปหาร เวลาที่จะใช้เพื่อดูว่าแต่ละคนทำได้กี่ชิ้น เพราะมันทำงานไปควบคู่กันได้
