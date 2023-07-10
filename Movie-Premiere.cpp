/* 
Author: Lasha Zibzibadze
Course: CSCI-135
Instructor: Genady Maryash

This program schedules time for an upcoming movie.
*/

#include <iostream>
using namespace std;

class Time { 
    public:
        int h;
        int m;
};

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie {
    public:
        string name;
        Genre genre;
        int duration;
};

class TimeSlot {
    public:
        Movie film;
        Time start;
          

};

Time addMinutes(Time time0, int min){
    int temp;
    int temp_m;
    if(min >=  60){
        temp = min / 60;
        temp_m= min % 60;
        //8 50 , 135
        // time0.h= time0.h + temp;
        // time0.m= time0.m + temp_m;
        if(time0.m+ temp_m > 60){
            return time0 = {time0.h +temp + 1, (time0.m + temp_m) %60};
            
        }
        else if (time0.m + temp_m == 60){
            return time0 = {time0.h +temp + 1, 00};
        }
        else{
            return time0 = {time0.h +temp, time0.m + temp_m};
        }
        

    }
    else{

        // time0.m= time0.m + min;
        if(time0.m + min > 60){
            return time0 = {time0.h+1, (time0.m + min) % 60};
        }
        // 15 56  , 50
        else if(time0.m+min == 60){
            return time0 = {time0.h+1, 00};
        }
        else{
            return time0 = {time0.h, time0.m + min};
        }


    }








}


int minutesSinceMidnight(Time time){
    int result;
    Time AM = {0, 00};
    int day = 1440; // 1day = 1440 min
    int hours= time.h * 60;
    int minutes= time.m;
    result= hours + minutes;







    return result;

}

int minutesUntil(Time earlier, Time later){
    int result;
    int hours_earlier= earlier.h * 60 + earlier.m;
    int hours_later= later.h * 60 + later.m;
    result= hours_later - hours_earlier;



    return result;

}

void print(Movie mov){
    string genre;
    switch(mov.genre){
        case ACTION : genre = "ACTION"; break;
        case COMEDY : genre = "COMEDY"; break;
        case DRAMA : genre = "DRAMA"; break;
        case ROMANCE : genre = "ROMANCE"; break;
        case THRILLER : genre = "THRILLER"; break;
               

    }

    cout<< mov.name << " " << genre << " (" << mov.duration << " min)";
}



void printTimeSlot(TimeSlot ts){

    Time end_time;
    end_time= addMinutes({ts.start.h, ts.start.m}, ts.film.duration);
    print(ts.film);
    cout<< " [starts at ";
    cout<< ts.start.h << ":" << ts.start.m;
    cout<< "," << " ends by " << end_time.h << ":" << end_time.m << "]" << endl;


}


TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){

    Time count_time = addMinutes(ts.start, ts.film.duration);
    TimeSlot find_next_available;
    return find_next_available = {nextMovie, count_time};




}




int main(){
    // TimeSlot f;
    // f.duration = 116;
    // f.name = "Back to the Future";
    // f.genre = "COMEDY";
    // f.start = {9,15};
    Movie f= {"Back to the Future", COMEDY, 116};
    TimeSlot first = {f, {9, 15}};
    printTimeSlot(first);
    Movie s= {"Black Panther", ACTION, 134};
    TimeSlot second = {s, {12, 15}};
    printTimeSlot(second);
    Movie t= {"Black Panther", ACTION, 134};
    TimeSlot third = {t, {16, 45}};
    printTimeSlot(third);
    Movie fo= {"Black Adam", ACTION, 125};
    TimeSlot four = {fo, {20, 10}};
    printTimeSlot(four);
    Movie fi= {"Bruce Almighty", COMEDY, 101};
    TimeSlot fifth = scheduleAfter(first, s);
    // printTimeSlot(fifth);
    printTimeSlot(fifth);
    








    return 0;
}

