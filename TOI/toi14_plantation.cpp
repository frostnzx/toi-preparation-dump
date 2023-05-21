#include<bits/stdc++.h>
#define DEBUG 0

using namespace std;

using ll = long long ;
using pii = pair<ll , ll> ;

int q , n ;
ll r , d ;

vector<pii> vec ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> q ;
    while(q--){
        cin >> n >> r >> d ;

        for(int i=0;i<n;i++){
            ll a , b ;
            cin >> a >> b ;
            vec.push_back({a , b});
        }
        sort(vec.begin() , vec.end());

        if(DEBUG){
            for(auto [x , y] : vec){
                cout << "x = " << x << " y = " << y << "\n" ; 
            }
        }

        ll lim = 2 * r + d ; bool flg = true ;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                ll dx = vec[j].first - vec[i].first , dy = vec[j].second - vec[i].second ;
                if(dx > lim || dy > lim){
                    break;
                }
                if(dx * dx + dy * dy < lim * lim){
                    flg = false ;
                    break;
                }
            }
            if(!flg){
                break;
            }
        }
        if(flg){
            cout << "Y\n" ;
        }
        else {
            cout << "N\n" ;
        }

        vec.clear();
    }
}


//keypoint : ยกกำลัง2 สองด้าน จะได้ไม่ต้องคิด sqrt เพื่อเลขที่แม่นยำ และ เปลี่ยนจากการคิดระยะห่างจากเส้นรอบวงเป็ยคิดจากจุด ศก. แทน
// break ตรงที่ แนวแกน x หรือ y ห่างกันโดยที่ ไม่ต้องคิดอีกแกนก็ห่างพอแล้ว
// เพราะ logic คือ ถึง dx^2 + dy^2 จะ >= lim^2 แต่ถ้า เลื่อนไปเรื่อยๆ dy อาจลดลงทำให้ dx^2 + dy^2 ยังมีโอกาส < lim^2 อยู่
// แต่ถ้าหาก แค่ dx^2 เพียงอันเดียวก็ >= lim^2 แล้ว ก็ไม่มีเหตุผลที่จะต้องเลื่อนไปต่อ เนื่องจาก dx จะเพิ่มขึ้นเรื่อยๆเสมอ เพราะ sort มาแล้ว

//หมายเหตุ : if(dy > lim) ที่จริงไม่รู้ทำไมถึงผ่าน tc เพราะถ้าเลื่อนไปเรื่อยๆอาจจะมีโอกาสที่ dy จะลดลงอยู่ แต่ข้อนี้ลองใส่เพื่อให้ผ่าน time แล้วดันถูกเฉย