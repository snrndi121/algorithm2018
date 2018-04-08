#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

/* to solve this */
/*
 You just need to know about essential operations of stack in library.
 Then receive commands from input data and save it into some variables.
 In this case, I used 2 variables.
	- stack < int > : to receive given data
	- vector < int > : to save results regarding to commands
*/
/* def */
using namespace std;

/* func */
void readCMD(stack < int >& _src, vector < int >& res);
int handlingCMD(string _s, stack < int >& _src);
void printRes(vector < int >& res);

/* var */
int main()
{
    stack < int > dataStack;
	vector < int > res;
	cout << "\n readCMD " << endl;
    readCMD(dataStack, res);
	printRes(res);
    return 0;
}
void readCMD(stack < int >& _src, vector < int >& _res)
{
    int n;
    cin >> n;

    for (int i = 0; i<n; ++i)
    {
        string s= "";
        cin >> s;
		// If a command is push, then receive number
        if (s.compare("push") == 0)
        {
            int x = 0;
            cin >> x;
            _src.push(x);
        } 
		else
        {	
			_res.push_back(handlingCMD(s, _src));
        }
    }
}
int handlingCMD(string s, stack < int >& _src)
{
	  int _res = 911201;
	  //Operation1.pop
      if (s.compare("pop") == 0)
      {
		  //If stack is not empty, it prints the top and get rid of it from the stack
          if (!_src.empty())
          {
               _res =  _src.top();
			   _src.pop();
          } 
		  //If stack is empty, it prints '-1'
		  else
          {
              _res = -1;
          }
      }
	  //Operation2.size
      else if (s.compare("size") == 0)
      {
             _res = _src.size();
      }
	  //Operation3.empty
      else if (s.compare("empty") == 0)
      {
          if (_src.empty()) { _res = 1;}
          else { _res = 0;}
      }
	  //Operation4.top
      else if (s.compare("top") == 0)
      {
          if(!_src.empty()) { _res = _src.top(); }
          else _res = -1;
      }
      else {;}
	  return _res;
}
void printRes(vector < int >& _res)
{
	for (unsigned int i = 0; i < _res.size(); ++i)
	{
		cout << _res[i] << endl;
	}
}
