#include<iostream>
#include"Queue.h"
#include<cstdlib>
using namespace std;

Queue queue(10);
Queue sec_queue(10);

Task t1 = Task(8, "Writing Report", "Write Required Report ", "12/1/21", "12/4/21", "Hadil");
Task t2 = Task(10, "Meeting And Planning", "Meeting For Job Planning ", "3/1/21", "7/1/21", "Hadil");
Task t3 = Task(4, "Maintaning Equipment", "Straightin And Rebuild Duity Equipment", "12/1/21", "12/4/21", "Hadil");
Task t4 = Task(2, "Support hours", "complete the support phase", "12/1/21", "12/4/21", "Hadil");
Task t5 = Task(5, "Monthly Plan", "Submit the monthly work hours plan", "12/1/21", "12/4/21", "Hadil");
Task t6 = Task(1, "Writing Report", "Write Required Report ", "12/1/21", "12/4/21", "Hadil");
Task t7 = Task(3, "Meeting And Planning", "Meeting For Job Planning ", "3/1/21", "7/1/21", "Hadil");
Task t8 = Task(7, "Maintaning Equipment", "Straightin And Rebuild Duity Equipment", "12/1/21", "12/4/21", "Hadil");
Task t9 = Task(6, "Support hours", "complete the support phase", "12/1/21", "12/4/21", "Hadil");
Task t10 = Task(9, "Monthly Plan", "Submit the monthly work hours plan", "12/1/21", "12/4/21", "Hadil");

Task ts[] = { t1,t2,t3,t4,t5,t6,t7,t8,t9,t10 };

void Display() {
	sec_queue = queue;

	while (!sec_queue.IsEmpty()) {

		 cout << "Title : " <<  sec_queue.Front().get_title() << endl;
		 cout << "Description : " << sec_queue.Front().get_description() << endl;
		 cout << "Start Date : " << sec_queue.Front().get_sdate() << endl;
		 cout << "End Date : " << sec_queue.Front().get_edate() << endl;
		 cout << "Employee Name : " << sec_queue.Front().get_ename() << endl;
		 cout << "Priority Value : (" << sec_queue.Front().get_p_value() << ")" << endl;
		sec_queue.Dequeue();
		
		cout << "\t-----------------------------------------" << endl;
	}
}
void Reminder() {
	sec_queue = queue;
	cout << "\t------------* Reminder *--------------" << endl;
	cout << " Upcoming Task : " << endl;
	cout << " Task : " << sec_queue.Front().get_title() << " with priority value : " << sec_queue.Front().get_p_value() << endl;
	cout << " Deadline : " << sec_queue.Front().get_edate() << endl;
	cout << "\t-----------------------------------------" << endl;
}

void Menu()
{
	cout << "\t*** Welcome To Employees Task Manager ***" << endl;
	cout << "\t-----------------------------------------" << endl;
	
	bool exit_flag = false;

	for (int i = 0; i < 10; i++) {

		queue.Enqueue(ts[i]);

	}
	

	while(!exit_flag){
		
		cout << "\t\t\t~ Main Menu ~" << endl;
		cout << "\t-----------------------------------------" << endl;
		cout << " 1] Read Tasks." << endl;
		cout << " 2] Create a Priority List." << endl;
		cout << " 3] Sort the List (Descendingly)." << endl;
		cout << " 4] Display the Sorted List." << endl;
		cout << " 5] Update the List." << endl;
		cout << " 6] Exit. " << endl;
		int choice;

		cout << "\t-----------------------------------------" << endl;
		cout << " Enter Your Choice : ";
		cin >> choice;
		cout << "\t-----------------------------------------" << endl;

		switch (choice)
		{
		case 1: {
			//Read Tasks
			cout << "\t\t\t~ Tasks ~" << endl;
			cout << "\t-----------------------------------------" << endl;
			for (int i = 0; i < 10; i++) {
				ts[i].DisplayDetails();
			}
			break; 
		}
		case 2: {
			cout << " \t The List was created " << endl;
			break; 
		}
		case 3: {
			//Sort the list
			cout << "\t The List was sorted" << endl;
			break; }

		case 4: {
			//Display the sorted list
			if (queue.IsEmpty()) {

				cout << " you have finished all of your tasks !" << endl;
				cout << "\t-----------------------------------------" << endl;
				
			}
			else {
				Display();
				
			}
			break;
		}
		case 5: {
			//Call the update menu
			
			bool return_flag = false;

			while(!return_flag){

				cout << "\t\t\t ~ Update Menu ~" << endl;
				cout << "\t-----------------------------------------" << endl;
				cout << " 1] Remove finished Task." << endl;
				cout << " 2] Back to Main Menu." << endl;
				int choice;

				cout << "\t-----------------------------------------" << endl;
				cout << " Enter Your Choice : ";
				cin >> choice;
				cout << "\t-----------------------------------------" << endl;

				switch (choice) {
				case 1:
				{
					
					queue.Dequeue();
					if (queue.IsEmpty()) {

						cout << " Congratulations, you have finished all of your tasks !" << endl;
						cout << "\t-----------------------------------------" << endl;
						
					}
					else {
						cout << "The task of the highest priority was removed !" << endl;
						cout << "\t-----------------------------------------" << endl;
						Reminder();
					}
					break;
				}
				case 2:
				{
					return_flag = true;
					break;
				}
				default: 
					break; 
				}
			}
			break;
		}
		case 6: {
			exit_flag = true;
			break;
		}
		default: 
			break; 
		}

	}
	
}

int main()
{
	Menu();
	return 0;
}