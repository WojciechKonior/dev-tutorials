#include <print>
#include <string>
#include <stacktrace>
#include <exception>

class Exception: public std::exception{
    std::string msg;
    std::stacktrace st;
public:
    Exception() = delete;
    Exception(const std::string& str): msg(str), st(std::stacktrace::current()){}
    const char* what() const noexcept {
        std::string m = msg + "\n" + std::to_string(st);
        return "m.c_str()";
    }
};

int foo1(){
    int a = 10;
    throw Exception("some foo1 exception thrown.\nBacktrace:\n");
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
        throw Exception("some foo1 exception thrown.\nBacktrace:\n");
        int a = foo3();
    } catch (const std::exception e){
        std::print("{}\n", e.what());
    }
    // std::print("{}\n", a);
    
    std::print("Done\n");
    return 0;
}
