// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        for (int j = i + 1; j < len; ++j) {
            if (j > i + 1 && arr[j] == arr[j - 1]) {
                continue;
            }
            int sum = arr[i] + arr[j];
            if (sum == value) {
                ++count;
                break;
            } else if (sum > value) {
                break;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int i = 0;
    int j = len - 1;

    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum == value) {
            ++count;

            // Пропускаем повторяющиеся значения
            int leftVal = arr[i];
            int rightVal = arr[j];
            while (i < j && arr[i] == leftVal) ++i;
            while (i < j && arr[j] == rightVal) --j;
        } else if (sum < value) {
            ++i;
        } else {
            --j;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        int target = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) {
                ++count;
                break;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return count;
}
