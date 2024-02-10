#pragma once

#include <iostream>
#include <string>

class Binary
{ 
public:
    Binary();
    Binary(const std::initializer_list< unsigned char> &t);
    Binary(const std::string &t);
    Binary(const Binary& other);
    Binary(Binary&& other) noexcept;      
    virtual ~Binary() noexcept;

    Binary add(const Binary& other);
    Binary remove(const Binary& other);
    bool equals(const Binary& other) const;
    bool more(const Binary &other) const;
    bool less(const Binary &other) const;
    std::ostream& print(std::ostream& os);
    int get_size();

private:
    size_t _size;
    unsigned char *_bin_num;
};