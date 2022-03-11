#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<int> typeConvert(string s);
void mergeSort(vector<int>& unsorted, int left, int right);
void merge(vector<int>& decomposed, int left, int center, int right);
void printList(vector<int> list);


int main() {
    string s;
    while(getline(cin, s)){
        // printf("Received Input: %s\n", s.c_str());
        if (s.empty()) {
            continue;
        }
        vector<int> unsorted = typeConvert(s);
        mergeSort(unsorted, 0, unsorted.size()-1);
        vector<int>& sorted = unsorted; 
        printList(sorted);
    }

    return 0;
}

void printList(vector<int> list){
    // printf("Sorted List: ");
    for (auto it = begin(list); it != end(list) -1; ++it) {
        printf("%d,", *it);
    }
    
    printf("%d\n", list.back());
}

vector<int> typeConvert(string s){
    vector<int> unsorted;
    stringstream ss(s);
    for (int i; ss >> i;) {
        unsorted.push_back(i);
        if (ss.peek() == ','){
            ss.ignore();
        }
    }
    return unsorted;
}

/* Mergesort (array, left, right)
    If r > l
        find the middle point to divide into halves
            (middle = l + (r-l)/2)
        call mergeSort on first half
            mergesort(arr, l. m)
        call mergeSort on second half
            mergesort(arr, m+1, r)
        merge the two halves sorted in step 2 and 3
            merge (arr, l, m, r)
*/
void mergeSort(vector<int>& unsorted, int left, int right){
    if (right > left) {
        int center = left + (right - left) / 2;
        mergeSort(unsorted, left, center);
        mergeSort(unsorted, center+1, right);
        merge(unsorted, left, center, right);
    }
}

void merge(vector<int>& decomposed, int left, int center, int right){
    int segmentLen = (right-left)+1;
    vector<int> sorted;
    int lIndex = left, rIndex = center+1;

    while ((lIndex < center+1) && (rIndex < right+1)){
        if (decomposed[lIndex] < decomposed[rIndex]) {
            sorted.push_back(decomposed[lIndex]);
            lIndex++;
        } else {
            sorted.push_back(decomposed[rIndex]);
            rIndex++;
        }
    }
    
    while (lIndex < center+1) {
        sorted.push_back(decomposed[lIndex]);
        lIndex++;
    }

    while (rIndex < right+1) {
        sorted.push_back(decomposed[rIndex]);
        rIndex++;
    }

    for (int i = 0; i < segmentLen; i++){
        decomposed[left+i] = sorted[i];
    }
}
