struct gun{
    char name[40];
    char caliber[40];
    unsigned int range;
    char country[40];
};

void write(struct gun *arr, int n);
void read(struct gun **arr, int *n);
void create(struct gun **arr, int *n);
void search(struct gun *arr, int n);