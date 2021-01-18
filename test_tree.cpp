

#include "octree.h"

struct Object{};

int main() {

std::vector<Object> objects(10);

mcoct::Octree<Object> tree(objects);

return 0;
}