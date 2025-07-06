#include<iostream>
#include<vector>


/*
LinkToArticle: https://www.geeksforgeeks.org/dsa/circular-array/
*/
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* buffer;
    int capacity;
    int head;
    int tail;

public:
    CircularQueue(int k) {
        capacity = k + 1; // Reserve one slot
        buffer = new int[capacity];
        head = 0;
        tail = 0;
    }

    ~CircularQueue() {
        delete[] buffer;
    }

    bool isEmpty() {
        return head == tail;
    }

    bool isFull() {
        return (tail + 1) % capacity == head;
    }

    bool enqueue(int value) {
        if (isFull()) return false;
        buffer[tail] = value;
        tail = (tail + 1) % capacity;
        return true;
    }

    bool dequeue() {
        if (isEmpty()) return false;
        head = (head + 1) % capacity;
        return true;
    }

    int front() {
        if (isEmpty()) return -1;
        return buffer[head];
    }

    int rear() {
        if (isEmpty()) return -1;
        return buffer[(tail - 1 + capacity) % capacity];
    }

    int size() {
        return (tail - head + capacity) % capacity;
    }
};

