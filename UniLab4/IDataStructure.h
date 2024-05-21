#pragma once

#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <stdexcept>

namespace UniLab4 {

    class IDataStructure {
    public:
        virtual void Insert(int value) = 0;
        virtual void RemoveLast() = 0;
        virtual void Replace(int index, int newValue) = 0;
        virtual void Rotate(int count) = 0;
        virtual double FindMedian() = 0;
        virtual std::vector<int> GetValues() = 0;
        virtual ~IDataStructure() {}
    };

    class MyArray : public IDataStructure {
        std::vector<int> data;
    public:
        void Insert(int value) override {
            data.push_back(value);
        }

        void RemoveLast() override {
            if (!data.empty()) {
                data.pop_back();
            }
        }

        void Replace(int index, int newValue) override {
            if (index >= 0 && index < data.size()) {
                data[index] = newValue;
            }
        }

        void Rotate(int count) override {
            if (data.empty()) return;
            count %= data.size();
            std::rotate(data.rbegin(), data.rbegin() + count, data.rend());
        }

        double FindMedian() override {
            if (data.empty()) throw std::runtime_error("Структура данных пуста.");
            std::vector<int> sortedData = data;
            std::sort(sortedData.begin(), sortedData.end());
            size_t n = sortedData.size();
            if (n % 2 == 0) {
                return (sortedData[n / 2 - 1] + sortedData[n / 2]) / 2.0;
            }
            else {
                return sortedData[n / 2];
            }
        }

        std::vector<int> GetValues() override {
            return data;
        }
    };

    class MyVector : public IDataStructure {
        std::vector<int> data;
    public:
        void Insert(int value) override {
            data.push_back(value);
        }

        void RemoveLast() override {
            if (!data.empty()) {
                data.pop_back();
            }
        }

        void Replace(int index, int newValue) override {
            if (index >= 0 && index < data.size()) {
                data[index] = newValue;
            }
        }

        void Rotate(int count) override {
            if (data.empty()) return;
            count %= data.size();
            std::rotate(data.rbegin(), data.rbegin() + count, data.rend());
        }

        double FindMedian() override {
            if (data.empty()) throw std::runtime_error("Структура данных пуста.");
            std::vector<int> sortedData = data;
            std::sort(sortedData.begin(), sortedData.end());
            size_t n = sortedData.size();
            if (n % 2 == 0) {
                return (sortedData[n / 2 - 1] + sortedData[n / 2]) / 2.0;
            }
            else {
                return sortedData[n / 2];
            }
        }

        std::vector<int> GetValues() override {
            return data;
        }
    };

    class MyStack : public IDataStructure {
        std::stack<int> data;
    public:
        void Insert(int value) override {
            data.push(value);
        }

        void RemoveLast() override {
            if (!data.empty()) {
                data.pop();
            }
        }

        void Replace(int index, int newValue) override {
            throw std::runtime_error("Замена элемента не поддерживается для cтруктуры типа Stack.");
        }

        void Rotate(int count) override {
            throw std::runtime_error("Поворот не поддерживается для cтруктуры типа Stack.");
        }

        double FindMedian() override {
            throw std::runtime_error("Нахождение медианы не поддерживается для cтруктуры типа Stack.");
        }

        std::vector<int> GetValues() override {
            std::stack<int> temp = data;
            std::vector<int> result;
            while (!temp.empty()) {
                result.push_back(temp.top());
                temp.pop();
            }
            std::reverse(result.begin(), result.end());
            return result;
        }
    };

    class MyQueue : public IDataStructure {
        std::queue<int> data;
    public:
        void Insert(int value) override {
            data.push(value);
        }

        void RemoveLast() override {
            throw std::runtime_error("Удаление последнего элемента не поддерживается для cтруктуры типа Queue.");
        }

        void Replace(int index, int newValue) override {
            throw std::runtime_error("Замена элемента не поддерживается для cтруктуры типа Queue.");
        }

        void Rotate(int count) override {
            throw std::runtime_error("Поворот не поддерживается для cтруктуры типа Queue.");
        }

        double FindMedian() override {
            throw std::runtime_error("Нахождение медианы не поддерживается для cтруктуры типа Queue.");
        }

        std::vector<int> GetValues() override {
            std::queue<int> temp = data;
            std::vector<int> result;
            while (!temp.empty()) {
                result.push_back(temp.front());
                temp.pop();
            }
            return result;
        }
    };
}

