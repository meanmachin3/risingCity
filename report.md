<h1 align="center"> Project Report </h1> <br>


## Table of Contents

- [Table of Contents](#table-of-contents)
- [City Implementation](#city-implementation)
  - [City Data Structure](#city-data-structure)
  - [City Interface](#city-interface)
- [Min Heap](#min-heap)
  - [Min Heap Data Structure](#min-heap-data-structure)
  - [Min Heap Interface](#min-heap-interface)
- [Red Black Tree](#red-black-tree)
  - [Red black Tree Node Structure](#red-black-tree-node-structure)
  - [Red Black Tree Interface](#red-black-tree-interface)
- [Main.cpp](#maincpp)

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
Building* insert(int, int, int, Node*);
```

```cpp
Building* removeMin();
```

```cpp
void swap(Building *, Building *);
```

```cpp
void heapify();
```

```cpp
void updateMin(int);
```

```cpp
int left_child(int);
```

```cpp
int right_child(int);
```

## Red Black Tree

### Red black Tree Node Structure

### Red Black Tree Interface

## Main.cpp