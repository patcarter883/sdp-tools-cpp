#include <string>

#include "sdp-tools-cpp/sdp-tools-cpp.hpp"

auto main() -> int
{
  auto const exported = exported_class {};

  return std::string("sdp-tools-cpp") == exported.name() ? 0 : 1;
}
