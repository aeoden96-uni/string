#pragma once
#include <cstddef> // std::size_t
#include <utility>
#include <cstring>

class String{
public:
    String();
    String(const char *);   // Konstruktor
    String(String const &); // CCtor kopiranjem
//    String & operator=(String const &); // OP kopiranjem
    ~String();

    String(String &&) noexcept;
//    String & operator=(String &&) noexcept;
    String & operator=(String) & noexcept;

    char operator[](std::size_t i) const { return data_[i]; }
    char & operator[](std::size_t i) { return data_[i]; }

    const char * data() const { return data_; }
    std::size_t size() const { return n_; }

    char * begin(){ return data_; }
    char * end() { return data_ + n_; }

    char const * begin() const{ return data_; }
    char const * end()  const { return data_ + n_; }
private:
    friend String operator+(String const & s1, String const & s2);
    friend void swap(String & s1, String & s2){
        using std::swap;
        swap(s1.data_, s2.data_);
        swap(s1.n_, s2.n_);
    }
    //friend void f() {}
    char * data_;
    std::size_t n_;
};
// void swap(String & s1, String & s2);