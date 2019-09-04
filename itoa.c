int strlen(const char* s)
{
	int count = 0;

	while (*s++ != '\0')
		count++;

	return count;
}

void reverse(char* s)
{
	int temp, i, j;
	int length = strlen(s);

	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

void itoa(int n, char* s)
{
	int i = 0, sign;

	if ((sign = n) < 0)
		n = -n;

	do
	{
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';
	s[i++] = '\0';
	reverse(s);
}
