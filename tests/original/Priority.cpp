 #include<iostream>
using namespace std;

class Priority{
  private:
int severity;
int people_at_risk;
float fire_spread_rate;
float fire_duration;
int dist_from_population;

public:
 Priority(int sev,int PAR,float FSR,float fire_time,int DFP){
  severity=sev;
  people_at_risk=PAR;
  fire_spread_rate=FSR;
 fire_duration=fire_time;
  dist_from_population=DFP;
 }

 float calculate_priority(){
  
  //Setting all the values to a range of 1 to 10.....to easily cal priority
  float severity_score=severity;
  float people_score=(people_at_risk/1000.0)*10;  //currently I set it to 1000 max
  float fire_spread_rate_score=(fire_spread_rate/20.0)*10;  //currently 20 kilometer square limit
  float fire_time_score=(fire_duration/8.0)*10;  //8 hours max taken
  float dist_from_population_score=10-(dist_from_population/20.0)*10;
  
  if(people_score>10)
  people_score=10;
  if(fire_spread_rate_score>10)
  fire_spread_rate_score=10;
  if(fire_time_score>10)
  fire_time_score=10;
  if(dist_from_population_score>10)
  dist_from_population_score=10;

//Calculation......
 float Priority_score=(severity_score *0.30)+
 (people_score*0.20)+(fire_spread_rate_score*0.20)+(fire_time_score*0.10)+(dist_from_population_score*0.10);


 return Priority_score;
}

};

int main()
{
    Priority fire1(8, 1066, 33, 5, 7);
   //testing.........
    cout << fire1.calculate_priority();

    return 0;
}

