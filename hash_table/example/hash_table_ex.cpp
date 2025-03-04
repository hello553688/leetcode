#include <iostream>
#include <list>
#include <vector>

// 定?哈希表的大小
const int TABLE_SIZE = 10;

// 哈希表的??
struct HashNode {
    int key;
    int value;
    HashNode(int k, int v) : key(k), value(v) {}
};

// 哈希表?
class HashTable {
private:
    std::vector<std::list<HashNode>> table;

    // ??的哈希函?，?里直接取余
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE);
    }

    // 向哈希表中插入?值?
    void insert(int key, int value) {
        int index = hashFunction(key);
        for (auto& node : table[index]) {
            if (node.key == key) {
                // 如果已存在相同的?，?更新值
                node.value = value;
                return;
            }
        }
        // 如果不存在相同的?，?添加新??
        table[index].emplace_back(key, value);
    }

    // ?哈希表中?取???的值
    int get(int key) {
        int index = hashFunction(key);
        for (auto& node : table[index]) {
            if (node.key == key) {
                return node.value;
            }
        }
        // 如果?不存在，?返回一?特定的值（?里??-1）
        return -1;
    }

    // ?哈希表中?除?值?
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove_if([key](const HashNode& node) {
            return node.key == key;
        });
    }
};

int main() {
    HashTable hashTable;
    
    // 插入?值?
    hashTable.insert(1, 10);
    hashTable.insert(2, 20);
    hashTable.insert(11, 30);

    // ?取???的值
    std::cout << "Value for key 1: " << hashTable.get(1) << std::endl;
    std::cout << "Value for key 2: " << hashTable.get(2) << std::endl;
    std::cout << "Value for key 11: " << hashTable.get(11) << std::endl;

    // ?除?值?
    hashTable.remove(2);
    std::cout << "Value for key 2 after removal: " << hashTable.get(2) << std::endl;

    return 0;
}
