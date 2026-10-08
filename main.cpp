#include <iostream>
#include <cmath>
#include <iomanip>

// 1. Standard Normal CDF
double norm_cdf(double x) {
    return 0.5 * std::erfc(-x / std::sqrt(2.0));
}

// 2. Calculate d1
double calculate_d1(double S, double K, double T, double r, double sigma) {
    return (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
}

// 3. Calculate d2
double calculate_d2(double d1, double T, double sigma) {
    return d1 - sigma * std::sqrt(T);
}

// 4. Calculate European Call Price
double call_price(double S, double K, double T, double r, double d1, double d2) {
    return S * norm_cdf(d1) - K * std::exp(-r * T) * norm_cdf(d2);
}

// 5. Calculate European Put Price
double put_price(double S, double K, double T, double r, double d1, double d2) {
    return K * std::exp(-r * T) * norm_cdf(-d2) - S * norm_cdf(-d1);
}

int main() {
    double S, K, T, r, sigma;

    std::cout << "--- Black-Scholes Terminal Pricer ---\n";
    std::cout << "Spot Price (S): "; 
    std::cin >> S;
    
    std::cout << "Strike Price (K): "; 
    std::cin >> K;
    
    std::cout << "Time to Maturity in years (T) [e.g., 0.5 for 6 months]: "; 
    std::cin >> T;
    
    std::cout << "Risk-free Rate (r) [e.g., 0.05 for 5%]: "; 
    std::cin >> r;
    
    std::cout << "Volatility (sigma) [e.g., 0.20 for 20%]: "; 
    std::cin >> sigma;

    // Run the math
    double d1 = calculate_d1(S, K, T, r, sigma);
    double d2 = calculate_d2(d1, T, sigma);

    // Format output to 4 decimal places
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "\nResults:\n";
    std::cout << "Call Price: " << call_price(S, K, T, r, d1, d2) << "\n";
    std::cout << "Put Price: " << put_price(S, K, T, r, d1, d2) << "\n";

    return 0;
}
