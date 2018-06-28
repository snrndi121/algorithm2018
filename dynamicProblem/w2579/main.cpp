/* origin of source : https://github.com/Mushu92/Baekjoon/blob/master/Dp/Steps.cpp
/* comment : uki408 */
/* To solve this
*

  * The point is that we must step the last stair.
  * ----------------------------------------------
  * |    i -3    |   i - 2   |   i - 1   |   i   |
  * ----------------------------------------------
  *
  * Therefore, There two cases exist, "[ i ] after [ i - 1 ]" and "[ i ] after [ i - 2 ]".
  * Course, We should add the proper accumulated cost for each case.
  * First of all, [ 0 ~ 2 ] stairs and accumulated cost are initialized.

*/
#include <iostream>
#include <vector>

using namespace std;

/* def */
/* var */
int sizeOfstairs;
vector < int > stairs;  //Info about stairs' cost
vector < int > accumWeight; //Accumulated cost by stairs[i]

/* func */
void input_read();
void step_stairs();
void print_answer();

int main(void)
{
    input_read();
    step_stairs();
    print_answer();

    return 0;
}
void input_read()
{
    int i=0;
    cin >> sizeOfstairs;
    stairs.reserve(sizeOfstairs);
	  accumWeight.reserve(sizeOfstairs);

    while(i < sizeOfstairs)
    {
        cin >> stairs[i++];
    }
}
void step_stairs()
{
    /* Initialize */
    accumWeight.push_back(stairs[0]); //accumWeight[0]
    accumWeight.push_back(max(stairs[1], stairs[0] + stairs[1])); //accumWeight[1]
    accumWeight.push_back(max(stairs[0] + stairs[2], stairs[1] + stairs[2])); //accumWeight[2]

    /* Exploring stairs */
    for (int i = 3; i < sizeOfstairs; ++i)
    {
        accumWeight.push_back(max(accumWeight[i - 2] + stairs[i], //case(1) : [ i ] after [i - 2]
                            accumWeight[i - 3] + stairs[i - 1] + stairs[i])); //case(2) : [ i ] after [i - 1]
    }
}
void print_answer()
{
    int answer = accumWeight.size() - 1;
    cout << accumWeight[answer] << endl;
}
