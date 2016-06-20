// Copyright [2016] <Niclas Grande>

#include "Bus/MessageBus.cpp"
#include <iostream>
#include <string>

using namespace std;

int main(void) {
  MessageBus msgBus;
  string desc = "Test message";
  cout << "Starting engine!" << endl;

  while (true) {
    cout << "Input message code (1,2,3) for message bus:" << endl;
    long l_input;
    Code code;
    cin >> l_input;
    switch (l_input) {
    case 1:
      code = PLAY_SOUND;
      break;
    case 2:
      code = STOP_SOUND;
      break;
    case 3:
      code = FLUSH_BUFFER;
      break;
    default:
      cout << "Error: 1,2 or 3 nothing else!!!" << endl;
      continue;
    }
    Message next_msg(desc, code);
    msgBus.sendMessage(next_msg);
  }

  cout << "Engine done!" << endl;
  return 0;
}
