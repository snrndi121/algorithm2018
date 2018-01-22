#include <include>
#include <list>
#include <queue>

using namespace std;

/* def */
typedef pair < int, int > pType;
/* var */
int goal = 0;
list < int > res;

/* func */
void input_read();
void building_craft();
void calucating_craft();

int main()
{
    cin >> test;
    while(test-- > )
    {
        list < pType > craft;
        input_read(craft);
        building_craft(resQue, );
    }
    return 0;
}
list < int > input_read()
{
    /* Initializing */
    /* Get numf of bulidings and their rules */
    int i = 0, numOfBuliing = 0, numOfrules = 0;
    cin >> numOfBuliing >> numOfrules;

    /* Get info about cost of buildings */
    int* craftInfo = new int[numOfBuliing];
    while(i < numOfBuliing) { cin >> craftInfo[i++];}

    /* Get info about process of craftings */
    list < pType > craft;
    int x, y, i = 0;
    while(i < numOfrules)
    {
        cin >> x >> y;
        craft.push_back(make_pair(x, y));
    }
    /* Get goal */
    cin >> goal;
}
void building_craft()
{
    queue < int > exploreQue, resQue;

}
void calucating_craft()
{}
