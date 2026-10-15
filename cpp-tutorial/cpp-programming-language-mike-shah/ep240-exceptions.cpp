#include <print>
#include <string>
#include <exception>

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
      
        throw std::exception(std::logic_error("Some logic error"));
    } catch(std::exception& e){
        std::print("Some exception thrown: {}\n", e.what());
    }

    // throw 123;
    std::print("Done\n");
    return 0;
}
