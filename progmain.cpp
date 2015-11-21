

#include <tchar.h>			//_tmain()

#include<iostream>
using namespace std;		//cin cout
#using <mscorlib.dll>		
#include <time.h>			//srand(time(NULL));
#include <stdlib.h>			//srand(time(NULL));

#include "flower.h"




void _tmain()
{
	//parameters
	int condition1 = 1;	//(1)spatial constraints (2)Periodic Boundary Condition
	int condition2 = 1;	//(1)4-neighbour (2)6-neighbour (3)8-neighbour

	
	int 				col; 
	int 				row;
	int 				times = 1;
	int 				nnth = 0;
	int 				seeding;
	DateTime 			time1;				// Time begins
	DateTime 			time2;				// Time ends
	

	cout<<"col: ";	
	cin>>col;
	
	cout<<"row: ";	
	cin>>row;
	
	cout<<"simulation times: ";	
	cin>>times; // Times of simulation
	
	cout<<"seed: ";	
	cin>>seeding;

	time1=DateTime::Now;

	flower fw(col,row,condition1,condition2);
	
	
	files *fil1=new files(S"distribution");
	files *fil2=new files(S"scores");
	
	

	StreamWriter* sw3=new StreamWriter(String::Concat(files::path,S"\\",S"generations.txt"));

	for (int t=1;t<times+1;t++)
	{
		srand(seeding);
		
		//wfiles
		files::dircounts++;
		fil1->chdir();		fil2->chdir();fil2->wtitle2();
				
		nnth++;
		fw.init(1);
		fw.index();
		
		//wfiles
		fil1->wfile1(fw,nnth);	fil2->wfile2(fw,nnth);		
				
		// mating
		while(fw.n_a>0&&fw.n_b>0)
    	{
			nnth++;

			fw.transfer();
			fw.index();

			//wfiles
			fil1->wfile1(fw,nnth);	fil2->wfile2(fw,nnth);
						
     	}
		

		sw3->WriteLine(nnth.ToString());
		nnth=0;
		seeding++;
	}
		

	
	time2 = DateTime::Now;
	sw3->WriteLine(time2.Subtract(time1).ToString());
	sw3->Flush();sw3->Close();

	//wfiles
	fil1->end();fil2->end();

}

