#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

/* var */
const int N = 30;
string str;

/* func */
void input_read();
int find_maximum();
void swap(string& s, int i, int j);
int isMultiple(const string& s);
int isLowerIn(string& s, char item);
string stackTostr(stack < char > sstack);

void print_stack(stack < char > s);

int main()
{
    input_read();

    int res=find_maximum();
    cout << res;
}
void input_read()
{
    cin >> str;
    sort(str.begin(), str.end(), greater < char >());
}
int find_maximum()
{
    if(str.size() < 2) { return -1;}
    //Init_stack
    stack < char > strStack;
    for(unsigned i=0; i < str.size(); ++i)
    {
        strStack.push(str[i]);
    }
    //init
    string s=stackTostr(strStack);
    int res=isMultiple(s);
    if(res != -1) { return res;}
    cout << " base :" << s << endl;
    //find nextnumber by descent
    string CGroup;
    while(!strStack.empty())
    {
        //set next str
        char stackTop=strStack.top();
        int i=isLowerIn(CGroup, stackTop);
        cout << endl;
        if(i != -1)
        {
            //part1. Switch(cur_top, new_top)
            strStack.pop();
            strStack.push(CGroup[i]);

            print_stack(strStack);
            cout << " >> " << CGroup[i] << " is in G(" << i << ")" << endl;
            cout << " >> it will switch " << stackTop << endl;
            CGroup[i]=stackTop;

            //part2. CGroup.sort()
            sort(CGroup.begin(), CGroup.end(), greater < char >());
            cout << " >> CGroup size : " << CGroup.size() << endl;

            //part3. Push CGroup all into strStack
            for(int j=0; (unsigned) j < CGroup.size(); ++j) { strStack.push(CGroup[j]);}
            CGroup.clear();
            print_stack(strStack);

            //part4. Set current number by a new string
            string s=stackTostr(strStack);
            //part5. Check its multiplicity
            int res=isMultiple(s);
            cout << " s :" << s << ", res :" << res << endl;
            if(res != -1) { return res;}
        }
        else {
            //part1. Set CGroup
            //if there is no lower value in the CGroup about the current top
            strStack.pop();
            CGroup.push_back(stackTop);
        }
    }
    return -1;
}
int isLowerIn(string& cgroup, char item)
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
string stackTostr(stack < char > sstack)
{
    //stack - > string
    string s;
    while(!sstack.empty())
    {
        char c=sstack.top();
        sstack.pop();
        s.insert(s.begin(), c);
    }
    return s;
}
int isMultiple(const string& s)
{
    int snum=atoi(s.c_str()); //stoi(s);
    return (snum % N == 0)? snum : -1;
}
void swap(string& s, int i, int j)
{
    char temp=s[i];
    s[i]=s[j];
    s[j]=temp;
}
void print_stack(stack < char > s)
{
    cout << endl;
    while(!s.empty())
    {
        char ctop=s.top();
        s.pop();
        cout << ctop << " - ";
    }
}
