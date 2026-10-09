constexpr auto add(int a, int b){
    return a+b;
}

consteval auto sub(int a, int b){
    return a+b;
}

template <typename T>
consteval auto mul(T a, T b){
    return a*b;
}

int main(){
    const int a = 2;
    auto res = add(1,2);
    constexpr auto b = 10 + a;
    auto res2 = sub(1,2);
    auto res3 = sub(a,3);
    auto res4 = mul(a,3);
    constinit static int c = 10;

    return 0;
}
