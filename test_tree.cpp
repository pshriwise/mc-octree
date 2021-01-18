
#include <array>

#include "octree.h"

struct Object{

    std::array<double, 6> BoundingBox() const { return {-10, -10, -10, 10, 10, 10}; }

};

int main() {

std::vector<Object> objects(10);

mcoct::Octree<Object> tree(objects);

return 0;
}