#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstddef>
#include <string>

template <typename T>
class MatrixBase {
protected:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    MatrixBase() : data(), rows(0), cols(0) {}

    MatrixBase(size_t r, size_t c) : data(r, std::vector<T>(c, T())), rows(r), cols(c) {}

    MatrixBase(size_t r, size_t c, const T& value) : data(r, std::vector<T>(c, value)), rows(r), cols(c) {}

    explicit MatrixBase(const std::vector<std::vector<T>>& values)
        : data(values), rows(values.size()), cols(values.empty() ? 0 : values[0].size()) {
        for (const auto& row : values)
            if (row.size() != cols)
                throw std::invalid_argument("MatrixBase : lignes de tailles differentes");
    }

    virtual ~MatrixBase() = default;

    void addElement(size_t row, size_t col, const T& value) {
        checkBounds(row, col);
        data[row][col] = value;
    }

    const T& getElement(size_t row, size_t col) const {
        checkBounds(row, col);
        return data[row][col];
    }

    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    void Display(std::ostream& os = std::cout) const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                os << data[i][j];
                if (j + 1 < cols) os << '\t';
            }
            os << '\n';
        }
    }

private:
    void checkBounds(size_t row, size_t col) const {
        if (row >= rows || col >= cols)
            throw std::out_of_range("MatrixBase : indice hors limites");
    }
};

template <typename T>
class MatrixNumerical;

template <typename T>
MatrixNumerical<T> getCoFactor(const MatrixNumerical<T>& m, size_t p, size_t q);

template <typename T>
class MatrixNumerical : public MatrixBase<T> {
public:
    MatrixNumerical() : MatrixBase<T>() {}
    MatrixNumerical(size_t r, size_t c) : MatrixBase<T>(r, c) {}
    MatrixNumerical(size_t r, size_t c, const T& value) : MatrixBase<T>(r, c, value) {}
    explicit MatrixNumerical(const std::vector<std::vector<T>>& values) : MatrixBase<T>(values) {}

    T getDeterminant() const {
        const size_t n = this->rows;
        if (n != this->cols)
            throw std::logic_error("getDeterminant : la matrice doit etre carree");
        if (n == 0) return T(1);
        if (n == 1) return this->data[0][0];
        if (n == 2)
            return this->data[0][0] * this->data[1][1] - this->data[0][1] * this->data[1][0];

        T det = T();
        int sign = 1;
        for (size_t j = 0; j < n; ++j) {
            det += static_cast<T>(sign) * this->data[0][j] * getCoFactor(*this, 0, j).getDeterminant();
            sign = -sign;
        }
        return det;
    }

    MatrixNumerical operator+(const MatrixNumerical& o) const {
        checkSameSize(o, "operator+");
        MatrixNumerical res(this->rows, this->cols);
        for (size_t i = 0; i < this->rows; ++i)
            for (size_t j = 0; j < this->cols; ++j)
                res.data[i][j] = this->data[i][j] + o.data[i][j];
        return res;
    }

    MatrixNumerical operator-(const MatrixNumerical& o) const {
        checkSameSize(o, "operator-");
        MatrixNumerical res(this->rows, this->cols);
        for (size_t i = 0; i < this->rows; ++i)
            for (size_t j = 0; j < this->cols; ++j)
                res.data[i][j] = this->data[i][j] - o.data[i][j];
        return res;
    }

    MatrixNumerical operator*(const MatrixNumerical& o) const {
        if (this->cols != o.rows)
            throw std::invalid_argument("operator* : dimensions incompatibles");
        MatrixNumerical res(this->rows, o.cols);
        for (size_t i = 0; i < this->rows; ++i)
            for (size_t j = 0; j < o.cols; ++j) {
                T sum = T();
                for (size_t k = 0; k < this->cols; ++k)
                    sum += this->data[i][k] * o.data[k][j];
                res.data[i][j] = sum;
            }
        return res;
    }

    MatrixNumerical operator*(const T& s) const {
        MatrixNumerical res(this->rows, this->cols);
        for (size_t i = 0; i < this->rows; ++i)
            for (size_t j = 0; j < this->cols; ++j)
                res.data[i][j] = this->data[i][j] * s;
        return res;
    }

    MatrixNumerical getInverse() const {
        const size_t n = this->rows;
        if (n != this->cols)
            throw std::logic_error("getInverse : la matrice doit etre carree");
        const T det = getDeterminant();
        if (det == T())
            throw std::runtime_error("getInverse : matrice singuliere (determinant nul)");

        MatrixNumerical inv(n, n);
        if (n == 1) {
            inv.data[0][0] = T(1) / this->data[0][0];
            return inv;
        }
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                const T sign = ((i + j) % 2 == 0) ? T(1) : T(-1);
                const T cofactor = sign * getCoFactor(*this, i, j).getDeterminant();
                inv.data[j][i] = cofactor / det;
            }
        }
        return inv;
    }

    MatrixNumerical operator/(const MatrixNumerical& o) const {
        return (*this) * o.getInverse();
    }

    static MatrixNumerical getIdentity(int n) {
        if (n < 0) throw std::invalid_argument("getIdentity : taille negative");
        MatrixNumerical id(static_cast<size_t>(n), static_cast<size_t>(n));
        for (int i = 0; i < n; ++i) id.data[i][i] = T(1);
        return id;
    }

private:
    void checkSameSize(const MatrixNumerical& o, const char* op) const {
        if (this->rows != o.rows || this->cols != o.cols)
            throw std::invalid_argument(std::string(op) + " : dimensions differentes");
    }
};

template <typename T>
MatrixNumerical<T> getCoFactor(const MatrixNumerical<T>& m, size_t p, size_t q) {
    const size_t n = m.getRows();
    if (n != m.getCols() || n == 0 || p >= n || q >= n)
        throw std::invalid_argument("getCoFactor : arguments invalides");
    MatrixNumerical<T> sub(n - 1, n - 1);
    size_t r = 0;
    for (size_t i = 0; i < n; ++i) {
        if (i == p) continue;
        size_t c = 0;
        for (size_t j = 0; j < n; ++j) {
            if (j == q) continue;
            sub.addElement(r, c, m.getElement(i, j));
            ++c;
        }
        ++r;
    }
    return sub;
}

#endif