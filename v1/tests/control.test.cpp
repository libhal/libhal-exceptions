#include <array>
#include <memory_resource>

#include <libhal-exceptions/control.hpp>

#include <boost/ut.hpp>

namespace hal {
boost::ut::suite<"control_test_suite"> control_test_suite = []() {
  using namespace boost::ut;
  "hal::set_exception_allocator()"_test = []() {
    // setup
    std::array<std::byte, 1024> buffer;
    std::pmr::monotonic_buffer_resource resource(buffer.data(), buffer.size());

    // exercise
    hal::set_exception_allocator(resource);

    // verify
    expect(that % &resource == &hal::get_exception_allocator());
  };
};
}  // namespace hal
