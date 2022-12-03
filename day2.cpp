#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <list>

using namespace std;


list<string> readAllLines(string filename) {
    ifstream myfile(filename);
    string line;
    list<string> allLines;
    if(myfile.is_open()) {
        while (getline(myfile, line)) {
            allLines.push_back(line);
        }
    }
    else {
        cout << "Error reading file (" << filename << ")" << endl;
    }

    return allLines;
}


int main() {

    string inputFile = "E:\\python_projects\\aoc_1\\day2.input";

    list<string> inputList = readAllLines(inputFile);

    int points = 0;

    for(auto it = inputList.begin(); it != inputList.end(); it++) {
        char opPlay = (*it)[0];
        char myPlay = (*it)[2];

        

        if( ((opPlay == 'A') && (myPlay == 'Y'))
            || ((opPlay == 'B') && (myPlay == 'Z'))
            || ((opPlay == 'C') && (myPlay == 'X'))
        )
        {
            points+=6;
        }
        
        if(opPlay+23 == myPlay) {
            points += 3;
        }

        points += (int) (myPlay-87);

    }
    cout << "Punkte Aufgabe 1 " << points << endl;


    //string inputFile = "E:\\python_projects\\aoc_1\\day2.input";

    inputList = readAllLines(inputFile);

    points = 0;

    for(auto it = inputList.begin(); it != inputList.end(); it++) {
        char opPlay = (*it)[0];
        char result = (*it)[2];

        
        char myPlay;

        //  z == we have to win
        if(result == 'Z') {
            if(opPlay == 'A') {
                myPlay = 'Y';
            } else if(opPlay == 'B') {
                myPlay = 'Z';
            } else {
                myPlay = 'X';
            }
        }
        // draw
        else if(result == 'Y') {
            myPlay = opPlay + 23;
        }
        // we need to lose 
        else {
            if(opPlay == 'A') {
                myPlay = 'Z';
            } else if(opPlay == 'B') {
                myPlay = 'X';
            } else {
                myPlay = 'Y';
            }
        }

        if( ((opPlay == 'A') && (myPlay == 'Y'))
            || ((opPlay == 'B') && (myPlay == 'Z'))
            || ((opPlay == 'C') && (myPlay == 'X'))
        )
        {
            points+=6;
        }
        
        if(opPlay+23 == myPlay) {
            points += 3;
        }

        points += (int) (myPlay-87);

    }
    cout << "Punkte Aufgabe 2 " << points << endl;



    return 0;
}