#ifndef TODO_LIST_H
#define TODO_LIST_H
#include <iostream>
#include <string>
#include <fstream> 
#include <vector> 
#include "TodoListInterface.h"

using namespace std;
class TodoList: public TodoListInterface {
  public:    
	/*I created three vectors so that I could 
	store information regarding onlytasks, days, and also tasks that includes days*/
		vector <string> tasks;
		vector <string> days;
		vector <string> onlyTasks;

		TodoList() {
			cout << "In Constructor" << endl;
			ifstream infile ("TODOList.txt");
			string line; 
			if (infile.is_open())
			{
				while ( getline (infile,line) )
				{
					cout << line << '\n';
				  tasks.push_back(line);
					days.push_back(line.substr(0, line.find(' ')));
					onlyTasks.push_back(line.substr(line.find(' ') + 1));

				}
				infile.close();
			}

  }    
	
	/*Destructor prints the output on the 
	TODOList txt file*/
  virtual ~TodoList() {
    cout << "In Destructor" << endl;
		ofstream outfile;
		outfile.open ("TODOList.txt", ofstream::out | ofstream::trunc);
		for(int i = 0; i < tasks.size(); i++){
			outfile << tasks[i] << endl;
		}
		outfile.close();
  }    

  /* Function adds pushes back on the vector */
  virtual void add(string _duedate, string _task) {
    cout << "In add " << _duedate << " "<< _task << endl;
		tasks.push_back(_duedate + " " + _task);
		days.push_back(_duedate);
		onlyTasks.push_back(_task);

  }
  
   /*   Returns 1 if it removes an item, 0 otherwise    */    
  virtual int remove(string _task){
		int sizeOfVector = tasks.size();
		for(int i = tasks.size() - 1; i >= 0; i--){
				if (tasks[i].find(_task) != string::npos) {
					tasks.erase(tasks.begin() + i);
				}

			} 
		if (sizeOfVector != tasks.size()){
			return 1;
		}
		else{
			return 0;
		}	
		
  }

	/*Function prints the whole TodoList*/
  virtual void printTodoList(){
    cout << "In list" << endl;
		for ( int i=0; i < tasks.size(); i++)
			{
				cout << tasks[i] << endl;
			}
	}

	/*Function prints the specific tasks 
	associated with the day*/
  virtual void printDaysTasks(string _date) 
  {	 
	  cout << "In days tasks" << endl;
		for(int i = 0; i < days.size(); i++){	
			if (days[i].find(_date) != string::npos) {
				cout << onlyTasks[i] << endl;
			}
		}
			
	}
  
};

#endif