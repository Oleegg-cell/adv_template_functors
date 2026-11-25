#include <iostream>
#include <vector>

// Шаблонная функция для скалярных значений
template <typename T>
T square(T value) {
    return value * value;
}

// Шаблонная перегрузка для std::vector<T>
template <typename T>
std::vector<T> square(const std::vector<T>& vec) {
    std::vector<T> result;
    result.reserve(vec.size());
    for (const auto& elem : vec) {
        result.push_back(square(elem));  // используем первую версию для элемента
    }
    return result;
}

// Вспомогательная функция для вывода вектора
template <typename T>
void print_vector(const std::vector<T>& vec) {
    bool first = true;
    for (const auto& v : vec) {
        if (!first) std::cout << ", ";
        std::cout << v;
        first = false;
    }
}

int main() {
    // Пример 1: скаляр
    int x = 4;
    std::cout << "[IN]: " << x << "\n";
    std::cout << "[OUT]: " << square(x) << "\n\n";

    // Пример 2: вектор
    std::vector<int> v = { -1, 4, 8 };
    std::cout << "[IN]: ";
    print_vector(v);
    std::cout << "\n[OUT]: ";
    auto squared_v = square(v);
    print_vector(squared_v);
    std::cout << "\n";

    return 0;
}