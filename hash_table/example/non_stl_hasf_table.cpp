#include <iostream>
#include <vector>
#include <list>

// 定?哈希表的大小
const int HASH_TABLE_SIZE = 10;
using namespace std;
// 哈希表???构
struct HashNode {
    int key;
    int value;
};

// 哈希表?
class HashMap {
private:
    vector<list<HashNode>> table; // 使用?表解??突
public:
    // 构造函?
    HashMap() : table(HASH_TABLE_SIZE) {}

    // 哈希函?
    int hashFunction(int key) {
        return key % HASH_TABLE_SIZE;
    }

    // 插入?值?
    void insert(int key, int value) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if ((*it).key == key) {
                (*it).value = value; // 如果?已?存在，更新值
                return;
            }
        }
        HashNode newNode = {key, value};
        table[index].push_back(newNode);
    }

    // ?取???的值
    int get(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            cout<<"value:"<<(*it).value<<" ";
            if ((*it).key == key) {
                return (*it).value; // 如果找到了??的?，返回其值
            }
        }
        return -1; // 如果找不到??的?，返回-1
    }
};

int main() {
    HashMap hashMap;
    
    // 插入?值?
    hashMap.insert(1, 5);
    hashMap.insert(2, 10);
    hashMap.insert(11, 15); // ????与 1 ?突
    // ?取???的值并?出
    cout << "Value for key 1: " << hashMap.get(1) << endl;
    cout << "Value for key 2: " << hashMap.get(2) << endl;
    cout << "Value for key 11: " << hashMap.get(11) << endl;
    cout << "Value for key 3: " << hashMap.get(3) << endl; // 不存在的?
    
    return 0;
}