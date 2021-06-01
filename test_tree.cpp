
#include <cassert>
#include <array>
#include <memory>

#include "octree.h"

struct Object{

    Object(const std::array<double, 6>& bounds) : bounds_(bounds) {}

    Object() {
        bounds_ = {-10, -10, -10, 10, 10, 10};
    }


    std::array<double, 6> BoundingBox() const { return bounds_; }

    std::array<double, 6> bounds_;
};

int main() {

std::vector<Object> objects(10);



auto tree = std::make_unique<mcoct::Octree<Object>>(objects);

assert(tree->tree_box().contains({0.0, 0.0, 0.0}));

return 0;

}