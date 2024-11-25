#include <stdio.h>

struct Item {
    int weight;
    int value;
    double ratio;
};


int partition(struct Item items[], int low, int high) {
    double pivot = items[high].ratio;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (items[j].ratio >= pivot) {
            i++;

            struct Item temp = items[i];
            items[i] = items[j];
            items[j] = temp;
        }
    }


    struct Item temp = items[i + 1];
    items[i + 1] = items[high];
    items[high] = temp;

    return i + 1;
}


void quickSort(struct Item items[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(items, low, high);
        quickSort(items, low, pivotIndex - 1);
        quickSort(items, pivotIndex + 1, high);
    }
}


double fractionalKnapsack(struct Item items[], int n, int capacity) {
    quickSort(items, 0, n - 1);

    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].ratio * capacity;
            break;
        }
    }
    return totalValue;
}

int main() {

    struct Item items[] = {
        {10, 60, 0},
        {20, 100, 0},
        {30, 120, 0}
    };

    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    printf("Knapsack Capacity: %d\n", capacity);

    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: %d, Value: %d, Ratio: %.2f\n",
               i + 1, items[i].weight, items[i].value, items[i].ratio);
    }

    double maxValue = fractionalKnapsack(items, n, capacity);
    printf("\nMaximum value in the knapsack: %.2f\n", maxValue);

    return 0;
}
