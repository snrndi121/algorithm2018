#include <iostream>
#include <vector>

using namespace std;

/* To slove
  * Use the already calculated data.
*/
/* def */
typedef pair < int, int > pType;

/* var */
vector < pType > accum; //to save accumulated fibonachi(n) data

/* func */
int* input_read(int& num);
void init_accum();
pType fibo(int n);
bool isset(int n);
int (*countCall(int num, int input[]))[2];
void result_print(int n, int (*res)[2]);

int main()
{
    int num;
    int* input = input_read(num);
    init_accum();

    int (*res)[2] = countCall(num, input);

    result_print(num, res);

    return 0;
}
//initialize the accumulated data to fibo(0) and fibo(1)
void init_accum()
{
    accum.push_back(make_pair(1, 0)); //fibo(0) : (1, 0)
    accum.push_back(make_pair(0, 1)); //fibo(1) : (0, 1)
}
//read input data
int* input_read(int& count)
{
    int i=0;
    cin >> count;
    int* input = new int[count];

    while(i < count)
    {
        cin >> input[i++];
    }
    return input;
}
//count the fibonacci calling
int (*countCall(int _num, int _input[]))[2]
{
    int (*numOfcall)[2] = new int[_num][2];
    for(int i = 0; i < _num; ++i)
    {
        //If before value is set, then use it
        int target = _input[i];
        if(isset(target))
        {
            numOfcall[i][0] = accum[target].first;
            numOfcall[i][1] = accum[target].second;
        } else {
            pType p = fibo(target);
            numOfcall[i][0] = p.first;
            numOfcall[i][1] = p.second;
        }
    }
    return numOfcall;
}
//check the accum[i] whether its values is set
bool isset(int i)
{
    return accum.size() > (unsigned) i ? true : false;
}
//modified fibonachi call
pType fibo(int n)
{
  if(n == 0)
  {
    return accum[0];
  } else if(n == 1)
  {
    return accum[1];
  } else
  {
      if(isset(n-1) && isset(n-2))
      {
          pType a=accum[n-1], b=accum[n-2];
          pType target=make_pair(a.first + b.first, a.second + b.second);
          if(!isset(n)) { accum.push_back(target); }
          return target;
      }
      else if(!isset(n-1) && isset(n-2))
      {
          pType a = fibo(n-1), b = accum[n-2];
          pType target=make_pair(a.first + b.first, a.second + b.second);
          accum.push_back(target);
          return target;
      }
      else
      {
          pType a = fibo(n-1), b = fibo(n-2);
          pType target=make_pair(a.first + b.first, a.second + b.second);
          accum.push_back(target);
          return make_pair(a.first + b.first, a.second + b.second);
      }
  }
}
//print result
void result_print(int n, int (*res)[2])
{
    for(int i=0; i < n; ++i)
    {
        cout << res[i][0] << ' ' << res[i][1] << endl;
    }
}
