#include <iostream>
#include <random>

// function to integrate
double function(double x, double y) {
    return x*y*y - 3*x;
}

double double_integrate(double low_0, double high_0, double low_1, double high_1, int iter = 100000) {
    std::random_device rd;
    std::default_random_engine reng(rd());
    std::uniform_real_distribution<> unif_0(low_0, high_0);
    std::uniform_real_distribution<> unif_1(low_1, high_1);

    double sum = 0;
    
    for (int i = 0; i < iter; ++i) {
        sum += function(unif_0(reng), unif_1(reng))*(high_0 - low_0)*(high_1 - low_1);
    }
    

    return sum / iter;
}

int main() {

    std::cout << double_integrate(1,3,2,4) << std::endl;;
    return 0;
}