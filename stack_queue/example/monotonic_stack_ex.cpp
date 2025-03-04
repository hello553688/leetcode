#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <stack>


using namespace std;
 
// Function to build Monotonic
// increasing stack
void increasingStack(int arr[], int N)
{
    // Initialise stack
    stack<int> stk;
 
    for (int i = 0; i < N; i++) {
 
        // Either stack is empty or
        // all bigger nums are popped off
        while (stk.size() > 0 && stk.top() > arr[i]) {
            stk.pop();
        }
        stk.push(arr[i]);
    }
 
    int N2 = stk.size();
    vector<int> ans(N2);
    int j = N2 - 1;
 
    // Empty Stack
    while (!stk.empty()) {
        ans[j] = stk.top();
        stk.pop();
        j--;
    }
 
    // Displaying the original array
    cout << "The Array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
 
    // Displaying Monotonic increasing stack
    cout << "The Stack: ";
    for (int i = 0; i < N2; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
 void decreasingStack(int arr[], int N)
{
    // Initialising Stack
    stack<int> stk;
 
    for (int i = 0; i < N; i++) {
 
        // Either stack empty or
        // all smaller nums are popped off
        while (stk.size() > 0 && stk.top() < arr[i]) {
            stk.pop();
        }
        stk.push(arr[i]);
    }
 
    int N2 = stk.size();
    vector<int> ans(N2);
    int j = N2 - 1;
 
    // Empty stack
    while (!stk.empty()) {
 
        ans[j] = stk.top();
        stk.pop();
        j--;
    }
 
    // Displaying the original array
    cout << "The Array: ";
    for (int i = 0; i < N; i++) {
 
        cout << arr[i] << " ";
    }
    cout << endl;
 
    // Displaying Monotonic Decreasing Stack
    cout << "The Stack: ";
    for (int i = 0; i < N2; i++) {
 
        cout << ans[i] << " ";
    }
    cout << endl;
}
// Driver code
int main()
{
    int arr_i[] = { 1, 4, 5, 3, 12, 10 };
    int arr_d[] = { 15, 17, 12, 13, 14, 10 };
    int N1 = sizeof(arr_i) / sizeof(arr_i[0]);
    int N2 = sizeof(arr_d) / sizeof(arr_d[0]);
    // Function Call
    increasingStack(arr_i, N1);
    decreasingStack(arr_d, N2);
    return 0;
}