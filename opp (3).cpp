#include<iostream>
#include<fstream>
using namespace std;

class person{
	public:
		// Attributes
	string name,surename,gender;
	int age;
		public:
		// SETTERS
		void set_name(string n)
		{
			name=n;
		}
		void set_surname(string s)
		{
			surename=s;
		}
		void set_gender(string g)
		{
			gender=g;
		}
		void set_age(int a)
		{
			age=a;
		}
		
		//GETTERS
		string get_name()
		{
			return this->name;
		}
		string get_surename()
		{
	      return this->surename;
		}
        string get_gender()
        {
        	return this->gender;
		}
		int get_age()
		{
			return this->age;
		}
};

class active{
   // Attributes
   public:
   static string data_file;
   string sickness,doctor;
   int idp;
   
   	// GETTERS
   	void set_doct(string n)
   	{
   		this->sickness=n;
	}
	void set_item_id(string i)
	{
		this->doctor=i;
	}
	void set_si(int p)
	{
		this->idp=p;
	}
	// SETTERS
	string get_sickn()
	{
		return this->sickness;
	}
	string get_rdoc()
	{
		return this->doctor;
	}
	int get_med()
	{
		return this->idp;
	}
    
	string get_data_file()
	{
			return this->data_file;
	}
};


class patient:public person{
     // Attributes
	 static string data_file;
	 string c_id;
     public:
     	// GETTERS
     	active p;
		 void set_paid(string s)
     	{
     		this->c_id=s;
		}
		//SETTERS
        string get_patid()
        {
        	return this->c_id;
		}
		string get_data_file()
		{
			return this->data_file;
		}

};

string patient :: data_file="patient";
string active :: data_file="active";


class data{
	public:
	patient C[100];
	active P[100];
	int psize,csize;
	data()
	{  
	    
	   string c_id,name,sure,gend,iname,iid;
	   int me,age;
	   ifstream cfile;
	   cfile.open("patient.txt");
	   
	   if(cfile){
	   	int i=0;
		while(!cfile.eof())
	   	{   // READING patient RECORD FROM DATA FILE patient.TXT
	   		csize=i;
			cfile>>c_id>>name>>sure>>gend>>age>>iid>>iname>>me;
	   	    C[i].set_age(age);C[i].set_paid(c_id);C[i].set_gender(gend);C[i].set_name(name);C[i].set_surname(sure);
			C[i].p.set_item_id(iid);C[i].p.set_doct(iname);C[i].p.set_si(me);
			i++;
			
		}
	   }
	   else
	   cout<<"ERROR IN CUSTOMR FILE";
	   cfile.close();
	   
	   ifstream pfile;
	   pfile.open("products.txt");
	   
	   if(pfile){
		int x=0;
		while(!pfile.eof())
	   	{   // READING active RECORD FROM DATA FILE active.TXT
	   		psize=x;
			pfile>>iid>>iname>>me;
	        P[x].set_item_id(iid);P[x].set_doct(iname);P[x].set_si(me); 		
			x++;
			
			
		}
		
	   }
	   pfile.close();
	}
	
	
	void showpat()
	{   
		for(int i=0;i<=psize;i++)
		{
			cout<<P[i].get_rdoc()<<"\t"<<P[i].get_sickn()<<"\t"<<P[i].get_med()<<endl;
		}
	}
	
    void showp()
    {
    	for(int i=0;i<=csize;i++)
		{
			cout<<C[i].get_age()<<"\t"<<C[i].gender<<"\t"<<C[i].get_patid()<<"\t"<<
			C[i].get_gender()<<"\t"<<C[i].get_name()<<"\t"<<C[i].get_surename()<<endl;
		}
	}

	void searchp(){
		string s;
    	cout<<" ENTER ID ";
    	cin>> s;
    	for(int i=0;i<=csize;i++)
    	{
    		if(C[i].get_patid()==s)
    		{
			cout<<P[i].get_rdoc()<<"\t"<<P[i].get_sickn()<<"\t"<<P[i].get_med()<<endl;
    		return;
			}
		}
		cout<<"Record not found ";
	}
	
	void add()
	{   string c_id,name,sure,gend,iname,iid;
	    int sickness,age;
		cout<<"Entre patient id ";
	    cin>>c_id;
		cout<<"entre name  ";
		cin>>name;
		cout<<"entre surename  ";
		cin>>sure;
		cout<<"Entre gender ";
		cin>>gend;
		cout<<"Entre doctor name ";
		cin>>iname;
		cout<<"Entre sickness ";
		cin>>iid;
		cout<<"Entre age";
		cin>>age;
		cout<<"Enter medicine ";
		cin>>sickness;
		csize++;
		C[csize].set_age(age);C[csize].set_paid(c_id);C[csize].set_gender(gend);C[csize].set_name(name);
		C[csize].set_surname(sure);C[csize].p.set_item_id(iid);C[csize].p.set_doct(iname);C[csize].p.set_si(sickness);
	    
	}
  
    void delet()
    {   string s;
    	cout<<"Entre ID";
    	cin>>s;
    	int i=0;
		for( i=0;i<=csize;i++)
    	{
    		if(C[i].get_patid()==s)
    		{
			 break;
			}
		}
		while(i<csize)
		{
			C[i]=C[i+1];
			i++;
		}
		csize--;
	}
	
	
	void upadate()
	{
		string c_id,name,sure,gend,iname,iid;
	    int sickness,age;
	    string s;
    	cout<<"Entre ID";
    	cin>>s;
		for(int i=0;i<=csize;i++){
		if(C[i].get_patid()==s)
		{
		
		cout<<"Entre patient id ";
	    cin>>c_id;
		cout<<"entre name  ";
		cin>>name;
		cout<<"entre surename  ";
		cin>>sure;
		cout<<"Entre gender ";
		cin>>gend;
		cout<<"Entre doctor name ";
		cin>>iname;
		cout<<"Entre sickness ";
		cin>>iid;
		cout<<"Entre age";
		cin>>age;
		cout<<"Enter medicine ";
		cin>>sickness;
		C[i].set_age(age);C[i].set_paid(c_id);C[i].set_gender(gend);C[i].set_name(name);
		C[i].set_surname(sure);C[i].p.set_item_id(iid);C[i].p.set_doct(iname);C[i].p.set_si(sickness);
	     return;
	    }
	  }
	}
	
   void menu()
   { char c;
    while(true){
	
	system("cls");
   	cout<<"1.ADD patient\n";
   	cout<<"2.Show patient\n";
   	cout<<"3.Show active patient\n";
   	cout<<"4.Search patient\n";
   	cout<<"5.Delete patient\n";
   	cout<<"6.Update patient\n";
    cout<<"7.EXIT\n";
	cout<<"Entre choice ";
   cin>>c;
   switch(c)
   {
   	case'1':
   		system("cls");
   		this->add();
   		system("pause");
   		break;
   	case '2':
   		system("cls");
   		this->showp();
   		system("pause");
   		break;
   case '3':
   	    system("cls");
   		this->showpat();
   		system("pause");
   		break;
   case '4':
   	system("cls");
   		this->searchp();
   		system("pause");
   		break;
   	case '5':
   		system("cls");
   		this->delet();
   		system("pause");
   		break;
   	case '6':
   		system("cls");
   		this->upadate();
   		system("pause");
   		break;
   	case '7':
   		exit(1);
	   default:
   		break;
   }
   }
   }
};

int main()
{
	data D;
    	D.menu();
}
