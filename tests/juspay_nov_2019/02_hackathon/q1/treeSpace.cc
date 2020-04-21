#include<iostream>
#include<unordered_map>
#include<vector>
#include<cstring>

using namespace std;

class TreeOfSpace {

private:
  int id;
  unordered_map<string, int> nameID;
  unordered_map<int, vector<int> > tree;
  unordered_map<int, int> locks;
  unordered_map<int, int> parentLocks;
  vector<int> parents;

public:
  TreeOfSpace(vector<vector<string> > connections) {
    string parent, child;
    int parentID, childID;

    id = 0;

    for(auto connection: connections) {
      parent = connection[0];
      child = connection[1];

      // find ID for parent node
      if(nameID.find(parent) == nameID.end()) {
        parentID = id;
        nameID[parent] = parentID;
        parents.push_back(parentID);
        id++;
      } else {
        parentID = nameID[parent];
      }

      // find ID for child node
      if(nameID.find(child) == nameID.end()) {
        childID = id;
        nameID[child] = childID;
        parents.push_back(childID);
        id++;
      } else {
        childID = nameID[child];
      }

      // join parent and child
      parents[childID] = parentID;

      // "tree" won't be used for this problem
      // just storing it for reference if needed
      tree[parentID].push_back(childID);
    }
  }

  // LOCK mechanism
  bool lock(string name) {
    int index;

    // check if given name is present
    // O(1)
    if(nameID.find(name) == nameID.end()) {
      cout<<name<<" not found.\n";
      return false;
    }

    index = nameID[name];

    // check if name is locked before
    // O(1)
    if(locks[index]) {
      cout<<name<<" locked before.\n";
      return false;
    }

    // check if name is present in ancestors of all acquired locks
    // O(1)
    if(parentLocks[index]) {
      cout<<name<<" present in ancestors.\n";
      return false;
    }

    // check if name is present in descendants of any locked node
    // check parents of given name and see if they are locked
    // O(log M)
    while(index != 0) {
      index = parents[index];
      if(locks[index]) {
        cout<<name<<" present in descendants.\n";
        return false;
      }
    }

    // YES .. name can be locked
    // set it in "locks"
    // set it's parents in "parentLocks"
    // O(1)+O(log M)
    index = nameID[name];
    locks[index]++;
    while(index != 0) {
      index = parents[index];
      parentLocks[index]++;
    }

    cout<<name<<" has been locked.\n";

    // Debugging
    // printLocks();
    // printParentLocks();

    return true;
  }

  void printLocks() {
    cout<<"LOCKS\n";
    for(auto entry: locks) {
      cout<<entry.first<<"  "<<entry.second<<endl;
    }
  }

  void printParentLocks() {
    cout<<"PARENT LOCKS\n";
    for(auto entry: parentLocks) {
      cout<<entry.first<<"  "<<entry.second<<endl;
    }
  }

  // UNLOCK mechanism
  bool unlock(string name) {
    int index;

    // check if given name is present
    // O(1)
    if(nameID.find(name) == nameID.end()) {
      cout<<name<<" not found.\n";
      return false;
    }

    index = nameID[name];

    // check if name is locked before
    if(locks[index] == 0) {
      cout<<name<<" not locked before.\n";
      return false;
    }

    // unset name in "locks"
    // O(1)
    locks.erase(index);

    // unset parents of name in "parentLocks"
    // O(log M)
    while(index != 0) {
      index = parents[index];
      parentLocks[index]--;
      if(parentLocks[index] == 0) {
        parentLocks.erase(index);
      }
    }

    cout<<name<<" has been unlocked.\n";

    return true;
  }

};

int main(void ) {
  string result, name;
  int choice;
  // list of {parent, child} connections
  vector<vector<string> > connections = {
    {"World", "Asia"},
    {"World", "Africa"},
    {"Asia", "India"},
    {"Asia", "China"},
    {"India", "Karnataka"},
    {"India", "Bihar"},
    {"Karnataka", "Bangalore"},
    {"Bangalore", "Juspay"},
    {"Africa", "Kenya"},
    {"Africa", "South Africa"}
  };

  // instantiating class and passing data
  TreeOfSpace tos(connections);

  cout<<"0 to QUIT\n";
  cout<<"1 to LOCK\n";
  cout<<"2 to UNLOCK\n\n\n";

  while(true) {
    cin>>choice;

    // QUIT
    if(choice == 0) {
      break;
    }

    if(choice<0 || choice>2) {
      cout<<"Incorrect choice.\n\n";
      continue;
    }

    cout<<"Enter name : ";
    cin>>name;
    cin.ignore();

    // LOCK
    if(choice==1) {
      result = tos.lock(name) ? "Success!" : "Error!";
      cout<<result<<"\n\n";
    }

    // UNLOCK
    if(choice==2) {
      result = tos.unlock(name) ? "Success!" : "Error!";
      cout<<result<<"\n\n";
    }
  }

  return 0;
}