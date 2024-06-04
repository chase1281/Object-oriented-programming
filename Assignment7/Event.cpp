#include "Event.h"

int Event::event_counter = 0;

Event::Event() : id(event_counter++) {}
Event::Event(string cont) : id(event_counter++), content(cont) {}
Event::~Event() {}

int Event::get_id() const {
    return id;
}

bool Event::contains(const string& keyword) const {
    return content.find(keyword) != string::npos;
}

void Event::print(ostream& out) const {
    out << id << ". " << content;
}

OneDayEvent::OneDayEvent() {}
OneDayEvent::OneDayEvent(const Date& d, const string& str) : date(d), Event(str) {}

bool OneDayEvent::relevant_to(const Date& theDay) const {
    return date == theDay;
}

bool OneDayEvent::relevant_to_period(const Date& start_date, const Date& end_date) const {
    return date >= start_date && date <= end_date;
}

void OneDayEvent::print(ostream& out) const {
    Event::print(out);
    out << ": ";
    date.print(out);
}

PeriodEvent::PeriodEvent() {}
PeriodEvent::PeriodEvent(const Date& d1, const Date& d2, const string& str) : begin(d1), end(d2), Event(str) {}

bool PeriodEvent::relevant_to(const Date& theDay) const {
    return theDay >= begin && theDay <= end;
}

bool PeriodEvent::relevant_to_period(const Date& start_date, const Date& end_date) const {
    return begin <= end_date && end >= start_date;
}

void PeriodEvent::print(ostream& out) const {
    Event::print(out);
    out << ": ";
    begin.print(out);
    out << " - ";
    end.print(out);
}

DeadlineEvent::DeadlineEvent() {}
DeadlineEvent::DeadlineEvent(const Date& d, const string& str) : deadline(d), Event(str) {}

bool DeadlineEvent::relevant_to(const Date& theDay) const {
    return theDay <= deadline;
}

bool DeadlineEvent::relevant_to_period(const Date& start_date, const Date& end_date) const {
    return deadline >= start_date && deadline <= end_date;
}

void DeadlineEvent::print(ostream& out) const {
    Event::print(out);
    out << ": ";
    out << "~";
    deadline.print(out);
}
