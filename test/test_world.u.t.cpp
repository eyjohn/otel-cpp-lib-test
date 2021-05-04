#include <dlfcn.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
using namespace ::testing;

namespace {
struct DlCloseGuard {
    void* handle = nullptr;
    ~DlCloseGuard() { dlclose(handle); }
};
}

TEST(TestWorld, World)
{
    // open the library
    void* handle = dlopen("../src/libotel-cpp-lib-test_world.so", RTLD_LAZY);
    ASSERT_TRUE(handle) << "Cannot open library: " << dlerror();

    DlCloseGuard guard { handle };

    dlerror(); // reset errors

    // load the symbol
    typedef void (*world_t)();
    world_t world = (world_t)dlsym(handle, "world");
    const char* dlsym_error = dlerror();

    ASSERT_FALSE(dlsym_error) << "Cannot load symbol 'world': " << dlsym_error;

    world();

    // close the library
    dlclose(handle);
}
