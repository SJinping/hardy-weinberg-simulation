
char *charjoin(char a[],char b[],char c[])
{	
	char	*mainchr=new char[];
	int		i = 0;
	int		j = 0;
	int		k = 0;
	for(i=0;a[i]!='\0';i++) mainchr[i]=a[i];
	for(j=0;b[j]!='\0';j++) mainchr[i+j]=b[j];
	for(k=0;c[k]!='\0';k++) mainchr[i+j+k]=c[k];
	mainchr[i+j+k]='\0';
	return mainchr;
};

// return 1,2,3,...num
int rannum(int num)		
{
	int nm;
	int muti=RAND_MAX/num;
	do{nm=rand();}while(nm>=muti*num);
	return ((nm%num)+1);
}

/***********************************************
Function name: bound
Description: Whether encounter a boundary or not
Input
pos_c: current column postion index
pos_r: current row postion index
cow: total columns
row: total rows
Output
1: no boundary
0: has boundary
***********************************************/
int bound(int pos_c,int pos_r,int cow,int row)
{
	if(pos_c<0)return 0;
	if(pos_r<0)return 0;
	if(pos_c>=cow)return 0;
	if(pos_r>=row)return 0;
	return 1;
};

/***********************************************
Function name: trans
Description: Mating two flowers randomly
Input
transfer: index of the genes in a flower, namely AA, Aa or aa
Output
0: a
1: A
***********************************************/
int trans(int transfer)
{
	if(transfer==2) return 1;	// A
	if(transfer==0) return 0;	// a
	return (rannum(2)-1);		// A or a
};

// 4-neighbour
int posi41(int pos_num,int row_col) // the first adjacent edge
{
	if (row_col==1)
	{
		if(pos_num==1)return -1;	else
		if(pos_num==2)return 0;		else
		if(pos_num==3)return 1;		else
		if(pos_num==4)return 0;		else 
		{System::Console::WriteLine("error pos41");system("PAUSE");}
	};
	if (row_col==2)
	{
		if(pos_num==1)return 0;		else
		if(pos_num==2)return 1;		else
		if(pos_num==3)return 0;		else
		if(pos_num==4)return -1;	else
		{System::Console::WriteLine("error pos41");system("PAUSE");}
	};
	{System::Console::WriteLine("error pos41");system("PAUSE");}
};

// 4-neighbour
int posi42(int pos_num,int row_col) // the second adjacent edge
{
	if (row_col==1)
	{
		if(pos_num==1)return -2;	else
		if(pos_num==2)return -1;	else
		if(pos_num==3)return 0;		else
		if(pos_num==4)return 1;		else
		if(pos_num==5)return 2;		else
		if(pos_num==6)return 1;		else
		if(pos_num==7)return 0;		else
		if(pos_num==8)return -1;	else
		{System::Console::WriteLine("error pos42");system("PAUSE");}
	};
	if (row_col==2)
	{
		if(pos_num==1)return 0;		else
		if(pos_num==2)return 1;		else
		if(pos_num==3)return 2;		else
		if(pos_num==4)return 1;		else
		if(pos_num==5)return 0;		else
		if(pos_num==6)return -1;	else
		if(pos_num==7)return -2;	else
		if(pos_num==8)return -1;	else
		{System::Console::WriteLine("error pos42");system("PAUSE");}
	};
	{System::Console::WriteLine("error pos42");system("PAUSE");}
};




// 6-neighbour
int posi61(int pos_num,int i_pos,int row_col)
{
	if(row_col==1)
	{
		if(pos_num==1)return -1;else
		if(pos_num==2)return -1;else
		if(pos_num==3)return 0;	else
		if(pos_num==4)return 1;	else
		if(pos_num==5)return 1;	else
		if(pos_num==6)return 0;
	};
	if(row_col==2)
	{
		if(pos_num==3)return 1;	else
		if(pos_num==6)return -1;

		if(i_pos%2==0)
		{
			
			if(pos_num==1)return -1;else
			if(pos_num==2)return 0;	else
			if(pos_num==4)return 0;	else
			if(pos_num==5)return -1;
		};
		if(i_pos%2==1)
		{
			if(pos_num==1)return 0;	else
			if(pos_num==2)return 1;	else
			if(pos_num==4)return 1;	else
			if(pos_num==5)return 0;
		};
	};
};

// 6-neighbour
int posi62(int pos_num,int i_pos,int row_col)
{
	if(row_col==1)
	{
		if(pos_num==1)return -2;
		if(pos_num==2)return -2;
		if(pos_num==3)return -2;
		if(pos_num==4)return -1;
		if(pos_num==5)return 0;
		if(pos_num==6)return 1;
		if(pos_num==7)return 2;
		if(pos_num==8)return 2;
		if(pos_num==9)return 2;
		if(pos_num==10)return 1;
		if(pos_num==11)return 0;
		if(pos_num==12)return -1;
	};
	if(row_col==2)
	{
		if(pos_num==1)return -1;
        if(pos_num==2)return 0;
        if(pos_num==3)return 1;
		if(pos_num==5)return 2;
		if(pos_num==7)return 1;
		if(pos_num==8)return 0;
		if(pos_num==9)return -1;
		if(pos_num==11)return -2;
		if(i_pos%2==0)
		{
			if(pos_num==4)return 1;
			if(pos_num==6)return 1;
			if(pos_num==10)return -2;
			if(pos_num==12)return -2;
		};
		if(i_pos%2==1)
		{
			if(pos_num==4)return 2;
			if(pos_num==6)return 2;
			if(pos_num==10)return -1;
			if(pos_num==12)return -1;
		};
	};
};




// 8-neighbour
int posi81(int pos_num,int row_col)
{
	if(row_col==1)
	{
		if(pos_num==1) return -1;else
		if(pos_num==2) return -1;else
		if(pos_num==3) return -1;else
		if(pos_num==4) return  0;else
		if(pos_num==5) return  1;else
		if(pos_num==6) return  1;else
		if(pos_num==7) return  1;else
		if(pos_num==8) return  0;
	};
	if(row_col==2)
	{
		if(pos_num==1) return -1;else
		if(pos_num==2) return  0;else
		if(pos_num==3) return  1;else
		if(pos_num==4) return  1;else
		if(pos_num==5) return  1;else
		if(pos_num==6) return  0;else
		if(pos_num==7) return -1;else
		if(pos_num==8) return -1;
	}

};

// 8-neighbour
int posi82(int pos_num,int row_col)
{
	if(pos_num==1) return -2;else
	if(pos_num==9) return  2;else

	if(row_col==1)
	{
		if(pos_num==2 ) return -2;else
		if(pos_num==3 ) return -2;else
		if(pos_num==4 ) return -2;else
		if(pos_num==5 ) return -2;else
		if(pos_num==6 ) return -1;else
		if(pos_num==7 ) return  0;else
		if(pos_num==8 ) return  1;else
		if(pos_num==10) return  2;else
		if(pos_num==11) return  2;else
		if(pos_num==12) return  2;else
		if(pos_num==13) return  2;else
		if(pos_num==14) return  1;else
		if(pos_num==15) return  0;else
		if(pos_num==16) return -1;
	};
	if(row_col==2)
	{
		if(pos_num==2 ) return -1;else
		if(pos_num==3 ) return  0;else
		if(pos_num==4 ) return  1;else
		if(pos_num==5 ) return  2;else
		if(pos_num==6 ) return  2;else
		if(pos_num==7 ) return  2;else
		if(pos_num==8 ) return  2;else
		if(pos_num==10) return  1;else
		if(pos_num==11) return  0;else
		if(pos_num==12) return -1;else
		if(pos_num==13) return -2;else
		if(pos_num==14) return -2;else
		if(pos_num==15) return -2;else
		if(pos_num==16) return -2;
	};
};