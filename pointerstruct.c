typedef struct
{
    int x;
    int y;
}abc;

int main(int argc, char const *argv[])
{
    abc a = {0, 1};
    abc *ptr = &a;
    (*ptr).x += 5; // (*&a).x // *,& cancelled out each other. hence, a.x
    ptr->y -= 1; // equivalent to (*ptr).y
    return (*ptr).y;
}
