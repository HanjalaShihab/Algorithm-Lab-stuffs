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
                // Swap items
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
        {10, 60, 0}, 
        {20, 100, 0}, 
        {30, 120, 0}  
    };

    int n = 3;
    int capacity = 50;

 
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    printf("Knapsack Capacity: %d\n", capacity);
    double maxValue = fractionalKnapsack(items, n, capacity);
    printf("Maximum value in the knapsack: %.2f\n", maxValue);

    return 0;
}
