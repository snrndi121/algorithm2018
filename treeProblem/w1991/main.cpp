#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/* To sovle this */
/*
 * You need to know about traversals of tree. It is simple.
 * As you know, the each order of searchi is below.
 * _(1) Preorder : root -> left child -> right childi_
 * _(2) Inorder : left child -> root > right child_
 * _(3) Postorder : left child -> right child -> root_
 * 
 * In this case, you do not have to make tree. Instead, there is matrix [x][3] in vector < node >. Check declarations of type.
 * For example, Look at a functions of preorder.
*/
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
/******** **Look** ********/
/* 
 * "A process of preorder" 
 * This is recursive implement.(the root is A)
 * A preorder calls first a root. Then it will call preorder(leftchild) and a new preorder is going to print itself.
 * It continues to repeat until its contents is '.'. After '.', it calls preorder(rightchild). (the next process is same with the left) 
 * If the right process meet '.', the next recursive will be ready to return; 
 * 
*/
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
