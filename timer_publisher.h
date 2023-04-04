#pragma once
#include <vector>

#include "observer.h"
#include "publisher.h"

class timer_publisher : public publisher {
 private:
  std::string name;
  int interval_seconds;
  std::vector<observer*> observers;

 public:
  timer_publisher(std::string name, int interval_seconds);
  void add_observer(observer* observer) override;

  /**
   * Start periodic notificaiton to observers.
   * This method runs eternally, so never returns.
   */
  void start_periodic_notification();
};
