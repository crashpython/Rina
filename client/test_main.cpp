/**
 * @brief Test Client Application
 * @author Vic Chan
 * @date 2017-10-30
 * */

#include "client.h"

#include <string.h>

int main(int argc, char* argv[]) {

  using namespace Rina;
  if (argc < 2) {

  }

  RinaClient client;
  client.init(atoi(argv[1]));
  std::string serverIP = "0.0.0.0";
  client.login(serverIP, 23333);

}