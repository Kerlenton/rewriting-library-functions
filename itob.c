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

void itob(int n, char* s, int b)
{
	int i = 0, sign, c;

	if ((sign = n) < 0)
		n = -n;

	do
	{
		c = n % b;
		s[i++] = (c < 9) ? c + '0' : c + 'a' - 10;
	} while ((n /= b) > 0);

	if (sign < 0)
		s[i++] = '-';
	s[i++] = '\0';
	reverse(s);
}
