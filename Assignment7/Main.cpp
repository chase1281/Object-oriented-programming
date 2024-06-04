#include "EventScheduler.h"

void process_command(EventScheduler scheduler) {
	string command, event_type, date_string, content, keyword, newfilename;
	Date start_date, end_date;
	while (1) {
		cout << "$";
		cin >> command;
		if (command == "add") { 
			cin >> event_type; 
			cin >> date_string;
			getline(cin, content);
			scheduler.add_event(event_type, date_string, content);
		}
		else if (command == "find") {
			cin >> date_string;
			int hyphen_pos = date_string.find('-');
			if (hyphen_pos != string::npos) {
				start_date = Date(date_string.substr(0, hyphen_pos));
				end_date = Date(date_string.substr(hyphen_pos + 1));
				scheduler.find_events_in_period(start_date, end_date);
			}
			else {
				cout << "Invalid date range format" << endl;
			}
		}
		else if (command == "search") {
			getline(cin, keyword);
			scheduler.search_events(keyword);
		}
		else if (command == "list") {
			scheduler.show_all_events();
		}
		else if (command == "delete") {
			int id;
			cin >> id;
			scheduler.delete_event(id);
		}
		else if (command == "exit") {
			break;
		}
		else if (command == "save") {
			cin >> newfilename;
			scheduler.save(newfilename);
		}
	}
}

int main() {
	EventScheduler scheduler;
	scheduler.load_data_file("events.txt");
	process_command(scheduler);

	return 0;
}