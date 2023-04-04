#include <future>
#include <vector>

#include "observer.h"
#include "publisher.h"
#include "timer_publisher.h"
#include "user.h"

int main() {
  timer_publisher bus_timer(" the bus has arrived!", 7);
  timer_publisher team_reminder("wake up, all the members!", 5);
  timer_publisher tv_notificator("your favorite TV show is starting...", 10);
  timer_publisher mail_notificator("new mail arrived", 3);

  user jimmy("very busy Jimmy");
  jimmy.subscribe(std::vector<publisher*>{&bus_timer, &team_reminder,
                                          &tv_notificator, &mail_notificator});

  user mike("busy Mike");
  mike.subscribe(std::vector<publisher*>{&mail_notificator, &bus_timer});

  user offenbach("not so busy Offenbach");
  offenbach.subscribe(std::vector<publisher*>{&tv_notificator});

  auto bus_timer_future = std::async(
      std::launch::async, [&]() { bus_timer.start_periodic_notification(); });
  auto team_reminder_future = std::async(std::launch::async, [&]() {
    team_reminder.start_periodic_notification();
  });
  auto tv_notificator_future = std::async(std::launch::async, [&]() {
    tv_notificator.start_periodic_notification();
  });
  auto mail_notificator_future = std::async(std::launch::async, [&]() {
    mail_notificator.start_periodic_notification();
  });

  bus_timer_future.wait();
  team_reminder_future.wait();
  tv_notificator_future.wait();
  mail_notificator_future.wait();
}
