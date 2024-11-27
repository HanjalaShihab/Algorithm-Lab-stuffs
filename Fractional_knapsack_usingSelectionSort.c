#include <stdio.h>

struct item {
    int it;
    int weight;
    int profit;
    double ratio;
};

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

    for (int i = 0; i < 5 - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < 5; j++) {
            if (item1[j].ratio > item1[maxIdx].ratio) {
                maxIdx = j;
            }
        }

        if (maxIdx != i) {
            struct item temp = item1[i];
            item1[i] = item1[maxIdx];
            item1[maxIdx] = temp;
        }
    }

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
