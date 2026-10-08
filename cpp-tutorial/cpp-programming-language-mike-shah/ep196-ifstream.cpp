#include <iostream>
#include <print>
#include <fstream>
#include <filesystem>
#include <string>

int main(){
    std::ofstream myfile("myFile.txt");
    myfile << "Another line\nWojtek konior\n";
    myfile.close();
    
    std::ifstream f("myFile.txt");
    if(f.is_open() && std::filesystem::exists("myFile.txt")){
        
        std::string line;
        while(std::getline(f, line)){

            std::cout << "read:" << line << std::endl;
        }
        f.close();
    } else {
        std::cerr << "file does not exist\n";
        f.close();
    }

    return 0;
}
