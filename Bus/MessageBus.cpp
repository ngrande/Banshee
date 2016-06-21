//
// Copyright (c) 2016 by Niclas Grande. All Rights Reserved.
//

#include "MessageBus.h"
#include <algorithm>

MessageBus::MessageBus(void) {
  this->pStopped = false;
  this->pMsgThread = std::thread(&MessageBus::processMsgQueue, this);
  this->pMsgThread.detach();
}

void MessageBus::processMsgQueue() {
  while (!pStopped) {
    std::unique_lock<std::mutex> lck(cv_m);
    cv.wait(lck);

    while (!this->pMsgQueue.empty()) {
      auto queuedMsg = this->pMsgQueue.front();
      this->pMsgQueue.pop();
      // process queuedItem here
      auto msgCode = queuedMsg.getCode();

      switch (msgCode) {
      case Code::PLAY_SOUND:
        // handle play sound message
        std::cout << "PLAY_SOUND message received!" << std::endl;
        break;
      case Code::STOP_SOUND:
        std::cout << "STOP_SOUND message receieved!" << std::endl;
        break;
      case Code::FLUSH_BUFFER:
        std::cout << "FLUSH_BUFFER message received!" << std::endl;
        break;
      }
    }
  }
}

void MessageBus::sendMessage(Message &msg) {
  this->pMsgQueue.push(msg);
  this->cv.notify_all();
}
