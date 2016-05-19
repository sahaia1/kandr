#include <stdio.h>

#define C 1
#define F 0

float
temp_conv(float temp, int type) {
	if (type == C)
		return (9.0)/(5.0) * temp + 32;
	else
		return (5.0)/(9.0) * (temp - 32);
}

void
temp_conv_ref(float *temp, int type) {
	if (type == C)
		*temp = (9.0)/(5.0) * *temp + 32;
	else
		*temp = (5.0)/(9.0) * (*temp - 32);
}

int
main() {
	float temp = 44.5;
	printf("temp in C for F = 44 -> %.2f\n", temp_conv(44, F));
	printf("temp in F for C = 45 -> %.2f\n", temp_conv(45, C));
	temp_conv_ref(&temp, F);
	printf("%.2f\n", temp);
	temp_conv_ref(&temp, C);
	printf("%.2f\n", temp);

	return 0;
}