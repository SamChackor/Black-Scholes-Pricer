#ifndef BLACK_SCHOLES_H
#define BLACK_SCHOLES_H

const double PI = 3.14159265358979323846;

// Core Math
double norm_cdf(double x);
double norm_pdf(double x);
double calculate_d1(double S, double K, double T, double r, double sigma);
double calculate_d2(double d1, double T, double sigma);

// Option Pricing
double call_price(double S, double K, double T, double r, double d1, double d2);
double put_price(double S, double K, double T, double r, double d1, double d2);

// Greeks
double call_delta(double d1);
double put_delta(double d1);
double calculate_gamma(double S, double T, double sigma, double d1);
double calculate_vega(double S, double T, double d1);
double call_theta(double S, double K, double T, double r, double sigma, double d1, double d2);
double put_theta(double S, double K, double T, double r, double sigma, double d1, double d2);
double call_rho(double K, double T, double r, double d2);
double put_rho(double K, double T, double r, double d2);

#endif // BLACK_SCHOLES_H
