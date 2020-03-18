//비트 마스크 문제
//대표 문제 : 집합

/* 피자집 예제 */
/*
  - 토핑 선택 가능(0 ~ 19)
  - 토핑 20가지
*/
//0...0 은 공집합
//1...1 은 꽉찬 집합 : 토핑 다 올라간 상태
#include <iostream>
#include <cstring>
using namespace std;

void addTopping(int *t, int _which)
{
    cout << ">> topping add (" << _which << ")"<< endl;
    (*t) |= (1 << _which);
    cout << ">> res_add :" << *t << endl;
}
void delTopping(int* t, int _which)
{
    cout << ">> topping del (" << _which << ")"<< endl;
    (*t) &= ~(1 << _which);
}
void toggleTopping(int*t, int _which)
{
    cout << ">> topping toggle (" << _which << ")"<< endl;
    (*t) ^= (1 << _which);
}
void printTopping(int t, int _which)
{
    cout << ">> printing topping state : (" << _which << ") topping is ";
    if (t & (1 << _which))
      cout << "in" << endl;
    else
      cout << "out" << endl;
}
string printAllTopping(int t)
{
    if (t == 0) return 0;
    else if (t == 1) return "1";
    string _tail = t%2 == 0? "0" : "1";
    return printAllTopping(t/2) + _tail;
}
int UnionTopping(int p1, int p2)
{
    cout << ">> get these pizza all topping" << endl;
    return p1 | p2;
}
int InterTopping(int p1, int p2)
{
    cout << ">> get these pizza common topping" << endl;
    return p1 & p2;
}
int MinusTopping(int p1, int p2)
{
    cout << ">> get these pizza topping which the former have only" << endl;
    return p1 & ~p2;
}
int MakeGoldBeefPizza()
{
    cout << "\n MakeSample Pizza1\n";
    /* bit operation */
    return 899232;
}
int MakeMushRoomPizza()
{
    cout << "\n MakeSample Pizza2\n";
    /* bit operation */
    return 343123;
}
int main()
{
  int topping = 0;
  int fullPizza = (1 << 20) - 1; //1 뒤에 20개의 0이 있음. 여기서 1 빼면 1이 다켜진 상태가 됨.
  //원소 추가
  addTopping(&topping, 3);
  //원소 확인
  printTopping(topping, 3);
  printTopping(topping, 4);

  //원소삭제
  delTopping(&topping, 3);
  printTopping(topping, 3);

  //토글링
  toggleTopping(&topping, 3);
  printTopping(topping, 3);

  //두 집한 연산하기
  int p1 = MakeGoldBeefPizza();
  int p2 = MakeMushRoomPizza();
  cout << printAllTopping(p1) << endl;
  cout << printAllTopping(p2) << endl;
  int r1 = UnionTopping(p1, p2);
  cout << printAllTopping(r1) << endl;
  int r2 = InterTopping(p1, p2);
  cout << printAllTopping(r2) << endl;
  int r3 = MinusTopping(p1, p2);
  cout << printAllTopping(r3) << endl;

  return 0;
}
