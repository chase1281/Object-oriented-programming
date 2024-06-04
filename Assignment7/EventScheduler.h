#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Event.h"

class EventScheduler {
private:
    vector<Event*> events;
    void parse_period_string(const string& period_str, Date& s, Date& t);
    void add_oneday_event(const string& date_string, const string& content);
    void add_period_event(const string& date_string, const string& content);
    void add_deadline_event(const string& date_string, const string& content);

public:
    void add_event(const string& type, const string& date_string, const string& content);
    void show_relevant_events(const Date& theDay) const;
    void search_events(const string& keyword) const;
    void show_all_events() const;
    void load_data_file(const string& file_name);
    void delete_event(int id);
    void save(const string& file_name) const;
    void find_events_in_period(const Date& start_date, const Date& end_date) const;
};

