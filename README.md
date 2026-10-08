# Black-Scholes Options Pricer 📈

A lightweight, fast, and self-contained C++ terminal application for calculating European Call and Put option prices, as well as their associated Greeks (Delta, Gamma, Vega, Theta, and Rho) using the Black-Scholes-Merton model.

## Overview

This project serves as a foundational quantitative finance tool. It takes standard market inputs (Spot Price, Strike Price, Time to Maturity, Risk-Free Rate, and Volatility) and outputs the theoretical fair value of European options, alongside the risk sensitivities (Greeks) used by traders to hedge portfolios.

## Project Structure

* `black_scholes.h` - Header file containing mathematical constants and function declarations.

* `black_scholes.cpp` - Implementation of the standard normal distributions, core pricing logic, and Greek calculations.

* `main.cpp` - The execution driver handling terminal I/O and formatting the output.

## The Mathematics

The project implements the classical Black-Scholes formulas for non-dividend-paying stocks.

### Probability Factors

The model relies on the standard normal cumulative distribution function, $N(x)$, and the probability density function, $N'(x)$. The core probability factors $d_1$ and $d_2$ are calculated as:

$$
d_1 = \frac{\ln(S/K) + (r + \frac{\sigma^2}{2})T}{\sigma\sqrt{T}}
$$

$$
d_2 = d_1 - \sigma\sqrt{T}
$$

### Option Pricing

* **European Call Price (**$C$**):**
  

  $$
  C = S \cdot N(d_1) - K \cdot e^{-rT} \cdot N(d_2)
  $$

* **European Put Price (**$P$**):**
  

  $$
  P = K \cdot e^{-rT} \cdot N(-d_2) - S \cdot N(-d_1)
  $$

### The Greeks

Risk sensitivities are calculated to measure how the option price responds to changes in market variables:

* **Delta (**$\Delta$**):** Sensitivity to spot price. $\Delta_{Call} = N(d_1)$, $\Delta_{Put} = N(d_1) - 1$

* **Gamma (**$\Gamma$**):** Sensitivity of Delta to spot price. $\Gamma = \frac{N'(d_1)}{S \cdot \sigma \cdot \sqrt{T}}$

* **Vega (**$\nu$**):** Sensitivity to volatility. $\nu = S \cdot N'(d_1) \cdot \sqrt{T}$

* **Theta (**$\Theta$**):** Sensitivity to time decay. (Calculated in code and scaled to a daily decay rate).

* **Rho (**$\rho$**):** Sensitivity to the risk-free interest rate.

## Build Instructions

### Prerequisites

You need a C++ compiler supporting at least C++11.

* **Windows:** MSYS2 with MinGW-w64 (`g++`)

* **macOS:** Clang (via Xcode Command Line Tools)

* **Linux:** GCC (`g++`)

### Compilation

Open your terminal, navigate to the project directory, and run the following command to compile the source code:

```
g++ main.cpp black_scholes.cpp -o pricer

```

### Execution

Run the compiled executable:

**On Mac/Linux/MSYS2:**

```
./pricer

```

**On Windows Command Prompt:**

```
pricer.exe

```

## Example Usage

Upon running the executable, you will be prompted to enter the market variables:

```
--- Black-Scholes Pricer & Greeks ---
Spot Price (S): 100
Strike Price (K): 100
Time to Maturity in years (T): 1
Risk-free Rate (r) [e.g., 0.05]: 0.05
Volatility (sigma) [e.g., 0.20]: 0.20

```

The program will then output the calculated theoretical prices and the Greeks for both Call and Put options.
