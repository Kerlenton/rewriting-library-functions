unsigned long int seed = 1;

unsigned int rand()
{
	int a = 16807;
	int m = 0x7fffffff;

	seed = seed * a % m;
	return seed;
}

void srand(unsigned int seedp)
{
	seed = seedp;
}
