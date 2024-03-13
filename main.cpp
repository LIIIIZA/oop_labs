#include <ctime>
//#include <pthread.h>
#include <thread>
#include <vector>
#include <iostream>
#include "container.h"

int val;
std::vector<int> values;
std::mutex mtx_int;
std::mutex mtx_vector;
//std::mutex mtx_gen_num;
bool is_done;
bool gen_func;
bool observe_func;
bool statistic_func;
//bool is_notified;
Container<int> c; 

void Gen_num() {
    int quantity; 
    while (!is_done) {
        while (!gen_func) {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
        {
            std::unique_lock<std::mutex> locker(mtx_vector);
            values.clear();
            srand((unsigned)time(NULL));
            quantity = rand() % 100 + 1;
            for (size_t i = 0; i < quantity; ++i) {
                values.push_back(rand());
            }
            observe_func = true;
            gen_func = false;
            std::this_thread::sleep_for(std::chrono::milliseconds(30));
        }
    }
}

void Observe() {
    while (!is_done) {
        while (!observe_func) {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
        {
            std::unique_lock<std::mutex> locker(mtx_vector);
            if (!values.empty()) {
                std::unique_lock<std::mutex> locker(mtx_int);
                val = values.back();
                values.pop_back();
                observe_func = false;
                statistic_func = true;
            }
            else {
                statistic_func = false;
                observe_func = false;
                gen_func = true;
            }
        }
    }
}

void Statistics() {
    while (!is_done) {
        while (!statistic_func) {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
        {
            std::unique_lock<std::mutex> locker(mtx_int);
            if (val) {
                c.add(val);
                std::cout << "amount: " << c.get_size() << std::endl;
                std::cout << "max: " << c.maximum() << std::endl;
                std::cout << "min: " << c.minimum() << std::endl;
                std::cout << "average: " << c.average() << std::endl;
                std::cout << "value: " << val << std::endl;
                std::cout << std::endl << std::endl;

                observe_func = true;
                statistic_func = false;
            }
        }
    }
}

int main() {
    //srand(time(0));
    is_done = false;
    gen_func = true;
    observe_func = false;
    statistic_func = false;
    std::thread g(Gen_num);
    std::thread o(Observe);
    std::thread s(Statistics);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    is_done = true;
    g.join();
    o.join();
    s.join();
    
    return 0;
}