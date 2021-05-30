
#include <limits>
#include <vector>

namespace mcoct {

#define INFTY std::numeric_limits<double>::infinity()

struct BoundingBox {

  BoundingBox() {
    min_[0] = INFTY; min_[1] = INFTY; min_[2] = INFTY;
    max_[0] = -INFTY; max_[1] = -INFTY; max_[2] = -INFTY;
  }

  BoundingBox(std::array<double, 6> bounds) {
    min_[0] = bounds[0];
    min_[1] = bounds[1];
    min_[2] = bounds[2];

    max_[0] = bounds[3];
    max_[1] = bounds[4];
    max_[2] = bounds[5];
  }

  BoundingBox(std::array<double, 3> min,
              std::array<double, 3> max) {

    min_[0] = min[0];
    min_[1] = min[1];
    min_[2] = min[2];

    max_[0] = max[0];
    max_[1] = max[1];
    max_[2] = max[2];

  }

  void update(const BoundingBox& other) {
    // update llc
    min_[0] = std::min(min_[0], other.min_[0]);
    min_[1] = std::min(min_[1], other.min_[1]);
    min_[2] = std::min(min_[2], other.min_[2]);

    // update urc
    max_[0] = std::max(max_[0], other.max_[0]);
    max_[1] = std::max(max_[1], other.max_[1]);
    max_[2] = std::max(max_[2], other.max_[2]);
  }

  bool contains(std::array<double, 3> pnt) {
    return
    min_[0] <= pnt[0] && max_[0] >= pnt[0] ||
    min_[1] <= pnt[1] && max_[1] >= pnt[1] ||
    min_[2] <= pnt[2] && max_[2] >= pnt[2];
  }

  bool contains(double pnt[3]) {
    return
    min_[0] <= pnt[0] && max_[0] >= pnt[0] ||
    min_[1] <= pnt[1] && max_[1] >= pnt[1] ||
    min_[2] <= pnt[2] && max_[2] >= pnt[2];
  }

  double min_[3], max_[3];
};

template <class T>
  class Octree{

  public:
  Octree(std::vector<T> objects) {

    for (const auto& object : objects) {
      auto bbox = object.BoundingBox();
      tree_box_.update(bbox);
    }

  };

  BoundingBox tree_box_;

  };

} // namespace mcoct
