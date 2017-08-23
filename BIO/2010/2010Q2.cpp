#include <iostream>
#include <array>

int mod(int a, int b){
	return ((a%b)+b)%b;
}

std::array<int, 7> movedie(std::array<int, 7> die){
	std::array<int,7> ndie = {1,1,1,1,1,1,1};
	ndie[6] = die[6];
	if (die[6]==0){
		ndie[0] = die[2];
		ndie[1] = die[3];
		ndie[2] = die[1];
		ndie[3] = die[0];
		ndie[4] = die[4];
		ndie[5] = die[5];
	}
	if (die[6]==1){
		ndie[0] = die[4];
		ndie[1] = die[5];
		ndie[2] = die[2];
		ndie[3] = die[3];
		ndie[4] = die[1];
		ndie[5] = die[0];
	}
	if (die[6]==2){
		ndie[0] = die[3];
		ndie[1] = die[2];
		ndie[2] = die[0];
		ndie[3] = die[1];
		ndie[4] = die[4];
		ndie[5] = die[5];
	}
	if (die[6]==3){
		ndie[0] = die[5];
		ndie[1] = die[4];
		ndie[2] = die[2];
		ndie[3] = die[3];
		ndie[4] = die[0];
		ndie[5] = die[1];
	}
	return ndie;
}

void dietipping(std::array<std::array<int, 11>, 11> diegrid){
	//0=f,1=r,2=b,3=l
	//t,b,e,f,l,r,heading
	std::array<int, 7> die = {1,6,5,2,3,4,0};
	std::array<int, 2> dielocation = {5,5};
	int n;
	std::cin>>n;
	int num;
	int h;
	while (n!=0){
		for (int i = 0; i<n; i++){
			num = diegrid[dielocation[0]][dielocation[1]] + die[0];
			if (num>6){
				num -= 6;
			}
			diegrid[dielocation[0]][dielocation[1]] = num;
			if (num==1||num==6){
				die = movedie(die);
			}
			if (num==2){
				die[6]+=1;
				die[6] = mod(die[6],4);
				die = movedie(die);
			}
			if (num==3||num==4){
				die[6]+=2;
				die[6] = mod(die[6],4);
				die = movedie(die);
			}
			if (num==5){
				die[6]-=1;
				die[6] = mod(die[6],4);
				die = movedie(die);
			}
			h = die[6];
			if (h==0){
				dielocation[1] = mod((dielocation[1]-1),11);
			}
			if (h==1){
				dielocation[0] = mod((dielocation[0]+1),11);
			}
			if (h==2){
				dielocation[1] = mod((dielocation[1]+1),11);
			}
			if (h==3){
				dielocation[0] = mod((dielocation[0]-1),11);
			}
		}
		//std::cout<<dielocation[0]<<" "<<dielocation[1]<<std::endl;
		for (int y = dielocation[1]-1; y<dielocation[1]+2; y++){
			for (int x = dielocation[0]-1; x<dielocation[0]+2; x++){
				if (x<0||x>10||y<0||y>10){
					std::cout<<'X';
				} else {
					std::cout<<diegrid[x][y];
				}
			}
			std::cout<<std::endl;
		}
		//for (int y = 0; y<11; y++){
		//	for (int x = 0; x<11; x++){
		//		std::cout<<diegrid[x][y];
		//	}
		//	std::cout<<std::endl;
		//}
		std::cin>>n;
	}
}

int main(int argc, char const *argv[])
{
	std::array<std::array<int, 11>, 11> diegrid;
	for (int x = 0; x<11; x++){
		for (int y = 0; y<11; y++){
			diegrid[x][y]=1;
		}
	}
	int temp;
	for (int y = 4; y<7; y++){
		for (int x = 4; x<7; x++){
			std::cin>>temp;
			diegrid[x][y] = temp;
		}
	}
	dietipping(diegrid);
	return 0;
}