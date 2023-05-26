#pragma once
#include <iostream>
#include <string>
#include <functional>
using namespace std;

template<typename K>
size_t murmur_hash2a(const K& key) {
    size_t hash = 0;
    const char* data = reinterpret_cast<const char*>(&key);
    size_t len = sizeof(key);
    const size_t m = 0x5bd1e995;
    const int r = 24;

    while (len >= 4) {
        size_t k = *(reinterpret_cast<const size_t*>(data));
        k *= m;
        k ^= k >> r;
        k *= m;

        hash *= m;
        hash ^= k;

        data += 4;
        len -= 4;
    }

    switch (len) {
    case 3:
        hash ^= static_cast<size_t>(data[2]) << 16;
    case 2:
        hash ^= static_cast<size_t>(data[1]) << 8;
    case 1:
        hash ^= static_cast<size_t>(data[0]);
        hash *= m;
    }

    hash ^= hash >> 13;
    hash *= m;
    hash ^= hash >> 15;

    return hash;
}

template<typename K, typename V>
struct KeyValuePair {
    K key;
    V value;
};

template<typename K, typename V>
class HashTable {
private:
    KeyValuePair<K, V>** table;
    bool** isOccupied;
    int size;

public:
    HashTable(int initialSize = 100) {
        size = initialSize;
        table = new KeyValuePair<K, V>* [size]();
        isOccupied = new bool* [size]();
        for (int i = 0; i < size; i++) {
            table[i] = new KeyValuePair<K, V>[size]();
            isOccupied[i] = new bool[size]();
        }
    }

    ~HashTable() {
        for (int i = 0; i < size; i++) {
            delete[] table[i];
            delete[] isOccupied[i];
        }
        delete[] table;
        delete[] isOccupied;
    }

    size_t hash(const K& key) const {
        return murmur_hash2a(key) % size;
    }

    void insert(const K& key, const V& value) {
        int index = hash(key);
        int startIndex = index;
        int i = 1;

        while (isOccupied[index][i]) {
            index = (startIndex + i) % size;
            i++;
        }

        table[index][i].key = key;
        table[index][i].value = value;
        isOccupied[index][i] = true;
    }

    V* search(const K& key) const {
        int index = hash(key);
        int startIndex = index;
        int i = 1;

        while (isOccupied[index][i]) {
            if (table[index][i].key == key) {
                return &(table[index][i].value);
            }

            index = (startIndex + i) % size;
            i++;
        }

        return nullptr;
    }

    void remove(const K& key) {
        int index = hash(key);
        int startIndex = index;
        int i = 1;

        while (isOccupied[index][i]) {
            if (table[index][i].key == key) {
                isOccupied[index][i] = false;
                return;
            }

            index = (startIndex + i) % size;
            i++;
        }
    }

    void resize(int newSize) {
        HashTable<K, V> newTable(newSize);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (isOccupied[i][j]) {
                    newTable.insert(table[i][j].key, table[i][j].value);
                }
            }
        }

        *this = newTable;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (isOccupied[i][j]) {
                    cout << "(" << table[i][j].key << ", " << table[i][j].value << ") ";
                }
            }
        }
        cout << endl;
    }

    void clear() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                isOccupied[i][j] = false;
            }
        }
    }

    void interface() {
        int choice;
        while (true) {
            cout << endl << "1. Insert a key" << endl;
            cout << "2. Search a key" << endl;
            cout << "3. Remove a key" << endl;
            cout << "4. Print Hash table" << endl;
            cout << "5. Clear Hash Table" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                K key;
                V value;
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                insert(key, value);
                cout << "Element inserted." << endl;
            }
            else if (choice == 2) {
                K key;
                cout << "Enter key: ";
                cin >> key;
                V* value = search(key);
                if (value) {
                    cout << "Value found: " << *value << endl;
                }
                else {
                    cout << "Value not found." << endl;
                }
            }
            else if (choice == 3) {
                K key;
                cout << "Enter key: ";
                cin >> key;
                remove(key);
                cout << "Element removed." << endl;
            }
            else if (choice == 4) {
                print();
            }
            else if (choice == 5) {
                clear();
                cout << "Table cleared." << endl;
            }
            else if (choice == 6) {
                break;
            }
            else {
                cout << "Invalid choice." << endl;
            }
        }
    }
};