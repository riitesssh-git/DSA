//C++ Code for binary search in rotated sorted array
// Lecture 18
// LEETCODE 33
#include <iostream>
#include <vector>
using namespace std;

int search(const vector<int>& arr, int target) {
    int start = 0, end = arr.size() - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(arr[mid] == target)
            return mid;

        // Left side is sorted
        if(arr[start] <= arr[mid]) {
            if(arr[start] <= target && target < arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        // Right side is sorted
        else {
            if(arr[mid] < target && target <= arr[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    int size, target;
    cout << "Enter size of the array: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter elements of the rotated sorted array:\n";
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Enter target to search: ";
    cin >> target;

    int result = search(arr, target);
    if(result != -1)
        cout << "\n" << target << " found at index: " << result << endl;
    else
        cout << "\nTarget not found in this array.\n";

    return 0;
}


