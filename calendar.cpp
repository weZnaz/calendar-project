#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int year,month,days,c;
    cin>>s>>year;
    if(s=="jan")
    {
        month=1;
        days=31;
    }
    if(s=="feb")
    {
         month=2;
         if((year%4==0 && year%100!=0) || year%400==0)
         days=29;
         else
         days=28;
    }
    if(s=="march")
    {
         month=3;
         days=31;
    }
    if(s=="april")
    {
         month=4;
         days=30;
    }
    if(s=="may")
    {
         month=5;
         days=31;
    }
    
    if(s=="june")
    {
         month=6;
         days=30;
    }
    if(s=="july")
    {
         month=7;
         days=31;
    }
     if(s=="aug")
    {
         month=8;
         days=31;
    }
    
    if(s=="sept")
    {
         month=9;
         days=30;
    }
    if(s=="oct")
    {
         month=10;
         days=31;
    }

    if(s=="nov")
    {
         month=11;
         days=30;
    }
    if(s=="dec")
    {
         month=12;
         days=31;
    }
    //zeller congruence to calculate th first day of the month
    int q=1;
    int k=(13*(month+1))/5;
    int p=year%100;
    int r=p/4;
    int j=(year/100)/4;
    int e=2*(year/100);
    int h=(q+k+p+r+j-e)%7;
    //cout<<h<<endl;
    //
    //
    int x=1;
    if(s=="jan" )h=h+1;
    if( s=="feb")h=h+2;
    if(h==0)h=7;

    
    const string YELLOW = "\033[33m";
    const string RESET = "\033[0m";
    
    const string mag="\033[35m";
    const string grn="\033[32m";
    const string red="\033[31m";

    int arr[6][8];
    cout<<mag<<"-----------------------------------\n"<<RESET;
    cout<<"             "<<YELLOW<<s<<" "<<year<<RESET<<"                  \n";
    cout<<grn<<"-----------------------------------\n"<<RESET;
    
    cout<<"  "<<"Sun"<<"  "<<"Mon"<<"  "<<"Tue  "<<"Wed  "<<"Thu  "<<red<<"Fri  "<<RESET<<"Sat  \n";
    for(int i=1;i<=7;i++)
    {
        
        for(int j=1;j<=7;j++)
        {
            if(i==1 && j<h){arr[i][j]=0;x--;}
            else 
            {
            arr[i][j]=x;
            }
            if(x>days)arr[i][j]=0;
            x++;
            
            
        }
        if(x>days)break;
    }
    
    for(int i=1;i<=6;i++)
    {cout<<"  ";
        for(int j=1;j<=7;j++)
        {
            if(arr[i][j]==0)cout<<"    ";
            else if(arr[i][j]<10){
                if(j==6)
                cout<<red<<" "<<arr[i][j]<<"  "<<RESET;
                else
                cout<<" "<<arr[i][j]<<"  ";
            
            
            
            }
            else{
                if(j==6)
                cout<<red<<arr[i][j]<<"  "<<RESET;
                else
                cout<<arr[i][j]<<"  ";
            }
            cout<<" ";
            if(arr[i][j]==days)return 0;
            c=arr[i][j];
        }cout<<endl;
        if(c==days)break;
        
    }

}
