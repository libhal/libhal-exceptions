#pragma once

#include <libhal/steady_clock.hpp>

struct resource_list
{
  hal::steady_clock* clock;
};

resource_list initialize_platform();
void application(resource_list& p_resource_list);
