#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "AdjacencyList.h"

using namespace std;

//Code found in this file was inspired / borrowed from the project 2 breakdown video
// specifically the "how to unit test function writing to stdout/std::cout" discussion/ stack overflow webpage

void AdjacencyList::pageRankInitializer(){
    setTotalSites();
    //if power iteration = 1 -> rank = 1 / # unique vertices
    for(auto& site: rank) {
        float pRank = 1.0f / totalSites;
        site.second = pRank;
    }
}

string AdjacencyList::pageRank(int n){
    totalSites = rank.size();

    pageRankInitializer();

    while(n > 1){
        //store prev Ranks
        map<string, float> prevRank = rank;

        //update rank of each pair in rank map/graph
        for(auto& x : rank){
            string site = x.first; //site to compute
            float inSum = 0.0f; //initialize indegree sum for each site

            //get indegree vector of string of a site being processed
            vector<string> inDegV = inDegreeGraph[site];

            //loop through inDegV getting each indegree previous rank
            for(string inSite: inDegV){
                //get in-degree sites # outdegrees
                int numOuts = outDegreeGraph[inSite].size();
                inSum += prevRank[inSite] / numOuts;
            }
            rank[site] = inSum;
        }
        n-=1;
    }

    string result;

    cout << fixed<< showpoint;
    cout << setprecision(2);

    ostringstream oss;
    streambuf* p_count_stream_buf = cout.rdbuf();
    cout.rdbuf((oss.rdbuf()));

    for(auto& member: rank){
        cout << member.first << " " << member.second << endl;
    }
    cout.rdbuf(p_count_stream_buf); //restore
    result += oss.str();
    cout <<result;
    return result;
}

void AdjacencyList::addVertex(string from, string to) {
    //outdegree graph
    outDegreeGraph[from].push_back(to);
    if(outDegreeGraph.find(to) == outDegreeGraph.end()) outDegreeGraph[to] = {};

    //indegree graph
    inDegreeGraph[to].push_back(from);
    if(inDegreeGraph.find(from) == inDegreeGraph.end()) inDegreeGraph[from] = {};

    //Ranks graph, ∀ranks initialized to 0;
    rank[from] = 0.0f;
    if(rank.find(to) == rank.end()) rank[to] = 0.0f;
}

void AdjacencyList::setTotalSites() {
    totalSites = rank.size();
}

/*---------------------------------------------Parse input-------------------------------------------------*/
void AdjacencyList::parseInputPrintHelper(const string& input) {
    int no_of_lines, power_iterations;
    string from, to;

    istringstream stream(input);

    stream >> no_of_lines >> power_iterations;

    for (int i = 0; i < no_of_lines; i++) {
        stream >> from >> to;
        addVertex(from,to);
    }
}

string AdjacencyList::parseInput(const string& input) {
    int no_of_lines, power_iterations;
    string from, to;

    istringstream stream(input);
    stream >> no_of_lines >> power_iterations;

    for (int i = 0; i < no_of_lines; i++) {
        stream >> from >> to;
        addVertex(from,to);
    }
    return pageRank(power_iterations);
}

/*-----------------------------print graph info, visual helper-------------------------------------*/
void AdjacencyList::printOutConnections() {
    for(auto& member: outDegreeGraph){
        cout << member.first << ": { ";
        for(auto& outConnect: member.second) cout << outConnect << ", ";
        cout << member.second.size();
        cout << " }"<<endl;
    }
}

void AdjacencyList::printInConnections() {
    for(auto& member: inDegreeGraph){
        cout << member.first << ": { ";
        for(auto& outConnect: member.second) cout << outConnect << ", ";
        cout << member.second.size();
        cout << " }"<<endl;
    }
}
