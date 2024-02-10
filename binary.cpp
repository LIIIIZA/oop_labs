#include "binary.h"

Binary::Binary() : _size(0), _bin_num{nullptr} {}

Binary::Binary(const std::initializer_list<unsigned char> &lst)
{
    _size = lst.size();
    if (_size == 0) {
        _bin_num = nullptr;
        return;
    }
    _bin_num = new unsigned char[lst.size()];
    int ind = lst.size() - 1;
    for (auto &c : lst){
        if ((c != '0') && (c != '1')) {
            throw std::invalid_argument("a binary number consists of only 0 and 1");
        }
        _bin_num[ind] = c;
        --ind;
    }
}

Binary::Binary(const std::string &str)
{
    _size  = str.size();
    if (_size == 0) {
        _bin_num = nullptr;
        return;
    }
    _bin_num = new unsigned char[str.size()];
    int ind = str.size() - 1;
    for (auto &c : str){
        if ((c != '0') && (c != '1')) {
            throw std::invalid_argument("a binary number consists of only 0 and 1");
        }
        _bin_num[ind] = c;
        --ind;
    } 
}

Binary::Binary(const Binary &old_binary)
{
    _size  = old_binary._size;
    if (_size == 0) {
        _bin_num = nullptr;
        return;
    }
    _bin_num = new unsigned char[_size];
    for (size_t i = 0; i <= _size; ++i) {
        _bin_num[i] = old_binary._bin_num[i];
    }
}

Binary::Binary(Binary &&other) noexcept
{
    _size = other._size;
    _bin_num = other._bin_num;
    other._size = 0;
    other._bin_num = {nullptr};
}

bool Binary::equals(const Binary &other) const
{
    if (_size != other._size) { return false; }
    for (size_t i = 0; i < _size; ++i) {
        if (this->_bin_num[i] != other._bin_num[i]) {
            return false;
        }
    }
    return true;
}

bool Binary::more(const Binary &other) const
{
    if (_size > other._size) { return true; }
    if (_size < other._size) { return false; }
    for (int i = _size; i >= 0; --i) {
        if (this->_bin_num[i] < other._bin_num[i]) {
            return false;
        }
    }
    if (this->equals(other)) { return false; }
    return true;
}

bool Binary::less(const Binary &other) const
{
    if (this->_size > other._size) { return false; }
    if (this->_size < other._size) { return true; }
    for (int i = _size - 1; i >= 0; --i) {
        if (this->_bin_num[i] < other._bin_num[i]) {
            return true;
        }
    }
    return false;
}

Binary Binary::add(const Binary &other)
{
    if (other._size == 0) { return Binary(*this); }
    if (this->_size == 0) { return Binary(other); }
    std::string res = "";
    size_t min_len = std::min(this->_size, other._size);
    size_t max_len = std::max(this->_size, other._size);
    size_t plus = 0;
    size_t digit = 0;
    for (size_t i = 0; i < min_len; ++i) {
        if (this->_bin_num[i] == '1') {
            digit++;
        }
        if (other._bin_num[i] == '1') {
            digit++;
        }
        digit += plus;
        if (digit < 2) {
            if (digit == 0) {
                res.push_back('0');
            }
            else {
                res.push_back('1');
            }
            plus = 0;
        }
        else {
            plus = 1;
            if (digit == 2) {
                res.push_back('0');
            }
            else {
                res.push_back('1');
            }
        }
        digit = 0;
    }
    if (max_len == min_len) {
        if (plus == 1) {
            res.push_back('1');
        }
        std::string reverse_res = std::string(res.rbegin(), res.rend());
        return Binary(reverse_res);
    }
    digit = 0;
    if (max_len == this->_size) {
        for (size_t i = min_len; i < max_len; ++i) {
            if (this->_bin_num[i] == '1') {
                digit++;
            }
            digit += plus;
            if (digit < 2) {
                if (digit == 0) {
                    res.push_back('0');
                }
                else {
                    res.push_back('1');
                }
                plus = 0;
            }
            else {
                plus = 1;
                res.push_back('0');
            }
            digit = 0;
        }
    }
    else {
        for (size_t i = min_len; i < max_len; ++i) {
            if (other._bin_num[i] == '1') {
                digit++;
            }
            digit += plus;
            if (digit < 2) {
                if (digit == 0) {
                    res.push_back('0');
                }
                else {
                    res.push_back('1');
                }
                plus = 0;
            }
            else {
                plus = 1;
                res.push_back('0');
            }
            digit = 0;
        }
    }
    std::string reverse_res = std::string(res.rbegin(), res.rend());
    return Binary(reverse_res);
}

Binary Binary::remove(const Binary &other)
{
    if (this->less(other)) {
        throw std::logic_error("the reduced is less than the subtracted");
    }
    size_t minus = 0;
    int digit = 0;
    std::string res = "";
    for (size_t i = 0; i < other._size; ++i) {
        if (this->_bin_num[i] == '1') {
            digit++;
        }
        if (other._bin_num[i] == '1') {
            digit--;
        }
        digit -= minus;
        if (digit >= 0) {
            minus = 0;
            if (digit == 0) {
                res.push_back('0');
            }
            else {
                res.push_back('1');
            }
        }
        else {
            res.push_back('1');
            minus = 1;
        }
        digit = 0;
    }
    for (size_t i = other._size; i < _size; ++i) {
        if (this->_bin_num[i] == '1') {
            digit++;
        }
        digit -= minus;
        if (digit == -1) {
            res.push_back('1');
            minus = 1;
        }
        else {
            minus = 0;
            if (digit == 1) {
                res.push_back('1');
            }
            else {
                res.push_back('0');
            }
        }
        digit = 0;
    }
    while (res[res.size()-1] == '0') {
        res.pop_back();
    }
    if (res.size() == 0) {
        return Binary("0");
    } 
    std::string reverse_res = std::string(res.rbegin(), res.rend());
    return Binary(reverse_res);
}

std::ostream &Binary::print(std::ostream &os)
{
    if (_size == 0) {
        os << "no value" << std::endl;
        return os;
    }
    for (int i = _size-1; i >= 0; --i){
        os << _bin_num[i];
    }
    os << std::endl;
    return os;
}

Binary::~Binary() noexcept
{
    if (_size > 0)
    {
        _size = 0;
        delete[] _bin_num;
        _bin_num = nullptr;
    }
}