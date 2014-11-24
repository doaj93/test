#include <iostream>
#include <vector>
using namespace std;
bool integer(float n)
{
  int nn=(long) n;
  if ((nn-n<0.000001)&&(nn-n>-0.000001)) 
	  return true;
  else return false;
}

vector<float> sort(vector<int> num,int dep,int times)
{
  int i;
  vector<int> nnum;
  int divide=1; // int(num[i]/divide)%10
  for (int t=0;t<dep;t++)
  {
    for (int c=0;c<10;c++)
      for (int i=0;i<num.size();i++)
        if (int(num[i]/divide)%10==c) nnum.push_back(num[i]);
    num=nnum;
    nnum.clear();
    divide=divide*10;
  }
  vector<float> ret(num.size());
  for (int i=0;i<num.size();i++)
    ret[i]=(float(num[i])/times);
  return ret;
}
int main()
{
  vector<float> num;
  vector<int> intnum(num.size());
  int i,dep,times,len;
  //random  then turn to num(float)  times=10000;
  int c;
  len=50;
  for (i=0;i<len;i++)
  {
    intnum.push_back(rand()%100+100);
    c=pow(10,rand()%3);
    num.push_back(float(intnum[i])/c);
  }
  times=100;
  //num(float) turn to intnum(int)
  for (i=0;i<len;i++)
	intnum[i]=int(num[i]*100);
  //find the maxnumber(max) and calculate the length(dep)
  int max=0;
  for (i=0;i<intnum.size();i++)
    if (intnum[i]>max) max=intnum[i];
  dep=0;
  while (max>0) {
    dep++;
    max=int(max/10);
  }
  num=sort(intnum,dep,times);
  for (int i=0;i<len;i++)
	cout<<num[i]<<" ";
}