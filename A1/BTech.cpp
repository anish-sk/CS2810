#ifndef BTECH_H 
#define BTECH_H
#include<string>
#include<iostream>
#include "Faculty.cpp"
using namespace std;
class Btech
{
	public:
	int Rollnumber;string hostel;
	Faculty facad,BTPguide;
	

	float cgpa;
	Btech(int Rollnumber,string hostel,Faculty facad,float cgpa)
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
	void setBTPguide(Faculty F)
	{
		BTPguide=F;
	}
	Faculty getBTPguide()
	{
		return BTPguide;
	}

};

#endif