#include <iostream>
#include <vector>

using namespace std;



template<typename T1, typename T2> //T1 - итератор, Т2 - функция изменения
class newIterator {
public:
    newIterator(T1 iter_new, T2 func_new) { // конструктор
        iter = iter_new;
        func = func_new;
    }

    auto operator*() {
        return func(*iter);
    }

    newIterator& operator++() {
        ++iter;
        return *this;
    }

    bool operator!=(newIterator other) {
        return iter != other.iter;
    }

private:
    T1 iter;
    T2 func;
};





template<typename T1, typename T2> //T1 - контейнер, Т2 - функция
void MyIterator(T1& container, T2 func) {
    newIterator begin(container.begin(), func); //конструкторы начала и конца
    newIterator end(container.end(), func);


    auto B = begin;
    while(B != end) {
        std::cout << *B << " ";
        ++B;
    }
}



int multiplication(int x) {
    return x*10;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Пример использования итератора преобразования
    MyIterator(numbers, multiplication);


    return 0;
}