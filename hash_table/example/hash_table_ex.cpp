#include <iostream>
#include <list>
#include <vector>

// �w?���ƪ��j�p
const int TABLE_SIZE = 10;

// ���ƪ�??
struct HashNode {
    int key;
    int value;
    HashNode(int k, int v) : key(k), value(v) {}
};

// ���ƪ�?
class HashTable {
private:
    std::vector<std::list<HashNode>> table;

    // ??�����ƨ�?�A?���������E
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE);
    }

    // �V���ƪ����J?��?
    void insert(int key, int value) {
        int index = hashFunction(key);
        for (auto& node : table[index]) {
            if (node.key == key) {
                // �p�G�w�s�b�ۦP��?�A?��s��
                node.value = value;
                return;
            }
        }
        // �p�G���s�b�ۦP��?�A?�K�[�s??
        table[index].emplace_back(key, value);
    }

    // ?���ƪ�?��???����
    int get(int key) {
        int index = hashFunction(key);
        for (auto& node : table[index]) {
            if (node.key == key) {
                return node.value;
            }
        }
        // �p�G?���s�b�A?��^�@?�S�w���ȡ]?��??-1�^
        return -1;
    }

    // ?���ƪ�?��?��?
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove_if([key](const HashNode& node) {
            return node.key == key;
        });
    }
};

int main() {
    HashTable hashTable;
    
    // ���J?��?
    hashTable.insert(1, 10);
    hashTable.insert(2, 20);
    hashTable.insert(11, 30);

    // ?��???����
    std::cout << "Value for key 1: " << hashTable.get(1) << std::endl;
    std::cout << "Value for key 2: " << hashTable.get(2) << std::endl;
    std::cout << "Value for key 11: " << hashTable.get(11) << std::endl;

    // ?��?��?
    hashTable.remove(2);
    std::cout << "Value for key 2 after removal: " << hashTable.get(2) << std::endl;

    return 0;
}
