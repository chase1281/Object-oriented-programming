#pragma once
#include "Date.h"

class Event {
protected:
    static int event_counter;
    int id;
    string content;
public:
    Event();
    Event(string cont);
    virtual ~Event();

    int get_id() const;
    bool contains(const string& keyword) const;
    virtual bool relevant_to(const Date& day) const = 0;
    virtual bool relevant_to_period(const Date& start_date, const Date& end_date) const = 0;
    virtual void print(ostream& out) const;
};

class OneDayEvent : public Event {
private:
    Date date;
public:
    OneDayEvent();
    OneDayEvent(const Date& d, const string& str);
    bool relevant_to(const Date& theDay) const;
    bool relevant_to_period(const Date& start_date, const Date& end_date) const;
    void print(ostream& out) const;
};

class PeriodEvent : public Event {
private:
    Date begin, end;
public:
    PeriodEvent();
    PeriodEvent(const Date& d1, const Date& d2, const string& str);
    bool relevant_to(const Date& theDay) const;
    bool relevant_to_period(const Date& start_date, const Date& end_date) const;
    void print(ostream& out) const;
};

class DeadlineEvent : public Event {
private:
    Date deadline;
public:
    DeadlineEvent();
    DeadlineEvent(const Date& d, const string& str);
    bool relevant_to(const Date& theDay) const;
    bool relevant_to_period(const Date& start_date, const Date& end_date) const;
    void print(ostream& out) const;
};
