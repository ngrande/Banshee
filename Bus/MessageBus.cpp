// "Copyright [2016] <Niclas Grande>"
#include "MessageBus.h"
#include <algorithm>

MessageBus::MessageBus(void) {
  this->pStopped = false;
  this->pMsgThread = thread(&MessageBus::processMsgQueue, this);
  this->pMsgThread.detach();
}

void MessageBus::processMsgQueue() {
  while (!pStopped) {
    unique_lock<mutex> lck(cv_m);
    cv.wait(lck);

    while (!this->pMsgQueue.empty()) {
      auto queuedMsg = this->pMsgQueue.front();
      this->pMsgQueue.pop();
      // process queuedItem here
      auto msgCode = queuedMsg.getCode();

      switch (msgCode) {
      case Code::PLAY_SOUND:
        // handle play sound message
        cout << "PLAY_SOUND message received!" << endl;
        break;
      case Code::STOP_SOUND:
        cout << "STOP_SOUND message receieved!" << endl;
        break;
      case Code::FLUSH_BUFFER:
        cout << "FLUSH_BUFFER message received!" << endl;
        break;
      }
    }
  }
}

void MessageBus::sendMessage(Message &msg) {
  this->pMsgQueue.push(msg);
  this->cv.notify_all();
}
