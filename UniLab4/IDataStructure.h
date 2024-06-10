#pragma once

#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <stdexcept>

namespace UniLab4 {
    
    // -- [ Функции взаимодействия со структурами ] --
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

    // -- [ Массив ] --
    
    class MyArray : public IDataStructure {
        std::vector<int> data;
    public:
        // Добавление элемента
        void Insert(int value) override {
            data.push_back(value);
        }
        
        // Удаление элемента
        void RemoveLast() override {
            if (!data.empty()) {
                data.pop_back();
            }
        }
        
        // Замена элемента
        void Replace(int index, int newValue) override {
            if (index >= 0 && index < data.size()) {
                data[index] = newValue;
            }
        }
        
        // Поворот элемента
        void Rotate(int count) override {
            if (data.empty()) return;
            count %= data.size();
            std::rotate(data.rbegin(), data.rbegin() + count, data.rend());
        }
        
        // Медиана массива
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

    // -- [ Вектор ] --
    
    class MyVector : public IDataStructure {
        std::vector<int> data;
    public:
        // Добавление элемента
        void Insert(int value) override {
            data.push_back(value);
        }
        
        // Удаление элемента
        void RemoveLast() override {
            if (!data.empty()) {
                data.pop_back();
            }
        }
        
        // Замена элемента
        void Replace(int index, int newValue) override {
            if (index >= 0 && index < data.size()) {
                data[index] = newValue;
            }
        }
        
        // Поворот элемента
        void Rotate(int count) override {
            if (data.empty()) return;
            count %= data.size();
            std::rotate(data.rbegin(), data.rbegin() + count, data.rend());
        }
        
        // Медиана вектора
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

    // -- [ Стэк ] --
    
    class MyStack : public IDataStructure {
        std::stack<int> data;
    public:
        // Добавление элемента
        void Insert(int value) override {
            data.push(value);
        }
        
        // Удаление элемента
        void RemoveLast() override {
            if (!data.empty()) {
                data.pop();
            }
        }
        
        // Замена элемента
        void Replace(int index, int newValue) override {
            throw std::runtime_error("Замена элемента не поддерживается для cтруктуры типа Stack.");
        }
        
        // Поворот элемента
        void Rotate(int count) override {
            throw std::runtime_error("Поворот не поддерживается для cтруктуры типа Stack.");
        }
        
        // Медиана стэка
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

    // -- [ Очередь ] --
    
    class MyQueue : public IDataStructure {
        std::queue<int> data;
    public:
        // Добавление элемента
        void Insert(int value) override {
            data.push(value);
        }
        
        // Удаление элемента
        void RemoveLast() override {
            throw std::runtime_error("Удаление последнего элемента не поддерживается для cтруктуры типа Queue.");
        }
        
        // Замена элемента
        void Replace(int index, int newValue) override {
            throw std::runtime_error("Замена элемента не поддерживается для cтруктуры типа Queue.");
        }
        
        // Поворот элемента
        void Rotate(int count) override {
            throw std::runtime_error("Поворот не поддерживается для cтруктуры типа Queue.");
        }
        
        // Медиана очереди
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

