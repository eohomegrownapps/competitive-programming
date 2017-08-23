#include <vector>
#include <string>
#include <iostream>

std::string designation(int monsters){
	if (monsters<5){
		return "few";
	}
	if (monsters<10){
		return "several";
	}
	if (monsters<20){
		return "pack";
	}
	if (monsters<50){
		return "lots";
	}
	if (monsters<100){
		return "horde";
	}
	if (monsters<250){
		return "throng";
	}
	if (monsters<500){
		return "swarm";
	}
	if (monsters<1000){
		return "zounds";
	}
	return "legion";
}

int main(int argc, char const *argv[])
{
	int m;
	std::cin>>m;
	std::cout<<designation(m)<<std::endl;
	return 0;
}

