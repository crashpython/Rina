/**
 * @brief Test Server Application
 * @author Vic Chan
 * @date 2017-10-25
 * */

#include "server.h"

int main(int argc, char* argv[]) {

  using namespace Rina;

  RinaServer server;
  server.init(atoi(argv[1]));
  server.start();


  return 0;
}