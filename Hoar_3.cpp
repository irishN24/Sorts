#include <iostream>
#include <vector>

void quickSort(std::vector<int>& A, int l, int r) {
    if (l >= r) {
        return;  // Если левая граница больше или равна правой, выходим
    }
    std::cout << "[" << l << "," << r << "]\n";
    int i = l, j = r;
    int x = A[(l + r) / 2];  // Опорный элемент
    std::cout << "x = " << x << "\n";

    // Разделение на две части
    while (i <= j) {
        while (A[i] < x) {
            std::cout << "i = " << i << "\n";
            i++;
        }
        while (A[j] > x) {
            std::cout << "j = " << j << "\n";
            j--;
        }
        if (i <= j) {
            std::swap(A[i], A[j]);
            std::cout << "i = " << i << "\n";
            i++;
            std::cout << "j = " << j << "\n";
            j--;
            for (int num : A) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    }

    // Рекурсивный вызов для левой и правой частей
    if (l < j) {
        quickSort(A, l, j);
    }
    if (i < r) {
        quickSort(A, i, r);
    }
}

int main() {
    std::vector<int> A = {4, 10, 6, 2, 7, 2, -1, 4, 11, 12, 0};

    quickSort(A, 0, A.size() - 1);

    for (int num : A) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}