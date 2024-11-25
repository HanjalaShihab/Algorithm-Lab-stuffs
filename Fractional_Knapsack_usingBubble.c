#include <stdio.h>

struct Item {
    int weight;
    int value;
    double ratio;
};

void selectionSort(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (items[j].ratio > items[maxIndex].ratio) {
                maxIndex = j;
            }
        }
        // Swap the items
        struct Item temp = items[i];
        items[i] = items[maxIndex];
        items[maxIndex] = temp;
    }
}

double fractionalKnapsack(struct Item items[], int n, int capacity) {
    selectionSort(items, n);

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

    int n = 4;
    int capacity = 50;

    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    printf("Knapsack Capacity: %d\n", capacity);
    for (int i = 0; i < n; i++) {
        printf("Weight: %d, Value: %d, Ratio: %.2f\n",
               i + 1, items[i].weight, items[i].value, items[i].ratio);
    }

    double maxValue = fractionalKnapsack(items, n, capacity);
    printf("\nMaximum value in the knapsack: %.2f\n", maxValue);

    return 0;
}
