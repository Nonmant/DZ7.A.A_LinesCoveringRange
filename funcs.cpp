//https://contest.yandex.ru/contest/27883/problems/A/

#include "funcs.h"
#include <bits/stdc++.h>

static const short int TeacherStart = 0;
static const short int TeacherEnd = 1;
typedef short int teacherEvent;

void parseFile(std::istream & input, std::ostream & output){

    int nStudents, mTeachers;
    input >> nStudents >> mTeachers;

    std::vector<std::pair<int,teacherEvent>> events(mTeachers*2);
    int start, end;
    for(int i = 0; i<mTeachers; ++i){
        input >> start >> end;
        events[i*2] = {start, TeacherStart};
        events[i*2 + 1] = {end, TeacherEnd};
    }

    std::sort(events.begin(), events.end());
    int prevPos = -1, gap = 0, teachers = 0;
    int pos = -1;
    for(const auto & event : events){
        pos = event.first;

        if(teachers == 0){
            gap+=std::max(pos-prevPos-1,0);
        }
        if(event.second == TeacherStart){
            ++teachers;
        } else if(event.second == TeacherEnd){
            --teachers;
        }
        prevPos = pos;
    }
    gap += nStudents-1-pos;

    output << gap;
}
