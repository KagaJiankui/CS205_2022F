#include <iostream>
#include <ostream>
struct DayInfo
{
  enum DAY
  {
    MON = 1,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
  } day;

  enum WEATHER
  {
    SUNNY = 1,
    WINDY,
    RAINY,
    CLOUDY,
    FOGGY,
    SNOWY
  } weather;
};

bool canTravel(DayInfo* dayinfo)
{
  return ((dayinfo->day == 6) || (dayinfo->day == 7)) && ((dayinfo->weather != 3) || (dayinfo->weather != 6));
}

int main(int argc, char const* argv[])
{
  struct DayInfo days[5] = {{DayInfo::MON, DayInfo::FOGGY},
                            {DayInfo::TUE, DayInfo::WINDY},
                            {DayInfo::WED, DayInfo::RAINY},
                            {DayInfo::SUN, DayInfo::SNOWY},
                            {DayInfo::SAT, DayInfo::SUNNY}};

  for (char i = 0; i < 5; i++)
  {
    if(canTravel(&days[i])){
      std::cout << "Today can travel";
    }else{
      std::cout << "Today is not recommend to travel";
    }
    std::cout << std::endl;
  }

  return 0;
}
