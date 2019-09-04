int isspace(char c)
{
	switch (c)
	{
	case ' ': case '\n': case '\t':
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

int atoi(char* s)
{
	int i, sign, val;

	for (i = 0; isspace(s[i]); i++);
	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0; isdigit(s[i]); i++)
		val = 10 * val + (s[i] - '0');

	return sign * val;
}
