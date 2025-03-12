#include <iostream>

int start_index = -1;
int end_index = -1;

void max_subarray_indices(const int arr[], int n) {
    if (n == 0) {
        start_index = -1;
        end_index = -1;
        return;
    }

    int max_sum = arr[0];
    int current_sum = arr[0];
    start_index = 0;
    end_index = 0;
    int temp_start = 0;

    for (int i = 1; i < n; ++i) {
        if (arr[i] > current_sum + arr[i]) {
            current_sum = arr[i];
            temp_start = i;
        } else {
            current_sum += arr[i];
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
            start_index = temp_start;
            end_index = i;
        }
    }
}

int main() {
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(a) / sizeof(a[0]);

    max_subarray_indices(a, n);

    std::cout <<  start_index << " " << end_index << std::endl;

    return 0;
}