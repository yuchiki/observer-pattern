#pragma once
#include "observer.h"

class publisher {
 public:
  virtual void add_observer(observer* observer) = 0;
};
