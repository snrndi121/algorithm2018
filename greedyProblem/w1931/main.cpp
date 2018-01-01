#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* To solve this */
/*
- We can use a greedy searching. The meetings are sorted by the end time.
	Then count the meeting if the before end time is lower than the current input's start time.
	
*/
/* def */
typedef pair < int, int > pType;

/* var */
vector < pType > input;
int T=0;

/* func */
void input_read();
void scheduling_meeting();

void init_input();
bool sortbyend(pType& a, pType& b);
bool isBooked(int* sch, int start, int end);
void bookSCH(int* sch, int start, int end);

int main()
{
	input_read();
	init_input();
	scheduling_meeting();
	return 0;
}
/* func::process */
void input_read()
{
	int n=0, s=0, e=0;
	cin >> n;
	while(n-- >0)
	{
		cin >> s >> e;
		input.push_back(make_pair(s,e));
		if( T < e + 1) { T = e + 1;}
	}
}
void scheduling_meeting()
{
		vector < pType >::iterator it=input.begin();
		vector < pType >::iterator it_end=input.end();
		int last=0;
		int countOfmeeting=0;

		for(; it != it_end; ++it)
		{
				pType p=(*it);
				if( last < p.first)
				{
						countOfmeeting++;
						last=p.second;
				}
		}
		cout << countOfmeeting;
}
/* func::method */
void init_input()
{
		sort(input.begin(), input.end(), sortbyend);
}
bool sortbyend(pType& a, pType& b)
{
		return a.second < b.second;
}
