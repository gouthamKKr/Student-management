#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<ctype.h>
#include<string.h>
#include<dos.h>
#include<math.h>

void getfee1();
void changefee1();
void payfees1();
void checkfees1();
void showstudfee1();
void putpayfees(int);
void showstudfee(int);

void writestudfee(int,char[]);
int flagG=1,flagF=1;

int programmenu()
{   
	clrscr();
	int mc;
	cout<<"\tSTUDENT MANAGEMENT\n";
	cout<<"\n............................";
	cout<<"\n:                          :";
	cout<<"\n:    1. Fee menu           :";
	cout<<"\n:    2. Student's menu     :";
	cout<<"\n:    3. EXIT               :";
	cout<<"\n:                          :";
	cout<<"\n:..........................:";
	cout<<"\n\nEnter your choice\n";
	cin>>mc;
	return mc;
}

class student
{
	int admno;
	char name[25];
	char   stream[15];
	char   substream[6];

 public:
	
	void addstudent(int a)
	{
		clrscr();
		admno=a;
		cout<<"Student name"; gets(name);
		cout<<"stream :"; gets(stream);
		if(strcmpi(stream,"commerce")==0)
		{
			cout<<"\nEnter the substream(IP/EP/Maths)\n";
			cin>>substream;
			if(strcmpi(substream,"IP")==0)
			strcat(stream,"-IP");
			else if(strcmpi(substream,"EP")==0)
			strcat(stream,"-EP");
			else if(strcmpi(substream,"Maths")==0)
			strcat(stream,"-Maths");
		}
		writestudfee(admno,stream);
	}
	
	    void displaystudent(void)   
    {
		cout<<"\n Admission No   : ";  cout<<admno;
		cout<<"\n Name           : ";  cout<<name;
		cout<<"\n Stream         : ";  cout<<stream;

	}


	int  retadmno()      {return admno;}			//function retadmno is called
	char* retname()       {return name;}
	char* retstream()     {return stream;}
};

void writestudent(void)
 {

     int x1;
	 char ch2;

	    fstream fp("student.DAT",ios::binary|ios::out|ios::in|ios::ate); ///file opening

	    if(!fp)
	    {
	      cout<<"\nFile opening ERROR!!!!";
	      getch();
	      exit (0);
	    }
	 while(flagG)
	 {
	     clrscr();
	     student S,S1; ///S :for returning the admission number of existing student (if any)
					   ///S1:for gettinf and writng a student data

		///cheking for presence of already existing student data......
	     if(fp.tellp()==0)
		    x1=1031;            ///Intiaialising admission number

	     else
		{
		  fp.seekp(fp.tellg()-sizeof(S));
		  fp.read((char*)&S,sizeof(S));
		  x1=S.retadmno();
		  x1+=1;                      ///Determining admission number
		}

		 S1.addstudent(x1);
		 fp.write((char*)&S1,sizeof(S1));
		 cout<<"\nDo you want to add another student(Y/N):";
		 ch2=getche();
		 ch2=tolower(ch2);
		 while(ch2!='y' && ch2!='n')  /// checking for yes or no only(rest is avoided)
		 {
			cout<<"\nYou have entered a wrong choice";
			cout<<"\nRE-Enter choice(Y/N):";
			ch2=getche();
		 }
		 if(ch2=='n')
			flagG=0;

	  }
  flagG=1;
  fp.close();   ///File closing
 }


void writestreamfee(void);

/** class fee is to store the whole basic details of fees for a particlar class**/
class fee                                ///class definition for class fee
{
	/// variables of class fee to store the fee datas
	int establish;
	int exam,library,PT,ID,medical;
	int laboratory,computer,caution;
	int total,tution,std;
	
	
	
	public:
	
	void getfee();                       ///getfee() is a function to get the fee details  @function1
	void changefee();                    ///changefee() is to modify the already enterd fee datas 
	
    ///ACCESSOR FUNCTIONS............................. 
    int retestablish()  {return establish;}			//
	int retexam()       {return exam;}				//
	int retlibrary()    {return library;}			//
	int retPT()         {return PT;}				//
	int retID()         {return ID;}				//
	int retmedical()    {return medical;}			//
	int retlaboratory() {return laboratory;}		//
	int retcomputer()   {return computer;}			//
	int retcaution()    {return caution;}			//
	int rettution()     {return tution;}			//
	int rettotal()      {return total;}				//
	///...............................................
};                                       ///END OF CLASS#####

void fee::changefee()
{
	int sfm;
	cout<<"  :----------------------------------:";
	cout<<"\n:          Fee Details             :";
	cout<<"\n:__________________________________:"<<endl;
	cout<<"\n 1. Class                : ";  cout<<std;
	cout<<"\n 2. Establishment Fee    : ";  cout<<establish;
	cout<<"\n 3. Exam Fee             : ";  cout<<exam;
	cout<<"\n 4. Library Fee          : ";  cout<<library;
	cout<<"\n 5. Sports & Games       : ";  cout<<PT;
	cout<<"\n 6. ID card              : ";  cout<<ID;
	cout<<"\n 7. Medical Fee          : ";  cout<<medical;
	cout<<"\n 8. Laboratory Fee       : ";  cout<<laboratory;
	cout<<"\n 9. Computer Fee         : ";  cout<<computer;
	cout<<"\n 10.Caution Deposit      : ";  cout<<caution;
	cout<<"\n 11.Tution Fee           : ";  cout<<tution;
	cout<<"\n\nEnter the field to change";
	cin>>sfm;
	
	switch(sfm)
	{
		case 1 : cout<<"Enter the Class : "; cin>>std; break;
		case 2 : cout<<"Enter the Establishment Fee : "; cin>>establish; break;
		case 3 : cout<<"Enter the Exam Fee : "; cin>>exam; break;
		case 4 : cout<<"Enter the Library Fee : ";  cin>>library; break;
		case 5 : cout<<"Enter the Sports & Games fee : ";  cin>>PT; break;
		case 6 : cout<<"Enter the fee for ID card : ";  cin>>ID; break;
		case 7 : cout<<"Enter the Medical Fee : ";  cin>>medical; break;
		case 8 : cout<<"Enter the Laboratory Fee : ";  cin>>laboratory; break;
		case 9 : cout<<"Enter the Computer Fee : ";  cin>>computer; break;
		case 10: cout<<"Enter the Caution Deposit : ";  cin>>caution; break;
		case 11: cout<<"Enter the Tution Fee : ";  cin>>tution; break;
	}

}
void fee::getfee(void)               ///Definition for function1 to enter the fee datas
{
	clrscr();
	cout<<"  :----------------------------------:";
	cout<<"\n:  Enter the fee details           :";
	cout<<"\n:__________________________________:"<<endl;
	cout<<"\n 1. Class                : ";  cin>>std;
	cout<<"\n 2. Establishment Fee    : ";  cin>>establish;
	cout<<"\n 3. Exam Fee             : ";  cin>>exam;
	cout<<"\n 4. Library Fee          : ";  cin>>library;
	cout<<"\n 5. Sports & Games       : ";  cin>>PT;
	cout<<"\n 6. ID card              : ";  cin>>ID;
	cout<<"\n 7. Medical Fee          : ";  cin>>medical;
	cout<<"\n 8. Laboratory Fee       : ";  cin>>laboratory;
	cout<<"\n 9. Computer Fee         : ";  cin>>computer;
	cout<<"\n 10.Caution Deposit      : ";  cin>>caution;
	cout<<"\n 11.Tution Fee           : ";  cin>>tution;

}

void writefee(void)           ///function to call getfee()[function1] and write object of fee to file
{
	ofstream fout("fee.DAT",ios::in|ios::binary|ios::end); ///opening fee.DAT file
	if(!fout)                    ///checking for correct opening of file fee.DAT
	{cout<<"File not opened correctly";    getch();   exit (0);}

	fee F;                       ///object of class fee

	F.getfee();                 //calling #function1#
	fout.write((char*)&F,sizeof(F)); ///writing object to file

	fout.close();         ///file closing
	writestreamfee();  //calling unction to set fees of each stream
}

void rewritefee(void)   ///function to  call changefee and write the updated data to file 
{
	fstream fp("fee.DAT",ios::in|ios::binary|ios::out||ios::app); ///opening fee.DAT file
	if(!fp)                ///checking for correct opening of file fee.DAT
	{cout<<"File not opened correctly";    getch();   exit (0);}
	
	fee F;                    ///object of class fee
	
	if(fp.tellp()==0)         ///checking if any data is available in fee.DAT
	{cout<<"No fee data available to change";}
	
	else
	{                      ///reading and writing updated fee data
		fp.read((char*)&F,sizeof(F));
		F.changefee();  //calling #function2#
		fp.write((char*)&F,sizeof(F));
	}
	
	fp.close();    ///fee.DAT closng
	writestreamfee(); //calling unction to set fees of each stream
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/**To store the details of each streams individually**/
class streamfees
 {
	 ///Variables to store the fee details of each stream
	 int streamno;
	 char streamf[15];
	 int initial;
	 int payfee;
	 int schoice;



   public:

	 /**to set the fee according to streams**/
	 void getstreamfee(int afee)
	 {
		 switch(afee)     ///to assign the stream according to stream number
		 {
			 case 1:strcpy(streamf,"Bio-Maths"); streamno=afee;
			 case 2:strcpy(streamf,"Bio-IP"); streamno=afee;
			 case 3:strcpy(streamf,"Computer"); streamno=afee;
			 case 4:strcpy(streamf,"Commerce-IP"); streamno=afee;
			 case 5:strcpy(streamf,"Commerce-EP/Maths"); streamno=afee;
		 }

		 ifstream fin("fee.DAT",ios::in||ios::binary);
		 fee F;
		 fin.read((char*)&F,sizeof(F));

		 ///calcuating initial amount to be paid
		 initial=F.retestablish()+F.retexam()+F.retlibrary()+F.retPT()+F.retID()+F.retmedical()+F.retcaution();

    /**Assingment of fees of initial and each term..**/
	/**/	 payfee=F.rettution();					///
	/**/	 										///
	/**/	 switch(afee)///
	/**/	     {
		       case 1:
		       case 2:
		       case 3:	initial+=F.retlaboratory();break;
		     }		///
	/**/	 										///
	/**/	 										///
	/**/	 										///
	/**/	 if(afee==2||afee==3||afee==4)			///
	/**/       { payfee+=F.retcomputer();}			///
	/**............................................**/
		 fin.close();
	 }

		 
	
	///ACCESSOR FUNCTIONS.........................
	 int retinitial()   {return initial;}		//
     int retpayfee()    {return payfee;}		//
	 int retstreamno()  {return streamno;}		//
	 char* retstreamf() {return streamf;}		//
	///........................................... 
 };
 
 
void writestreamfee(void)
{
  ofstream temp("temp.DAT",ios::out||ios::binary||ios::app);
  if(!temp)
	{cout<<"File not opened correctly";    getch();   exit (0);}
  
  
  else
  {
	for(int i=0;i<5;i++)
	{
		streamfees F1;
		F1.getstreamfee(i+1);
		temp.write((char*)&F1,sizeof(F1));	
	}
  }
  temp.close();
  remove("streamfee.DAT");
  rename("temp.DAT","streamfee.DAT");
}
	



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


/**class to store the data of students individually**/

class studfee
{
	///Variables of studfee class
	int admnos;
	int streamnos;   ///stream number based on stream of student according to table in the class streamfees
	char initials;   ///to store payment of initial amounts
	char terms[3];   ///to store payment of each term

  public:

	/**Constructor of class studfee **/
	studfee(int admission,char streams[15])
	{
		admnos=admission;
		///Determining the stream number based on stream of student
		if(strcmpi(streams,"Bio-Maths")==0)
			streamnos=1;
		else if(strcmpi(streams,"Bio-IP")==0)
			streamnos=2;
		else if(strcmpi(streams,"computer")==0)
			streamnos=3;
		else if(strcmpi(streams,"Commerce-IP"))
			streamnos=4;
		else
			streamnos=5;

		///initialising initial,term1,term2,term3 as 'N'  meaning fees is not paid
		for(int i=0;i<3;i++)
			terms[i]='N';
		initials='N';
	}

	studfee(){}

	/**Function to check the payment details of student ::Dispalys 'Paid'/'Not Paid' on status of payment**/
	void checkfee()
	{
		if(initials=='N')
			cout<<"Initial Amount: Not paid";
		else
			cout<<"Initial Amount: Paid";

		for(int i=0;i<3;i++)
		{
			if(terms[i]=='N')
				cout<<" Term-"<<i+1<<" Fee: Not Paid"<<endl;

			else
				cout<<" Term-"<<i+1<<" Fee: Paid"<<endl;
		}
		getch();
	}

	/**To pay fees of a student::Entering Y for paid and N for not paid**/
	void payfee(int aterm)  /// aterm is for term number
	{
		char paychoice;
		if(initials=='N')         ///if initial amount is not paid it must be paid first
		{
			cout<<"Initial amount not paid\nAsk to pay";   getch();
			cout<<"Has the amount paid(Y/N)";
			cin>>paychoice;
			if(toupper(paychoice)!='Y')
				return;
		}


		if(toupper(terms[aterm])=='Y')
		{
			cout<<"Term fee already paid";
		}


		else
		{
			cout<<"Has amount paid(Y/N)";
			cin>>paychoice;
			if(tolower(paychoice)=='y')
				terms[aterm]='Y';
		}
	}

	/**to show the amounts to be payable by student**/


	///ACCESSOR FUNCTIONS.....................
	int retadmnos()  {return admnos;}		//
	char retterm1()  {return terms[0];}		//
	char retterm2()  {return terms[1];}		//
	char retterm3()  {return terms[3];}		//
 ///.......................................
};

void showstudfee(int a)
	{
		ifstream fin("streamfee.DAT",ios::in||ios::binary);
		streamfees F;
		if(!fin){cout<<"File opening ...ERROR....."; getch(); exit (0);}

		while(fin)
		{
			fin.read((char*)&F,sizeof(F));

			if(F.retstreamno()==a)
			{
				clrscr();
				///Displayig the amounts to be paid
				cout<<"\nPayable by student at starting of year :"<<F.retinitial()<<" Rs";
				cout<<"\nFees in each term                      :"<<F.retpayfee()<<" Rs";
				getch();
			}
		}
		fin.close();
	}
/**funtion t create an object of sutdfee and write to file studfee.DAT**/
void writestudfee(int no,char string[15])
{
	studfee S(no,string);            ///creating object of studfee
	ofstream fout("studfee.DAT",ios::in||ios::binary||ios::app);  ///opening file studfee.DAT to write student fee details
	fout.write((char*)&S,sizeof(S)); ///writing feedata to file 
	fout.close();            ///studfee.DAT closing statement
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


int studfeemenu(void)
{
	int sfm;
	cout<<"\n\t......................................";
	cout<<"\n\t:            FEE MENU                :";
	cout<<"\n\t:....................................:";
	cout<<"\n\t:                                    :";
	cout<<"\n\t:    1. Pay student's fee            :";
	cout<<"\n\t:    2. Check payment status         :";
	cout<<"\n\t:    3. Check payment amount         :";
	cout<<"\n\t:    4. GO BACK                      :";
	cout<<"\n\t:    5. EXIT                         :";
	cout<<"\n\t:....................................:";
	cout<<"\n\n\t Enter your choice";
	cin>>sfm;
	return sfm;
}

int officefeemenu(void)
{
	int sfm;
	cout<<"\n\t......................................";
	cout<<"\n\t:            FEE MENU                :";
	cout<<"\n\t:....................................:";
	cout<<"\n\t:                                    :";
	cout<<"\n\t:    1. Enter a new fee structure    :";
	cout<<"\n\t:    2. Edit current fee structure   :";
	cout<<"\n\t:    3. GO BACK                      :";
	cout<<"\n\t:    4. EXIT                         :";
	cout<<"\n\t:....................................:";
	return sfm;
}

void studfeeprg(void)
{
	int feeprg;
	flagF=1;
	while(flagF)
	{
		feeprg=studfeemenu();
		switch(feeprg)
		{
			case 1: payfees1();    break;
			case 2: checkfees1();  break;
			case 3: showstudfee1();break;
			case 4: flagF=0;       break;
			case 5: exit (0);
			default:cout<<"WRONG CHOICE?????? ...PRESS ENTER.......";
		}
	}
	flagF=1;
}


void officefeeprg(void)
{
	int feeprg;
	flagF=1;
	while(flagF)
	{
		switch(feeprg)
		{
			case 1:getfee1();      break;
			case 2:changefee1();   break;
			case 3:flagF=0;        break;
			case 4: exit(0);
			default:cout<<"WRONG CHOICE?????? ...PRESS ENTER.......";
		}
	}
	flagF=1;
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

char Searchstudenta(int adm)
{
	
	clrscr();
	char ch3;
	ifstream fin("student.DAT",ios::in||ios::binary);
	student S;
	while(fin.read((char*)&S,sizeof(S)))
	{
		if(adm==S.retadmno());
		S.displaystudent();
		cout<<"Is this the required student(Y/N)";
		cin>>ch3;
		if(tolower(ch3)=='y')
		{ 
			fin.close();
			return ch3;
		}
		
		else
		{
			ch3='n';
			fin.close();
			return ch3;
		}
	}
	ch3='n';
	fin.close();
	return ch3;
}
	
int Searchstudentn(char A[25])
{
	int a;
	clrscr();
	char ch3;
	ifstream fin("student.DAT",ios::in||ios::binary);
	student S;
	while(fin.read((char*)&S,sizeof(S)))
	{
		if(strcmpi(A,S.retname())==0)
		{
			S.displaystudent();
			cout<<"Is this the required studeent";
			if(tolower(ch3)=='y')
				a=S.retadmno();
			fin.close();
			return a;
		}
	}
	fin.close();
	return (0);
}
	

void putpayfees(int n)
{
	clrscr();
	int a;
	ifstream fin("studfee.DAT",ios::in||ios::binary);
	ofstream fout("temp.DAT",ios::out||ios::binary);
	studfee F;
	while(fin.read((char*)&F,sizeof(F)))
	{
		if(F.retadmnos()==n)
		{
			cout<<"Enter the Term of fee to be paid";
			cin>>a;
			F.payfee(a);
		}
		fout.write((char*)&F,sizeof(F));
	}
	fin.close();
	fout.close();
	remove("studfee.DAT");
	rename("temp.DAT","studfee.DAT");
}


void payfees1(void)
{
	char chp;
	int sfm;
	int adm;
	flagG=1;
	char A[25];
	while(flagG)
	{
		cout<<"\nGet student by:";
		cout<<"\n    1. Admission Number";
		cout<<"\n    2. Name";
		cout<<"\n    3. GO BACK";
		cin>>sfm;


		if(sfm==1)
		{
			cout<<"\nEnter the admission number";
			cin>>adm;
			chp=Searchstudenta(adm);
			if(chp=='y')
				putpayfees(adm);
			else
				cout<<"Student not Found";
		}

		if(sfm==2)
		{       cout<<"\nEnter the name of student: "; gets(A);
			adm=Searchstudentn(A);
			if(adm!=0)
				putpayfees(adm);
			else
				cout<<"Student not Found";
		}
	
		else if(sfm==3)
			flagG=0;
			
		else
		{
			cout<<"\nWRONG CHOICE......TRY AGAIN....";
			getch();
		}
		
   }
   flagG=1;
}
	

void checkfees(int a)
{
	ifstream fin("studfee.DAT",ios::in||ios::binary);
	studfee S;
	while(fin.read((char*)&S,sizeof(S)))
	{
		if(S.retadmnos()==a)
		{
			S.checkfee();
			return;
		}
	}	
	
}	

void checkfeestud(int n)
{
	
}
void showstudfee1(void)
{
  while(1)
  {
	int sno; 
	cout<<"\n\t..............................";
	cout<<"\n\t:            STREAM          :";
	cout<<"\n\t:----------------------------:";
	cout<<"\n\t:   							:";
	cout<<"\n\t:   1. Bio-Maths				:";
	cout<<"\n\t:   2. Bio-IP				:";
	cout<<"\n\t:   3. Computer				:";
	cout<<"\n\t:   4. Commerce-IP			:";
	cout<<"\n\t:   5. Commerce-EP/Maths 	:";
	cout<<"\n\t:   6. GO BACK				:";
	cout<<"\n\t:............................:"<<endl;
	cin>>sno;
	
	if(sno==6)
		return;
	
	switch(sno)
	{
		case 1: 
		case 2:
		case 3:
		case 4:
		case 5: showstudfee(sno); break;
		default: cout<<"\n WRONG CHOICE?????...TRY AGAIN......";
	}
  }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void checkfees1(void)
{
	int ckf;
	char chp;
	int adm;
	char A[25];

	while(flagG)
	{
		cout<<"\nGet student by:";
		cout<<"\n1.Admission number";
		cout<<"\n2.Name";
		cout<<"\n3.GO BACK";
		cin>>ckf;
		if(ckf==1)
		{
			cout<<"\nEnter the admission number";
			cin>>adm;
			chp=Searchstudenta(adm);
			if(chp=='y')
				checkfees(adm);                    /*function call*/   ///function not written
			else
				cout<<"Student not Found";
		}

		else if(ckf==2)
		{       cout<<"\nEnter the student name: "; gets(A);
			adm=Searchstudentn(A);
			if(adm!=0)
				checkfees(adm);                       /*function call*/   ///function not written
			else
				cout<<"Student not Found";
		}

		else if(ckf==3)
			flagG=0;

		else
		{
			cout<<"\nWRONG CHOICE......TRY AGAIN....";
			getch();
		}
	}
	flagG=1;
}	
	

void getfee1()
{
	cout<<"***************************************";
	getch();
	clrscr();
}

void changefee1()
{
	cout<<"***************************************";
	getch();
	clrscr();
}


void feeprg(void)
{
	int fpg;
	while(1)
	{
		cout<<"\n\t..................................";
		cout<<"\n\t:         FEE MENU				:";
		cout<<"\n\t:--------------------------------:";
		cout<<"\n\t:								:";
		cout<<"\n\t:     1. FEE RECORD(OFFICE)  	:";
		cout<<"\n\t:     2. STUDENTS FEE MENU    	:";
		cout<<"\n\t:     3. GO BACK					:";
		cout<<"\n\t:................................:";

		cout<<"\n\tEnter yor choice "; cin>>fpg;

		if(fpg==3)
			return;

		switch(fpg)
		{
			case 1: officefeeprg(); break;
			case 2: studfeeprg();   break;
			default: cout<<"WRONG CHOICE????????????????  ...TRY AGAIN.....";
		}
	}
}

void studentprg(void)
{
	writestudent();
}

void main()
{
	int choiceM;
	while(1)
	{
		choiceM=programmenu();
		switch(choiceM)
		{
			case 1: feeprg();
			case 2: studentprg();
			case 3: return;
			default: clrscr(); cout<<"\n\tWRONG CHOICE????????   ...TRY AGAIN..........";
		}

	}
}
