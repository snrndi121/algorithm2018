/* To solve this
  * It was the key to know about 'topological sorting'.
*/
  #include <iostream>
  #include <vector>
  #include <queue>

  using namespace std;

  /* def */
  typedef vector < int > vType;
  typedef vector < vType > vvType;
  /* var */
  int goal;
  vector < int > res;

  /* func */
  void input_read(vType& _indegree, vType& _cost, vvType& _rules);
  void building_craft(vType& _indegree, vType& _cost, vvType& _rules);
  void print_res();

  int main()
  {
      int testcase;
      cin >> testcase;
      while(testcase-- > 0)
      {
          vector < int > indegree, cost;
          vector < vector < int > > rules;
          input_read(indegree, cost, rules);
          building_craft(indegree, cost, rules);
      }
      print_res();
      return 0;
  }
  void input_read(vType& _indegree, vType& _cost, vvType& _rules)
  {
      /* Initializing */
      int i = 0 , numOfBuliing = 0, numOfrules = 0, x = 0, y = 0;
      cin >> numOfBuliing >> numOfrules;

      _indegree.resize(numOfBuliing);
      _rules.resize(numOfBuliing);

      for(int k=0; k<numOfBuliing; ++k) { _rules[k] = vector < int >();}

      /* Get info about cost of buildings */
      int _d = 0;
      while(i++ < numOfBuliing) { cin >> _d; _cost.push_back(_d);}

      /* Get info about process of craftings */
      i = 0;
      while(i < numOfrules)
      {
          cin >> x >> y;
          _rules[x - 1].push_back(y - 1);
          _indegree[y - 1]++;
          i++;
      }
      /* Get goal */
      cin >> goal;
  }
  void building_craft(vType& _indegree, vType& _cost, vvType& _rules)
  {
      /* Initializing */
      queue < int > searchQue;
      vector < int  > weight;
      unsigned sz = _indegree.size();
      weight.resize(sz);
      /* Set searchQue */
      for (unsigned i=0; i < sz; ++i)
      {
          if (_indegree[i] == 0) { searchQue.push(i);}
      }
      int top = searchQue.front();
      weight[top] = _cost[top];

      /* set searchQue */
      while (!searchQue.empty())
      {
          /* step1. Get top from searchQue */
          top = searchQue.front();
          searchQue.pop();

          /*step2. Set siblings from rules[top] */
          for (vector < int >::iterator it = _rules[top].begin(); it != _rules[top].end(); ++it)
          {
              int child = (*it);
              _indegree[child]--;
              /* solution key : Recurrence relation */
              weight[child] = max(weight[child], weight[top] + _cost[child]);
              /* */
              if (_indegree[child] == 0) { searchQue.push(child);}
          }
      }
      res.push_back(weight[goal - 1]);
  }
  void print_res()
  {
      vector < int >::iterator it = res.begin();
      vector < int >::iterator it_end = res.end();
      for (; it != it_end; ++it) { cout << (*it) << endl;}
  }
