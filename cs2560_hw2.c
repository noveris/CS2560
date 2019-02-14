#include <stdio.h>

int main() {
	printf("Restaurant Bill\n");
	printf("----------------------------------------------------------------------------\n");
	float bill = 88.67;
	float tax_mult = 0.0675;
	float tip_mult = 0.20;

	float tax_amount = tax_mult * bill;
	float after_tax = bill + tax_amount;
	float tip_amount = tip_mult * after_tax;
	float total = tip_amount + after_tax;

	printf("Meal Cost:  %.2f\n", bill);
	printf("Tax amount: %.2f\n", tax_amount);
	printf("Tip amount: %.2f\n", tip_amount);
	printf("Total amount: %.2f\n", total);

	printf("\nOcean Levels\n");
	printf("----------------------------------------------------------------------------\n");
	float rise_rate = 1.5;
	printf("How much the ocean levels will rise in coming years:\n");
	printf("5 years:  %.1fmm\n", (rise_rate * 5));
	printf("7 years:  %.1fmm\n", (rise_rate * 7));
	printf("10 years: %.1fmm\n", (rise_rate * 10));

	printf("\nStock Trading Program\n");
	printf("----------------------------------------------------------------------------\n");
	int share_count = 1000;
	float share_price = 45.50;
	float commission_mult = 0.02;
	float sold_price = 56.90;

	float buy_amount = share_price * share_count;
	float sell_amount = sold_price * share_count;

	float buy_commission = buy_amount * commission_mult;
	float sell_commission = sell_amount * commission_mult;

	printf("Joe paid %.2f for his stock\n", buy_amount);
	printf("Joe paid %.2f in commission to buy the stock\n", buy_commission);
	printf("Joe sold the stock for %.2f\n", sell_amount);
	printf("Joe paid %.2f in commission to sell the stock\n", sell_commission);
	printf("Joe's profit after commission: %.2f\n", (sell_amount - (buy_amount + buy_commission + sell_commission)));




	printf("\nPattern Displays\n");
	printf("----------------------------------------------------------------------------\n");
	printf("Pattern A\n");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j <= i; j++) {
			printf("+");
		}
		printf("\n");
	}

	printf("\nPattern B\n");
	for (int i = 10; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			printf("+");
		}
		printf("\n");
	}

}
