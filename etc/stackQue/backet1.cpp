#include <iostream>
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
//func

void read_input()
{
    for (int i = 0; i < 10; ++i) ms.push(i);
    cout << ms.top() << endl;
    for (int i = 0; i < 11; ++i) ms.pop();
    cout << ms.top() << endl;

}
void write_output()
{

}
int main()
{
    read_input();
    write_output();
    return 0;
}
