//#include <catch2/catch_test_macros.hpp>
//#include <iostream>
//#include <sstream>
//#include "AdjacencyList.h"
//
//using namespace std;
//
////Code found in this file was inspired / borrowed from the project 2 breakdown video
//// specifically the "how to unit test function writing to stdout/std::cout" discussion/ stack overflow webpage
//
//TEST_CASE("Facebook Indegree = 0, Rank should = 0", "[tag]") {
//    AdjacencyList list;
//
//    string input = R"(6 2
//google.com gmail.com
//google.com maps.com
//facebook.com ufl.edu
//ufl.edu google.com
//ufl.edu gmail.com
//gmail.com maps.com)";
//
//    string expectedOutput = R"(facebook.com 0.00
//gmail.com 0.20
//google.com 0.10
//maps.com 0.30
//ufl.edu 0.20
//)";
//
//    string actualOutput = list.parseInput(input);
//
//    REQUIRE(actualOutput == expectedOutput);
//}
//
//TEST_CASE("Example Online Test", "[tag]") {
//    AdjacencyList list;
//
//    string input = R"(32 5
//github.com youtube.com
//openai.com github.com
//weather.com getbootstrap.com
//youtube.com zoom.us
//youtube.com github.com
//facebook.com roblox.com
//microsoft.com disney.com
//facebook.com aman.com
//roblox.com aman.com
//google.com facebook.com
//getbootstrap.com zoom.us
//google.com disney.com
//github.com roblox.com
//weather.com github.com
//roblox.com openai.com
//disney.com youtube.com
//aman.com openai.com
//getbootstrap.com openai.com
//aman.com microsoft.com
//aman.com getbootstrap.com
//facebook.com microsoft.com
//aman.com roblox.com
//disney.com zoom.us
//weather.com disney.com
//disney.com weather.com
//github.com getbootstrap.com
//getbootstrap.com google.com
//microsoft.com getbootstrap.com
//openai.com disney.com
//facebook.com youtube.com
//google.com microsoft.com
//youtube.com microsoft.com
//)";
//
//    string expectedOutput = R"(aman.com 0.02
//disney.com 0.09
//facebook.com 0.01
//getbootstrap.com 0.08
//github.com 0.07
//google.com 0.03
//microsoft.com 0.04
//openai.com 0.05
//roblox.com 0.04
//weather.com 0.03
//youtube.com 0.07
//zoom.us 0.08
//)";
//
//    ;
////    string actualOutput = list.parseInput(input, false);
//    string actualOutput = list.parseInput(input);
//
//    REQUIRE(actualOutput == expectedOutput);
//}
//TEST_CASE("Power iterations = 3", "[tag]") {
//    AdjacencyList list;
//
//    string input = R"(7 3
//google.com gmail.com
//google.com maps.com
//facebook.com ufl.edu
//ufl.edu google.com
//ufl.edu gmail.com
//maps.com facebook.com
//gmail.com maps.com)";
//
//    string expectedOutput = R"(facebook.com 0.30
//gmail.com 0.15
//google.com 0.10
//maps.com 0.25
//ufl.edu 0.20
//)";
//
////    string actualOutput = list.parseInput(input, false);
//    string actualOutput = list.parseInput(input);
//
//    REQUIRE(actualOutput == expectedOutput);
//}
//TEST_CASE("Power iterations = 2", "[tag]") {
//    AdjacencyList list;
//
//  string input = R"(7 2
//google.com gmail.com
//google.com maps.com
//facebook.com ufl.edu
//ufl.edu google.com
//ufl.edu gmail.com
//maps.com facebook.com
//gmail.com maps.com)";
//
//  string expectedOutput = R"(facebook.com 0.20
//gmail.com 0.20
//google.com 0.10
//maps.com 0.30
//ufl.edu 0.20
//)";
//
////  list.parseInput(input);
////  string actualOutput = list.parseInput(input, false);
//  string actualOutput = list.parseInput(input);
//
//  REQUIRE(actualOutput == expectedOutput);
//}
//TEST_CASE("Power Iterations = 1", "[flag]") {
//    AdjacencyList list;
//
//    string input = R"(7 1
//google.com gmail.com
//google.com maps.com
//facebook.com ufl.edu
//ufl.edu google.com
//ufl.edu gmail.com
//maps.com facebook.com
//gmail.com maps.com)";
//
//    string expectedOutput = R"(facebook.com 0.20
//gmail.com 0.20
//google.com 0.20
//maps.com 0.20
//ufl.edu 0.20
//)";
////    string actualOutput = list.parseInput(input, false);
//    string actualOutput = list.parseInput(input);
//
//    REQUIRE(actualOutput == expectedOutput);
//}
//
//TEST_CASE("COUT Test OutDegree Adjacency List", "[flag]"){
//    AdjacencyList list;
//    //do functions that make the adjacency list like insert
//    //depends on implementation
//
//    string input = R"(7 2
//google.com gmail.com
//google.com maps.com
//facebook.com ufl.edu
//ufl.edu google.com
//ufl.edu gmail.com
//maps.com facebook.com
//gmail.com maps.com)";
//
//    string expectedOutput = R"(facebook.com: { ufl.edu, 1 }
//gmail.com: { maps.com, 1 }
//google.com: { gmail.com, maps.com, 2 }
//maps.com: { facebook.com, 1 }
//ufl.edu: { google.com, gmail.com, 2 }
//)";
//    ostringstream oss;
//    streambuf* p_count_stream_buf = cout.rdbuf();
//    cout.rdbuf((oss.rdbuf()));
//
//list.parseInputPrintHelper(input);
//
//    //put the function that prints/cout's here in bt the stack overflo code to capture it
//    //like list.printRanks(); but depends on implementation
//    list.printOutConnections();
//
//    cout.rdbuf(p_count_stream_buf); //restore
//
//    //put expected output in bt the quotation marks, this will compare the output captured w/ expected output
//    assert(oss && oss.str() == expectedOutput);
//    cout << oss.str();
//}
//TEST_CASE("COUT Test InDegree Adjacency List", "[flag]"){
//    AdjacencyList list;
//
//    string input = R"(7 2
//google.com gmail.com
//google.com maps.com
//facebook.com ufl.edu
//ufl.edu google.com
//ufl.edu gmail.com
//maps.com facebook.com
//gmail.com maps.com)";
//
//    string expectedOutput = R"(facebook.com: { maps.com, 1 }
//gmail.com: { google.com, ufl.edu, 2 }
//google.com: { ufl.edu, 1 }
//maps.com: { google.com, gmail.com, 2 }
//ufl.edu: { facebook.com, 1 }
//)";
//    ostringstream oss;
//    streambuf* p_count_stream_buf = cout.rdbuf();
//    cout.rdbuf((oss.rdbuf()));
//
//    list.parseInputPrintHelper(input);
//
//    list.printInConnections();
//
//    cout.rdbuf(p_count_stream_buf); //restore
//
//    assert(oss && oss.str() == expectedOutput);
//    cout << oss.str();
//}