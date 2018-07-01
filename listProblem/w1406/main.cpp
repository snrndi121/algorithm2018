#include <iostream>
#include <string.h>

/*
 cursor actuall cannot be on first.
 Therefore, (L + 1) is range of movement of cursor when there is L string.
*/
#define DEFAULT_WORD ' '
#define LEN_STR 100000
using namespace std;

class word {
friend class sentence;
public:
  word(char _data = 0, word* _left = 0, word* _right = 0)
  { data = _data, left = _left, right = _right;}
private:
  char data;
  word* left, *right;
};
class sentence {
public:
  sentence() {
    first = new word(DEFAULT_WORD, 0, 0);
    last = new word(DEFAULT_WORD, 0, 0);
    mcursor = NULL;
  }
  void create_base() {
      //read initial string
      char input[LEN_STR];
      cin >> input;
      int len = strlen(input);
      //make string to linked list
      for (int i = 0; i < len; ++i ) {
          word* new_word;
          if (mcursor != NULL) {
              new_word = new word(input[i], mcursor, 0);
              mcursor->right = new_word;
              mcursor = new_word;
          }
          else {
              new_word = new word(input[i], first, 0);
              first->right = new_word;
              mcursor = new_word;
          }
      }
      //set 'last'
      mcursor-> right = last;
      last->left = mcursor;
      mcursor = last;
  };
  //insert a word on only left
  void insert_word(word* _base, char _data) {
      //| _where->left | - | new word | - | _where |
      if (_base != first) {
          word* new_word = new word(_data, _base->left, _base);
          _base->left->right = new_word;
          _base->left = new_word;
      } else {
          //| _where | - | new_word | - |_where->right |
          word* new_word = new word(_data, _base, _base->right);
          _base->right->left = new_word;
          _base->right = new_word;
      }
  };
  void delete_word(word* base) {
      //| target->left | - | target | - | base |
      if (base != first && base->left != first) {
          word* target = base->left;
          target->left->right = base;
          base->left = target->left;//mcursor = leftTotarget;
          delete target;
      } else {
      /*ignore the command*/}
  };
  void solve_algorithm() {
    //read command
    int count = 0;
    char command[2];
    cin >> count;
    for (int i = 0; i < count; ++i) {
        cin >> command[0];
        if (command[0] == 'L' && mcursor->left != first) {
            //have mcursor left
            //cout << ">> move left" << endl;
            mcursor = mcursor->left;
        } else if (command[0] == 'D' && mcursor != last) {
            //have mcursor right
            //cout << ">> move right" << endl;
            mcursor = mcursor->right;
        } else if (command[0] == 'B') {
            //cout << ">> delete" << endl;
            delete_word(mcursor);
            //print_chain();cout<<endl;
        } else if (command[0] == 'P') {
            //cout << ">> insert" << endl;
            cin >> command[1];
            insert_word(mcursor, command[1]);
            //print_chain();cout<<endl;
        } else {
          /* no action */
          //mcursor is on first or last now
        }
        //print_chain();cout<<endl;
        //cout << "mcursor_data :" << mcursor->data << endl;
    }
  };
  void print_chain() {
      word* start = first->right;
      while (start != last) {
        cout << start->data;
        start = start->right;
      }
  };
private:
  word* first, *last, *mcursor;
};
int main() {
    sentence wordchain;
    //cout << "# create # " << endl;
    wordchain.create_base();
    //cout << "# solve # " << endl;
    wordchain.solve_algorithm();
    //cout << "# print # " << endl;
    wordchain.print_chain();
}
