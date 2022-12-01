#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <list>

using namespace std;
int main() {

    string line;

    list<int> all_sums;

    int summe = 0;
    int max_sum = 0;
    ifstream myfile("E:\\python_projects\\aoc_1\\day1.input");
    if(myfile.is_open()) {
        while (getline(myfile, line)) {
            
            if(line.empty()) {
                all_sums.push_back(summe);
                summe = 0;
            }
            else {
                summe += stoi(line);
            }
            
        }
        myfile.close();
    } else {
        cout << "unable to open file " << endl;
    }


    all_sums.sort();
    all_sums.reverse();

    cout << "1: Max Summe ist " << all_sums.front() << endl;

    int top3 = 0;

    top3 += all_sums.front();
    all_sums.pop_front();

    top3 += all_sums.front();
    all_sums.pop_front();

    top3 += all_sums.front();
    all_sums.pop_front();

    cout << "2: top 3 ist " << top3 << endl;
    
    return 0;
}