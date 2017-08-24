#include <iostream>

int main(int argc, char const *argv[])
{
	std::cout<<"Euan Ong"<<std::endl<<"Magdalen College School"<<std::endl;
	int kin,uinal,tun,katun,baktun;
	std::cin>>baktun>>katun>>tun>>uinal>>kin;
	long days = 0;
	days+=(baktun-13)*144000+(katun-20)*7200+(tun-7)*360+(uinal-16)*20+(kin-3);
	int year = 2000;
	//std::cout<<days<<std::endl;
	while (true){
		int d;
		if (year%4==0){
			d=366;
		} else {
			d=365;
		}
		if (days-d>=0){
			days-=d;
			year++;
		} else {
			break;
		}
	}
	int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int month = 1;
	for (int i = 0; i<12; i++){
		int val = months[i];
		if (year%4==0&&i==1){
			val++;
		}
		if (days-val>=0){
			days-=val;
			month++;
		} else {
			break;
		}
	}
	int day = days+1;
	std::cout<<day<<" "<<month<<" "<<year<<std::endl;
	return 0;
}