#include <iostream>
#include <fstream>
#include <string> 
#include "TodoList.h"
using namespace std;

int main(int argc, char *argv[]) {
  TodoList myList;
  for(int i = 0; i < argc; i++){
    cout << "argv[" << i << "]=" << argv[i] << endl;
  }

  string firsttarg = argv[1];
  if(firsttarg.compare("add")==0){
    cout << "Doing an add" << endl;
    string date = argv[2];
    string task = argv[3];
    
    cout << "date " << date << " task " << task << endl;
    myList.add(date, task);
    
  }

	if(firsttarg.compare("printList") ==0){
		cout << "Printing lists..." << endl;
		myList.printTodoList();
	}
	
	if(firsttarg.compare("remove") ==0){
		cout << "Removing" << endl;
		string task = argv[2];
		
		myList.remove(task);

	}

	if(firsttarg.compare("printDay")==0){
		cout << "Doing printing" << endl;
		string date = argv[2];
		    
		myList.printDaysTasks(date);
		
  }


}