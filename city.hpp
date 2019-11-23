#ifndef RISINGCITY_CITY_HPP
#define RISINGCITY_CITY_HPP
class City {
private:
    int global_time;
    RBTree *rbTree;
    Heap *heap;
public:
    City();
    int current_period_finish_time;
    int current_building_finish_time;
    Building *current_building;
    void insert(int, int, int );

    void printBuilding(int);

    void printBuilding(int, int);

    void updateGlobalTimer(int);

    bool hasBuildingToWorkOn();

    int getGlobalTime();

    int workOnBuilding(int);

//    Building *buildingInProcess();
//
//    void incrementGlobalCounterBy(int);
//
//    Building *removeMin();
//
//    int getTimeWorkedOnBuilding();
    void updateGlobalTimer2(int current_time);

    void workOnBuilding();

    void incremenetGlobalTimer();
};
#endif //RISINGCITY_CITY_HPP
