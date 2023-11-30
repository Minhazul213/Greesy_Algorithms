#include<stdio.h>
int main()
{
    float weight[30],profit[30],per_weight [30],TotalProfit=0,temp,capacity;
    int numberOfItem,i,j;
    printf("Enter the number of items :");
    scanf("%d",&numberOfItem);
    int n=numberOfItem;
    for (i = 0; i < n; i++)
    {
        printf("Enter Weight for item[%d] :\n",i);
        scanf("%f", &weight[i]);
        printf("Enter Profit for item[%d] :\n",i);

        scanf("%f", &profit[i]);
    }
    printf("Enter the capacity of knapsack :\n");
    scanf("%f",&capacity);

    for(i=0; i<n; i++)
        per_weight [i]=profit[i]/weight[i];

    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (per_weight [i] < per_weight [j])
            {
                temp = per_weight [j];
                per_weight [j] = per_weight [i];
                per_weight [i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }

    printf("Knapsack problems using Greedy Algorithm:\n");
    for (i = 0; i < n; i++)
    {
        if (weight[i] > capacity)
            break;
        else
        {
            TotalProfit = TotalProfit + profit[i];
            capacity = capacity - weight[i];
        }
    }
    if (i < n)
        TotalProfit = TotalProfit + (per_weight [i]*capacity);
    printf("\nThe maximum profit is :%.2f\n",TotalProfit);
    return 0;
}
