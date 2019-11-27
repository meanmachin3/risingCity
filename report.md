<h1 align="center"> Project Report </h1> <br>


## Table of Contents

- [Table of Contents](#table-of-contents)
- [Main.cpp](#maincpp)
- [City Implementation](#city-implementation)
  - [City Data Structure](#city-data-structure)
  - [City Interface](#city-interface)
- [Min Heap](#min-heap)
  - [Min Heap Data Structure](#min-heap-data-structure)
  - [Min Heap Interface](#min-heap-interface)
- [Red Black Tree](#red-black-tree)
  - [Red black Tree Node Structure](#red-black-tree-node-structure)
  - [Red Black Tree Interface](#red-black-tree-interface)

## Main.cpp

```javascript
    while(lines in file) {
        tokens = parse(line);
        while(globalTimer != currentTime) {
            process nodes in minheap
            updateGlobalTimer();
        }
        if (command == "insert") {
            insert(building_num);
        } else if (command == "printbuilding" && argument_count == 1) {
            print(building_num);
        } else if (commmand == "printbuilding" && argument_count == 2) {
            print(from, to); // Print all buildings with number in between from and to
        }
    }
```

The algorithm presents are very brief overiew of the implementation of risingCity. The idea is to process it line by and line and taken action on the read line.  
Once the line is read, look for the time present in the currently read line and check if it is greater than the `global_timer`. Find the difference between the currently read time and `global_timer`. Find out the time required to complete the building with minimum `executed_time`, if it requires more than `5` days then work on it for `5` days else work on that building for `total_time` - `executed_time` and update `global_timer` accordingly.  
Once the building has been processed, read the command that is to be executed. If the command is `Insert` then push the building into the min heap and red black while maintain the heap & tree structure.  
If the line that's being read is a `PrintBuilding` command, check for the number of argument it contains. If the `PrintBuilding` command contains only one argument, the print the respective building else if it contains 2 arguments, print the building nodes between the give range.  
When all the lines are processed from the file input, check if there's any more building to be worked on in the min heap. If there is any, increment `global_counter` by an arbitrary amount (100 in this case) and repeat the above steps again.

Below is representation of changes that takes place in min heap. Each node is representated using  `(building_num, executed_time, total_time)`

<pre>
0: Insert(50,100)

        (50, 0, 100)

45: Insert(15,200)

            (15,0,200)
            /
        (50,45,100)

46: PrintBuilding(0,100)

            (15,1,200)
            /
        (50,45,100)

90: PrintBuilding(0,100)

            (15,45,200)
            /
        (50,45,100)

92: PrintBuilding(0,100)

            (50,45,100)
            /
        (15,47,200)

93: Insert(30,50)

            (30,0,50)
            /        \
    (50,46,100)     (15,47,200)

95: PrintBuilding(0,100)

            (30,2,50)
            /       \
    (50,46,100)     (15,47,200)

96: PrintBuilding(0,100)

            (30,3,50)
            /       \
    (50,46,100)   (15,47,200)

100: PrintBuilding(0,100)

            (30,7,50)
            /      \
    (50,46,100)   (15,47,200)

135: PrintBuilding(0,100)

            (30,42,50)
            /       \
    (50,46,100)     (15,47,200)

140: Insert(40,60)

            (40,45,60)
            /       \
    (50,46,100)     (15,47,200)
    /
(30,47,50)

</pre>
## City Implementation

### City Data Structure

```cpp
int global_time;
RBTree *rbTree;
Heap *heap;
```

City contains `global_time` that keeps track of the global counter. There's a pointer reference to Red black tree( `rbTree`) and a min heap(`heap`) to interact with respective data structure

### City Interface

```cpp
void insert(int building_num, int executed_time, int total_time);

```

Accepts `building_num`, `executed_time` & `total_time` and inserts it into min heap and red black tree. Acts as an interface between the input and data structures(min heap and red black).

```cpp
void printBuilding(int buildingNum);
```

Accepts `buildingNum` to be printed. Looks up for the given building number and prints it.

```cpp
void printBuilding(int from, int to);
```

Accepts a range from `from` to `to` of building number to be printed. Looks up for the given range and prints it.

```cpp
void updateGlobalTimer(int time);
```

Setter to modify the `global_time` by given `time`

```cpp
bool hasBuildingToWorkOn();
```

Checks if there any building that could be worked on i.e Checks for the heap size. Returns true if there are more than more element inside the min heap data structure otherwise false.

```cpp
int getGlobalTime();
```

Getter for `global_time`.

```cpp
int workOnBuilding(int time);
```

Selects the smallest element from the min heap and either works till the building is completed or for given `time` period.

## Min Heap

### Min Heap Data Structure

```cpp
struct Building{
    int building_num;
    int executed_time;
    int total_time;
    struct Node* twin;
};
```

Each element in min heap is an instance of `Building`. `Building` data structure contains `building_num`, `executed_time` & `total_time`. `executed_time` denotes for how long the building was worked on. `twin` maintains a pointer reference to corresponding node in red black tree.

### Min Heap Interface

```cpp
Building* insert(int building_num, int executed_time, int total_time, Node* rbt_twin);
```

Creates a new nodes inside the min heap using `building_num`, `executed_time`, `total_time`. `rbt_twin` is the reference to node in red black tree.

```cpp
Building* removeMin();
```

Removes the minimum element from the min heap.

```cpp
void swap(Building *, Building *);
```

Swaps two building nodes, replacing their content with each other.

```cpp
void heapify();
```

Used or maintain order of min heap. If there's any violation wrt to min heap, building node with minimum value is taken as root.

```cpp
void updateMin(int time);
```

Increment the minimum node's `executed_time` with the give amount of `time`.

```cpp
int left_child(int i);
```

Returns left child index.

```cpp
int right_child(int i);
```

Returns left child index.

## Red Black Tree

### Red black Tree Node Structure

```cpp
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
```

Each instance of `Node` is data in red black. `Node` consists of `building_num` which would be unique within the data structure. `color` refers to the type of node i.e `RED` or `BLACK`. `left` and `right` node refers to the left and right child of the red black tree. `parent` pointer maintains reference to it's parent node. `twin` is used to store pointer reference to corresponding node in min heap.

### Red Black Tree Interface

```cpp
Node *insert(const int &n);
```

Inserts a node with building num `n` to Red Black Tree. Time Complexity: `O(log n)`

```cpp
Node *search(int building_num);
```

Looks up a node with building num `building_num` to Red Black Tree. Time Complexity: `O(log n)`

```cpp
std::string join(const std::vector<std::string> & arr, const char * delim);
```

Method to join an array `arr` with delimiter `delim`. E.g: `join({"Hi", "Hello"}, ',')` returns `Hi, Hello`. Time Complexity: `O(n)`

```cpp
void inorder(int low, int high);
```

Runs an inorder traversal on tree and looks up node with building number between `low` and `high`. Time complexity: `O(log n + (high - low))`

```cpp
void delete_node(Node *node);
```

Deletes the given node from red black tree. Time Complexity: `O(log n)`

```cpp
void fix(Node *& node);
```

Fix violation in red black tree due to `node` on insert or delete. Time Complexity: `O(log n)`

```cpp
void right_rotate(Node *);
```

Performs right rotation in red black tree. Time Complexity: `O(1)`

```cpp
void left_rotate(Node *);
```

Performs left rotation in red black tree. Time Complexity: `O(1)`
