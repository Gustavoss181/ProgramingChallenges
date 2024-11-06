#include <vector>
#include <iostream>

using namespace std;

class MyCalendar {
private:
    vector<int> startTimes;
    vector<int> endTimes;

    bool isBookingPossible(int startTime, int endTime, int pos){
        return (((startTime < startTimes[pos] and startTime < endTimes[pos]) and
                (endTime < startTimes[pos] and endTime <= endTimes[pos]))
                or
                ((startTime > startTimes[pos] and startTime >= endTimes[pos]) and
                (endTime > startTimes[pos] and endTime > endTimes[pos])));
    }

    bool isBookingPossible(int startTime, int endTime, int pos){
        if(startTimes[pos] <= startTime and startTime < endTimes[pos]) return false;

        if(startTimes[pos] < endTime and endTime <= endTimes[pos]) return false;

        if(startTimes[pos] <= startTime and endTime >= endTimes[pos]) return false;

        return true;
    }
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(int i=0; i<startTimes.size(); ++i){
            if(!isBookingPossible(startTime, endTime, i))
                return false;
        }
        startTimes.push_back(startTime);
        endTimes.push_back(endTime);
        return true;
    }
};

int main(int argc, char const *argv[]){
    MyCalendar* obj = new MyCalendar();

    cout << obj->book(10, 20) << endl;
    cout << obj->book(15, 25) << endl;
    cout << obj->book(20, 30) << endl;

    delete obj;

    return 0;
}


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */