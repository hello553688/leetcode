#include<iostream> 
#include<unordered_map> 
  
using namespace std; 
  
int main() 
{ 
    // unordered map 
    // unordered_map<int , string> umap;    //Count of elements=1 
    unordered_multimap<int , string> umap;  //Count of elements=2 
    // Inserting elements into the map 
    umap.insert(make_pair(1,"Welcome")); 
    umap.insert(make_pair(2,"to")); 
    umap.insert(make_pair(3,"GeeksforGeeks")); 
      
    // Try inserting element with 
    // duplicate keys 
    umap.insert(make_pair(3,"CS Portal")); 
      
    // Print the count of values with key 3 
    // to check if duplicate values are stored  
    // or not 
    cout<<"Count of elements in map, mapped with key 3: "
            <<umap.count(3); 
      
    return 0; 
} 