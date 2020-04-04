/*
  * Nomal Tree
*/
template < typename T >
struct normTree{
    T val;
    normTree* parent;
    vector <normTree*> child;
};
void printNormTree(normTree *root)
{
    cout << root->val << endl;
    for (int i = 0; i < root->child.size(); ++i) {
        printNormTree(root->child[i]);
    }
}
int height(normTree *root)
{
    int h = 0;
    for (int i = 0; i < root->child.size(); ++i) {
        h = max(h, 1 + height(root->child[i]));
    }
    return h;
}
/*
  * Tree - treap
*/
template < typename T >
struct TreapNode {
    T val;
    int priority, size;
    TreapNode *left, *right;
    TreapNode(const T& _val) : val(_val), priority(rand()), size(1), left(NULL), right(NULL) {}
    void setLeft(TreapNode* _newleft) { left =_newleft; calcSize();}
    void setRight(TreapNode* _newright) { right =_newright; calcSize();}
    void calcSize() {
        size = 1;
        if (left) size += left->size;
        if (right) size += right->size;
    }
};
