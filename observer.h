#pragma once
#include "notification.h"

class observer {
 public:
  virtual void receive_notification(notification received_notification) = 0;
};
