#pragma once
#include <vector>

#include "observer.h"
#include "publisher.h"

class user : public observer {
 private:
  std::string name;

 public:
  user(std::string name);
  void receive_notification(notification receive_notification) override;

  void subscribe(std::vector<publisher*> publishers);
};
