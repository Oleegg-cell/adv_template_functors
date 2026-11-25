#include <iostream>
#include <vector>

template <typename T>
class table {
    std::vector<std::vector<T>> data;
    size_t rows, cols;

public:
    table(size_t rows, size_t cols)
        : data(rows, std::vector<T>(cols)), rows(rows), cols(cols) {
    }

    // Прокси-класс строки
    class Row {
        std::vector<T>& row;
    public:
        Row(std::vector<T>& r) : row(r) {}
        T& operator[](size_t col) { return row[col]; }
        const T& operator[](size_t col) const { return row[col]; }
    };

    // Неконстантная версия: table[i][j] = value
    Row operator[](size_t index) { return Row(data[index]); }

    // Константная версия: cout << table[i][j]
    const Row operator[](size_t index) const { return Row(const_cast<std::vector<T>&>(data[index])); }

    size_t Size() const { return rows * cols; }
};

int main() {
    table<int> test(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0] << "\n"; // 4

    const table<int>& cref = test;
    std::cout << cref[0][0] << "\n"; // 4 — константная версия работает
    std::cout << cref.Size() << "\n"; // 6
}