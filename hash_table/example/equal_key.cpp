#include <iostream>
#include <unordered_map>

int main() {
    //---unordered_multimap:unordered map which allow same key
    std::unordered_multimap<int, int> myMultiMap;

    // 插入?值?
    myMultiMap.insert({1, 5});
    myMultiMap.insert({2, 10});
    myMultiMap.insert({1, 15}); // 1 ????值

    // ?取???的值并?出
    std::cout << "Values for key 1: ";
    auto range = myMultiMap.equal_range(1);
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->second << " ";
    }
    std::cout << std::endl;

    range = myMultiMap.equal_range(2);
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->second << " ";
    }
    std::cout << std::endl;

    return 0;
}
