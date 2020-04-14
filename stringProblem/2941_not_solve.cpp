#include <iostream>
using namespace std;

/*
  * 문자열이 몇 개의 문자로 구성되어있는지 찾아라
  * 특별한 문자와 일반 영문 소문자가 포함이 되어있을 때
dz=
c=
s=
z=
c-
d-
lj
nj

dz=c-c=s=d-ljnj

(6->3)ddz=z=
(5->3)dd-z=
(8->4)ddz=d-z=
(9->6)ljes=njak
*/
int main()
{
    string _input; cin >> _input;
    const string marker = "dz=c-c=s=d-ljnj";
    int f = 0, temp = 0;
    int count = _input.size();
    for (int i = 0; i < _input.size(); ++i) {
        int m = marker.find(_input[i]);
        cout << endl << _input[i] << ":(" << temp << "," <<  m << ")" << endl;
        if (m != -1 && (m-temp) == 1) {//문자열안에 있는 녀석이면
          cout << "catch1";
          count--;
          temp = m;
          if (m+temp == 1) count--;//dz면
        }
    }
    cout << count << endl;
}
