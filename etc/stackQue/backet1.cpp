#include <iostream>
#include <stack>
#include <vector>
//def
using namespace std;
/*
  * stack 구현해보기
*/
// template< typename T >
// struct mstack {
//     mstack(T _size) {
//         size =_size;
//         arr = new T[size];
//     }
//     void push(T i) {
//         if (size == mtop || arr == NULL) {
//             cerr << "(cerr) stack is not ready"<< endl;
//         }
//         else {
//             arr[++mtop] = i;
//         }
//     }
//     void pop() {
//         if (mtop != -1) {
//             mtop--;
//         }
//     }
//     bool empty() { return top == -1;}
//     T top() const {
//         if (!empty()) return arr[mtop];
//         else -1;///실제 stack은 뭘 내보내지?
//     }
//     int mtop = -1;
//     int size;
//     T* arr;
// };
// struct mstack < int > ms(100);
//var
uint sam_size = 0;
vector < string > input_brackets;
//func
void read_input()
{
    cin >> sam_size;
    for (uint i = 0; i < sam_size; ++i) {
        string s;
        cin >> s;
        input_brackets.push_back(s);
    }
}
void write_output(bool _res)
{
    if (_res) cout << "YES" << endl;
    else cout << "NO" << endl;
}
bool solve_bracket(const string& src)
{
    const string openings = "({[", closing = ")}]";
    stack < char > remains;
    for (int i = 0; i < src.size(); ++i) {
        //시작인지 봐야하고
        //시작인데 저 범위 안에 들어오는 지 확인도 같이 해줘야한다.
        if (openings.find(src[i]) != -1)
          //만약 두 조건이 맞다면
          remains.push(src[i]);
        //시작이 아니라면
        else {
          //top()이 일단 존재를 해야함. -> 혹은 마지막에 논리연산 곱 시켜줘도 되겠다.
          if (remains.empty()) return false;
          //짝이 맞는지 확인
          if (openings.find(remains.top()) != closing.find(src[i])) return false;
          remains.pop();
        //아니라면 실패
        }
    }
    //마지막에 남은 값이 있다면 false;
    return remains.empty();
}
int main()
{
    read_input();
    for (int i = 0; i < sam_size; ++ i) {
      bool res = solve_bracket(input_brackets[i]);
      write_output(res);
    }
    return 0;
}
