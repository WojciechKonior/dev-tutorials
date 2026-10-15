#include <print>
#include <string>
#include <stacktrace>
#include <exception>

class Exception: public std::exception{
    std::string msg;
    std::stacktrace st;
public:
    Exception() = delete;
    Exception(const char* str): msg(str), st(std::stacktrace::current()) { 
        std::print("{}\nBacktrace:\n{}\n",msg, st);
    }
    // Exception(const std::string& str): msg(str), st(std::stacktrace::current()){}
    const char* what() const noexcept override {
        // std::print("{}\n", st);
        
        return "Hej";
    }
};

int foo1(){
    int a = 10;
    throw Exception("some foo1 exception thrown.");
    return a;
}

int foo2(){
    return foo1();
}

int foo3(){
    return foo2();
}

int main(){
    try {
        // throw Exception("some foo1 exception thrown.\nBacktrace:\n");
        int a = foo3();
    } catch (const std::exception& e){
        e.what();
    }
    // std::print("{}\n", a);
    
    std::print("Done\n");
    return 0;
}
