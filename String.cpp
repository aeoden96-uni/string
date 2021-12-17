#include "String.h"
//#include <fmt/format.h>

String::String() : data_{nullptr}, n_{0}
{
    //fmt::print("Default Ctor\n");
}

String::String(const char * cstr) : data_{nullptr}, n_{std::strlen(cstr)}
{
    //fmt::print("Cstring Ctor\n");

    if(n_ > 0){
        data_ = new char[n_ + 1];
        std::strcpy(data_, cstr);
    }
}

String::~String(){
    //fmt::print("Dtor\n");
    delete [] data_;
}

String::String(String const & str) : data_{str.n_ > 0 ? new char[str.n_ +1] : nullptr},
                                     n_{str.n_}
{
    //fmt::print("Copy Ctor\n");
    if(n_ > 0){
        std::strcpy(data_, str.data_);
    }
}

String operator+(String const & s1, String const & s2){
    std::size_t N = s1.n_ + s2.n_;
    char * tmp = new char[N+1];
    if(s1.n_ > 0)
        std::strcpy(tmp, s1.data_);
    if(s2.n_ > 0)
        std::strcpy(tmp + s1.n_, s2.data_);
    tmp[N] = '\0';
    return String{tmp};
}

String::String(String && rhs) noexcept : data_{rhs.data_}, n_{rhs.n_} {
    //fmt::print("Move Ctor\n");
    rhs.data_ = nullptr;
    rhs.n_ = 0;
}

/*
// x = std::move(x)
String & String::operator=(String && rhs) noexcept{
    fmt::print("Move OP\n");
    if(data_ != rhs.data_){  // nije preporučeno
        std::swap(data_, rhs.data_);
        n_ = rhs.n_;
        delete [] rhs.data_;
        rhs.n_ = 0;
    }

    return *this;
}

// x = x;
String & String::operator=(String const & rhs){
    fmt::print("Copy OP\n");
    char * data_new = nullptr;
    if(rhs.n_ > 0){
        data_new = new char[rhs.n_ + 1];
        std::strcpy(data_new, rhs.data_);
    }
    std::swap(data_new, data_);
    n_ = rhs.n_;
    delete [] data_new;
    return *this;
}
*/

String & String::operator=(String rhs) & noexcept { // copy and swap idiom
    swap(*this, rhs);
    return *this;
}
