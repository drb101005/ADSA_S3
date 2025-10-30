#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
    float ratio;
} Item;

int compare(const void *a, const void *b) {
    float r1 = ((Item*)a)->ratio;
    float r2 = ((Item*)b)->ratio;
    return (r2 > r1) - (r2 < r1);  // Descending order
}

float fractional_knapsack(int capacity, Item items[], int n) {
    // Calculate and sort by value/weight ratio
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }
    qsort(items, n, sizeof(Item), compare);
    
    float total_value = 0;
    
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            // Take whole item
            capacity -= items[i].weight;
            total_value += items[i].value;
        } else {
            // Take fraction of item
            total_value += items[i].value * ((float)capacity / items[i].weight);
            break;
        }
    }
    
    return total_value;
}

int main() {
    Item items[] = {
        {60, 10, 0},   // value, weight, ratio
        {100, 20, 0},
        {120, 30, 0}
    };
    int n = 3;
    int capacity = 50;
    
    float max_value = fractional_knapsack(capacity, items, n);
    printf("Maximum value: %.2f\n", max_value);  // Output: 240.00
    
    return 0;
}