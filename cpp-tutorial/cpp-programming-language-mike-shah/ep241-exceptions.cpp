#include <print>
#include <string>
#include <exception>

class Exception : public std::exception{
    std::string msg;
public:
    Exception() = delete;
    Exception(const std::string& str): msg(str) {}
    const char* what() const noexcept {
        return msg.c_str();
    }
};

int main(){

    // try{
    //     throw 1;
    // } catch (...) {
    //     std::print("Some unhandled exception thrown\n");
    // }

    // try{
    //     throw 3;
    // } catch(int e) {
    //     std::print("int exception thrown: {}\n", e);
    // }

    // try {
    //     throw std::string("Hello");
    // } catch (std::string e) {
    //     std::print("Some std::string thrown: {}\n", e);
    // }

    // try {
    //     throw std::logic_error("Error");
    // } catch (std::exception& e){
    //     std::print("Some exception thrown: {}\n", e.what());
    // }

    try{
      
        throw Exception("Some message");
    } catch(const std::exception& e){
        std::print("Some exception thrown: {}\n", e.what());
    }

    // throw 123;
    std::print("Done\n");
    return 0;
}
