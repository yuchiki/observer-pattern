#include "user.h"

#include <iostream>

#include "observer.h"

user::user(std::string name) { this->name = name; }

void user::subscribe(std::vector<publisher*> publishers) {
  for (publisher* subscribing_publisher : publishers) {
    subscribing_publisher->add_observer(this);
  }
}

void user::receive_notification(notification received_notification) {
  std::cout << name << " received a message: " << std::endl;
  std::cout << "    from     : " << received_notification.message_id << ":"
            << received_notification.publisher_name << std::endl;
  std::cout << "    subject  : " << received_notification.subject << std::endl;
  std::cout << "    message  : " << received_notification.message << std::endl;
}
