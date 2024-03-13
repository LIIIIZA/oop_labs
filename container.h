#include <vector>
#include <algorithm>
#include <iostream>
#include <mutex>
#include <numeric>
 
template <typename T>
class Container 
{
public:
    Container() = default;
    ~Container() = default;
    std::recursive_mutex _lock;
    std::vector<T> elements;
    void add(T elem) {
        std::lock_guard<std::recursive_mutex> locker(_lock);
        elements.push_back(elem);
    }
    T maximum() {
        std::lock_guard<std::recursive_mutex> locker(_lock);
        return *std::max_element(elements.begin(), elements.end());
    }
    T minimum() {
        std::lock_guard<std::recursive_mutex> locker(_lock);
        return *std::min_element(elements.begin(), elements.end());
    }
    T average() {
        std::lock_guard<std::recursive_mutex> locker(_lock);
        int size = this->get_size();
        return (std::accumulate(elements.begin(), elements.end(), 0.0))/size;
    }
    int get_size() { 
        std::lock_guard<std::recursive_mutex> locker(_lock);
        return elements.size();
    }
    void print() {
        std::lock_guard<std::recursive_mutex> locker(_lock);
        for (T elem: elements) {
            std::cout << elem << " ";
        }
    }
};
