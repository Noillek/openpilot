#include <sys/resource.h>
#include <limits.h>

#include <cstdio>
#include <cstdlib>

#include "cereal/messaging/messaging.h"
#include "common/swaglog.h"
#include "common/util.h"

ExitHandler do_exit;

void run_model() {
  SubMaster sm({"carState", "carControl"});

  while (!do_exit) {
    sm.update(100);
  }
}

int main(int argc, char **argv) {
  setpriority(PRIO_PROCESS, 0, -15);
  run_model();
  return 0;
}