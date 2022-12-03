#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <list>
#include <set>
#include <algorithm>
#include <vector>


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

    string inputFile = "E:\\python_projects\\aoc_1\\day3.input";

    list<string> inputList = readAllLines(inputFile);

    int sum = 0;

    for(auto it = inputList.begin(); it != inputList.end(); it++) {
        string line = (string)*it;
        string firstHalf = line.substr(0, line.length()/2);
        string secondHalf = line.substr(line.length()/2);

        set<char> bucket;

        for(int i=0; i < firstHalf.length(); i++) {
            bucket.insert(firstHalf[i]);
        }

        char matchingChar;

        for(int i=0; i < secondHalf.length(); i++) {
            if(bucket.count(secondHalf[i]) == 1) {
                matchingChar = secondHalf[i];
                break;
            }
        }
        int value = 0;

        if(matchingChar - 96 < 0) {
            // uppercase
            value = (matchingChar - 64 +26);
        } else {
            value = (matchingChar - 96);
        }

        cout << matchingChar << " " << value << endl;

        sum += value;

    }

    cout << "Summe 1 " << sum << endl;

    inputList = readAllLines(inputFile);

    sum = 0;

    for(auto it = inputList.begin(); it != inputList.end(); it++) {
        string line1 = (string)(*(it++));
        string line2 = (string)(*(it++));
        string line3 = (string)(*(it));

        string myIntersection, myIntersection2;

        std::sort(line1.begin(), line1.end());
        std::sort(line2.begin(), line2.end());
        set_intersection(line1.begin(), line1.end(), line2.begin(), line2.end(), back_inserter(myIntersection));

        std::sort(myIntersection.begin(), myIntersection.end());
        std::sort(line3.begin(), line3.end());
        set_intersection(myIntersection.begin(), myIntersection.end(), line3.begin(), line3.end(), back_inserter(myIntersection2));

        char matchingChar = myIntersection2[0];

        int value = 0;

        if(matchingChar - 96 < 0) {
            // uppercase
            value = (matchingChar - 64 +26);
        } else {
            value = (matchingChar - 96);
        }

        sum += value;
        
    }

    cout << "Summe 2 " << sum << endl;

    return 0;
}