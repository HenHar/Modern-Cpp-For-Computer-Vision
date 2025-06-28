#pragma once

#include <cstddef>
#include <stdexcept>

using namespace std;

namespace ipb {

    template <typename T>
    class named_vector {
        string _name = "";
        T* _data = nullptr;
        size_t _size = 0;
        size_t _capacity = 0;

        void resize(size_t new_size) {
            T* temp = new T[new_size];

            for(size_t i = 0; i < _size; i++)
                temp[i] = _data[i];

            delete[] _data;
            _data = temp;
            _capacity = new_size;
        }

    public:
        // Constructor
        named_vector() = default;

        // Destructor
        ~named_vector() = default;

        // Copy constructor (deleted to avoid shallow copy issues)
        named_vector(const named_vector& other) = delete;

        // Assignment operator (deleted to avoid shallow copy issues)
        named_vector& operator=(const named_vector& other) = delete;

        // Add element to the end
        void push_back(const T value) {
            if (_capacity == 0)
                resize(2);
            else if (_size == _capacity)
                resize(2 * _size);

            _data[_size] = value;
            ++_size;
        }

        // Reserve capacity
        void reserve(size_t new_capacity) {
            if (new_capacity <= _size)
                throw std::invalid_argument("New capacity must be bigger than current size of vector");

            if (new_capacity <= _capacity)
                return;

            resize(new_capacity);
        }

        // Access element by index
        T& operator[](const size_t index) {
            if (index >= _size)
                throw std::invalid_argument("Index must be less than vector's size");

            return _data[index];
        }

        named_vector& operator=(named_vector&& other) noexcept {
            // Self-assignment check
            if (this == &other) {
                return *this;
            }

            // Clean up existing data
            delete[] _data;

            // Move data from other
            _name = other._name;
            _data = other._data;
            _size = other._size;
            _capacity = other._capacity;

            // Reset other to valid empty state
            other._data = nullptr;
            other._size = 0;
            other._capacity = 0;

            return *this;
        }

        // Assignment from pair (name, initializer_list)
        named_vector& operator=(const std::pair<std::string, std::initializer_list<T>>& p) {
            delete[] _data;

            _name = p.first;
            _size = 0;
            _capacity = 0;
            _data = nullptr;

            if (p.second.size() > 0) {
                reserve(p.second.size());
                for (const auto& item : p.second) {
                    push_back(item);
                }
            }

            return *this;
        }

        T *vector() {
            return _data;
        }

        // empty method
        bool empty() {
            return _size == 0;
        }

        string name() {
            return _name;
        }

        // Get size
        int size() const {
            return static_cast<int>(_size);
        }
    };

} // namespace ipb
