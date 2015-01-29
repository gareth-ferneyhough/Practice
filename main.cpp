#include <string>
#include <vector>
#include <utility>
#include <set>
#include <stack>
#include <array>
#include <iostream>

#include "grafixMask.h"
#include "marketing.h"
#include "circuits.h"
#include "path_finding.h"

using namespace std;

void testGrafixMask()
{    
    grafixMask g;
    vector<string> input;
        
    input.push_back("0 20 399 20");
    input.push_back("0 44 399 44");
    input.push_back("0 68 399 68");
    input.push_back("0 92 399 92");

    input.push_back("0 116 399 116");
    input.push_back("0 140 399 140");
    input.push_back("0 164 399 164");
    input.push_back("0 188 399 188");

    input.push_back("0 212 399 212");
    input.push_back("0 236 399 236");
    input.push_back("0 260 399 260");
    input.push_back("0 284 399 284");

    input.push_back("0 308 399 308");
    input.push_back("0 332 399 332");
    input.push_back("0 356 399 356");
    input.push_back("0 380 399 380");

    input.push_back("0 404 399 404");
    input.push_back("0 428 399 428");
    input.push_back("0 452 399 452");
    input.push_back("0 476 399 476");

    input.push_back("0 500 399 500");
    input.push_back("0 524 399 524");
    input.push_back("0 548 399 548");
    input.push_back("0 572 399 572");

    input.push_back("0 596 399 596");
    input.push_back("5 0 5 599");
    input.push_back("21 0 21 599");
    input.push_back("37 0 37 599");

    input.push_back("53 0 53 599");
    input.push_back("69 0 69 599");
    input.push_back("85 0 85 599");
    input.push_back("101 0 101 599");

    input.push_back("117 0 117 599");
    input.push_back("133 0 133 599");
    input.push_back("149 0 149 599");
    input.push_back("165 0 165 599");

    input.push_back("181 0 181 599");
    input.push_back("197 0 197 599");
    input.push_back("213 0 213 599");
    input.push_back("229 0 229 599");

    input.push_back("245 0 245 599");
    input.push_back("261 0 261 599");
    input.push_back("277 0 277 599");
    input.push_back("293 0 293 599");

    input.push_back("309 0 309 599");
    input.push_back("325 0 325 599");
    input.push_back("341 0 341 599");
    input.push_back("357 0 357 599");

    input.push_back("373 0 373 599");
    input.push_back("389 0 389 599");

    vector<int> regions = g.sortedAreas(input);

    for(auto it = regions.begin(); it != regions.end(); ++it)
    {
        cout << *it << endl;
    }
}

void testMarketing()
{
    //array<string, 5> input = {"1 4","2","3","0",""};    
    //array<string, 5> input = {"1","2","0"};    
    //array<string, 6> input = {"1","2","3","0","0 5","1"};
    array<string, 30> input = {"","","","","","","","","","",
                            "","","","","","","","","","",
                            "","","","","","","","","",""};
    Marketing m;
    cout << m.howMany(vector<string>(input.begin(), input.end())) << endl;;
}

void testCircuits()
{
    //array<string, 3> connects = {"1 2", "2", ""};
    //array<string, 3> costs = {"5 3", "7", ""};

    //array<string, 6> connects = {"1 2 3 4 5","2 3 4 5","3 4 5","4 5","5",""};
    //array<string, 6> costs = {"2 2 2 2 2","2 2 2 2","2 2 2","2 2","2",""};

    /*array<string, 13> connects = {"","2 3 5","4 5","5 6","7","7 8","8 9","10",
                                    "10 11 12","11","12","12",""};
    array<string, 13> costs = {"","3 2 9","2 4","6 9","3","1 2","1 2","5",
                                    "5 6 9","2","5","3",""};*/

    array<string, 8> connects = {"","2 3","3 4 5","4 6","5 6","7","5 7",""};                                    
    array<string, 8> costs = {"","30 50","19 6 40","12 10","35 23","8","11 20",""};
                                    

    Circuits c;
    cout << c.howLong(vector<string>(connects.begin(), connects.end()), vector<string>(costs.begin(), costs.end()));    
}

void testPathFinding()
{
    //array<string, 4> b = {"....",
    //                      ".A..",
    //                      "..B.",
    //                      "...."};

    /*array<string, 3> b = {"XXXXXXXXX",
                         "A...X...B",
                         "XXXXXXXXX"};*/

    /*array<string, 3> b = {"XXXXXXXXX",
                        "A.......B",
                        "XXXXXXXXX"};*/

    /*array<string, 3> b = {"XXXXXXXXX",
                         "A.......B",
                         "XXXX.XXXX"};*/

    /*array<string, 5> b = {"...A.XXXXX.....",
                            ".....XXXXX.....",
                            "...............",
                            ".....XXXXX.B...",
                            ".....XXXXX....."};*/

    array<string, 20> b = {"AB.................X",
                         "XXXXXXXXXXXXXXXXXXX.",
                         "X..................X",
                         ".XXXXXXXXXXXXXXXXXXX",
                         "X..................X",
                         "XXXXXXXXXXXXXXXXXXX.",
                         "X..................X",
                         ".XXXXXXXXXXXXXXXXXXX",
                         "X..................X",
                         "XXXXXXXXXXXXXXXXXXX.",
                         "X..................X",
                         ".XXXXXXXXXXXXXXXXXXX",
                         "X..................X",
                         "XXXXXXXXXXXXXXXXXXX.",
                         "X..................X",
                         ".XXXXXXXXXXXXXXXXXXX",
                         "X..................X",
                         "XXXXXXXXXXXXXXXXXXX.",
                         "...................X",
                         ".XXXXXXXXXXXXXXXXXXX"};

        
    PathFinding p;
    cout << p.minTurns(vector<string>(b.begin(), b.end()));
}

int main()
{
   //testGrafixMask();
   //testMarketing();
    //testCircuits();
    testPathFinding();   
    
    char c;
    cin >> c;

    return 0;
}