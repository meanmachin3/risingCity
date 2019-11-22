enum color {
    RED, BLACK
};

struct Node {

    int building_num;
    bool color;
    Node *left;
    Node *right;
    Node *parent;
    Building *twin;

    Node(int building_num) {
        this->building_num = building_num;
        parent = left = right = NULL;
    }
};


// class of redblack tree
class RBTree {

private:
    Node *root;
protected:
    void rotate_left(Node *&, Node *&);

    void rotate_right(Node *&, Node *&);

    void fixtree(Node *&, Node *&);

public:
    RBTree();

    Node *insert(const int &n);

    Node *search(int);

    std::string join(const std::vector<std::string> &, const char *);

    void inorder(int, int);

    void delete_node(Node *);

    void fix(Node *&);

    void right_rotate(Node *);

    void left_rotate(Node *);

    void transplant(Node *, Node *, Node *);
};

RBTree::RBTree() {
    root = NULL;
}