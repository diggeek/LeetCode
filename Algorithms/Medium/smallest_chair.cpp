#include "problems.hpp"

int smallestChair(std::vector<std::vector<int>>& times, int targetFriend) {
    const int CHAIRS_TOTAL = 10000;
    int chairs[CHAIRS_TOTAL] = {};

    const int TIMES_TOTAL = 100'001;
    int target_arrive_time = times[targetFriend][0];
    std::sort(times.begin(), times.end(),
        [](const std::vector<int>& lhs, const std::vector<int>& rhs){return lhs[0] < rhs[0];});
    std::forward_list<int>* leave[TIMES_TOTAL] {};


    for (int t=0, i=0; t<=target_arrive_time; ++t) {
        while(leave[t] && !(leave[t]->empty())) {
            chairs[leave[t]->front()] = 0;
            leave[t]->pop_front();
        }

        if (times[i][0] == t) {
            for (int c=0;c<CHAIRS_TOTAL; ++c) {
                if (chairs[c] == 0) {
                    chairs[c] = 1;
                    if (!leave[times[i][1]]) {
                        leave[times[i][1]] = new std::forward_list<int>(1, c);
                    } else {
                        if (!leave[times[i][1]]->empty()) {
                            leave[times[i][1]]->push_front(c);
                        }
                    }

                    if (t == target_arrive_time) {
                        return c;
                    }
                    ++i;
                    break;
                }
            }
        }
    }

    return -1;
}
