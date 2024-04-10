struct stat;

// system calls
int fork(void);
int exit(int) __attribute__((noreturn));
int wait(int*);
int pipe(int*);
int write(int, const void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(const char*, char**);
int open(const char*, int);
int mknod(const char*, short, short);
int unlink(const char*);
int fstat(int fd, struct stat*);
int link(const char*, const char*);
int mkdir(const char*);
int chdir(const char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);

// ulib.c
int stat(const char*, struct stat*);
char* strcpy(char*, const char*);
void *memmove(void*, const void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void fprintf(int, const char*, ...);
void printf(const char*, ...);
char* gets(char*, int max);
int fgets(int fd, char*, int max);
int getline(char **lineptr, uint *n, int fd);
uint strlen(const char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);
int memcmp(const void *, const void *, uint);
void *memcpy(void *, const void *, uint);

// array operations
void print_array(int* arr, int size);
void sort_int_array(int* arr, int size);
void delete_at_index(int** arr, int index, int *size);
void add_at_index(int** arr, int value, int index, int *size);
int binary_search(int* arr, int target, int size);
int* array_union(int* arr1, int* arr2, int size1, int size2, int *new_size);
int* array_intersection(int* arr1, int* arr2, int size1, int size2, int *new_size);
