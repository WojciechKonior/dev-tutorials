#include <print>
#include <string>
#include <filesystem>
#include <iostream>


int main(){
    const char* path_to_test = "/home/wkonior/cpp-tutorials/main.cpp";
    std::filesystem::path p(path_to_test);
    std::cout << p.stem();

    std::cout << "stem: " << p.stem() << std::endl;
    std::cout << "filename: " << p.filename() << std::endl;
    std::cout << "extension: " << p.extension() << std::endl;
    std::cout << "root dir: " << p.root_directory() << std::endl;
    std::cout << "parent path: " << p.parent_path() << std::endl;
    std::cout << std::filesystem::current_path() << std::endl;
    std::print("Done\n");

    for(auto entry: std::filesystem::directory_iterator{std::filesystem::current_path()}){
        std::cout << entry << std::endl;
    }

    for(auto entry: std::filesystem::recursive_directory_iterator(std::filesystem::current_path())){
        std::cout << entry << std::endl;
    }
    return 0;
}
