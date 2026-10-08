#include <iostream>
#include <cmath>
#include <iomanip>

const double PI = 3.14159265358979323846;

// Standard Normal Cumulative Distribution Function (CDF)
double norm_cdf(double x) {
    return 0.5 * std::erfc(-x / std::sqrt(2.0));
}

// Standard Normal Probability Density Function (PDF)
double norm_pdf(double x) {
    return std::exp(-0.5 * x * x) / std::sqrt(2.0 * PI);
}

double calculate_d1(double S, double K, double T, double r, double sigma) {
    return (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
}

double calculate_d2(double d1, double T, double sigma) {
    return d1 - sigma * std::sqrt(T);
}

double call_price(double S, double K, double T, double r, double d1, double d2) {
    return S * norm_cdf(d1) - K * std::exp(-r * T) * norm_cdf(d2);
}

double put_price(double S, double K, double T, double r, double d1, double d2) {
    return K * std::exp(-r * T) * norm_cdf(-d2) - S * norm_cdf(-d1);
}

// --- NEW GREEKS FUNCTIONS ---

double call_delta(double d1) {
    return norm_cdf(d1);
}

double put_delta(double d1) {
    return norm_cdf(d1) - 1.0;
}

double calculate_gamma(double S, double T, double sigma, double d1) {
    return norm_pdf(d1) / (S * sigma * std::sqrt(T));
}

int main() {
    double S, K, T, r, sigma;

    std::cout << "--- Black-Scholes Pricer & Greeks ---\n";
    std::cout << "Spot Price (S): "; 
    std::cin >> S;
    
    std::cout << "Strike Price (K): "; 
    std::cin >> K;
    
    std::cout << "Time to Maturity in years (T): "; 
    std::cin >> T;
    
    std::cout << "Risk-free Rate (r) [e.g., 0.05]: "; 
    std::cin >> r;
    
    std::cout << "Volatility (sigma) [e.g., 0.20]: "; 
    std::cin >> sigma;

    double d1 = calculate_d1(S, K, T, r, sigma);
    double d2 = calculate_d2(d1, T, sigma);

    std::cout << std::fixed << std::setprecision(4);
    
    std::cout << "\n--- Prices ---\n";
    std::cout << "Call Price: " << call_price(S, K, T, r, d1, d2) << "\n";
    std::cout << "Put Price:  " << put_price(S, K, T, r, d1, d2) << "\n";

    std::cout << "\n--- Greeks ---\n";
    std::cout << "Call Delta: " << call_delta(d1) << "\n";
    std::cout << "Put Delta:  " << put_delta(d1) << "\n";
    std::cout << "Gamma:      " << calculate_gamma(S, T, sigma, d1) << "\n";

    return 0;
}
