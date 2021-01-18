
#include <limits>
#include <vector>

namespace mcoct {

#define INFTY std::numeric_limits<double>::infinity()

struct BoundingBox {

  BoundingBox() {
    min[0] = INFTY; min[1] = INFTY; min[2] = INFTY;
    max[0] = -INFTY; max[1] = -INFTY; max[2] = -INFTY;
  }

  void update(const BoundingBox& other) {
    // update llc
    min[0] = std::min(min[0], other.min[0]);
    min[1] = std::min(min[1], other.min[1]);
    min[2] = std::min(min[2], other.min[2]);

    // update urc
    max[0] = std::max(max[0], other.max[0]);
    max[1] = std::max(max[1], other.max[1]);
    max[2] = std::max(max[2], other.max[2]);
  }

  double min[3], max[3];
};

template <class T>
  class Octree{

  public:
  Octree(std::vector<T> objects) {

    for (const auto& object : objects) {
      auto bbox = object.BoundingBox();
    }

  };

  };

} // namespace mcoct
