#include <iostream>
#define DEFAULT_NODE 0
using namespace std;

class node {
	friend class nodechain;
public :
	node(int _data = 0, node* _next = 0) {
		data=_data, next=_next;
	}
private :
	int data;
	node* next;
};
class nodechain {
public :
	nodechain(int num = 0, int pin = 0) {
		first = last = NULL;
		pin_num = num, pin_flag = pin;
	}
	void create_node(int num) {
		for (int i = 0; i < num; ++i) {
			node* new_node = new node(i + 1, 0);
			if (first != NULL) {
				last->next = new_node;
				last = new_node;
			}
			else {
				first = new node(DEFAULT_NODE, new_node);
				last = new_node;
			}
		}
		last->next = first->next;
	}
	void solve_algorithm() {
		int i = 0;
		node* cur_node = first;
		cout << "<";
		while (first->next != last) {
			//find start point left side on target to be deleted
			for (int i = 0; i < pin_flag - 1; ++i)
				cur_node = cur_node->next;
			//delete : 'cur_node->next' willl be deleted
			del_node(cur_node, cur_node->next);
		}
		cout << first->next->data;
		cout << ">";
		delete first, last;
	}
	void del_node(node* base, node* target) {
		if (target->next == base->next) {//there are 2 elements
			cout << "last" << endl;
			cout << target->data << ", ";
			base->next = 0; first->next = base;
		}
		else {//more than 2
			cout << target->data << ", ";
			base->next = target->next;
		}
		//move last & first
		if (target == last) {
			last = base;
		}
		else if (target == first->next) {
				first->next = target->next;
		}
		delete target;
	}
	void print_node(int _until) {
		node* cur_node = first->next;
		for (int i = 0; i < _until; ++i) {
			cout << cur_node->data << endl;
			cur_node = cur_node->next;
		}
	}
private :
	node* first, *last;
	int pin_num, pin_flag;
};
int main() {
	int a, b;
	cin >> a >> b;
	nodechain chain(a, b);
	//cout << "# create_chain " << endl;
	chain.create_node(a);
	/*
		cout << "# print_chain " << endl;
		chain.print_node(a);
	*/
	//cout << " # solve_problem # " << endl;
	chain.solve_algorithm();
}