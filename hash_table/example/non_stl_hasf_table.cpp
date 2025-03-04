#include <iostream>
#include <vector>
#include <list>

// �w?���ƪ��j�p
const int HASH_TABLE_SIZE = 10;
using namespace std;
// ���ƪ�???��
struct HashNode {
    int key;
    int value;
};

// ���ƪ�?
class HashMap {
private:
    vector<list<HashNode>> table; // �ϥ�?���??��
public:
    // �۳y��?
    HashMap() : table(HASH_TABLE_SIZE) {}

    // ���ƨ�?
    int hashFunction(int key) {
        return key % HASH_TABLE_SIZE;
    }

    // ���J?��?
    void insert(int key, int value) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if ((*it).key == key) {
                (*it).value = value; // �p�G?�w?�s�b�A��s��
                return;
            }
        }
        HashNode newNode = {key, value};
        table[index].push_back(newNode);
    }

    // ?��???����
    int get(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            cout<<"value:"<<(*it).value<<" ";
            if ((*it).key == key) {
                return (*it).value; // �p�G���F??��?�A��^���
            }
        }
        return -1; // �p�G�䤣��??��?�A��^-1
    }
};

int main() {
    HashMap hashMap;
    
    // ���J?��?
    hashMap.insert(1, 5);
    hashMap.insert(2, 10);
    hashMap.insert(11, 15); // ????�O 1 ?��
    // ?��???���Ȧ}?�X
    cout << "Value for key 1: " << hashMap.get(1) << endl;
    cout << "Value for key 2: " << hashMap.get(2) << endl;
    cout << "Value for key 11: " << hashMap.get(11) << endl;
    cout << "Value for key 3: " << hashMap.get(3) << endl; // ���s�b��?
    
    return 0;
}