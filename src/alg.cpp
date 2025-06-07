// Copyright 2021 NNTU-CS
#include <chrono>
#include <thread>
#include <unordered_set>
#include <algorithm>

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    std::sort(arr, arr + len);
    for (int i = 0; i < len - 1; ++i) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        for (int j = i + 1; j < len; ++j) {
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;
            if (arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    std::sort(arr, arr + len);
    int i = 0, j = len - 1;
    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum == value) {
            ++count;
            int left = arr[i], right = arr[j];
            while (i < j && arr[i] == left) ++i;
            while (i < j && arr[j] == right) --j;
        } else if (sum < value) {
            ++i;
        } else {
            --j;
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    std::sort(arr, arr + len);
    for (int i = 0; i < len - 1; ++i) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        int target = value - arr[i];
        int l = i + 1, r = len - 1;
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
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    return count;
}
