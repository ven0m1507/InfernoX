
#include "Priority.h"

Priority::Priority(int sev, int PAR, float FSR, float fire_time, int DFP) {
    severity = sev;
    people_at_risk = PAR;
    fire_spread_rate = FSR;
    fire_duration = fire_time;
    dist_from_population = DFP;
}

float Priority::calculate_priority() {
    // Scale values to a range of 1 to 10.
    float severity_score = severity;
    float people_score = (people_at_risk / 1000.0) * 10;
    float fire_spread_rate_score = (fire_spread_rate / 20.0) * 10;
    float fire_time_score = (fire_duration / 8.0) * 10;
    float dist_from_population_score =
        10 - (dist_from_population / 20.0) * 10;

    if (people_score > 10)
        people_score = 10;
    if (fire_spread_rate_score > 10)
        fire_spread_rate_score = 10;
    if (fire_time_score > 10)
        fire_time_score = 10;
    if (dist_from_population_score > 10)
        dist_from_population_score = 10;

    float Priority_score =
        (severity_score * 0.30) +
        (people_score * 0.20) +
        (fire_spread_rate_score * 0.20) +
        (fire_time_score * 0.10) +
        (dist_from_population_score * 0.10);

    return Priority_score;
}
