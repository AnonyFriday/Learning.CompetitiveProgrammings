#pragma once

#include <initializer_list>
#include <iostream>
#include <memory>
#include <optional>
#include <stdexcept>

template <typename T>
class MyVector {
 private:
  // Data Members
  size_t sz;
  size_t cp;
  std::unique_ptr<T[]> data = nullptr;

  // reallocate if size overload the capacity
  void reallocate() {
    if (sz < cp) return;

    cp *= 2;
    std::unique_ptr<T[]> newData = std::make_unique<T[]>(cp);

    // copy value from old to new array
    for (size_t i = 0; i < sz; i++) {
      newData[i] = std::move(data[i]);
    }

    // data take back the ownership
    // old data's object is freed and the pointer newData is also deallocated
    // newData ───> nullptr
    data = std::move(newData);
  }

 public:
  // === Constructor ===
  // Default Constructor
  MyVector()
      : sz(0), cp(2), data(std::make_unique<T[]>(cp)) {
  }

  // Initializer List
  MyVector(std::initializer_list<T> list)
      : sz(list.size()),
        cp(list.size() * 2),
        data(std::make_unique<T[]>(cp)) {
    if (sz == 0) return;

    size_t i = 0;

    for (const auto& item : list) {
      data[i++] = item;
    }
  }

  // Destructor
  ~MyVector() {
    data.reset();
    std::cout << "Vector has been destroyed." << std::endl;
  }

  // === Methods ===
  void push_back(T el) {
    if (sz >= cp) {
      reallocate();
    }

    data[sz++] = std::move(el);
  }

  T pop_back() {
    if (sz == 0) {
      throw std::out_of_range("Cannot pop from an empty vector!");
    }

    auto el = data[--sz];
    return el;
  }

  size_t size() const {
    return sz;
  }

  size_t capacity() const {
    return cp;
  }

  bool isEmpty() const {
    return sz == 0;
  }

  T front() const {
    return data[0];
  }

  T back() const {
    return data[sz - 1];
  }

  std::optional<T> at(const int i) const {
    if (i < 0 || i >= (int)sz) {
      return std::nullopt;
    }

    return data[i];
  }

  const T* begin() const {
    return &data[0];
  }

  const T* end() const {
    return &data[sz];
  }

  // === Operators ===

  // Regular: can read and write (vector[0] = 10)
  T& operator[](size_t index) {
    return data[index];
  }

  const T& operator[](size_t index) const {
    return data[index];
  }

  // return only the value
  T at(size_t index) const {
    if (index >= sz) {
      throw std::out_of_range("Index out of range");
    }

    return data[index];
  }
};