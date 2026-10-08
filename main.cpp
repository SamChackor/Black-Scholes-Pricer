#include <iostream>
#include <iomanip>
#include "black_scholes.h"

int main() {
    double S, K, T, r, sigma;

    std::cout << "--- Black-Scholes Pricer & Greeks ---\n";
    std::cout << "Spot Price (S): "; std::cin >> S;
    std::cout << "Strike Price (K): "; std::cin >> K;
    std::cout << "Time to Maturity in years (T): "; std::cin >> T;
    std::cout << "Risk-free Rate (r) [e.g., 0.05]: "; std::cin >> r;
    std::cout << "Volatility (sigma) [e.g., 0.20]: "; std::cin >> sigma;

    double d1 = calculate_d1(S, K, T, r, sigma);
    double d2 = calculate_d2(d1, T, sigma);

    std::cout << std::fixed << std::setprecision(4);
    
    std::cout << "\n--- Prices ---\n";
    std::cout << "Call Price: " << call_price(S, K, T, r, d1, d2) << "\n";
    std::cout << "Put Price:  " << put_price(S, K, T, r, d1, d2) << "\n";

    std::cout << "\n--- Call Greeks ---\n";
    std::cout << "Delta: " << call_delta(d1) << "\n";
    std::cout << "Gamma: " << calculate_gamma(S, T, sigma, d1) << "\n";
    std::cout << "Vega:  " << calculate_vega(S, T, d1) / 100.0 << " (per 1% vol)\n";
    std::cout << "Theta: " << call_theta(S, K, T, r, sigma, d1, d2) / 365.0 << " (per day)\n";
    std::cout << "Rho:   " << call_rho(K, T, r, d2) / 100.0 << " (per 1% rate)\n";

    std::cout << "\n--- Put Greeks ---\n";
    std::cout << "Delta: " << put_delta(d1) << "\n";
    std::cout << "Gamma: " << calculate_gamma(S, T, sigma, d1) << "\n";
    std::cout << "Vega:  " << calculate_vega(S, T, d1) / 100.0 << " (per 1% vol)\n";
    std::cout << "Theta: " << put_theta(S, K, T, r, sigma, d1, d2) / 365.0 << " (per day)\n";
    std::cout << "Rho:   " << put_rho(K, T, r, d2) / 100.0 << " (per 1% rate)\n";

    return 0;
}
