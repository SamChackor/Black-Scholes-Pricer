#include "black_scholes.h"
#include <cmath>

double norm_cdf(double x) {
    return 0.5 * std::erfc(-x / std::sqrt(2.0));
}

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

double call_delta(double d1) {
    return norm_cdf(d1);
}

double put_delta(double d1) {
    return norm_cdf(d1) - 1.0;
}

double calculate_gamma(double S, double T, double sigma, double d1) {
    return norm_pdf(d1) / (S * sigma * std::sqrt(T));
}

double calculate_vega(double S, double T, double d1) {
    return S * norm_pdf(d1) * std::sqrt(T);
}

double call_theta(double S, double K, double T, double r, double sigma, double d1, double d2) {
    double term1 = -(S * norm_pdf(d1) * sigma) / (2.0 * std::sqrt(T));
    double term2 = r * K * std::exp(-r * T) * norm_cdf(d2);
    return term1 - term2;
}

double put_theta(double S, double K, double T, double r, double sigma, double d1, double d2) {
    double term1 = -(S * norm_pdf(d1) * sigma) / (2.0 * std::sqrt(T));
    double term2 = r * K * std::exp(-r * T) * norm_cdf(-d2);
    return term1 + term2;
}

double call_rho(double K, double T, double r, double d2) {
    return K * T * std::exp(-r * T) * norm_cdf(d2);
}

double put_rho(double K, double T, double r, double d2) {
    return -K * T * std::exp(-r * T) * norm_cdf(-d2);
}
