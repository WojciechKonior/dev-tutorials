#include <print>
#include <string>
#include <stacktrace>
#include <exception>

template<typename... Pack>
void PrintAllArgs(Pack... args){
    (std::print("{} ", args), ...);
    std::print("\n");
}

int main(){
    PrintAllArgs(1, 2, 3.0, "Wojtek", "itp", 10);
    std::print("Done\n");
    return 0;
}
