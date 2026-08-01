#pragma once

#include <stdint.h>
#include "types.h"


class FileManager{
  
  public:
  bool begin(const char* image_name);
  void list();
};
