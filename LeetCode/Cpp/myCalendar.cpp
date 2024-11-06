#include <vector>
#include <iostream>

using namespace std;

struct Reservation{
    int startTime;
    int endTime;
    Reservation* next;
    Reservation() : startTime(0), endTime(0), next(nullptr) {}
    Reservation(int startTime, int endTime) : startTime(startTime), endTime(endTime), next(nullptr) {}
    Reservation(int startTime, int endTime, Reservation* next) : startTime(startTime), endTime(endTime), next(next) {}
    ~Reservation(){
        if(next) delete next;
    }
    void print(){
        cout << "|" << startTime << "---" << endTime << "| -> ";
        if(next)
            next->print();
        else
            cout << "Null" << endl;
    }
};

class MyCalendar {
private:
    Reservation* reservationsBegin;
    Reservation* reservationsEnd;
public:
    MyCalendar() {
        reservationsBegin = new Reservation();
        reservationsEnd = reservationsBegin;
    }

    ~MyCalendar(){
        reservationsBegin->print();
        delete reservationsBegin;
    }
    
    bool book(int startTime, int endTime) {
        // reservationsBegin->print();
        if(endTime <= startTime) return false;
        if(startTime == reservationsEnd->endTime){
            reservationsEnd->endTime = endTime;
            return true;
        }
        if(startTime > reservationsEnd->endTime){
            reservationsEnd->next = new Reservation(startTime, endTime);
            reservationsEnd = reservationsEnd->next;
            return true;
        }
        Reservation* currReservation = reservationsBegin;
        while(currReservation != reservationsEnd){
            if(startTime < currReservation->endTime) return false;
            if(startTime < currReservation->next->startTime and !(endTime <= currReservation->next->startTime)) return false;
            if(startTime == currReservation->endTime and endTime == currReservation->next->startTime){
                currReservation->endTime = currReservation->next->endTime;
                currReservation->next = currReservation->next->next;
                return true;
            }
            if(startTime == currReservation->endTime){
                currReservation->endTime = endTime;
                return true;
            }
            if(endTime == currReservation->next->startTime){
                currReservation->next->startTime = startTime;
                return true;
            }
            if(startTime > currReservation->endTime and endTime < currReservation->next->startTime){
                Reservation* newReservation = new Reservation(startTime, endTime, currReservation->next);
                currReservation->next = newReservation;
                return true;
            }
            currReservation = currReservation->next;
        }
        return false;
    }
};

int main(int argc, char const *argv[]){
    MyCalendar* obj = new MyCalendar();

    cout << obj->book(27, 41) << endl;
    cout << obj->book(5, 24) << endl;
    cout << obj->book(99, 100) << endl;
    cout << obj->book(99, 100) << endl;
    cout << obj->book(57, 67) << endl;
    cout << obj->book(38, 48) << endl;
    cout << obj->book(29, 46) << endl;
    cout << obj->book(79, 94) << endl;
    cout << obj->book(19, 35) << endl;
    cout << obj->book(93, 100) << endl;
    cout << obj->book(52, 67) << endl;
    cout << obj->book(82, 99) << endl;
    cout << obj->book(76, 94) << endl;
    cout << obj->book(80, 90) << endl;
    cout << obj->book(43, 62) << endl;
    cout << obj->book(97, 100) << endl;
    cout << obj->book(4, 19) << endl;
    cout << obj->book(20, 34) << endl;
    cout << obj->book(53, 67) << endl;
    cout << obj->book(27, 41) << endl;
    cout << obj->book(69, 83) << endl;
    cout << obj->book(62, 74) << endl;
    cout << obj->book(38, 48) << endl;
    cout << obj->book(61, 75) << endl;
    cout << obj->book(93, 100) << endl;
    cout << obj->book(18, 37) << endl;
    cout << obj->book(86, 99) << endl;
    cout << obj->book(62, 79) << endl;
    cout << obj->book(80, 97) << endl;
    cout << obj->book(55, 74) << endl;
    cout << obj->book(26, 37) << endl;
    cout << obj->book(64, 81) << endl;
    cout << obj->book(62, 79) << endl;
    cout << obj->book(44, 54) << endl;
    cout << obj->book(67, 81) << endl;
    cout << obj->book(11, 27) << endl;
    cout << obj->book(79, 95) << endl;
    cout << obj->book(61, 80) << endl;
    cout << obj->book(79, 91) << endl;
    cout << obj->book(41, 55) << endl;

    delete obj;

    return 0;
}


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */