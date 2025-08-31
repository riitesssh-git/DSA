//Program for search single element in sorted array
//Leetcode : 540
//Lecture : 20

#include<iostream>
#include<vector>
using namespace std;

int single_element(vector <int> &A) {

    int n = A.size();
    if(n == 1) return A[0];

    int st = 0, end = n - 1;

    while(st <= end) {
        
        int mid = st + (end - st) / 2;
        //edge cases
        if(mid == 0 && A[0] != A[1])
            return A[mid];
        if(mid == n-1 && A[n-1] !=  A[n-2]) 
            return A[mid];

        if(mid % 2 == 0) {      //mid is even
            if(A[mid-1] == A[mid])  // left
                end = mid - 1;
            else                    // right
                st = mid + 1;
        } else {               //Mid is odd
            if(A[mid-1] == A[mid])  //right
                st = mid + 1;
            else 
                end = mid - 1;
        }
    }

    return 0;
}

int main() {

    int size;
    cout << "Enter size of array : ";
    cin >> size;
    vector <int> arr(size);
    cout << "Enter all the elements of array : " << endl;
    for(int i=0; i<size; i++) {
        cin >> arr[i];
    }
    int single = single_element(arr);
    cout << "\n" << "Single element in the array is : " << single << endl;

    return 0;
}