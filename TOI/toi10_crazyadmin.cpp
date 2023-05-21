#include<bits/stdc++.h>

using namespace std;

const int N = 105 ;

int k , n , v[N] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k >> n ;

    int mx = -1e9 , vsum = 0 ;
    for(int i=1;i<=n;i++){
        cin >> v[i] ;
        mx = max(mx , v[i]);
        vsum += v[i] ;
    }


    int  l = mx , r = vsum+1 , ans = 1e9 ;
    while(l <= r){
        int m = (l+r)/2 ;

        int c = 1 , cap = 0 ;
        for(int i=1;i<=n;i++){
            if(cap + v[i] <= m){
                cap += v[i] ;
            }
            else {
                c++;
                cap = v[i] ;
            }
        }

        if(c <= k){
            ans = min(ans , m) ;
            r = m-1 ;
        }
        else l = m+1 ;
    }

    cout << ans ;
}

//keypoint : ทำให้ box_max ใกล้เคียงกับค่า sum ของกล่องที่มากที่สุดโดยพยายามลดลงเรื่อยๆ จนถึงจุดก่อนที่จะ จุ <= k ไม่ได้อีก แล้วจำค่า
// จุดก่อนที่จะจุไม่ได้อีกเอาไว้ เพราะค่านั้นเป็นค่า sum ของกล่องที่มากที่สุด เพราะ ค่า sum ของกล่องที่น้อยกว่านั้นจะยังใช้ได้อยู่แต่จะมีอันเดียวและอันแรก
// ที่ทำให้ใช้ไม่ได้คือ ค่า sum ของกล่องที่มากที่สุด

//similars to cses1085
