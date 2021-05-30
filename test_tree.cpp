
#include <cassert>
#include <array>
#include <memory>

#include "octree.h"

struct Object{

    std::array<double, 6> BoundingBox() const { return {-10, -10, -10, 10, 10, 10}; }

};

int main() {

std::vector<Object> objects(10);

auto tree = std::make_unique<mcoct::Octree<Object>>(objects);

assert(tree->tree_box_.contains({0.0, 0.0, 0.0}));

return 0;

}