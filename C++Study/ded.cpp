#include <iostream>
#include<ctime>

using namespace std;


void weatherForcast(char *w="sunny")
{
  time_t t=time(0);
  char tmp[64];
  strftime(tmp,sizeof(tmp),"%Y/%m/%d %x %A",localtime(&t));
  cout<<tmp<<"today is weather "<<w<<endl;
}
int main(int argc, char *argv[])
{
    //sunny windy cloudy foggy rainy
    weatherForcast();
    weatherForcast("rainy");
    weatherForcast();

    return 0;
}
