typedef struct
{
    int x;
    int y;
    int z;
}init, desiginit;

int main(int argc, char const *argv[])
{
	init i = {1, 2, 3}; // initialization
	desiginit di = 
	{
		.y = 2, 
		.x = 1, 
		.z = 3
	}; // designated initialization
	return 0;
}
