#include <stdio.h>
#include <ctype.h>
#include <math.h>

// double
// pow(num, exponent) {
// 	if (num == 0.0 || num == 1.0 || exponent == 1)
// 		return num;
// 	else if (exponent == 0)
// 		return 1.0;
// 	else 
// 		for (int i = 1; i < exponent; i++)
// 			num *= num;
// 		return num;
// }

double
atof(char s[]) {
	double val, power;
	int i, sign, power_sign, power_exponent;
	power_exponent = 0;
	for (i = 0; isspace(s[i]); i++);

	sign = (s[i] == '-')? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for(power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if (s[i] == 'e' || s[i] == 'E') {
		i++;
		power_sign = (s[i] == '-')? -1 : 1;
		if (s[i] == '-' || s[i] == '+')
			i++;
		for(power_exponent = 0.0; isdigit(s[i]); i++)
			power_exponent = 10.0 * power_exponent + (s[i] - '0');
	}
	// printf("%d\n", power_exponent);

	return sign * val / power * pow(10.0, power_exponent * power_sign);
}

int
main(int argc, char *argv[]) {
	printf("%f\n", atof(argv[1]));
	return 1;
}