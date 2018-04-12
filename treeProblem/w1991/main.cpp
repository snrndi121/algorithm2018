#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* def */
typedef pair < char, char* > node;

/* func */
void input_read(); 
bool sortByparent(node& a, node& b) { return a.first < b.first; }
void treeSearching();
void preorder(char _node);
void inorder(char _node);
void postorder(char _node);

void printVector()
{
	for (vector < node >::iterator it = input.begin();
			it != input.end(); ++it)
	{
		cout << it.first << endl;
	}
}
/* var */
vector < node > input;

int main()
{
	input_read();
	treeSearching();
	return 0;
}
void input_read()
{
	/* Init Input_data */
	int num;
	cin >> num;

	/* Get input */
	char parent, child[2];
	for (int i=0; i< num; ++i)
	{
		cin >> parent >> child[0] >> child[1];
		input.push_back(make_pair(parent, child));	
	}	
	printVector();
	sort(input.begin(), input.end(), sortByparent);
	printVector();
}
void treeSearching()
{
	preorder('A');
	cout << endl;

	inorder('A');
	cout << endl;

	postorder('A');
	cout << endl;
}
void preorder(char _node) 
{
	unsigned char i = _node - 65;
	char* _child = input[i].second;

	if (_node == '.')
		return ;
	cout << (char)_node;
	preorder(_child[0]);
	preorder(_child[1]);
}
void inorder(char _node)
{
	unsigned char i = _node - 65;
	char* _child = input[i].second;

	if (_node == '.')
		return ;
	inorder(_child[0]);
	cout << (char)_node;
	inorder(_child[1]);
}
void postorder(char _node)
{
	unsigned char i = _node - 65;
	char* _child = input[i].second;

	if (_node == '.')
		return ;
	postorder(_child[0]);
	postorder(_child[1]);
	cout << (char)_node;
}

