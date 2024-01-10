#include <iostream>
using namespace std;

const int MAXSIZE = 10007;  // 哈希表的最大容量

struct HashNode {
    int key;
    int val;
    bool valid;  // 标记该节点是否有效（即该位置是否有元素）
    HashNode(int k = 0, int v = 0, bool flag = false) : key(k), val(v), valid(flag) {}
};

class HashTable {
private:
    HashNode table[MAXSIZE];  // 哈希表数组
    int hashFunc(int key) {  // 哈希函数
        return key % MAXSIZE;
    }
public:
    void insert(int key, int val) {  // 插入操作
        int idx = hashFunc(key);
        while (table[idx].valid && table[idx].key != key) {  // 冲突处理
            idx = (idx + 1) % MAXSIZE;
        }
        table[idx] = HashNode(key, val, true);
    }

    int get(int key) {  // 查找操作
        int idx = hashFunc(key);
        while (table[idx].valid) {  // 冲突处理
            if (table[idx].key == key) {
                return table[idx].val;
            }
            idx = (idx + 1) % MAXSIZE;
        }
        return -1;  // 没找到返回-1
    }

    void remove(int key) {  // 删除操作
        int idx = hashFunc(key);
        while (table[idx].valid) {  // 冲突处理
            if (table[idx].key == key) {
                table[idx].valid = false;
                return;
            }
            idx = (idx + 1) % MAXSIZE;
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(1, 100);
    ht.insert(2, 200);
    ht.insert(3, 300);

    cout << ht.get(2) << endl;  // 输出200

    ht.remove(2);
    cout << ht.get(2) << endl;  // 输出-1

    return 0;
}
