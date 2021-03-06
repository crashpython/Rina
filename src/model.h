/**
 * @brief Model
 * @author Vic Chan
 * @date 2017-10-30
 * */


#ifndef RINA_MODEL_H
#define RINA_MODEL_H
#include <string>
#include <vector>


// 登录
#define LOGIN         "*2c411521vn148-e=1r"
// 登出
#define LOGOUT        "e21874vnwv1o2870810"
// 请求聊天记录
#define GET_ALL       "1321c32-23@(*^&*#Bv"
// 登录成功
#define LOGIN_SUCCESS "&*TBX*GR*&@BC&GF&*@"
// 发送成功
#define SEND_SUCESS   "&*^*@BUOWBDI(*@#&(^"
// 下线成功
#define OUT_SUCCESS   "^&*^&#%*&(G&FC&^WRG"

namespace Rina {

/**
 *
 *  Message: [{user$}]
 *
 *
 *
 *
 *
 * */



enum UserState {
  online = 0,
  offline = 1
};

enum MessageType {
  normal = 0,
  login,
  logout,
  getall,
  success
};

class Message {
 public:
  Message() =default;

  Message(std::string& _name, std::string& _content, std::string& ip, long time):
      username(_name),
      content(_content),
      ipAddress(ip),
      timestamp(time){};

  Message& operator=(const Message& );
  Message(const Message& );
  std::string getUsername()  { return username; }
  std::string getContent()  { return content; }
  std::string getAddress() { return ipAddress; }
  MessageType getType();
  long getTime()  { return timestamp; }
  std::string toString();

 private:
  std::string username;
  std::string content;
  std::string ipAddress;
  long timestamp;
};

class MultiMessage {
 public:
  MultiMessage()= default;
  std::vector<Message> messages;
  MultiMessage(std::vector<Message>& msgs):messages(msgs){};
  std::string toString();
};


int parseMessage(char* str, std::vector<Message>& message);


struct User {

  int sockfd;
  std::string name;
  UserState state = offline;
  long updateSeq = 0;
};

inline long getTime() {
  long timestamp = time(nullptr);
  return timestamp;
}


}

#endif //RINA_MODEL_H
