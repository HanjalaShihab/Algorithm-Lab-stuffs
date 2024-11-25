#include<stdio.h>
#include<string.h>
typedef struct item
{
    int it;
    int weight;
    int profit;
    double ratio;
}item;
int main()
{
     item item1[5] = {
         {1,10,120},
         {2,12,150},
         {3,9,200},
         {4,12,180},
         {5,15,190}};
         for(int i=0; i<5;i++)
         {
             item1[i].ratio = (double)item1[i].profit/item1[i].weight;
         }
    for(int i = 0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(item1[j].ratio<item1[j+1].ratio)
            {
                struct item temp = item1[j];
                item1[j] = item1[j+1];
                item1[j+1]=temp;
            }
        }
    }
    double maxProfit = 0;
    int currentWeight=0;
   int  maxWeight = 40;
    for(int i=0; i<5;i++)
    {
        if(currentWeight+item1[i].weight < maxWeight)
        {
            currentWeight += item1[i].weight;
            maxProfit += item1[i].profit;
        }
        else
        {
            int remainingWeight = maxWeight - currentWeight;
        maxProfit += remainingWeight * item1[i].ratio;
        break;
        }
    }
         for(int i=0; i<5;i++)
    {
        printf("%d %d %d %lf\n",item1[i].it,item1[i].weight,item1[i].profit,item1[i].ratio);
    }
    printf("Max profit: %lf ",maxProfit);


}
