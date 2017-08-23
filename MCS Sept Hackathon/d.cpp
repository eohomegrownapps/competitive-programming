#include <iostream>
#include <vector>
#include <algorithm>

int findinarr(std::vector<int> v, int num){
	int index = -1;
	for (int i = 0; i<v.size(); i++){
		if (v[i]==num){
			index = i;
		}
	}
	return index;
}

std::vector<int> digits(int num){
	std::vector<int> v;
	while (num > 0){
	    int digit = num%10;
	    v.push_back(digit);
	    //std::cout<<digit;
	    num = num/10;
	}
	//std::cout<<std::endl;
	std::reverse(v.begin(), v.end());
	return v;
}

void division(int a, int b){
	std::vector<int> bnum;
	bnum = digits(a);
	std::vector<int> answer;
	int carry = 0;
	int current;
	int ans;
	bool decimal = false;
	int where;
	std::vector<int> remainders;
	//for (int i = 0; i<upto; i++){
	int i = 0;
	int findinarrans;
	while (true){
		if (i>bnum.size()-1){
			if (decimal==false){
				//remainders.push_back(current);
				decimal=true;
				where = i;
				//'where' is the index of 1st decimal digit
				//std::cout<<"W"<<where<<std::endl;
			}
			bnum.push_back(0);
		}
		current = bnum[i]+carry*10;
		carry = current%b;
		//std::cout<<"current"<<std::endl;
		//std::cout<<current<<std::endl;
		//std::cout<<carry<<std::endl;
		if (current-carry==0){
			ans=0;
		} else {
			ans = (current-carry)/b;
		}
		answer.push_back(ans);
		if (decimal==true){
			if (findinarr(remainders,current)!=-1){
				//std::cout<<"remainders"<<std::endl;
				for (int i = 0; i<remainders.size(); i++){
					//std::cout<<remainders[i]<<std::endl;
				}
				//std::cout<<"Cycle"<<std::endl;
				//std::cout<<i<<std::endl;
				//std::cout<<findinarr(remainders,current)+where<<std::endl;
				//std::cout<<i-findinarr(remainders,current)-where<<std::endl;
				findinarrans = findinarr(remainders,current)+where;
				break;
			}
			remainders.push_back(current);
		}
		i++;
	}
	int count = 1;
	std::cout<<a<<"/"<<b<<" = ";
	for (int i = 0; i<answer.size()-1; i++){
		if (count==51){
			std::cout<<"...";
			break;
		}
		if ((i+1==where)|(i<where&&answer[i]!=0)|(i>where)|(i==where)){
			if (i==where){
				std::cout<<".";
			}
			if (i==findinarrans){
				std::cout<<"(";
			}
			std::cout<<answer[i];
		}
		if (i<where==false){
			count++;
		}
	}
	std::cout<<")"<<std::endl;
	std::cout<<i-findinarr(remainders,current)-where<<" = number of digits in repeating cycle"<<std::endl;
	//return answer;
}

int main(int argc, char const *argv[])
{
	int a,b;
	std::cin>>a>>b;
	division(a,b);
	return 0;
}