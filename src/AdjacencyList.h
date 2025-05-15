#pragma once

#include <string>
#include <map>
#include <vector>

using namespace std;

class AdjacencyList {
    private:
    map<string, vector<string>> outDegreeGraph;
    map<string, vector<string>> inDegreeGraph;
    map<string, float> rank;
    int totalSites = 0;

    public:
    void addVertex(string v1, string v2);
    string pageRank(int n);
    void pageRankInitializer();

    /*-----------------------------Helpers-------------------------------------*/
    string parseInput(const string& input);
    void parseInputPrintHelper(const string& input);
    void setTotalSites();

    /*-----------------------------print graph info-------------------------------------*/
    void printOutConnections();
    void printInConnections();
//    void printRanks();

};

