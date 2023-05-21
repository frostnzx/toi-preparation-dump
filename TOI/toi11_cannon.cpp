#include<bits/stdc++.h>

using namespace std;

using pii = pair<int,int> ;

int n , m , q , l ;

vector<int> gun ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q >> l ;

    for(int i=1 , x;i<=n;i++){
        cin >> x ;
        gun.push_back(x);
    }

    while(q--){
        int ans = 0 ;
        vector<pii> pre , noins ;

        for(int i=1 ,y;i<=m;i++){
            cin >> y ;
            pre.push_back({y-l , 1});
            pre.push_back({y+l+1 , -1});
        }
        sort(pre.begin() , pre.end());

        int cnt = 0 , s ;
        for(auto [idx , ty] : pre){
            if(ty == 1){
                if(cnt == 0){
                    s = idx ;
                }
                cnt++;
            }
            else {
                cnt--;
            }

            if(cnt == 0){
                noins.push_back({s , idx-1});
            }
        }

        for(auto [x , y] : noins){
            ans += upper_bound(gun.begin() , gun.end() , y) - lower_bound(gun.begin() , gun.end() , x) ;
        }
        cout << ans << "\n" ;
    }
}
//keypoint : อาจไม่ต้อง สร้าง vector noins ขึ้นมาเพื่อเก็บช่วงตัวที่ไม่ intersect กันก็ได้ แต่เปลี่ยนเป็น หา lb กับ ub ธรรมดา
// แล้วเก็บค่าว่าหาไปมากสุดช่วงไหนแล้วแล้วจำกัดให้หามากสุดได้ตั้งแต่ค่า ub เก่าจนถึง ub ใหม่เพื่อกันนับตัวซ้ำในกรณีที่สองช่วง intersect กัน
// ทำแบบนี้ได้เพราะยังไงจุดวางปืนใหญ่อันใหม่ก็ไม่มีทางคลอบครุมไปถึงช่วงก่อนอันเก่าที่อันเก่าไปไม่ถึงอยู่แล้ว เพราะมันเรียงลำดับ idx กันและมีความยาว
// l ของแต่ละอันเท่ากัน แต่ถ้าความยาวของแต่ละอันไม่เท่ากันอาจต้องใช้วิธีเก็บช่วงที่ไม่ intersect แบบที่ทำอันนี้
