#ifndef MESSAGE_BUS_H
#define MESSAGE_BUS_H
#include <condition_variable>
#include <iostream>
#include <queue>
#include <string>
#include <thread>

using namespace std;

enum Code { PLAY_SOUND, FLUSH_BUFFER, STOP_SOUND } MessageCode;

class Message {
private:
  string pDescription;
  Code pMsgCode;

public:
  Message(string &description, Code &msgCode)
      : pDescription(description), pMsgCode(msgCode){};

  string const getDescription() const { return this->pDescription; };

  long const getCode() const { return this->pMsgCode; };
};

class MessageBus {
private:
  queue<Message> pMsgQueue;
  thread pMsgThread;
  mutex cv_m;
  condition_variable cv;

  bool pStopped;

  void processMsgQueue();

public:
  MessageBus();
  void sendMessage(Message &msg);
};
#endif
