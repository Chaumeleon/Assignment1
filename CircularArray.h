// STUDENT ORGANIC WAGYU CODE
// Author: Brandon Chau
// San Diego State University
// CS210/CS496: Data Structures
//
// File: CircularArray.h
// Defines the CircularArray collection class.

#define VERSION_CIRARRAY 0.1

// STUDENT CODE
#ifndef PROG1_CIRCULARARRAY_H
#define PROG1_CIRCULARARRAY_H

#include "Queue.h"
#include "List.h"

namespace sdsu {
    template<typename T>
    class CircularArray : public sdsu::Queue<T>, public sdsu::List<T> {

    private:
        // Size represents how many T items the structure holds
        int curSize;

        // Capacity represents how many T items the structure CAN hold
        int curCapacity;

        // todo: head and tail counters for the circular nature
        int head = 0;
        int tail = 0;

        int maxSize = 10;
        // the array on the heap
        T *storage;

    public:

        // This is the default class constructor. It sets the current size to 0
        CircularArray() : curSize(0){
            // todo: initialize a default capacity storage array on the heap
            curCapacity = 10;
            storage = new T[10];
        }

        // The copy constructor!
        CircularArray(const CircularArray<T> &other) : CircularArray() {
            std::cout << "Copying . . .";
            curSize = other.curSize;
            curCapacity = other.curCapacity;
            head = other.head;
            tail = other.tail;
           // storage = new T[curSize + 1];
            *storage = *other.storage;

        }

        ~CircularArray() override {
            delete[] storage;
        }

        void clear() override {
            // size == 0, and the capacity and dynamic array should
            // shrink back to its default size. There is a potential
            // for a memory leak here.
            if (curSize != 0) {
                curSize = 0;
                curCapacity = 10;
                delete[] storage;
                storage = new T[10];
            }
        }

        T dequeue() override {
            T val = storage[head];
            head++; //fix needs more logic
            curSize--;
            return val;
        }

        bool enqueue(T value) override {
           // value = t

           // removes the old storage and replaces it with a new storage that's twice in size (2n + 1).
            if (curSize == curCapacity) {
                T* tempStorage = new T[(2 * curCapacity) + 1];
                curCapacity = (2 * curCapacity) + 1;

                // copying the current value to new array
                for (int i = 0; i < curSize; i++) {
                    tempStorage[i] = storage[i];
                }

                delete[] storage;
                storage = tempStorage;
            }

            if (curSize == curCapacity) {
                head = tail = 0;
                storage[tail] = value;
            }
            else {
                tail++;
                tail = tail % 10;
                storage[tail] = value;
            }
            curSize++; //needed to include a size for the array


            /*
            storage[tail] = t;
            tail++;
            curSize++;
            if (curSize > maxSize) {
                t = new T[curSize + 10];
                for (i = head; i < tail; i++) {
                    t[i] = storage[i];
                }
            }
            */
            return false;
        }

        bool isEmpty() const override {
            return size() == 0;
        }

        T& peek() override {
            // todo: this is here to make it compile, but it is wrong.
            return storage[0];
        }

        bool addFirst(T t) override {
            // a well written insert method makes this a single line.
            return false;
        }

        bool addLast(T t) override {
            // a well written insert method makes this a single line.
            return false;
        }

        T& get(int idx) override {
            // todo: we need idx range checking. In C++, this is dangerous.
            throw std::out_of_range("CircularArray<T>::get(idx) : index out of range.");
            return storage[idx];
        }

        bool insert(int idx, T t) override {
            // if you figure out if you are closer to the head or tail, you can
            // minimize the amount of array manipulation you need to perform.

            return false;
        }

        T remove(int i) override {
            // Figure out if the target index is closer to the front or back
            // and then shuffle from that index (tail or head).
            throw std::out_of_range("CircularArray<T>::remove(i) : index out of range.");
            return 0;
        }

        T removeFirst() override {
            // If you wrote remove correctly, this can be a single line.
            // you *might* want to clean up any exception handling though . . . .
            return 0;
        }

        T removeLast() override {
            // If you wrote remove correctly, this can be a single line.
            // you *might* want to clean up any exception handling though . . . .
            return 0;
        }

        void set(int idx, T value) override {
            throw std::out_of_range("CircularArray<T>::set(idx,value) : index out of range.");
        }

        int size() const override {
            return curSize;
        }
    };
}

#endif //PROG1_CIRCULARARRAY_H
