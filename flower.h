
#using <mscorlib.dll>
using namespace System;			//DateTime
using namespace System::IO;

#include <iomanip>
using namespace std;			//ofstream

#include <math.h>	

#include "function.h"

class flower
{
public:
	int col,row,bounds;				
	int condition1,condition2;
	
	int n_a,n_b;						// The number of A and a
	int fw_num[3];						// Total number of flowers
	int sur_no1,sur_no2;				// The number of neibours

	int **location1;					// Location of flowers
	int **location2;					// int temp	used:transfer
	
	
	// Initialize
	flower(int i_col,int i_row,int cond1,int cond2)
  	{
	    col=i_col;
	    row=i_row;
	    condition1=cond1;
	    condition2=cond2;

		location1 = new int*[col];
		for(int i=0;i<col;i++)
		{
			location1[i]=new int[row];
		}
		
		location2=new int*[col];
		for(int i=0;i<col;i++)
		{
			location2[i]=new int[row];
		}
					
		if(cond2==1){sur_no1=4;sur_no2=8;};
		if(cond2==2){sur_no1=6;sur_no2=12;}; 
		if(cond2==3){sur_no1=8;sur_no2=16;};
		if(cond2==4){sur_no1=24;/*sur_no2=;*/};							
	}
	
	




	// Initialize
	// The elements in location1 will be initialized as aa(0), Aa(1) or AA(2)
	void init(int cond)
	{
		for(int i=0;i<col;i++)
			for(int j=0;j<row;j++)
			{
				location1[i][j]=0;
				for(int k=0;k<2;k++)	
					location1[i][j] += rannum(2)-1;
			}	
	}
		

	/* 
	*fwcount
	*Calculate the number of AA, Aa and aa.
	*fw_num[index]		AA:index=2	Aa:index=1	aa:index=0
	*/
	void fwcount(void)	
	{
		for(int i=0;i<3;i++)
			fw_num[i]=0;
		for(int i=0;i<col;i++)
			for(int j=0;j<row;j++)
				fw_num[location1[i][j]]++;
		n_a=fw_num[2]*2+fw_num[1];
		n_b=fw_num[0]*2+fw_num[1];
	}
	
			
		

	/*
	** Mating
	** condition1 == 1: spatial constraints.
	** condition1 == 2: Periodic Boundary Condition
	*/
	void transfer(void)
	{
		int surround;
		for(int i=0;i<col;i++)
			for(int j=0;j<row;j++) 
				location2[i][j]=location1[i][j];

		for(int i=0;i<col;i++)
			for(int j=0;j<row;j++)
			{
				// spatial constraints. Randomly mated by any other element
		        if(condition1 == 1)
		        {
					int ran_col = 0;
					int ran_row = 0;
		            do
		            {
		            	ran_col = rannum(col) - 1;
		            	ran_row = rannum(row) - 1;
		            }
		            while(ran_col == i && ran_row == j);   

		             location1[i][j] = trans(location2[i][j])
									+ trans(location2[ran_col][ran_row]); 
				}
				
		        if(condition1 == 2)
		        {
		            surround=rannum(sur_no1);
		            location1[i][j] = trans(location2[i][j])
									+ trans(location2[(i+pos1(surround,i,1)+col)%col][(j+pos1(surround,i,2)+row)%row]);
				}
			}
	};

	


	int pos1(int num_pos,int pos_i,int col_row)
	{
		if(condition2==1)return posi41(num_pos,col_row);else
		if(condition2==2)return posi61(num_pos,pos_i,col_row);else
		if(condition2==3)return posi81(num_pos,col_row);
	};
	int pos2(int num_pos,int pos_i,int col_row)
	{
		if(condition2==1)return posi42(num_pos,col_row);else
		if(condition2==2)return posi62(num_pos,pos_i,col_row);else
		if(condition2==3)return posi82(num_pos,col_row);	
	};



	void index(void)
	{
		fwcount();
			
	};

	

	
};
__gc class files
{
public:
	static String* path = Directory::GetCurrentDirectory();
	
	static int dircounts = 0; 
	int filecount,linecount;
	StreamWriter* sw ;
	String* filename;					// record flowers
	String* ffilename;
	
	

	


	//////////////////////////////////////////////////////////////////
	files(String *fnam)
	{
		filename=fnam;
		
		//counter=fw.ix1ctscope;
		//chrwid=0;for(int i=1;fw.col*fw.row>=i;i*=10)chrwid++;
	};
	////////////////////////////////////////////////////////////////
	


	void chdir(void)
	{
		//dircounts+=1;
		filecount=0;
		if(!Directory::Exists(dircounts.ToString("d3")))Directory::CreateDirectory(dircounts.ToString("d3"));
		chfile();
	};

	void chfile(void)
	{
		if(dircounts>1){sw->Flush();sw->Close();};
		filecount++;linecount=0;
		ffilename = String::Concat(path,S"\\",dircounts.ToString("d3"),S"\\",String::Concat(filename,filecount.ToString("d3"),S".txt"));
		sw =new StreamWriter(ffilename,false);
	};
		
	void wtitle2(void)
	{
		sw->Write(S"generation_NO\t");
		sw->Write(S"AA_num\tAa_num\taa_num\t");
		sw->WriteLine();linecount++;
	};
		
	
	void wfile1(flower fw,int nnth)
	{
		if(linecount>500000)chfile();	// write into another file when the line count of file1 is greater than 500k

		sw->WriteLine(nnth.ToString());linecount++;
		for(int i=0;i<fw.col;i++)
		{
			for(int j=0;j<fw.row;j++)
			{
				sw->Write(fw.location1[i][j]);
			}
			sw->WriteLine();linecount++;
		};
	};

	void wfile2(flower fw,int nnth)
	{
		if(linecount>500000){chfile();wtitle2();};	
		
		sw->Write("{0}\t",nnth.ToString());
		sw->Write("{0}\t{1}\t{2}\t",fw.fw_num[2].ToString(),fw.fw_num[1].ToString(),fw.fw_num[0].ToString());
		sw->WriteLine();linecount++;
	};
	


	void end(void)
	{
		sw->Flush();sw->Close();

	};
		
};
