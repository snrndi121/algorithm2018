#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/* def */
#define N 30

/* var */
string s;

/* func */
void input_read(void);
int counterStr(void);
int IsLowerIn(string& CGroup, char item);
int isMultiple(const string& s);

/* To solve this */
/*
  Sort the input string 's' in big order. For example, input : 1234 then make it into '4321'.
  Because we have to find the largest number which is a multiple of 30. After that, Check the
  current combination where it is a mulitiple of 30

  To do : But this algorithm, now, is overtime. Therefore we should reduce the time.
*/
int main()
{
    input_read();

    int res=counterStr();
    cout << res << endl;

    return 0;
}
void input_read(void)
{
    cin >> s;
    sort(s.begin(), s.end(), greater < char > ());
}
int counterStr(void)
{
      if(s.size() < 2) { return -1;}

      int res=isMultiple(s);
      if(res != -1) { return res;}

      string temp;
      while(!s.empty())
      {
            char c = s.back();
            int res=IsLowerIn(temp, c);
            if(res != -1)
            {
                s.pop_back();
                s.push_back(temp[res]);
                temp[res]=c;

                sort(temp.begin(), temp.end(), greater <char>());

                //part3. Push CGroup all into s
                for(int j=0; (unsigned) j < temp.size(); ++j) { s.push_back(temp[j]);}

                temp.clear();

                //part5. Check its multiplicity
                int res=isMultiple(s);

                if(res != -1) { return res;}
            } else {
                //part1. Set temp
                //if there is no lower value in the temp about the current top
                s.pop_back();
                temp.push_back(c);
            }
        }
        return -1;
}
int IsLowerIn(string& cgroup, char item)
{
    for(int i=0; (unsigned) i < cgroup.size(); ++i)
    {
        if(cgroup[i] < item)
        {
            return i;
        }
    }
    return -1;
}
int isMultiple(const string& s)
{
    int snum=atoi(s.c_str()); //stoi(s);
    return (snum!=0 && snum % N == 0)? snum : -1;
}
