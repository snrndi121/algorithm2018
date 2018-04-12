#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* def */
typedef pair < char, char > child;
typedef pair < char, child > node;

/* func */
void input_read(); 
bool sortByparent(node& a, node& b) { return a.first < b.first; }
void treeSearching();
void preorder(char _node);
void inorder(char _node);
void postorder(char _node);

void printVector();
/* var */
vector < node > input;

int main()
{
	input_read();
	treeSearching();
	return 0;
}
void printVector()
{
	for (vector < node >::iterator it = input.begin();
			it != input.end(); ++it)
	{
		node item = *it;
		cout << item.first << ' '<< item.second.first << ' ' << item.second.second << endl;
	}
	cout << endl;
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
		input.push_back(make_pair(parent, make_pair(child[0], child[1])));	
	}	
	sort(input.begin(), input.end(), sortByparent);
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
	int i = _node - 'A';
	char _left = input[i].second.first, _right = input[i].second.second;

	if (_node == '.')
		return ;
	cout << (char)_node;
	preorder(_left);
	preorder(_right);
}
void inorder(char _node)
{
	unsigned char i = _node - 65;
	char _left = input[i].second.first, _right = input[i].second.second;

	if (_node == '.')
		return ;
	inorder(_left);
	cout << (char)_node;
	inorder(_right);
}
void postorder(char _node)
{
	unsigned char i = _node - 65;
	char _left = input[i].second.first, _right = input[i].second.second;

	if (_node == '.')
		return ;
	postorder(_left);
	postorder(_right);
	cout << (char)_node;
}
