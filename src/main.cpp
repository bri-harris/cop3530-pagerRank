#include <iostream>
#include <string>
#include <sstream>
#include "AdjacencyList.h"

using namespace std;

int main() {
    int no_of_lines, power_iterations;
    string from, to;

    AdjacencyList list;

    cin >> no_of_lines;
    cin >> power_iterations;

    //for each of next no_of_lines, read in vertices from & to
    for (int i = 0; i < no_of_lines; i++) {

        cin >> from;
        cin >> to;

        list.addVertex(from,to);
    }
    list.pageRank(power_iterations);
    return 0;
}
