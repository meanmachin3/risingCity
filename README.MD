<h1 align="center"> Rising City </h1> <br>

[![Actions Status](https://github.com/meanmachin3/risingCity/workflows/Test/badge.svg)](https://github.com/meanmachin3/risingCity/actions)

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
## Table of Contents

- [Table of Contents](#table-of-contents)
- [Problem Description](#problem-description)
- [Build Process](#build-process)
- [License](#license)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

## Problem Description

<details><summary>Click to read problem description</summary>
<p>

Wayne Enterprises is developing a new city. They are constructing many buildings and plan to use software to keep track of all buildings under construction in this new city. A building record has the following fields:

__buildingNum__: unique integer identifier for each building.
__executed_time__: total number of days spent so far on this building.
__total_time__: the total number of days needed to complete the construction of the building.

The needed operations are:

1. Print (buildingNum) prints the triplet buildingNume,executed_time,total_time.
2. Print (buildingNum1, buildingNum2) prints all triplets bn, executed_tims, total_time for which buildingNum1 <= bn <= buildingNum2.
3. Insert (buildingNum,total_time) where buildingNum is different from existing building numbers and executed_time = 0.

In order to complete the given task, you must use a min-heap and a Red-Black Tree (RBT). You must write your own code the min heap and RBT. Also, you may assume that the number of active buildings will not exceed 2000.

A min heap should be used to store (buildingNums,executed_time,total_time) triplets ordered by executed_time. You mwill need a suitable mechanism to handle duplicate executed_times in your min heap. An RBT should be used store (buildingNums,executed_time,total_time) triplets ordered by buildingNum. You are required to maintain pointers between corresponding nodes in the min-heap and RBT.

Wayne Construction works on one building at a time. When it is time to select a building to work on, the building with the lowest executed_time (ties are broken by selecting the building with the lowest buildingNum) is selected. The selected building is worked on until complete or for 5 days, whichever happens first. If the building completes during this period its number and day of completion is output and it is removed from the data structures. Otherwise, the building’s executed_time is updated. In both cases, Wayne Construction selects the next building to work on using the selection rule. When no building remains, the completion date of the new city is output.

</p>
</details>

## Build Process

- Clone or download the repo using `git clone https://github.com/meanmachin3/risingCity.git`
- `make` to compile source
- `make clean` to clean the compiled binaries
- `./risingCity input.txt` to run the compiled binary
- The program output will be placed in output.txt

## License

[![License](http://img.shields.io/:license-mit-blue.svg?style=flat-square)](http://badges.mit-license.org)
- **[MIT license](http://opensource.org/licenses/mit-license.php)**
