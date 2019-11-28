Heap::Heap(int size) {
    root = new Building[size];
    element_added = 0;
}

/*!
 * Swaps a two given node a & b, by swapping their building_num, executed_time, total_time and rbt node reference
 * @param a Building number one
 * @param b Building number two
 */
void Heap::swap(Building *a, Building *b) {
    std::swap(a->building_num, b->building_num);
    std::swap(a->executed_time, b->executed_time);
    std::swap(a->total_time, b->total_time);
    std::swap(a->twin, b->twin);
}

/*!
 * Inserts a new node in min heap.
 * @param building_num: Building number for the node to be inserted
 * @param executed_time: Total executed time of the newly inserted building
 * @param total_time: Time it takes to complete completion of the newly inserted building
 * @param rbtNode: Reference to the node in red black treee
 * @return: Returns the inserted building node from min heap
 */
Building *Heap::insert(int building_num, int executed_time, int total_time, Node *rbtNode) {

    int insert_pos = ++element_added;

    root[element_added].building_num = building_num;
    root[element_added].executed_time = executed_time;
    root[element_added].total_time = total_time;
    root[element_added].twin = rbtNode;
    rbtNode->twin = &root[insert_pos];

    while (insert_pos > 1) {
        if (root[insert_pos].executed_time <= root[insert_pos / 2].executed_time) {
            if (root[insert_pos].executed_time == root[insert_pos / 2].executed_time) {
                if (root[insert_pos].building_num < root[insert_pos / 2].building_num) {
                    swap(&root[insert_pos], &root[insert_pos / 2]);
                    insert_pos = insert_pos / 2;
                } else {
                    break;
                }
            } else {
                swap(&root[insert_pos], &root[insert_pos / 2]);
                insert_pos = insert_pos / 2;
            }
        } else {
            break;
        }
    }
    return &root[insert_pos];
}

/*!
 * Returns index to the left child of a given parent node index x
 * @param x parent node index
 * @return left child node index
 */
int Heap::left_child(int x) {
    return x * 2;
}

/*!
 * Returns index to the right child of the given parent node index x
 * @param x parent node index
 * @return right child node index
 */
int Heap::right_child(int x) {
    return x * 2 + 1;
}

/*!
 * Performs a heapify operation on the min heap
 */
void Heap::heapify() {
    int x = 1;
    int parent;
    while (true) {
        if (left_child(x) > element_added)
            break;
        if (right_child(x) > element_added)
            parent = left_child(x);
        else {
            if (root[left_child(x)].executed_time < root[right_child(x)].executed_time) {
                parent = left_child(x);
            } else {
                parent = right_child(x);
            }
        }

        if (root[parent].executed_time < root[x].executed_time) {
            if (root[parent].executed_time == root[x].executed_time) {
                if (root[parent].building_num < root[x].building_num) {
                    swap(&root[parent], &root[x]);
                    x = parent;
                } else {
                    break;
                }
            }
            swap(&root[x], &root[parent]);
            x = parent;
        } else {
            break;
        }
    }
}


/*!
 * Removes the top element from the min heap(i.e minimum element from the min heap)
 * @return Minimum value removed from heap
 */
struct Building *Heap::removeMin() {
    int top = 1;

    struct Building *removed = new Building;

    removed->building_num = root[top].building_num;
    removed->executed_time = root[top].executed_time;
    removed->total_time = root[top].total_time;

    root[top].building_num = root[element_added].building_num;
    root[top].executed_time = root[element_added].executed_time;
    root[top].total_time = root[element_added].total_time;

    element_added--;
    heapify();
    return removed;
}