// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    // Полный перебор всех пар (медленный, O(n^2))
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        for (int j = i + 1; j < len; ++j) {
            if (j > i + 1 && arr[j] == arr[j - 1]) {
                continue;
            }
            if (arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    // Метод двух указателей (средняя скорость, O(n))
    int count = 0;
    int i = 0;
    int j = len - 1;

    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum == value) {
            ++count;
            int left = arr[i];
            int right = arr[j];
            while (i < j && arr[i] == left) {
                ++i;
            }
            while (i < j && arr[j] == right) {
                --j;
            }
        } else if (sum < value) {
            ++i;
        } else {
            --j;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    // Бинарный поиск для второй половины (самый быстрый, O(n log n))
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        int target = value - arr[i];
        int l = i + 1;
        int r = len - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (arr[m] == target) {
                ++count;
                break;
            } else if (arr[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
    }
    return count;
}
