//
// Copyright (c) 2016 by Niclas Grande. All Rights Reserved.
//

#include "Bus/MessageBus.h"
#include "Memory/MemoryPool.h"
#include <iostream>
#include <string>

int main(void) {
  MessageBus msgBus;
  std::string desc = "Test message";
  std::cout << "Starting engine!" << std::endl;
  unsigned int test = TO_POW_OF_TWO<unsigned int, 2, 31>::RESULT;
  std::cout << test << std::endl;
  bool doExit = false;
  while (!doExit) {
    std::cout << "Input message code (1,2,3 or 1337 for exit) for message bus:"
              << std::endl;
    int input;
    Code code;
    std::cin >> input;
    switch (input) {
    case 1:
      code = PLAY_SOUND;
      break;
    case 2:
      code = STOP_SOUND;
      break;
    case 3:
      code = FLUSH_BUFFER;
      break;
    case 1337:
      doExit = true;
      break;
    default:
      std::cout << "Error: 1,2 or 3 nothing else!!!" << std::endl;
      continue;
    }
    Message next_msg(desc, code);
    msgBus.sendMessage(next_msg);
  }

  std::cout << "Engine done!" << std::endl;
  return 0;
}
