#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Sort.h"
using namespace std;


bool Sort::read_word(string& word, ifstream& din)
{
    // Initialize variables
    word = "";
    bool found_word = false;

    // Loop reading characters until word is found
    while (!din.fail() && !din.eof() && !found_word)
    {
        // Read next character from file
        char ch;
        din.get(ch);

        // Append lower case letter to word
        if (ch >= 'a' && ch <= 'z')
            word = word + ch;

        // Convert upper case letter to lower case and append
        else if (ch >= 'A' && ch <= 'Z')
            word = word + char(ch - 'A' + 'a');

        // Return word if length greater than zero
        else if (word.length() > 0)
            found_word = true;
    }

    // Return boolean flag
    return found_word;
}

void Sort::merge_sort2(string data[], string copy[], int low, int high)
{
    // Check terminating condition
    int range = high - low + 1;
    if (range > 1)
    {
        // Divide the array and sort both halves
        int mid = (low + high) / 2;
        merge_sort2(data, copy, low, mid);
        merge_sort2(data, copy, mid + 1, high);

        // Initialize array indices
        int index1 = low;
        int index2 = mid + 1;
        int index = 0;

        // Merge smallest data elements into copy array
        while (index1 <= mid && index2 <= high)
        {
            if (data[index1] < data[index2])
                copy[index++] = data[index1++];
            else
                copy[index++] = data[index2++];
        }

        // Copy any remaining entries from the first half
        while (index1 <= mid)
            copy[index++] = data[index1++];

        // Copy any remaining entries from the second half
        while (index2 <= high)
            copy[index++] = data[index2++];

        // Copy data back from the temporary array
        for (index = 0; index < range; index++)
            data[low + index] = copy[index];
    }
}

void Sort::merge_sort(string data[], int low, int high)
{
    // Check terminating condition
    int range = high - low + 1;
    if (range > 1)
    {
        // Allocate memory and call merge_sort2
        string* copy = new string[range];
        merge_sort2(data, copy, low, high);
        delete[]copy;
    }
}
