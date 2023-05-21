#include<bits/stdc++.h>

using namespace std;

const int N = 5e5+5 ;

int n , k , m ;

struct DATA{
    int ty , s , id ;

    bool operator < (const DATA &other) const {
        if(s != other.s)
            return s < other.s ;
        else return ty < other.ty ;
    }
};

vector<DATA> rq ;
bool ans[N] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> m ;
    for(int i=1 ,x , y;i<=n;i++){
        cin >> x >> y ;
        rq.push_back({1 , x , i});
        rq.push_back({0 , y+1 , i});
    }

    sort(rq.begin() , rq.end()) ;

    int cnt = 0 ;
    for(auto &[ty , s , id] : rq){
        if(ty){
            if(cnt < k){
                cnt++;
                ans[id] = true ;
            }
        }
        else {
            if(ans[id]){
                cnt--;
            }
        }
    }

    for(int i=1 , x;i<=m;i++){
        cin >> x ;
        cout << (ans[x] ? "Y " : "N ") ;
    }
}
//Sweep line technique
//keypoint : จะไล่จากตัวที่ขอเริ่มก่อน ไปเรื่อยๆ แยกเป็น point 2 ประเภท คือ point + กับ  - ถ้าเจอ + แล้วตอนนี้ยังมีคนใช้ไม่ถึง k ก็เพิ่ม cnt ไปอีก แต่ถ้าเจอ - แล้ว ตัว - ตัวนั้นเป็นตัวที่ก่อนหน้านี้ตอนเจอ + ใช้แล้วก็ให้ลด cnt เพราะคำขอนั้นสิ้นสุดตรงนี้
//warning : 1. เวลาเจอ - ที่ต้อง เช็ค if(ans[id]) เพราะต้่องให้แน่ใจว่าตัวที่จะลบนั้นเป็นตัวที่ก่อนหน้านี้ตัดสินใจใช้เท่านั้น
//    2. การ sort ถ้าตัว s เท่ากัน ต้อง sort ตามประเภท + , - ให้ประเภท - ขึ้นก่อน เพราะกันกรณีที่มีตัวจบของตัวก่อนหน้ามาจบพร้อมตัวที่กำลังจะขอเริ่ม ก็ให้ลบตัวที่จบออกก่อนค่อยพิจารณาตัวที่ขอเรื่มว่าถึง k ไหม


//important : แนวคิดสำคัญของข้่อนี้คือการพิจารณาแค่ point ที่สำคัญ ไม่จำเป็นต้องคิดเรียงทุก วินาที
