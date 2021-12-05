#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Sort.h"
using namespace std;

int main()
{
    //Get name of file
    cout << "Enter name of input file: ";
    string name1;
    cin >> name1;

    //declare variables
    ifstream din;
    ofstream dout;
    ofstream dout2;
    string word;
    string last = "";
    string phraise;
    string pairs[10001];
    int count = 0;
    Sort words;

    din.open(name1);

    // Read words and insert to array
    for (int i = 0; i < 10000; i++) {
        if (words.read_word(word, din)) {
            phraise = last + " " + word;
            pairs[count] = phraise;
            last = word;
            count++;
            if (count % 1000 == 0) {
                cout << "Still running...." << count << endl;
            }
        }
    }
    dout2.open("output2.txt");
    for (int i = 0; i < count; i++) {
        dout2 << pairs[i] << endl;
    }
    //sort array
    words.merge_sort(pairs, 0, count);

    //output every pair of words and their count to output.txt
    dout.open("output.txt");
    int matches = 0;
    for (int i = 0; i < count; i++) {
        if (pairs[i] == pairs[i + 1]) {
            matches = matches + 1;
        }
        if (pairs[i] != pairs[i + 1]) {
            dout << matches << " " << pairs[i] << endl;
            matches = 0;
        }
    }

    // Close files
    din.close();
    dout.close();
}

