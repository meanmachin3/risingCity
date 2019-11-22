# RisingCity

## General

### Problem Description
```
Wayne Enterprises is developing a new city. They are constructing many buildings and plan to use software to keep track of all buildings under construction in this new city. A building record has the following fields:
__buildingNum__: unique integer identifier for each building.
__executed_time__: total number of days spent so far on this building.
__total_time__: the total number of days needed to complete the construction of the building.
 
The needed operations are:

1. __Print (buildingNum)__ prints the triplet buildingNum, executed_time, total_time.
2. __Print (buildingNum1, buildingNum2)__ prints all triplets bn, executed_tims, total_time for which buildingNum1 <= bn <= buildingNum2.
3. __Insert (buildingNum,total_time)__ where buildingNum is different from existing building numbers and executed_time = 0.
```