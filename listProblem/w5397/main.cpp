#include <iostream>
#include <algorithm>
#include <cstdlib>

#define DEFAULT_ACT '_'
using namespace std;

struct point {
    point(int _x = 0, int _y = 0) {x = _x, y = _y;}
    int x, y;
};
class stone {
  friend class bridge;
public:
    stone(point _data = 0, stone* _left = 0, stone* _right = 0) {
        data = _data;
        left = _left, right = _right;
    }
private:
  point data;
  stone* left, *right;
};
bool point_asc(point a, point b) { return a.x < b.x && a.y < b.y;}
class bridge{
public:
  bridge(int _numOfstone = 0, int _numOfcmd = 0) {
      numOfstone = _numOfstone, numOfcmd = _numOfcmd;
      action= new char[numOfcmd];
      first = new stone(new point(0, 0));
      current = first;
  }
  void create_bridge() {
      //get command
      for (int i = 0; i < numOfcmd; ++i) { cin >> action[i];}
      //get stone_point
      point* spoint[numOfstone];
      for (int i = 0; i < numOfstone; ++i) {
          int point_x, point_y;
          cin >> point_x >> point_y;
          spoint[i] = new point(point_x, point_y);
      }
      //spoint[0] is a starting point
      //therefore, exclude it.
      sort(spoint[1], spoint[numOfstone], point_asc);
      cout << ">> starter :" << spoint[0].x << spoint[y] << endl;
      for (int i = 1; i < numOfstone; ++i) {
          cout << spoint[i].x << ", " << spoint[i].y << endl;
      }
      //bridge list;
      for (int i = 0; i < numOfstone; ++i) {
          stone* new_stone = new stone(spoint[i], current, 0);
          current->right = new_stone;
          current = new_stone;
      }
  }
  bool doAction(char _action, stone* _base) {
      stone* next_stone = _base->right;
      while (next_stone->right != 0 ) {
            //compare the difference between a point of start and a point of base
            char _call = whichAction(_base, next_stone);
            if (_action == _call) {
                current = new_stone;
                delete_current(_base);
            }
            new_stone = new_stone->right;
      }
      return false;
  }
  char whichAction(point* _src, point* _dst) {
      char res = DEFAULT_ACT;
      int diff_x = _src->x - _dst->x,
          diff_y = _src->y - _dst->y;
      if (abs(diff_x) == abs(diff_y)) {
          if (diff_x > 0 && diff_y > 0) { return 'A';}
          else if if (diff_x > 0 && diff_y < 0) { return 'B';}
          else if (diff_x < 0 && diff_y > 0) { return 'C';}
          else if (diff_x < 0 && diff_y < 0) { return 'D';}
          else{;}
      }
      return res;
  }
  void solve_algorithm() {
      int i =0;
      bool jump_flag = true;
      current = first->right;
      while(jump_flag && i < numOfcmd) {
          //Do action[i]
          jummp_flag = doAction(action[i++], current);
      }
  }
  void delete_stone(stone* target) {
      //| target-> left | - | target | - | target->right |
      if (target != first) {
          target->left->right = target->right;
          target->right->left = target->left;
      }
      delete target;
  }
  void print_bridge() {
      stone* start = first;
      while(start->right != 0) {
          cout << start->data.x << ", " >> start->data.y << endl;
      }
  }
private:
  int numOfcmd, numOfstone;
  char* action;
  stone* first, *current;
};
int main() {
    int a, b;
    cin >> a >> b;
    cout << "# Initialize brigde " << endl;bridge steppingBridge(a, b);
    cout << "# Creating bridge list " << endl;steppingBridge.create_bridge();
    cout << "# Solving algorithm " << endl;steppingBridge.solve_algorithm();
    cout << "# Remaining stone list" << endl;steppingBridge.print_bridge();
    return 0;
}
