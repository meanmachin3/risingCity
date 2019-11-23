#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <stack>

#define MAX_SIZE 2001
#define WORK_LIMIT 5

std::ofstream fout;

#include "../minHeap.hpp"
#include "../RBTree.hpp"
#include "../minHeap.cpp"
#include "../RBTree.cpp"
#include "../city.hpp"
#include "../city.cpp"

TEST_CASE("Testing Red Black Tree") {
    fout.open("test_output_file.txt");
    RBTree* rbt = new RBTree;
    Node *inserted_node = rbt->insert(4);
    REQUIRE(inserted_node->building_num == 4);
    rbt->insert(8);
    rbt->insert(6);
    rbt->insert(9);
    rbt->insert(3);
    rbt->insert(2);
    rbt->insert(1);
//    Node *searched = rbt->search(9);
//    REQUIRE(searched->building_num == 9);
}
