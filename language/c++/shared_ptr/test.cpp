#include "object.hpp"
#include "sharedptr.hpp"

using namespace std;


int main(int argc, char** argv) {
    SharedPtr<Object> s1_ptr(new Object());
    SharedPtr<Object> s2_ptr = s1_ptr;
    return 0;
}

