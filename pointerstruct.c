typedef struct abc
{
    int x;
    int y;
}abc_t;

int main(int argc, char const *argv[])
{
    abc_t a = {0, 1};
    abc_t *ptr = &a;
    (*ptr).x += 5; // (*&a).x // *,& cancelled out each other. hence, a.x
    ptr->y -= 1; // equivalent to (*ptr).y
    return (*ptr).y;
}
