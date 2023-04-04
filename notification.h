#pragma once
#include <string>

struct notification {
  std::string publisher_name;
  int message_id;
  std::string subject;
  std::string message;
};
