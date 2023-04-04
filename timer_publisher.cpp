#include "timer_publisher.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <thread>

timer_publisher::timer_publisher(std::string name, int interval_seconds) {
  this->name = name;
  this->interval_seconds = interval_seconds;
}

void timer_publisher::add_observer(observer* new_observer) {
  observers.push_back(new_observer);
}

void timer_publisher::start_periodic_notification() {
  int message_id = 0;
  while (true) {
    for (observer* obs : observers) {
      std::time_t current_time;
      time(&current_time);

      notification time_notification{name, message_id, "current datetime",
                                     ctime(&current_time)};

      obs->receive_notification(time_notification);

      message_id++;
    }
    std::this_thread::sleep_for(std::chrono::seconds(interval_seconds));
  }
}
