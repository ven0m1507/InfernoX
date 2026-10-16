
#ifndef PRIORITY_H
#define PRIORITY_H

class Priority {
private:
    int severity;
    int people_at_risk;
    float fire_spread_rate;
    float fire_duration;
    int dist_from_population;

public:
    Priority(int sev, int PAR, float FSR, float fire_time, int DFP);

    float calculate_priority();
};

#endif
