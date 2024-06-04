#include "EventScheduler.h"
#include <sstream>

void EventScheduler::parse_period_string(const string& period_str, Date& s, Date& t) {
    size_t idx = period_str.find_first_of("-");
    Date d1(period_str.substr(0, idx));
    Date d2(period_str.substr(idx + 1));
    s = d1;
    t = d2;
}

void EventScheduler::add_event(const string& event_type, const string& date_string, const string& content) {
    try {
        if (event_type == "-O")
            add_oneday_event(date_string, content);
        else if (event_type == "-P")
            add_period_event(date_string, content);
        else if (event_type == "-D")
            add_deadline_event(date_string, content);
    }
    catch (const invalid_argument& ex) {
        cout << "Invalid Date String!! " << ex.what() << '\n';
    }
}

void EventScheduler::add_oneday_event(const string& date_string, const string& content) {
    Date d(date_string);
    OneDayEvent* e = new OneDayEvent(d, content);
    events.push_back(e);
}

void EventScheduler::add_period_event(const string& date_string, const string& content) {
    Date s, t;
    parse_period_string(date_string, s, t);
    PeriodEvent* e = new PeriodEvent(s, t, content);
    events.push_back(e);
}

void EventScheduler::add_deadline_event(const string& date_string, const string& content) {
    Date d(date_string);
    DeadlineEvent* e = new DeadlineEvent(d, content);
    events.push_back(e);
}

void EventScheduler::show_relevant_events(const Date& theDay) const {
    for (const auto& ev : events) {
        if (ev->relevant_to(theDay)) {
            ev->print(cout);
            cout << endl;
        }
    }
}

void EventScheduler::search_events(const string& keyword) const {
    for (const auto& ev : events) {
        if (ev->contains(keyword)) {
            ev->print(cout);
            cout << endl;
        }
    }
}

void EventScheduler::show_all_events() const {
    for (const auto& ev : events) {
        ev->print(cout);
        cout << endl;
    }
}

void EventScheduler::load_data_file(const string& file_name) {
    ifstream infile(file_name);
    if (!infile) {
        cerr << "Failed to open the file: " << file_name << endl;
        return;
    }

    string line, date_string, content;
    while (getline(infile, line)) {
        size_t idx = line.find_first_of(" ");
        if (idx == string::npos) continue;
        date_string = line.substr(0, idx);
        content = line.substr(idx + 1);
        if (date_string.find('-') != string::npos)
            add_period_event(date_string, content);
        else if (date_string.find('~') != string::npos)
            add_deadline_event(date_string.substr(1), content);
        else
            add_oneday_event(date_string, content);
    }
    infile.close();
}

void EventScheduler::delete_event(int id) {
    for (auto it = events.begin(); it != events.end(); ++it) {
        if ((*it)->get_id() == id) {
            delete* it;
            events.erase(it);
            return;
        }
    }
    cout << "No such events exist." << endl;
}

void EventScheduler::save(const string& file_name) const {
    ofstream outfile(file_name);
    if (!outfile) {
        cerr << "Failed to create the file: " << file_name << endl;
        return;
    }

    for (const auto& e : events) {
        e->print(outfile);
        outfile << endl;
    }
    outfile.close();
}

void EventScheduler::find_events_in_period(const Date& start_date, const Date& end_date) const {
    for (const auto& ev : events) {
        if (ev->relevant_to_period(start_date, end_date)) {
            ev->print(cout);
            cout << endl;
        }
    }
}
