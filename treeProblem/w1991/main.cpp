/* preorder, inorder, postorder */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/* def */
typedef pair < char, char > pType_char;
/* var */
vector < pType_char > input;
int numOfnode;

/* func */
void input_read();
void searching_tree();
void preorder(const char base);
int getIndex(const char c);
int main()
{
	input_read();
	searching_tree();
	return 0;
}
void input_read()
{
		int i = 0;
		cin >> numOfnode;
		input.resize(numOfnode);
		while(i++ < numOfnode)
		{
				char _parent, _leftchild, _rightchild;
				cin >> _parent >> _leftchild >> _rightchild;
				input.push_back(make_pair(_leftchild, _rightchild));
		}
}
void searching_tree()
{
		// preorder : root - left - right
		preorder('A');
		// inorder : left - root - right

		// postorder : left - right - root
}
void preorder(const char base)
{
		cout << " >> base :" << base << endl;
		int i = getIndex(base);
		cout << " >> i :" << i << endl;
		if (i != -1)
		{
				cout << base << endl;

				preorder(input[i].first);	//left
				preorder(input[i].second); //right
		}
}
int getIndex(const char tar)
{
		cout << ">> getindex of :" << tar << endl;
		if (tar == '.') return -1;
		const int base = (char)'A';
		return (int)tar - base;
}
