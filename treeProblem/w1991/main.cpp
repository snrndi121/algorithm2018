#include <iostream>
#include <list>

using namespace std;

/* def */

/* func */
void input_read();
void treeSearching();
void preorder(char _node);
void inorder(char _node);
void postorder(char _node);

/* var */
char** input = NULL;

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
	
	input = new char*[2];
	for (int i=0; i<num; ++i)
	{
		input[i] = new char[2];	
	}

	/* Get input */
	char p, l, r;
	for (int i=0; i< num; ++i)
	{
		cin >> p >> l >> r;
		input[i][0] = l;
		input[i][1] = r;
	}	
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

	if (_node == '.')
		return ;
	cout << (char)_node;
	preorder(input[i][0]);
	preorder(input[i][1]);
}
void inorder(char _node)
{
	unsigned char i = _node - 65;
	if (_node == '.')
		return ;
	inorder(input[i][0]);
	cout << (char)_node;
	inorder(input[i][1]);
}
void postorder(char _node)
{
	unsigned char i = _node - 65;
	if (_node == '.')
		return ;
	postorder(input[i][0]);
	postorder(input[i][1]);
	cout << (char)_node;
}

