int isspace(char c)
{
	switch (c)
	{
	case ' ': case '\t': case '\n':
		return 1;

	default: 
		return 0;
	}
}

int isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	else
		return 0;
}

double atof(char* s)
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++);
	sign = (s[i] == '-') ? -1 : 1;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	return sign * val / power; 
}
