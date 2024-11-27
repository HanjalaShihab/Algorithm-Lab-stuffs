#include <stdio.h>

struct item {
    int it;
    int weight;
    int profit;
    double ratio;
};


int partition(struct item arr[], int low, int high) {
    double pivot = arr[high].ratio; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].ratio > pivot) { 
            i++;
            struct item temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    struct item temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Quick Sort function
void quickSort(struct item arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1);      
        quickSort(arr, pi + 1, high);       
    }
}

int main() {
    struct item item1[5] = {
        {1, 10, 120},
        {2, 12, 150},
        {3, 9, 200},
        {4, 12, 180},
        {5, 15, 190}
    };

    for (int i = 0; i < 5; i++) {
        item1[i].ratio = (double)item1[i].profit / item1[i].weight;
    }

  
    quickSort(item1, 0, 4);

    double maxProfit = 0.0;
    int currentWeight = 0;
    int maxWeight = 40;

    // Calculate maximum profit
    for (int i = 0; i < 5; i++) {
        if (currentWeight + item1[i].weight <= maxWeight) {
            currentWeight += item1[i].weight;
            maxProfit += item1[i].profit;
        } else {
            int remainingWeight = maxWeight - currentWeight;
            maxProfit += remainingWeight * item1[i].ratio;
            break;
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("%d %d %d %.2lf\n", item1[i].it, item1[i].weight, item1[i].profit, item1[i].ratio);
    }

    printf("Maximum Profit: %.2lf\n", maxProfit);

    return 0;
}
