#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
//def
typedef vector < int > vtype;
typedef pair < int, int > ptype;
typedef vector < vtype > vvtype;
//
typedef vtype type1;
typedef vvtype type2;
//var
type1 input1;
//func
void genInput()
{

}
template < typename T >
void printAnswer(const vector <T>& src)
{
    for (int i = 0; i < src.size(); ++i) {
        cout << src[i] << endl;
    }
}

int main()
{
    genInput();
    solution(_dataSource, _tags);
    return 0;
}
