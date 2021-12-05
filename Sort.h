#pragma once
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
class Sort
{
public:
	bool read_word(string& word, ifstream& din);
	void merge_sort2(string data[], string copy[], int low, int high);
	void merge_sort(string data[], int low, int high);
};

