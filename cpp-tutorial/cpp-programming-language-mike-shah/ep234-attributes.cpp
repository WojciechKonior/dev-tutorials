#include <print>

[[nodiscard]]
int meaningful_value_generated(){
    return 42;
}

[[nodiscard, deprecated]]
int meaningful_value_generated2(){
    return 43;
}

void FallThrough(int input){
    switch(input){
        case 0:
            [[fallthrough]];
        case 1:
            std::print("fallthrough here\n");
            [[fallthrough]];
        case 2:
        
        default:
            std::print("default\n");
    }
}

int main(){

    int a = meaningful_value_generated();
    // int b = meaningful_value_generated2();

    
    std::print("Done\n");
    return 0;
}
