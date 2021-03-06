
#include <cassert>
#include <array>
#include <memory>

#include "octree.h"

struct TestObject{

    TestObject(const std::array<double, 6>& bounds) : bounds_(bounds) {}

    TestObject() {
        bounds_ = {-10, -10, -10, 10, 10, 10};
    }


    std::array<double, 6> BoundingBox() const { return bounds_; }

    std::array<double, 6> bounds_;
};

int main() {


std::vector<TestObject> objects;
objects.push_back(TestObject({-5.0, -5.0, -5.0, 5.0, 5.0, 5.0}));

auto tree = std::make_unique<mcoct::Octree<TestObject>>(objects);

assert(tree->tree_box().contains({0.0, 0.0, 0.0}));
assert(!tree->tree_box().contains({6.0, 0.0, 0.0}));

return 0;

}