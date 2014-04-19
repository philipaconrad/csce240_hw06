/****************************************************************
 * Main program for doing union-find algorithm.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Date: 12 January 2014
 * Edited by: Allan Bates, Phillip Conrad, Janice Neighbor, 
 * William Warren
**/

#include "Main.h"

static const string TAG = "Main: ";

int main(int argc, char *argv[])
{
    string timeCallOutput = "";
    string inFileName = "";
    string outFileName = "";
    string logFileName = "";
    
    ofstream outStream;
    
    Scanner inStream;


    UnionFind unionFind;


    Utils::CheckArgs(3, argc, argv, "infilename outfilename logfilename");
    
    inFileName = (string) argv[1];
    outFileName = (string) argv[2];
    logFileName = (string) argv[3];

    Utils::FileOpen(outStream, outFileName);
    Utils::LogFileOpen(logFileName);

    timeCallOutput = Utils::timecall("beginning");
    
    Utils::logStream << timeCallOutput;
    Utils::logStream << TAG << "Beginning execution" << endl;
    Utils::logStream.flush();

    Utils::logStream << TAG << "infile '" << inFileName << "'" << endl;
    Utils::logStream << TAG << "outfile '" << outFileName << "'" << endl;
    Utils::logStream << TAG << "logfile '" << logFileName << "'" << endl;


    inStream.openFile(inFileName);
    int numberOfArcs = inStream.nextInt();
    for(int arc = 0; arc < numberOfArcs; ++arc)
    {
        int a = inStream.nextInt();
        int b = inStream.nextInt();
        
        unionFind.addArc(a, b);
    }

    unionFind.buildForest();

    unionFind.unionFind();

    timeCallOutput = Utils::timecall("ending");
    Utils::logStream << timeCallOutput;
    Utils::logStream << TAG << "Ending execution" << endl;
    Utils::logStream.flush();

    Utils::FileClose(outStream);
    Utils::FileClose(Utils::logStream);

    return 0;
}
