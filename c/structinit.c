typedef struct init
{
    int x;
    int y;
    int z;
}init_t, desiginit_t;

int main(int argc, char const *argv[])
{
	init_t i = {1, 2, 3}; // initialization
	desiginit_t di = 
	{
		.y = 2, 
		.x = 1, 
		.z = 3
	}; // designated initialization
	return 0;
}
