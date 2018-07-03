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
bool point_asc(point a, point b) { return a.x != b.x ? a.x < b.x : a.y < b.y;}
class bridge {
public:
    bridge(int _numOfstone = 0, int _numOfcmd = 0) {
        numOfstone = _numOfstone, numOfcmd = _numOfcmd;
        action = new char[numOfcmd];
        current = NULL;
    }
    void create_bridge() {
        //get command_action
        cout << " >> get command : ";
        for (int i = 0; i < numOfcmd; ++i) { cin >> action[i];}
        //get stone_point
        point* spoint[numOfstone];
        for (int i = 0; i < numOfstone; ++i) {
            int point_x, point_y;
            cin >> point_x >> point_y;
            spoint[i] = new point(point_x, point_y);
        }
        cout << " >> bef of sort " << endl;
        for (int i = 0; i < numOfstone; ++i) {
            cout << spoint[i]->x << ", " << spoint[i]->y << endl;
        }
        //spoint[0] is a starting point
        //therefore, exclude it.
        cout << " >> result of sort " << endl;
        sort(spoint[0], spoint[numOfstone - 1], point_asc);
        for (int i = 1; i < numOfstone; ++i) {
            cout << spoint[i]->x << ", " << spoint[i]->y << endl;
        }
        //bridge list;
        for (int i = 0; i < numOfstone; ++i) {
            stone* new_stone;
            if (current != NULL) {
              new_stone = new stone(*spoint[i], current, 0);
              current->right = new_stone;
              current = new_stone;
            } else {
                new_stone = new stone(*spoint[i], 0, 0);
                first = current = new_stone;
            }
        }
    }
    void create_bridge2() {
        //get command_action
        cout << " >> get command : ";
        for (int i = 0; i < numOfcmd; ++i) { cin >> action[i];}
        //get stone_point
        point spoint[numOfstone];
        for (int i = 0; i < numOfstone; ++i) { cin >> spoint[i].x >> spoint[i].y;}
        //spoint[0] is a starting point
        //therefore, exclude it.
        cout << " >> result of sort " << endl;
        sort(&spoint[1], &spoint[numOfstone], point_asc);
        for (int i = 1; i < numOfstone; ++i) {
            cout << spoint[i].x << ", " << spoint[i].y << endl;
        }
        //bridge list;
        for (int i = 0; i < numOfstone; ++i) {
            stone* new_stone;
            if (current != NULL) {
              new_stone = new stone(spoint[i], current, 0);
              current->right = new_stone;
              current = new_stone;
            } else {
                new_stone = new stone(spoint[i], 0, 0);
                first = current = new_stone;
            }
        }
        first->left = current;
        current->right = first;
        current = first;
    }
    void solve_algorithm() {
        int i =0;
        bool jump_flag = true;
        while(jump_flag && i < numOfcmd) {
            //Do action[i]
            cout << "\n# doAction " << endl;
            jump_flag = doAction(action[i++], current);
        }
    }
    bool doAction(char _action, stone* _base) {
        stone* next_stone = _base->right;
        cout << " >> current_action : " << _action << endl;
        cout << " >> current_stone : " << _base->data.x << ", " << _base->data.y << endl;
        while (next_stone->right != 0) {
              //compare the difference between a point of start and a point of base
              char _call = whichAction(_base->data, next_stone->data);
              cout << " > call : " << _call << endl;
              if (_action == _call) {
                  cout << "src :" << _base->data.x << ", " << _base->data.y << " vs dst : " << next_stone->data.x << ", " << next_stone->data.y << endl;
                  cout << " > Get !!!" << endl;
                  current = next_stone;
                  delete_stone(_base);
                  return true;
              }
              next_stone = next_stone->right;
        }
        return false;
    }
    char whichAction(point& _src, point& _dst) {
        cout << "# whichAction " << endl;
        char res = DEFAULT_ACT;
        int diff_x = _dst.x - _src.x,
            diff_y = _dst.y - _src.y;
        if (abs(diff_x) == abs(diff_y)) {
            if (diff_x > 0 && diff_y > 0) { return 'A';}
            else if (diff_x > 0 && diff_y < 0) { return 'B';}
            else if (diff_x < 0 && diff_y > 0) { return 'C';}
            else if (diff_x < 0 && diff_y < 0) { return 'D';}
            else{;}
        }
        return res;
    }
    void delete_stone(stone* target) {
        //| target-> left | - | target | - | target->right |
        if (target->right != target->left) { //more than 2
            target->left->right = target->right;
            target->right->left = target->left;
        } else {
            first = target->right;
            first->right = 0;
            first->left = 0;
            current = first;
        }
        /*
        if (target != first) {
            target->left->right = target->right;
            target->right->left = target->left;
        } else {//init
            first = target->right;
        }
        */
        delete target;
    }
    void print_bridge() {
        stone* start = first;
        while(start->right != 0) {
            cout << start->data.x << ", " << start->data.y << endl;
            start = start->right;
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
    cout << "# Creating bridge list " << endl;steppingBridge.create_bridge2();
    //cout << "# Remaining stone list" << endl;steppingBridge.print_bridge();
    cout << "# Solving algorithm " << endl;steppingBridge.solve_algorithm();
    return 0;
}
