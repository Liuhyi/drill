// Custom assert implementation
#ifdef NDEBUG
    #define assert(expression) ((void)0)  // Does nothing when NDEBUG is defined
#else
    #include <iostream>
    #include <cstdlib>
    #define assert(expression) \
        if (!(expression)) { \
            std::cerr << "Assertion failed: " << #expression << " in " << __FILE__ << " at line " << __LINE__ << std::endl; \
            std::exit(EXIT_FAILURE); \
        }
#endif

// Test the custom assert implementation
int main() {
    int a = 5;
    int b = 10;

    assert(a == b);  // Will trigger the assertion failure code if NDEBUG is not defined

    return 0;
}
