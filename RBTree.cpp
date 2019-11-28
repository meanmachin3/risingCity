/*!
 * Constructor
 */
RBTree::RBTree() {
    root = nullptr;
}

/*!
 *To search a given key in Binary Search Tree, we first compare it with root,
 * if the key is present at root, we return root. If key is greater than root’s key, 
 * we recur for right subtree of root node. Otherwise we recur for left subtree.
 * @param root Root node of RBT
 * @param building_num Node to be searched for
 * @return Return the searched node
 */
Node *search(Node *root, int building_num) {
    if (root == nullptr)
        return nullptr;
    else if (root->building_num == building_num)
        return root;
    else if (building_num < root->building_num)
        return ::search(root->left, building_num);
    else
        return ::search(root->right, building_num);
}

/*!
 * https://www.geeksforgeeks.org/count-bst-nodes-that-are-in-a-given-range/
 * The idea is to traverse the given binary search tree starting from root.
 * For every node being visited, check if this node lies in range, if yes,
 * then print to file and recur for both of its children. If current node
 * is smaller than low value of range, then recur for right child, else recur for left child.
 * @param root Root of tree
 * @param low Lowest integer value to look up
 * @param high Highest integer value to look up
 */
void inorder(Node *root, int low, int high, std::vector <std::string> &res) {
    if (root == nullptr) {
        return;
    }
    if (root->building_num > low) {
        ::inorder(root->left, low, high, res);
    }

    if (root->building_num <= high && root->building_num >= low) {
        Building *correspondingBuilding = root->twin;
        std::stringstream ss;
        ss << "(" << correspondingBuilding->building_num << "," << correspondingBuilding->executed_time << ","
           << correspondingBuilding->total_time << ")";
        res.push_back(ss.str());
    }

    if (root->building_num < high) {
        ::inorder(root->right, low, high, res);
    }

}


/*!
 * Helper function that perform search for a node in RBTree and prints it.
 * @param building_num Building to be searched for
 * @return Searched node with building_num
 */
Node *RBTree::search(int building_num) {
    Node *found = ::search(root, building_num);
    if (found == nullptr)
        fout << "(0,0,0)\n";
    else {
        Building *correspondingBuilding = found->twin;
        fout << "(" << correspondingBuilding->building_num << "," << correspondingBuilding->executed_time << ","
             << correspondingBuilding->total_time << ")" << "\n";
    }
    return found;
}


/*!
 * https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/
 * Insets a given node in red black tree. If the node to be inserted already exists in the red black, throws
 * error and half the execution of current program
 * @param root Root Node of Tree
 * @param ptr Node to be inserted
 * @return Inserted element
 */
Node *insert(Node *root, Node *ptr) {
    if (root == nullptr)
        return ptr;

    if (ptr->building_num < root->building_num) {
        root->left = insert(root->left, ptr);
        root->left->parent = root;
    } else if (ptr->building_num > root->building_num) {
        root->right = insert(root->right, ptr);
        root->right->parent = root;
    } else {
        std::cerr << "Duplicate Building Number" << "\n";
        exit(1);
    }
    return root;
}

/*!
 * Helper method insert a given building in red black tree. After insertion, fixes any violation in red black tree.
 *
 * @param building_num: Building number of the node to be inserted
 * @return Returns the inserted node in red black tree
 */
Node *RBTree::insert(const int &building_num) {
    Node *node = new Node(building_num);
    Node *res = node;
    root = ::insert(root, node);
    fix(node);
    return res;
}

/*!
 * Helper method to print the building triplets from red black tree.
 * @param low: lowest building number to be printed
 * @param high: highest building number to be printed
 */
void RBTree::inorder(int low, int high) {
    std::vector <std::string> res;
    ::inorder(root, low, high, res);
    std::sort(res.begin(), res.end());
    std::string s;
    for (size_t i = 0; i < res.size(); ++i) {
        s += res[i];
        s += ",";
    }

    s.pop_back();
    fout << s;
    fout << "\n";
}

/*!
 * Returns the successor node in case an element is deleted from red black tree
 * @param node: Node to find successor of
 * @return returns: If found returns pointer reference to the successor node else returns nullptrt
 */
Node *successor(Node *node) {
    Node *successor = nullptr;
    if (node->left != nullptr) {
        successor = node->left;
        while (successor->right != nullptr)
            successor = successor->right;
    } else {
        successor = node->right;
        while (successor->left != nullptr) {
            successor = successor->left;
        }
    }
    return successor;
}


/*!
 * https://github.com/greatsharma/Red_Black_Tree/blob/master/RB_Tree.cpp
 * Deletes a specified node from red black tre
 * @param z: Node to be deleted from the red black tree.
 */
void RBTree::delete_node(Node *node) {
    node = root;
    Node *pVoid = nullptr;
    Node *node_to_be_deleted = nullptr;
    Node *child = nullptr;

    /*
    node :- node which the user wants to delete
    node_to_be_deleted :- node which is actually deleted
    child :- node_to_be_deleted's child
    */


    if (node->left == nullptr || node->right == nullptr)
        node_to_be_deleted = node;
    else
        node_to_be_deleted = successor(node);

    if (node_to_be_deleted->left != nullptr)
        child = node_to_be_deleted->left;
    else {
        if (node_to_be_deleted->right != nullptr)
            child = node_to_be_deleted->right;
        else
            child = nullptr;
    }
    if (child != nullptr)
        child->parent = node_to_be_deleted->parent;
    if (node_to_be_deleted->parent == nullptr)
        root = child;
    else {
        if (node_to_be_deleted == node_to_be_deleted->parent->left)
            node_to_be_deleted->parent->left = child;
        else
            node_to_be_deleted->parent->right = child;
    }
    if (node_to_be_deleted != node) {
        node->color = node_to_be_deleted->color;
        node->building_num = node_to_be_deleted->building_num;
        node->twin = node_to_be_deleted->twin;

        struct Building *temp;
        temp = node->twin;
        temp->twin = node;

    }
    if (pVoid != nullptr)
        fix(child);
}

/*!
 * Performs a left rotation on red black tree
 * @param node
 */
void RBTree::left_rotate(Node *node) {
    if (node->right == nullptr) {
        return;
    } else {
        Node *right_child = node->right;
        if (right_child->left != nullptr) {
            node->right = right_child->left;
            right_child->left->parent = node;
        } else {
            node->right = nullptr;
        }
        if (node->parent != nullptr) right_child->parent = node->parent;
        if (node->parent == nullptr) root = right_child;
        else if (node == node->parent->left) node->parent->left = right_child;
        else node->parent->right = right_child;
        right_child->left = node;
        node->parent = right_child;
    }
}

/*!
 * Performs a right rotation on red black tree
 * @param node
 */
void RBTree::right_rotate(Node *node) {
    if (node->left == nullptr)
        return;
    else {
        Node *y = node->left;
        if (y->right != nullptr) {
            node->left = y->right;
            y->right->parent = node;
        } else
            node->left = nullptr;
        if (node->parent != nullptr)
            y->parent = node->parent;
        if (node->parent == nullptr)
            root = y;
        else {
            if (node == node->parent->left)
                node->parent->left = y;
            else
                node->parent->right = y;
        }
        y->right = node;
        node->parent = y;
    }
}

/*!
 * Fixes red black tree, in case of violation either due to insertion or deletion of any node in red black tree
 * @param node: Node that caused violation
 */
void RBTree::fix(Node *&node) {
    Node *sibling; // node's sibling
    while (node != root && node->color == BLACK) {
        if (node->parent->left == node) {
            sibling = node->parent->right;

            if (sibling->color == RED) {
                /*
                 case 1 :- sibling is RED
                 conclusion :- Always take control to case 2,3 or 4.
                 */
                sibling->color = BLACK;
                node->parent->color = RED;
                RBTree::left_rotate(node->parent);
                sibling = node->parent->right;
            }

            if (sibling->right->color == BLACK && sibling->left->color == BLACK) {
                /*
                  case 2 :- sibling and both it's children are BLACK.
                  solution :- take BLACK from both node and sibling.
                  conclusion :- terminates if came from case 1
                  */
                sibling->color = RED;
                node = node->parent;
            } else if (sibling->right->color == BLACK) {
                /*
                  case 3 :- sibling=BLACK , sibling->left=RED and sibling->right=BLACK
                  conclusion :- case 3 take us to case 4
                  */
                sibling->left->color = BLACK;
                sibling->color = RED;
                RBTree::right_rotate(sibling);
                sibling = node->parent->right;
            } else {
                /*
                  case 4 :- sibling is BLACK and sibling->right is RED
                  conclusion :- terminates
              */
                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                sibling->right->color = BLACK;
                RBTree::left_rotate(node->parent);
                node = root;
            }
        } else {
            sibling = node->parent->left;
            if (sibling->color == RED) {
                sibling->color = BLACK;
                node->parent->color = RED;
                right_rotate(node->parent);
                sibling = node->parent->left;
            }
            if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
                sibling->color = RED;
                node = node->parent;
            } else if (sibling->left->color == BLACK) {
                sibling->right->color = BLACK;
                sibling->color = RED;
                left_rotate(sibling);
                sibling = node->parent->left;
            } else {
                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                sibling->left->color = BLACK;
                right_rotate(node->parent);
                node = root;
            }
        }
        node->color = BLACK;
        root->color = BLACK;
    }
}