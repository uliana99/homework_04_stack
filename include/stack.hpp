//  "Copyright (C) 2017, Koshkina Uliana"
#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <initializer_list>
using namespace std;

template <typename T>
class Stack {
        T* array_;
        size_t array_size_;
        size_t count_ = 0;

 public:
        Stack() noexcept : Stack(100) {}

        explicit Stack(size_t _size) noexcept : array_size_(_size), array_(new T[_size]) {}

        void swap(Stack& u) noexcept {
            std::swap(this->array_, u.array_);
            std::swap(this->array_size_, u.array_size_);
            std::swap(this->count_, u.count_);
        }

        Stack(const Stack& u) noexcept : array_(new T[u.array_size_]), array_size_(u.array_size_), count_(u.count_) {
            std::copy(u.array_, u.array_ + u.array_size_, array_);
        }

        Stack(Stack&& u) noexcept : array_(u.array_), array_size_(u.array_size_), count_(u.count_) {
            u.array_ = nullptr;
            u.array_size_ = 0;
            u.count_ = 0;
        }

        Stack(initializer_list<T> l) noexcept : array_size_(l.size()), array_(new T[l.size()]), count_(l.size()) {
            std::copy(l.begin(), l.end(), array_);
        }

        Stack<T>& operator=(const Stack& u) noexcept {
            if(this != &u) {
                Stack(u) .swap(*this);
            }
            return *this;
        }

        Stack<T>& operator=(Stack&& u) noexcept {
            if(this != &u) {
                Stack(std::move(u)) .swap(*this);
            }
            return *this;
        }

        size_t count() const noexcept {
            return count_;
        }

        bool empty() const noexcept {
            if(count_ == 0) return false;
            return true;
        }

        void push(T const &item) noexcept {
            if (count_ == array_size_) {
                T* new_array_ = new T[array_size_*2];
                for (int i = 0; i < array_size_; i++) {
                    new_array_[i] = array_[i];
                }
                array_size_ = array_size_ * 2;

                delete[] array_;
                array_ = new_array_;
            }
            array_[count_++] = item;
        }

        T top() const noexcept {
            return array_[count_];
        }

        void pop() noexcept {
            if(count_ == 0) throw std::logic_error("Error");
            --count_;
        }

        ~Stack() noexcept {
            delete[] array_;
        }
};

#endif  /*  STACK_HPP  */
