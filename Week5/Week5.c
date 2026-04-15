#include <stdio.h>

float swap(float a, float b){
    int temp=a;
    a=b;
    b=temp;
    return a,b;
}

int main() {
    int n, i, j, capacity;
    float value[10], weight[10], ratio[10], temp;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter value and weight:\n");
    for(i = 0; i < n; i++) {
        scanf("%f %f", &value[i], &weight[i]);
        ratio[i] = value[i] / weight[i];
    }
    printf("Enter capacity: ");
    scanf("%d", &capacity);
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(ratio[i] < ratio[j]) {
                    swap(ratio[i],ratio[j]);
                    swap(value[i],value[j]);
                    swap(weight[i],weight[j]);
            }
        }
    }
    float total = 0;
    for(i = 0; i < n; i++) {
        if(capacity >= weight[i]) {
            total += value[i];
            capacity -= weight[i];
        } else {
            total += value[i] * (capacity / weight[i]);
            break;
        }
    }
    printf("Maximum value = %.2f", total);
    return 0;
}


