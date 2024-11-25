#include <stdio.h>

struct Item {
    int weight;
    int value;
    double ratio;
};


void bubbleSort(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {

                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}


double fractionalKnapsack(struct Item items[], int n, int capacity) {
    bubbleSort(items, n);

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
        {10, 60, 0}, // Item 1: weight = 10, value = 60
        {20, 100, 0}, // Item 2: weight = 20, value = 100
        {30, 120, 0}  // Item 3: weight = 30, value = 120
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
