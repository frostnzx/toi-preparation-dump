#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<int,int> ;

vector<pii> pre ;
unordered_map<ll , ll> mp ;
unordered_map<int , vector<int> > ft ;

int cur[4] = {1 , 1 , 1 , 1} ; // {2,3,5,7}
int m , n ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n ;
    for(int i=1;i<=m;i++){
        int x , s ,e ;
        cin >> x >> s >> e ;
        pre.push_back({s , x});
        pre.push_back({e+1 , -x});
    }

    pre.push_back({1 , 0}); // sweep line ควรใส่อันแรกกับท้ายด้วยกัน error
    pre.push_back({n , 0});

    sort(pre.begin() , pre.end()) ;

    ll ans = -1e9 ;

    ft[2] = {1 , 0 , 0 , 0} ; ft[3] = {0 , 1 , 0 , 0}; ft[4] = {2 , 0 , 0 , 0} ;
    ft[5] = {0 , 0 , 1 , 0} ; ft[6] = {1 , 1 , 0 , 0}; ft[7] = {0 , 0 , 0 , 1} ;
    ft[8] = {3 , 0 , 0 , 0} ; ft[9] = {0 , 2 , 0 , 0}; ft[10] = {1 , 0 , 1 , 0} ;

    for(int i=0;i<pre.size();i++){
        auto [idx , v] = pre[i] ;
        if(v > 0){
            for(int j=0;j<4;j++){
                cur[j] += ft[v][j] ;
            }
        }
        else if(v < 0){
            for(int j=0;j<4;j++){
                cur[j] -= ft[v * -1][j] ;
            }
            continue;
        }

        ll cnt = 1 ;
        for(int j=0;j<4;j++){
            cnt *= cur[j] ;
        }

        if(cnt >= ans){
            ans = cnt ;
            mp[ans] += pre[i+1].first - idx ;
        }
    }

    cout << ans << " " << mp[ans] ;
}


//keypoint : sweepline + number theory 
// ใช่้ sweep line เก็บ event ว่า ในช่องนั้นมีเลขอันไหนเป็นตัวประกอบเท่าใด
// สมมุติช่องนั้นเป็น 72 แต่เราจะเก็บเป็นรูปแบบ array นับว่ามีตัวประกอบเฉพาะตัวไหนกี่ตัวบ้าง
// ฉะนั้น 72 = 2 x 2 x 2 x 3 x 3  เราจะได้ว่า cur[2] = 3 ตัว , cur[3] = 2 ตัว
// แล้วเมื่อเราได้จำนวนตัวประกอบเฉพาะแล้ว ก็จะหาได้ว่าจะมีตัวประกอบกี่ตัวโดยเอา จำนวนของตัวนั้น + 1 คูณกันทั้งหมด
// จะได้ (3+1) * (2+1) = 12 จำนวน แปลว่า 72 จะมีตัวประกอบ 12 ตัว
// (เหมือนสูตร หารลงตัวกี่ตัวที่เอาเลขชี้กำลังมาบวก 1 แล้วคูณกันนั่นแหละ)
