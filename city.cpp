
City::City() {
    global_time = 0;
    heap = new Heap(MAX_SIZE);
    rbTree = new RBTree;
//    working_on = nullptr;
//    time_to_work = 0;
}

int City::getGlobalTime() {
    return global_time;
}

//Building* City::buildingInProcess() {
//    return working_on;
//}
//
//int City::getTimeWorkedOnBuilding(){
//    return time_to_work;
//}
//
//Building *City::removeMin() {
//    return heap->removeMin();
//}
//void City::incrementGlobalCounterBy(int time) {
//    global_time += time;
//}

void City::updateGlobalTimer(int current_time) {
    int time_to_work;
    // There's a entry for a new job
    while (current_time > global_time) {
        // The selected building is worked on until complete or for 5 days, whichever happens first.
        if (current_time - global_time < WORK_LIMIT) {
            time_to_work = current_time - global_time;
        } else {
            time_to_work = 5;
        }
        // If you have any building to work on, work for time_to_work days else set global time to current_time
        if (hasBuildingToWorkOn()) {
            global_time = global_time + time_to_work - workOnBuilding(time_to_work);
        } else {
            global_time = current_time;
        }

    }
}

/*!
 * Check if there's any building to work on.
 * @return Total building to be worked on. 0 if none.
 */
bool City::hasBuildingToWorkOn() {
    return heap->element_added;
}

/*!
 *  Working on the building with smallest executed_time
 * @param time Time to work on building for given time
 * @return Total time worked on a building
 */
int City::workOnBuilding(int time) {
    Building *smallest = &(heap->root[1]);
    int worked = std::min(time, smallest->total_time - smallest->executed_time);
    smallest->executed_time += worked;

    /*
     * If the executed time is equal to executed time, remove it from min heap and RBT. If executed_time > total_time
     * return the additional time worked on it
     */
    if (smallest->total_time - smallest->executed_time <= 0) {
        fout << "(" << smallest->building_num << "," << (global_time + worked) << ")" << "\n";
        rbTree->delete_node(smallest->twin);
        heap->removeMin();
    }
    heap->heapify();
    return time - worked;
}

/*!
 * Returns all character to the right of delimiter
 * @param str - input string
 * @param delim - character it delimit from
 * @return return subtring of character present to the right of delimiter
 */
std::string get_right_of_delim(std::string const &str, std::string const &delim) {
    return str.substr(str.find(delim) + delim.size());
}

/*!
 * Returns all character to the left of delimiter
 * @param str - input string
 * @param delim - character it delimit from
 * @return return subtring of character present to the left of delimiter
 */
std::string get_left_of_delim(std::string const &str, std::string const &delim) {
    return str.substr(0, str.find(delim));
}


/*!
 *  Tokenize input string
 * @param line - input line from file
 * @return token - vector of string containing all keywords from a line. Ex: 20: Insert(20, 10) will be returned as {20, Insert, 20, 10}
 */
std::vector<std::string> parse_line(std::string line) {
    std::vector<std::string> tokens;
    if (line.find('\r') != std::string::npos) {
        line.pop_back();
    }
    line.pop_back();
    if (line.find(':') != std::string::npos) {
        tokens.push_back(get_left_of_delim(line, ":")); // Arrival time of construction
        // Check for construction type
        if (line.find("Insert") != std::string::npos) {
            tokens.push_back("Insert");
        } else if (line.find("PrintBuilding") != std::string::npos) {
            tokens.push_back("PrintBuilding");
        }
        // Parse input params
        std::string params = get_right_of_delim(line, "(");
        if (params.find(',') != std::string::npos) {
            tokens.push_back(get_left_of_delim(params, ","));
            tokens.push_back(get_right_of_delim(params, ","));
        } else {
            tokens.push_back(params);
        }

    } else {
        std::cerr << "Invalid String" << '\n';
    }
    return tokens;
}

/*!
 * Inserts new building into RBT and min heap
 * @param buildingNum
 * @param total_time
 */
void City::insert(int buildingNum, int executed_time, int total_time) {
    // Insert the value in min heap as well as RBT Tree
    Node *n = rbTree->insert(buildingNum);
    heap->insert(buildingNum, 0, total_time, n);
}

/*!
 * Prints the triplet buildingName, executed_time, total_time for buildingNum
 * @param buildingNum
 */
void City::printBuilding(int buildingNum) {
    rbTree->search(buildingNum);
}

/*!
 * Prints the triplet buildingName, executed_time, total_time from fromBuildingNum to toBuildingNum
 * @param buildingNum
 */
void City::printBuilding(int fromBuildingNum, int toBuildingNum) {
    rbTree->inorder(fromBuildingNum, toBuildingNum);
}
