#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;

const int N = 6e6+5 ;

ll n , w , v[N] , qs[N] , ans = -1e9 , len = -1e9 ;

deque<pii> dq ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> w ;
    for(int i=1;i<=n;i++){
        cin >> v[i] ;
        qs[i] = qs[i-1] + v[i] ;
    }

    for(int i=1;i<=n;i++){
        while(!dq.empty() && i - dq.front().second > w){
            dq.pop_front();
        }
        while(!dq.empty() && qs[i] <= dq.back().first){
            dq.pop_back();
        }

        dq.push_back({qs[i] , i});

        if(qs[i] - dq.front().first > ans){
            ans = qs[i] - dq.front().first ;
            len = i - dq.front().second ;
        }
        else if(qs[i] - dq.front().first == ans){
            len = min(ans , i - dq.front().second);
        }
    }

    cout << ans << "\n" << len ;
}

//keypoint : minimum deque 
// - pop ตัวที่ออกนอกช่วงทิ้ง 
// - pop prefix ที่มากกว่าตัวล่าสุดทิ้ง (ต้องการ dq.front() ให้เก็บ prefix ตัวที่น้อยสุด)