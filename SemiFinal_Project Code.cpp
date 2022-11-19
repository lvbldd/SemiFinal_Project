//C++ source code and sample
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("SemiFinal.txt");
    if(!fin.is_open())
    {
        cout<<"Cannot Open File"<<endl;
        exit(1);
    }
    cout<<"---------------------------------------"<<endl;
	cout<<"         Semi-Final Project"<<endl;
	cout<<"---------------------------------------"<<endl;
	
    
//   user input variables;              //formula variables
    int customer;                	float cartTime; 
    int items[10];          		float scanTime; 
    int packaging[10];         		float packTime;  
    string choice[10];      		float payingTime;  
    string method[10];       		float printTime; 
    string value[10];       		float TidleTime;   
                                 	float TotalQueuetime;
                                 	float FtotalQueuetime;
	


    //take input from the user 
    fin>>customer;

    
    //loop used to display the 3 customers
    for(int a=1;a<=customer;a++)
    {
        fin>>items[a]>>choice[a]>>packaging[a]>>method[a];
        {
            if(method[a]=="cash")
            {
                fin>>value[a];
            }
        }
    }
    
    cout<<customer<<endl;
    for(int a=1;a<=customer;a++)
    {
        cout<<items[a]<<" "<<choice[a]<<" "<<packaging[a]<<" "<<method[a]<<" "<<endl;
        if(method[a]=="cash")
        {
            cout<<value[a]<<endl;
        }
        cout<<endl;
    }


	
    for(int a=1;a<=customer;a++)
    {
	
	    //print out the reciept
        cout<<"Customer :#"<<a<<""<<endl;
        cout<<"Number of Cart Items: "<<items[a]<<endl;
        if(choice[a]=="box")
        {
            cout<<"Preferred Packaging: box"<<endl;
            cout<<"Number of Boxes:"<<packaging[a]<<endl;
        }
        
        if(choice[a]=="bag")
        {
            cout<<"Preferred Packaging: bag"<<endl;
            cout<<"Number of Bags:"<<packaging[a]<<endl;
        }
        
        if(method[a]=="cash")
        {
            if(value[a]=="exact")
            {
                cout<<"Preferred Method: cash(exact)"<<endl;    
            }
            if(value[a]=="notexact")
            {
                cout<<"Preferred Method: cash(not exact)"<<endl;
            }
        }
        
        if(method[a]=="digital")
        {
            cout<<"Preferred Payment Method: digital"<<endl;
        }
        
        
     //given variables   
   #define tocasher 
   #define scanItems 
   #define toPack 
   #define packBox 
   #define packBag 
   #define byCard 
   #define exact 
   #define notExact 
   #define receiptPrint 
   #define textdata 
   #define idleTime 

        
        //formulas

        (cartTime=0.00) = items[a] * tocasher 0.5;
        (scanTime=0.00)= items[a] * scanItems 0.5;

        if(choice[a]=="bag")
        {
            (packTime=0.00) = (items[a] * toPack 0.5) + (packaging[a] * packBag 5);
        }

        if(choice[a]=="box")
        {
        (packTime=0.00) = (items[a] * toPack 0.5) + (packaging[a] * packBox 10); 
        }
        
        if(method[a]=="cash")
        {
            if(value[a]=="e")
            {
                (payingTime=0.00) = exact 15;
            }
            if(value[a]=="ne")
            {
                (payingTime=0.00) = notExact 20;
            }
        }
        
        if(method[a]=="digital")
        {
            (payingTime=0.00) = byCard 15;
        }
        
        (printTime=0.00) = (items[a] * receiptPrint 0.3) + textdata 2;
        if(a<2)
        {
            (TidleTime=0.00) = idleTime 3 - 3;  
        }
        
        else
        {
            (TidleTime=0.00) = idleTime 3;
        }
        

        TotalQueuetime = cartTime + scanTime + packTime + payingTime + printTime + TidleTime;

        cout<<"_____________________________________"<<endl;
        cout<<"Total De-carting Time: "<<
		cartTime<<endl;
        cout<<"Total Scanning Time: "<<
		scanTime<<endl;
        cout<<"Total Packing Time: "<<
		packTime<<endl;
        cout<<"Total Paying Time: "<<
		payingTime<<endl;
        cout<<"Total Receipt Printing Time: "<<
		printTime<<endl;
        cout<<"Idle Time: "<<
		TidleTime<<endl;
        cout<<"Total Customer Queue Time: "<<
		TotalQueuetime<<endl;
        cout<<"+++++++++++++++++++++++++++++++++++++++"<<endl;
        FtotalQueuetime+=TotalQueuetime;
    }
    cout<<"Total Lane Queue Time: "<<FtotalQueuetime<<endl;
    fin.close();

    return 0;
}
