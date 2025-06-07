// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;  // пропускаем дубликаты
        for (int j = i + 1; j < len; ++j) {
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;
            int sum = arr[i] + arr[j];
            if (sum == value) {
                ++count;
                break;  // только одна уникальная пара с arr[i]
            } else if (sum > value) {
                break;
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            ++count;

            int lval = arr[left];
            int rval = arr[right];

            while (left < right && arr[left] == lval) {
                ++left;
            }
            while (left < right && arr[right] == rval) {
                --right;
            }
        } else if (sum < value) {
            ++left;
        } else {
            --right;
        }
    }
    return count;
}

int binarySearch(int* arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len - 1; ++i) {
        // Пропуск дубликатов
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int target = value - arr[i];
        int j = binarySearch(arr, i + 1, len - 1, target);

        if (j != -1) {
            ++count;
        }
    }

    return count;
}
