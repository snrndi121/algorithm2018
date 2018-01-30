#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

/* def */
typedef pair < int, int > pType;
class craft{
public :
    craft() {};
    void setGoal(int g) { goal = g;}
    void setDelay(int* d, int sz)
    {
        for (int i=0; i < sz; ++i) { delay.push_back(d[i]);}
    }
    void setRules(pType r[], int sz)
    {
        rules.resize(sz);
        indegree.resize(sz);

        for (int i=0; i < sz; ++i)
        {
            int x = r[i].first - 1, y = r[i].second - 1;
            rules[x].push_back(y);
            indegree[y]++;
        }
    }
    unsigned getIndegree(vector < int >& v)
    {
        unsigned i=0;
        v.reserve(indegree.size());
        for (; i < indegree.size(); ++i) { v.push_back(indegree[i]);}
        return i;
    }
    unsigned getRules(unsigned int i, list < int >& l)
    {
        for ( list < int >::iterator it = rules[i].begin(); it != rules[i].end(); ++it)
        {
            l.push_back(*it);
        }
        return rules[i].size();
    }
    bool getRules(unsigned int i) const { return (rules[i].size() == 0);}
    int getDelay(int i ) { return delay[i];}
    int getGoal() const { return goal;}
private :
    int goal;
    vector < int > indegree;
    vector < list < int > > rules;
    vector < int > delay;
};
/* var */
vector < int > res;

/* func */
void input_read(craft& c);
void building_craft(craft& c);
void print_res();

int main()
{
    int testcase;
    cin >> testcase;
    while(testcase-- > 0)
    {
        craft c;
        input_read(c);
        building_craft(c);
    }
    print_res();
    return 0;
}
void input_read(craft& c)
{
    /* Initializing */
    /* Get numf of bulidings and their rules */
    int i = 0, numOfBuliing = 0, numOfrules = 0;
    cin >> numOfBuliing >> numOfrules;

    /* Get info about cost of buildings */
    int* delay = new int[numOfBuliing];
    while(i < numOfBuliing) { cin >> delay[i++];}
    c.setDelay(delay, numOfBuliing);

    /* Get info about process of craftings */
    i = 0;
    pType* rules= new pType[numOfrules];
    while(i < numOfrules)
    {
        cin >> rules[i].first >> rules[i].second;
        i++;
    }
    c.setRules(rules, numOfrules);

    /* Get goal */
    cin >> i;
    c.setGoal(i - 1);
}
void building_craft(craft& c)
{
    /* Initializing */
    queue < int > searchQue;
    vector < int > indegree;
    int sz = c.getIndegree(indegree), currentCost = 0, goal = c.getGoal();

    /* Set searchQue */
    for ( int i=0; i<sz; ++i)
    {
        if (indegree[i] == 0) { searchQue.push(i);}
    }
    currentCost = c.getDelay(searchQue.front());
    list < int > siblings;

    /* Set resQue */
    while (!searchQue.empty() && searchQue.front() != goal)
    {
        int indexOftop = searchQue.front();
        searchQue.pop();

        /* step1. Get list of rules[i] */
        list < int > li;
        c.getRules(indexOftop, li); //get Rules form class craft which have the 'indexOftop' index.

        /*step2. Set siblings from li[i] */
        for (list < int >::iterator it = li.begin(); it != li.end(); ++it)
        {
            int child = (*it);
            indegree[child]--;
            /*
            if ((indegree[child] == 0 && !c.getRules(child))
              ||(indegree[child] == 0 && child == goal))
            */
            if (indegree[child] == 0 && (!c.getRules(child) || child == goal))
            {
                siblings.push_back(child);
            }
        }

        /* step3. Add sibling into searchQue */
        if(searchQue.empty())
        {
            cout << " >> siblings :";
            int maxOfsibling = 0;
            for (list < int >::iterator it = siblings.begin(); it != siblings.end(); ++it)
            {
                cout << (*it) + 1 << '(' << c.getDelay(*it) << ") ";
                maxOfsibling =  max(maxOfsibling, c.getDelay(*it));
                searchQue.push(*it);
            }
            cout << endl;
            siblings.clear();
            currentCost += maxOfsibling;
        }
    }
    res.push_back(currentCost);
}
void print_res()
{
    vector < int >::iterator it = res.begin();
    vector < int >::iterator it_end = res.end();
    for (; it != it_end; ++it) { cout << (*it) << endl;}
}
