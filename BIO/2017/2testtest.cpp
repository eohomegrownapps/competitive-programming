#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> availabledots(int dot){
	std::vector<int> v;
	//clockwise.
	if (dot==0){
		v.push_back(1);
		v.push_back(6);
		return v;
	}
	if (dot==5){
		v.push_back(11);
		v.push_back(4);
		return v;
	}
	if (dot==30){
		v.push_back(24);
		v.push_back(31);
		return v;
	}
	if (dot==35){
		v.push_back(34);
		v.push_back(29);
		return v;
	}
	if (dot<6){
		v.push_back(dot+1);
		v.push_back(dot+6);
		v.push_back(dot-1);
		return v;
	}
	if (dot>29){
		v.push_back(dot-1);
		v.push_back(dot-6);
		v.push_back(dot+1);
		return v;
	}
	if (dot%6==0){
		v.push_back(dot-6);
		v.push_back(dot+1);
		v.push_back(dot+6);
		return v;
	}
	if ((dot+1)%6==0){
		v.push_back(dot+6);
		v.push_back(dot-1);
		v.push_back(dot-6);
		return v;
	}
	v.push_back(dot-6);
	v.push_back(dot+1);
	v.push_back(dot+6);
	v.push_back(dot-1);
	return v;
}

int converttobox(int num){
	int n = (num-(num%6))/6;
	n = (n%6)*5;
	n += (num%6);
	return n;
}

std::vector<int> boxes(std::vector<std::vector<int> > adjlist, int start, int end){
	if (start>end){
		int swap = start;
		start = end;
		end = swap;
	}
	if (std::abs(end-start)==1){
		//if on top
		if (start<6){
			//end,start end,end+6 start,start+6 start+6,end+6
			if ((std::find(adjlist[start].begin(), adjlist[start].end(),end)!=adjlist[start].end())&&
				(std::find(adjlist[start].begin(), adjlist[start].end(),start+6)!=adjlist[start].end())&&
				(std::find(adjlist[end].begin(), adjlist[end].end(),end+6)!=adjlist[end].end())&&
				(std::find(adjlist[start+6].begin(), adjlist[start+6].end(),end+6)!=adjlist[start+6].end())){
				std::vector<int> v;
				v.push_back(converttobox(start));
				return v;
			}
		} else if (start>29){
			//end,start end,end+6 start,start+6 start+6,end+6
			if ((std::find(adjlist[start].begin(), adjlist[start].end(),end)!=adjlist[start].end())&&
				(std::find(adjlist[start].begin(), adjlist[start].end(),start-6)!=adjlist[start].end())&&
				(std::find(adjlist[end].begin(), adjlist[end].end(),end-6)!=adjlist[end].end())&&
				(std::find(adjlist[start-6].begin(), adjlist[start-6].end(),end-6)!=adjlist[start-6].end())){
				std::vector<int> v;
				v.push_back(converttobox(start-6));
				return v;
			}
		} else{
			std::vector<int> v;
			if ((std::find(adjlist[start].begin(), adjlist[start].end(),end)!=adjlist[start].end())&&
				(std::find(adjlist[start].begin(), adjlist[start].end(),start+6)!=adjlist[start].end())&&
				(std::find(adjlist[end].begin(), adjlist[end].end(),end+6)!=adjlist[end].end())&&
				(std::find(adjlist[start+6].begin(), adjlist[start+6].end(),end+6)!=adjlist[start+6].end())){
				v.push_back(converttobox(start));
			}if ((std::find(adjlist[start].begin(), adjlist[start].end(),end)!=adjlist[start].end())&&
				(std::find(adjlist[start].begin(), adjlist[start].end(),start-6)!=adjlist[start].end())&&
				(std::find(adjlist[end].begin(), adjlist[end].end(),end-6)!=adjlist[end].end())&&
				(std::find(adjlist[start-6].begin(), adjlist[start-6].end(),end-6)!=adjlist[start-6].end())){
				v.push_back(converttobox(start-6));
			}
			return v;
		}
	}
	if (std::abs(end-start)==6){
		if (start%6==0){
			//start,start+1 end,end+1 start,end start+1,end+1
			if ((std::find(adjlist[start].begin(), adjlist[start].end(),end)!=adjlist[start].end())&&
				(std::find(adjlist[start].begin(), adjlist[start].end(),start+1)!=adjlist[start].end())&&
				(std::find(adjlist[end].begin(), adjlist[end].end(),end+1)!=adjlist[end].end())&&
				(std::find(adjlist[start+1].begin(), adjlist[start+1].end(),end+1)!=adjlist[start+1].end())){
				std::vector<int> v;
				v.push_back(converttobox(start));
				return v;
			}
		} else if ((start+1)%6==0){
			//end,start end,end+6 start,start+6 start+6,end+6
			if ((std::find(adjlist[start].begin(), adjlist[start].end(),end)!=adjlist[start].end())&&
				(std::find(adjlist[start].begin(), adjlist[start].end(),start-1)!=adjlist[start].end())&&
				(std::find(adjlist[end].begin(), adjlist[end].end(),end-1)!=adjlist[end].end())&&
				(std::find(adjlist[start-1].begin(), adjlist[start-1].end(),end-1)!=adjlist[start-1].end())){
				std::vector<int> v;
				v.push_back(converttobox(start-1));
				return v;
			}
		} else{
			std::vector<int> v;
			if ((std::find(adjlist[start].begin(), adjlist[start].end(),end)!=adjlist[start].end())&&
				(std::find(adjlist[start].begin(), adjlist[start].end(),start+1)!=adjlist[start].end())&&
				(std::find(adjlist[end].begin(), adjlist[end].end(),end+1)!=adjlist[end].end())&&
				(std::find(adjlist[start+1].begin(), adjlist[start+1].end(),end+1)!=adjlist[start+1].end())){
				v.push_back(converttobox(start));
			}if ((std::find(adjlist[start].begin(), adjlist[start].end(),end)!=adjlist[start].end())&&
				(std::find(adjlist[start].begin(), adjlist[start].end(),start-1)!=adjlist[start].end())&&
				(std::find(adjlist[end].begin(), adjlist[end].end(),end-1)!=adjlist[end].end())&&
				(std::find(adjlist[start-1].begin(), adjlist[start-1].end(),end-1)!=adjlist[start-1].end())){
				v.push_back(converttobox(start-1));
			}
			return v;
		}
	}
	std::vector<int> empty;
	return empty;

}

void dots(int starta, int moda, int startb, int modb, int turns){
	starta-=1;
	startb-=1;
	std::vector<int> awin;
	std::vector<int> bwin;
	std::vector<std::vector<int> > adjlist;
	std::vector<int> temp;
	int cura = starta;
	int curb = startb;
	bool usable;
	std::vector<int> available;
	std::vector<int> b;
	for (int i = 0; i<36; i++){
		adjlist.push_back(temp);
	}
	for (int i = 0; i<turns; i++){
		for (int i = 0; i<adjlist.size(); i++){
			std::cout<<i<<": ";
			for (int j = 0; j<adjlist[i].size(); j++){
				std::cout<<adjlist[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
		cura+=moda;
		if (cura>35){
			cura-=36;
		}
		usable = false;
		while (usable==false){
			//std::cout<<cura<<std::endl;
			//std::cout<<"iterate"<<std::endl;
			available = availabledots(cura);
			for (int i = 0; i<available.size(); i++){
				if (std::find(adjlist[cura].begin(), adjlist[cura].end(),available[i])==adjlist[cura].end()){
					usable = true;
					adjlist[cura].push_back(available[i]);
					adjlist[available[i]].push_back(cura);
					b=boxes(adjlist, cura, available[i]);
					for (int x : b){
						//std::cout<<"boxes"<<std::endl;
						//std::cout<<x<<std::endl;
						awin.push_back(x);
					}
					break;
				}
			}
			if (usable==false){
				cura+=1;
				if (cura>35){
					cura-=36;
				}
			}
		}

		curb+=modb;
		if (curb>35){
			curb-=36;
		}
		usable = false;
		while (usable==false){
			//std::cout<<"iterate"<<std::endl;
			available = availabledots(curb);
			for (int i = available.size()-1; i>=0; i--){
				if (std::find(adjlist[curb].begin(), adjlist[curb].end(),available[i])==adjlist[curb].end()){
					usable = true;
					adjlist[curb].push_back(available[i]);
					adjlist[available[i]].push_back(curb);
					b=boxes(adjlist, curb, available[i]);
					for (int x : b){
						//std::cout<<"boxes"<<std::endl;
						//std::cout<<x<<std::endl;
						bwin.push_back(x);
					}
					break;
				}
			}
			if (usable==false){
				curb+=1;
				if (curb>35){
					curb-=36;
				}
			}
		}
	}
	for (int i = 0; i<25; i++){
		if (std::find(awin.begin(), awin.end(),i)!=awin.end()){
			std::cout<<"X ";
		} else if (std::find(bwin.begin(), bwin.end(),i)!=bwin.end()){
			std::cout<<"O ";
		} else {
			std::cout<<"* ";
		}
		if ((i+1)%5==0){
			std::cout<<std::endl;
		}
	}
	std::cout<<std::endl;
	std::cout<<awin.size()<<" "<<bwin.size()<<std::endl;
}

int main(int argc, char const *argv[])
{
	std::vector<std::vector<int> > adjlist;
}
