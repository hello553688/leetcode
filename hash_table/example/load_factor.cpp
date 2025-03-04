#include <iostream> 
#include <unordered_map> 
using namespace std; 
  
int main() 
{ 
  
    // declaration of unordered_map 
    unordered_map<int, int> sample; 
  
    // inserts element 
    sample.insert({ 1, 2 }); 
    sample.insert({ 2, 4 }); 
    sample.insert({ 5, 8 }); 
    sample.insert({ 7, 10 }); 
  
    cout << "The size is: " << sample.size(); // Number of occupied slots
    cout << "\nThe bucket_count is: "
         << sample.bucket_count(); //total Number of slots
  
    cout << "\nThe load_factor is: "
         << sample.load_factor(); 
  
    sample.insert({ 9, 0 }); 
  
    cout << "\n\nThe size is: "
         << sample.size(); 
  
    cout << "\nThe bucket_count is: "
         << sample.bucket_count(); 
  
    cout << "\nThe load_factor is: "
         << sample.load_factor(); 
  
    sample.insert({ 11, 1 }); 
  
    cout << "\n\nThe size is: "
         << sample.size(); 
  
    cout << "\nThe bucket_count is: "
         << sample.bucket_count(); 
  
    cout << "\nThe load_factor is: "
         << sample.load_factor(); 
    return 0; 
} 