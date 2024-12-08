#include <iostream>
#include <vector>

void bitSort(std::vector<int>& A, int l, int r, int k) {
    if (l >= r || k < 0) {
        return;  // Если левая граница больше или равна правой или k < 0, выходим
    }

    int i = l, j = r;

    // Разделение на две части по k-ому разряду
    while (i <= j) {
        while (i <= j && !(A[i] & (1 << k))) {
            std::cout << "i = " << i << "\n";
            i++;
        }
        while (i <= j && (A[j] & (1 << k))) {
            std::cout << "j = " << j << "\n";
            j--;
        }
        if (i < j) {
            std::swap(A[i], A[j]);
            for (int num : A) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
            i++;
            std::cout << "i = " << i << "\n";
            j--;
            std::cout << "j = " << j << "\n";
        }
    }

    // Рекурсивный вызов для левой и правой частей
    bitSort(A, l, j, k - 1);
    bitSort(A, i, r, k - 1);
}

int main() {
    std::vector<int> A = {177, 47, 511, 144, 155, 116, 132, 139, 168, 11};
    int n = A.size();

    // Определяем номер старшего разряда
    int maxElement = *std::max_element(A.begin(), A.end());
    int k = 0;
    while (maxElement >>= 1) {
        k++;
    }

    bitSort(A, 0, n - 1, k);

    for (int num : A) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}