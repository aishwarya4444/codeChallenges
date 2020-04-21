#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstring>
#include<memory>

using namespace std;

// ----------------
// maintaining list of messages
// ----------------
class MessageCache {
  private:
    size_t messageId;
    unordered_map<size_t, shared_ptr<string>> messages;
  public:
    MessageCache() {
      messageId = 0;
      cout<<"Message Cache is up and running!"<<endl;
    }

    size_t addMessage(string& message) {
      messages[messageId] = make_shared(message);
      messageId++;
      return messageId-1;
    }

    void printMessage(int& messageId) {
      cout<<messages[messageId]<<endl;
    }

    ~MessageCache() {
      cout<<"Message Cache is down!"<<endl;
    }
};

// ----------------
// group info and operations
// ----------------
class Group {
  private:
    string groupName;
    vector<size_t> messages;
  public:
    Group() {
      // no-op
    }

    Group(string name) {
      groupName = name;
    }

    string getName() {
      return groupName;
    }

    void addMessage(size_t& messageId) {
      messages.push_back(messageId);
      cout<<"Message sent!"<<endl;
    }

    void printGroupName() {
      cout<<groupName<<endl;
    }

    void printMessagesForGroup(MessageCache &mc) {
      for(auto messageId: messages) {
        mc.printMessage(messageId);
      }
    }
};

// ----------------
// user info and operations
// ----------------
class User {
  private:
    string userName;
    vector<size_t> messages;
    vector<Group> groups;
  public:
    User() {
      // no op
    }

    User(string name) {
      userName = name;
    }

    string getName() {
      return userName;
    }

    void printUserName() {
      cout<<userName<<endl;
    }

    void addMessage(size_t messageId) {
      messages.push_back(messageId);
      cout<<"Message sent!"<<endl;
    }

    void addGroup(Group group) {
      groups.push_back(group);
    }

    void printMessagesForUser(MessageCache &mc) {
      for(auto messageId: messages) {
        cout<<messageId<<endl;
        mc.printMessage(messageId);
      }
    }

    void printMessagesForGroups(MessageCache &mc) {
      for(auto group: groups) {
        cout<<"Messages for group :: "<<group.getName()<<endl;
        group.printMessagesForGroup(mc);
      }
    }
};

// ----------------
// chat application
// ----------------
class ChatApp {
  private:
    MessageCache mc;
    vector<User> users;
    vector<Group> groups;
  public:
    ChatApp() {
      // add some users
      users.push_back({"u1"});
      users.push_back({"u2"});
      users.push_back({"u3"});
      users.push_back({"u4"});
      users.push_back({"u5"});

      // add some groups
      groups.push_back({"g1"});
      groups.push_back({"g2"});
      groups.push_back({"g3"});
      groups.push_back({"g4"});
      groups.push_back({"g5"});

      // send some messages to existing users
      sendMessageToUser("u1", "message1 for u1");
      sendMessageToUser("u1", "message2 for u1");
      sendMessageToUser("u1", "message3 for u1");
      sendMessageToUser("u2", "message1 for u2");
      sendMessageToUser("u3", "message1 for u3");

      // send some messages to existing groups
      sendMessageToGroup("g1", "message1 for g1");
      sendMessageToGroup("g2", "message1 for g2");
      sendMessageToGroup("g2", "message2 for g2");
      sendMessageToGroup("g4", "message1 for g4");

      // add users to groups


      // initial data set
      cout<<"Setup done!"<<endl;
      cout<<"\n\n\n\n\n\n";
    }

    // Registration [1]
    void registerUser(string userName) {
      bool found = false;
      for(auto user: users) {
        if(user.getName() == userName) {
          found = true;
          break;
        }
      }
      if(found) {
        cout<<"User found!"<<endl;
      } else {
        users.push_back({userName});
        cout<<"User added!"<<endl;
      }
    }

    // for adding group
    void addGroup(string groupName) {
      bool found = false;
      for(auto group: groups) {
        if(group.getName() == groupName) {
          found = true;
          break;
        }
      }
      if(found) {
        cout<<"Group already exists!"<<endl;
      } else {
        groups.push_back({groupName});
        cout<<"Group added!"<<endl;
      }
    }

    // Registration [2]
    void registerUserToGroup(string userName, string groupName) {
      bool foundUser = false, foundGroup = false;
      Group targetGroup;
      User targetUser;
      for(auto group: groups) {
        if(group.getName() == groupName) {
          targetGroup = group;
          foundGroup = true;
          break;
        }
      }
      for(auto user: users) {
        if(user.getName() == userName) {
          targetUser = user;
          foundUser = true;
          break;
        }
      }
      if(!foundUser) {
        cout<<"User not found!"<<endl;
      } else if(!foundGroup) {
        cout<<"Group not found!"<<endl;
      } else {
        targetUser.addGroup(targetGroup);
        cout<<"User subscribed to group!"<<endl;
      }
    }

    // List users or groups [1]
    void printAllUsers() {
      for(auto user: users) {
        user.printUserName();
      }
    }

    // List users or groups [2]
    void printAllGroups() {
      for(auto group: groups) {
        group.printGroupName();
      }
    }

    // Send message to user or group [1]
    void sendMessageToUser(string destUser, string message) {
      auto messageId = mc.addMessage(message);
      for(auto user: users) {
        if(user.getName() == destUser) {
          user.addMessage(messageId);
          break;
        }
      }
    }

    // Send message to user or group [2]
    void sendMessageToGroup(string destGroup, string message) {
      auto messageId = mc.addMessage(message);
      for(auto group: groups) {
        group.addMessage(messageId);
      }
    }

    // Read messages sent to user or group [1]
    void printMessageForUser(string userName) {
      bool found = false;
      for(auto user: users) {
        if(user.getName() == userName) {
          found = true;
          user.printMessagesForUser(mc);
          break;
        }
      }
      if(!found) {
        cout<<"User not found!"<<endl;
      }
    }

    // Read messages sent to user or group [2]
    void printMessagesForGroups(string userName) {
      bool found = false;
      for(auto user: users) {
        if(user.getName() == userName) {
          found = true;
          user.printMessagesForGroups(mc);
          break;
        }
      }
      if(found) {
        cout<<"User not found!"<<endl;
      }
    }

    // options given to user
    void getOptions() {
      cout<<endl;
      cout<<"[0] register a user"<<endl;
      cout<<"[1] register to a group"<<endl;
      cout<<"[2] list of all users"<<endl;
      cout<<"[3] list all groups"<<endl;
      cout<<"[4] send message to user"<<endl;
      cout<<"[5] send message to group"<<endl;
      cout<<"[6] read message sent to user"<<endl;
      cout<<"[7] read message sent to groups"<<endl;
      cout<<endl;
    }

    // perform action
    void doAction(int choice, string srcUser) {
      string destUser, group, message;
      switch (choice) {
        case 0:
          registerUser(srcUser);
          break;
        case 1:
          cout<<"Enter group : ";
          getline(cin,group);
          registerUserToGroup(srcUser, group);
          break;
        case 2:
          printAllUsers();
          break;
        case 3:
          printAllGroups();
          break;
        case 4:
          cout<<"Enter user you want to send message to : ";
          getline(cin,destUser);
          cout<<"Enter message : ";
          getline(cin,message);
          sendMessageToUser(destUser, message);
          break;
        case 5:
          cout<<"Enter group you want to send message to : ";
          getline(cin,group);
          cout<<"Enter message : ";
          getline(cin,message);
          sendMessageToGroup(group, message);
          break;
        case 6:
          printMessageForUser(srcUser);
          break;
        case 7:
          printMessagesForGroups(srcUser);
          break;
        default:
          cout<<"Invalid choice!"<<endl;
          break;
      }
    }

};

// not multi threaded currently
int main() {
  ChatApp chat;
  string userName;
  int choice;

  chat.getOptions();
  while(1) {
    cout<<"Enter your choice : ";
    cin>>choice;
    cin.ignore();

    // new user login
    if(choice == 0) {
      cout<<"Enter username : ";
      getline(cin,userName);
    }
    chat.doAction(choice, userName);
  }
  return 0;
}
