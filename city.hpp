#ifndef RISINGCITY_CITY_HPP
#define RISINGCITY_CITY_HPP
class City {
private:
    int global_time;
    RBTree *rbTree;
    Heap *heap;
public:
    City();
//    int time_to_work;
//    Building *working_on;
    void insert(int, int, int );

    void printBuilding(int);

    void printBuilding(int, int);

    void updateGlobalTimer(int);

    bool hasBuildingToWorkOn();

    int getGlobalTime();

    int workOnBuilding(int);

    int left_child(int);

    int right_child(int);

//    Building *buildingInProcess();
//
//    void incrementGlobalCounterBy(int);
//
//    Building *removeMin();
//
//    int getTimeWorkedOnBuilding();
};
#endif //RISINGCITY_CITY_HPP
