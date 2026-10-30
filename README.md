# 🧮 Matrix Calculator

A high-performance, high-precision C++ linear algebra calculator capable of performing matrix operations and solving systems of linear equations. 

Unlike standard linear algebra tools that suffer from floating-point drift, this engine utilizes a **custom BigInt and Fraction pipeline** to guarantee **100% exact rational arithmetic without any precision loss**, making it immune to rounding errors during deep row reductions.

Currently available as an interactive C++ console application, with an active migration underway toward a highly modular, OOP-based matrix library for external project integration.

---

## 🛠️ Key Features

### 🎛️ Core Matrix Operations
*   **Basic Arithmetic:** Matrix Addition, Subtraction, and Multiplication.
*   **Transformations:** Transpose and Matrix Power (\(A^n\)).
*   **Advanced Algebra:** Determinant, Matrix Inverse, Rank, and Reduced Row Echelon Form (RREF).

### ⚡ Linear System Solvers
*   **Matrix Inverse Method:** Solves X = A⁻¹B for invertible systems.
*   **Cramer's Rule:** Determinant-based solving for exact coordinate tracking.
*   **Gauss-Jordan Elimination:** Robust row-reduction strategy for handling systems of any size.

---

## 🧠 Under the Hood: Zero-Loss Architecture

Standard floating-point types (`float`, `double`) inevitably introduce rounding errors during multi-step row transformations. This project eliminates that entire class of bugs using a custom-built numerical stack:

```text
[ Custom BigInt Class ]   ──> Enforces infinite-precision integer limits
│
[ Custom Fraction Class ] ──> Handles exact numerator/denominator arithmetic
│
[ Matrix Engine Core ]    ──> Runs RREF, Inverses, and Solvers with 0% drift
```

*   **Custom BigInt:** Manages arbitrarily large integer states to prevent integer overflow during multi-step cross-multiplications.
*   **Custom Fraction:** Wraps two `BigInt` objects into an exact rational number framework ($p/q$). Every division step in Gauss-Jordan maintains absolute mathematical fidelity.

---

## 📦 Getting Started

### Prerequisites
Ensure you have a modern C++ compiler supporting at least **C++17** (e.g., `g++` 9+ or `clang` 10+).

### Installation
```bash
# Clone the repository
git clone https://github.com

# Navigate into the project workspace
cd matrix-calculator
```

### Compilation & Execution
Compile all the core components and utility modules together using `g++`:

```bash
g++ -std=c++17 \
  BigInt.cpp \
  fraction.cpp \
  fraction_matrix_features.cpp \
  fraction_matrix_utilities.cpp \
  Matrix_utilities.cpp \
  basic_utilities.cpp \
  display.cpp \
  main.cpp \
  -o matrix_calc

# Run the console application
./matrix_calc
```
---

## 🚀 Future Roadmap

This project is actively evolving from a standalone CLI tool into a production-ready package.

- [x] Implement arbitrary-precision integer arithmetic (`BigInt`)
- [x] Build exact rational division pipelines (`Fraction`)
- [x] Complete standard matrix transformations & system solvers
- [ ] Refactor core engines into modular, object-oriented Matrix classes (`Matrix<T>`)
- [ ] Overload operators (`+`, `-`, `*`, `<<`) for native-feeling syntax
- [ ] Package the project as a header-only or compiled library (`.a` / `.so`) for external applications (and my future Linear Algebra Projects)

---

## 🤝 Contributing

Any contributions you make are **greatly appreciated**.

---

## 📄 License

Distributed under the MIT License. See `LICENSE` for more information.

