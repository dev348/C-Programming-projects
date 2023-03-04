#include <stdio.h>

int main() {
    int units;
    float tariff = 0.0;

    printf("Enter the number of units consumed: ");
    scanf("%d", &units);

    if (units <= 50) {
        tariff = units * 0.5;
    } else if (units <= 150) {
        tariff = 25 + ((units - 50) * 0.75);
    } else if (units <= 250) {
        tariff = 100 + ((units - 150) * 1.2);
    } else {
        tariff = 220 + ((units - 250) * 1.5);
    }

    printf("Total electricity bill for %d units: %.2f\n", units, tariff);

    return 0;
}
