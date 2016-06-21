//
// Copyright (c) 2016 by Niclas Grande. All Rights Reserved.
//

// The Message Bus is used to send messages. Those messages will be
// send over to all "subscribed" modules - each module can then handle this
// message and react to it on its own. This uncouples every module from another.
// The Message Bus works as a central station for message sending.

#ifndef BUS_MESSAGEBUS_H_
#define BUS_MESSAGEBUS_H_
#include <condition_variable>
#include <iostream>
#include <queue>
#include <string>
#include <thread>

enum Code { PLAY_SOUND, FLUSH_BUFFER, STOP_SOUND };

class Message {
private:
  std::string pDescription;
  Code pMsgCode;

public:
  Message(std::string &description, Code &msgCode)
      : pDescription(description), pMsgCode(msgCode) {}

  std::string const getDescription() const { return this->pDescription; }

  int64_t const getCode() const { return this->pMsgCode; }
};

class MessageBus {
private:
  std::queue<Message> pMsgQueue;
  std::thread pMsgThread;
  std::mutex cv_m;
  std::condition_variable cv;

  bool pStopped;

  void processMsgQueue();

public:
  MessageBus();
  void sendMessage(Message &msg);
};
#endif
