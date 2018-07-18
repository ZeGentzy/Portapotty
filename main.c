#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>

void ExampleFn(const char* data);
void ExampleFn2(const char* data);

int main()
{
#ifdef DLSYM_LIBEXAMPLEFN
    void* handle;
    handle = dlopen("libexamplefn.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    dlerror();

    void (*ExampleFn)(const char*);
    *(void **) (&ExampleFn) = dlsym(handle, "ExampleFn");

    void (*ExampleFn2)(const char*);
    *(void **) (&ExampleFn2) = dlsym(handle, "ExampleFn2");
#endif

    char *error;
    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

    ExampleFn2("Hi2P");
    ExampleFn("Hi");
    ExampleFn2("Hi2");
    ExampleFn("Hi");
    ExampleFn("Hi");
    printf("SUCCESS, restarting down\n");

#ifdef DLSYM_LIBEXAMPLEFN
    dlclose(handle);
    handle = dlopen("libexamplefn.so", RTLD_LAZY);

    *(void **) (&ExampleFn) = dlsym(handle, "ExampleFn");
    *(void **) (&ExampleFn2) = dlsym(handle, "ExampleFn2");
#endif
    ExampleFn("Hi");

#ifdef DLSYM_LIBEXAMPLEFN
    dlclose(handle);
#endif
    printf("SUCCESS, shuting down\n");
    exit(EXIT_SUCCESS);
}
