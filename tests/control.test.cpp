#include <boost/ut.hpp>

namespace hal {
boost::ut::suite<"override_new_test_suite"> override_new_test_suite = []() {
  using namespace boost::ut;
  "operator new(...)"_test = []() {
    // TODO(#109): Add testing for operator new APIs
  };
  "operator delete(...)"_test = []() {
    // TODO(#109): Add testing for operator delete APIs
  };
};
}  // namespace hal
