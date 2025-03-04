#include <iostream>
#include <vector>
using namespace std;
// Binary search function
int binarySearch(const std::vector<int>& array, int target) {
    int left = 0;
    int right = array.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        cout<<"array[mid]:"<<array[mid]<<endl;
        // Check if target is present at mid
        if (array[mid] == target)
            return mid;

        // If target greater, ignore left half
        if (array[mid] < target)
            left = mid + 1;
        // If target is smaller, ignore right half
        else
            right = mid - 1;
    }

    // If target is not found in the array
    return -1;
}
int main() {
    std::vector<int> array = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 14;
    int result = binarySearch(array, target);
    if (result != -1)
        std::cout << "Element found at index " << result << std::endl;
    else
        std::cout << "Element not found in the array." << std::endl;
    return 0;
}
