#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const double rates[5][3] = {
    {0.10, 0.06, 0.02},
    {0.25, 0.15, 0.05},
    {0.53, 0.33, 0.13},
    {0.87, 0.47, 0.17},
    {1.44, 0.80, 0.30}
};

int get_rate_period(int hour) {
    if (hour >= 8 && hour < 18) return 0;
    if (hour >= 18 && hour < 22) return 1;
    return 2;
}

void compute_charge(char step, string number, int start_h, int start_m, int end_h, int end_m) {
    int total_minutes = (end_h * 60 + end_m) - (start_h * 60 + start_m);
    int day_min = 0, eve_min = 0, off_min = 0;
    int current_h = start_h, current_m = start_m;

    while (total_minutes > 0) {
        int period = get_rate_period(current_h);
        int next_period_hour = (period == 0) ? 18 : (period == 1) ? 22 : 8;
        int next_period_min = next_period_hour * 60;
        int current_time_min = current_h * 60 + current_m;
        
        int minutes_in_this_period = min(total_minutes, next_period_min - current_time_min);

        if (period == 0) day_min += minutes_in_this_period;
        else if (period == 1) eve_min += minutes_in_this_period;
        else off_min += minutes_in_this_period;

        total_minutes -= minutes_in_this_period;
        current_h = (current_time_min + minutes_in_this_period) / 60;
        current_m = (current_time_min + minutes_in_this_period) % 60;
    }

    int rate_index = step - 'A';
    double total_cost = day_min * rates[rate_index][0] + eve_min * rates[rate_index][1] + off_min * rates[rate_index][2];

    cout << setw(8) << number
         << setw(6) << day_min
         << setw(6) << eve_min
         << setw(6) << off_min
         << setw(2) << step
         << fixed << setprecision(2) << setw(6) << total_cost
         << endl;
}

int main() {
    string step, number;
    int start_h, start_m, end_h, end_m;
    
    while (cin >> step && step != "#") {
        cin >> number >> start_h >> start_m >> end_h >> end_m;
        compute_charge(step[0], number, start_h, start_m, end_h, end_m);
    }

    return 0;
}
