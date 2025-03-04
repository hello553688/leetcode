// C++ program to demonstrate  
// functionality of unordered_map 
#include <iostream> 
#include <unordered_map> 
using namespace std; 
  
// Driver code 
int main() 
{ 
  // Declaring umap to be of  
  // <string, int> type key  
  // will be of STRING type  
  // and mapped VALUE will 
  // be of int type 
  unordered_map<string, int> umap = {{"Ground", 1}, 
                                      {"Floor", 2}, 
                                      {"Table", 3}}; 
  cout << umap.size() << endl; 
  unordered_map<int, int> umap_int={{1,10},{2,10},{3,10}};

  // inserting values by using [] operator 
  umap["GeeksforGeeks"] = 10; 
  umap["Practice"] = 20; 
  umap["Contribute"] = 30; 
  
  // Traversing an unordered map 
  for (auto x : umap) 
    cout << x.first << " " <<  
            x.second << endl; 

  cout<<endl;
  for (auto x : umap_int) 
    cout << x.first << " " <<  
            x.second << endl; 
}