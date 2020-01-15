#ifndef DUALDEGREE_H 
#define DUALDEGREE_H
#include<string>
#include<iostream>
#include "Faculty.cpp"
using namespace std;
class Dualdegree
{  
	public:
	int Rollnumber;string hostel;
	Faculty facad,DDPguide,TAsupervisor;
	float cgpa;

	Dualdegree(int Rollnumber,string hostel,Faculty facad,float cgpa)
	{
		this->Rollnumber=Rollnumber;
		this->hostel=hostel;
		this->facad=facad;
		this->cgpa=cgpa;
	}
	string getHostel()
	{
		return hostel;
	}
	Faculty getFacad()
	{
		return facad;
	}
	void changeHostel(string H)
	{
		hostel=H;
	}
	void setDDPguide(Faculty F)
	{
		DDPguide=F;
	}
	Faculty getDDPguide()
	{
		return DDPguide;
	}
	void setTAsupervisor(Faculty F)
	{
		TAsupervisor=F;
	}
	Faculty getTAsupervisor()
	{
		return TAsupervisor;
	}
	bool checksame()
	{
		return TAsupervisor.name==DDPguide.name;
	}
};
#endif