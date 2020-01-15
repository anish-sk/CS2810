#include <bits/stdc++.h>
#include "Faculty.cpp"
#include "BTech.cpp"
#include "Dualdegree.cpp"
#include "IITMclass.cpp"
using namespace std;

bool myfunc(Btech i,Btech j)
{
   return (i.cgpa>j.cgpa);
}

bool myfunc1(Dualdegree i,Dualdegree j)
{
	return (i.hostel<j.hostel);
}
int main()
{   
    IITMclass I; 

	int n,m;
    char Hostel[10][5]={"H1","H2","H3","H4","H5","H6","H7","H8","H9","H10"};

    n=55;   //rand()%(100000)+1;
    m=10;   //rand()%(100)+1;

    set<string> Ss;
    set<int> Si;

    for(int i=0;i<m;++i)
    { 	//cout<<i;cout<<flush;
        char a[10];
    	int b=rand()%2;
    	Faculty F;
    	F.Permanent=(b==1);              
    	for(int j=0;j<9;j++)
    	{
    		a[j]=(rand())%26+'a';
    	}
    	a[9]='\0';
    	F.name=a;
    	(I.Vf).push_back(F);                 // generating facultyname randomly ...
    }
    while(n--)
    {   //cout<<"hi";
        int rollno=rand()%(100000);
    	int b=rand()%2;
    	int i=rand()%10;
    	int j=rand()%m;                   // generating student details randomly ...
    	string hostel=Hostel[i];          
       	Faculty facad=I.Vf[j];              // Assigning Facultyadvisors randomly to students...
    	float cgpa=(rand()%1000 + 1)/100;
    	if(b)
    		(I.Vb).push_back(Btech(rollno,hostel,facad,cgpa));
    	else
    		(I.Vd).push_back(Dualdegree(rollno,hostel,facad,cgpa));
    }

    // assign BTP guides and DDP guides 

    sort((I.Vb).begin(),(I.Vb).end(),myfunc);  // sorting B.tech students based on cgpa..
    sort((I.Vd).begin(),(I.Vd).end(),myfunc1);  // sorting Dualdegree students based on hostel name..
    
    int b=0,d=0;

    vector<bool> B((I.Vd).size(),false);

    int totalcount=0;
    for(auto it:(I.Vf))
    {	//cout<<"hi";
    	if(it.Permanent)
    	{  
           int i,j;
    	   for(i=b;i<(I.Vb).size()&&(i<b+2);i++)      // setting BTP guide assigns two students per faculty (if possible)
           	   (I.Vb)[i].setBTPguide(it);            
           b=i;
           for(j=d;j<(I.Vd).size()&&(j<d+2);j++)          // setting DDP guide assigns two students per faculty (if possible)
           	 (I.Vd)[j].setDDPguide(it);
           d=j;
    	}
        //cout<<"hi";
        int count=0;
        while(count<5 && totalcount<((I.Vd).size()))
        {
        	int g=(rand()%((I.Vd).size()));
        	if(!B[g])
        	{
        		B[g]=true;
        		(I.Vd)[g].setTAsupervisor(it);          // making faculty as TA supervisor for five random students
        		 count++;                            // if possible 5 otherwise lesser than 5
        		 totalcount++;
        	}
        	//cout<<count<<" ";
        }
        //cout<<"hi";

    }
    return 0;
}