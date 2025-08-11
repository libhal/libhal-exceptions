#pragma once

#include <cstdint>
namespace ke {
using console_writer = void(std::uint32_t p_pc, std::uint32_t p_guess_error);
void print_nearpoint_table_errors(console_writer p_writer);
}  // namespace ke

#include <libhal/functional.hpp>
#include <libhal/units.hpp>

/**
 * @brief A driver that implements a usb interface such as a keyboard, mouse,
 * microphone, virtual serial port, camera, or joystick.
 *
 */
class usb_interface
{
  /**
   * @brief A callback that accepts a span of bytes and writes it to a USB
   * endpoint buffer.
   *
   */
  using descriptor_stream = hal::callback<void(std::span<hal::u8>)>;

  /**
   * @brief Write descriptors to the descriptor stream
   *
   * An enumerator will pass a callback to this function in order to provide a
   * pathway from this driver to the host for its own descriptor. The
   * implementation should only emit its parts of its own descriptor. It is the
   * responsibility of this implementation to provide the correctly formatted
   * and complete descriptor to the stream before returning.
   *
   * @param p_stream - this callback accepts, as its input, a full descriptor of
   * parts of a descriptor in order.
   * @param p_string_index -
   * @return hal::u16 - the current string index after this function has
   * completed. The difference between the input p_string_index and the returned
   * value is the number of descriptor strings used by this function.
   */
  hal::u16 write_descriptors(descriptor_stream p_stream,
                             hal::u16 p_string_index);
};

struct usb_cdc : public usb_interface
{};

hal::u16 usb_cdc::write_descriptors(descriptor_stream p_stream,
                                    hal::u16 p_string_index)
{
  p_stream(interface_association_descriptor());
  p_stream(interface_descriptor_control());
  p_stream(cdc_header_functional_descriptor());
  // etc
}
