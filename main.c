#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>

void ExampleFn(const char* data);

int main()
{
    void* handle;

    handle = dlopen("libexamplefn.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    dlerror();

    void (*ExampleFn)(const char*);
    *(void **) (&ExampleFn) = dlsym(handle, "ExampleFn");

    char *error;
    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

    ExampleFn("Hi");
    printf("SUCCESS, shuting down\n");

    dlclose(handle);
    exit(EXIT_SUCCESS);
}
