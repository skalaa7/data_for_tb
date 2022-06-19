#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;
void printbin(string bin)
{
   cout<<"Bin: ";
        for(int i=0;i<32;i++)
        {
            cout<<bin[i];
            if(i==10)
                cout<<".";
        }
        cout<<endl;
}
void add1(string bin, int index)
{

    if(bin[index]=='0')
    {
        bin[index]='b';
        cout<<"0->1,"<<index<<endl;
        return;
    }
    else if(bin[index]=='1')
    {
        bin[index]='a';
        cout<<"1->0,"<<index<<endl;
        index--;
        add1(bin,index);
    }
}
void flag(int flagnum)
{
    cout<<"flag"<<flagnum<<endl;
}
int main()
{
    string hex="00000000";
    string bin="00000000000000000000000000000000";
    double dec;
    int i;
    int counter=1;
    int mult;
    int negativ;
    fstream in,out;
    //in.open("ulazdec.txt",ios::in);
    //in.open("izlazdec.txt",ios::in);
    in.open("faza1dec.txt",ios::in);

    if(in.is_open())
    {
        //out.open("ulazhex.txt",ios::out);
        //out.open("izlazhex.txt",ios::out);
        out.open("faza1hex.txt",ios::out);
    if(out.is_open())
    {

    for(int b=1;b<=5151;b++)//5152
    {
        dec=0;
        i=0;
        negativ=0;
        hex.clear();
        bin.clear();
        //while(hex.length()!=9)
        //{
            cout<<"Unesi dec:"<<endl;
            /*for(int k=0;k<8;k++)
            {
                cin>>hex[k];
            }*/
            //cin>>dec;
            in>>dec;

        //}

        cout<<"Dec: "<<setprecision(17)<<dec<<endl;
        bin[0]='0';
        if(dec<0)
        {
            negativ=1;
            dec=dec*(-1.0);
            //bin[0]='1';
            //dec+=pow(2.0,-21);
        }
        else
        {
            bin[0]='0';
            //flag(0);
        }
        for(int i=0;i<32;i++)
        {
            //flag(i);
            if(dec>=pow(2.0,10-i))
            {
                bin[i]='1';
                dec=dec-pow(2.0,10-i);
                //cout<<bin[i]<<endl;
            }
            else
            {
                bin[i]='0';
                //cout<<bin[i]<<endl;
            }
        }
        //printbin(bin);
        cout<<"Bin: ";
        for(int i=0;i<32;i++)
        {
            cout<<bin[i];
            if(i==10)
                cout<<".";
        }
        cout<<endl;
        //cout<<endl;
        if(negativ)
        {
            for(i=0;i<32;i++)
            {
                if(bin[i]=='0')
                {
                    bin[i]='1';
                }
                else if(bin[i]=='1')
                {
                    bin[i]='0';
                }
            }
            int index=31;
            //add1(bin,31);
            while(1){
            if(bin[index]=='0')
            {
            bin[index]='1';
            //cout<<"0->1,"<<index<<endl;
            break;
            }
            else if(bin[index]=='1')
            {
            bin[index]='0';
            //cout<<"1->0,"<<index<<endl;
            index--;
            //add1(bin,index);
            }
            }

            cout<<"Negativ"<<endl;
            //printbin(bin);
            cout<<"Bin: ";
            for(int i=0;i<32;i++)
            {
                cout<<bin[i];
                if(i==10)
                    cout<<".";
            }
            cout<<endl;
        }

        int index=31;
        add1(bin,31);
        i=0;
        for(int k=0;k<32;k+=4)
        {
            if((bin[k]=='0')&&
               (bin[k+1]=='0')&&
               (bin[k+2]=='0')&&
               (bin[k+3]=='0'))
            {
                hex[i]='0';
            }
            else if((bin[k]=='0')&&
               (bin[k+1]=='0')&&
               (bin[k+2]=='0')&&
               (bin[k+3]=='1'))
            {
                hex[i]='1';
            }
            else if((bin[k]=='0')&&
               (bin[k+1]=='0')&&
               (bin[k+2]=='1')&&
               (bin[k+3]=='0'))
            {
                hex[i]='2';
            }
            else if((bin[k]=='0')&&
               (bin[k+1]=='0')&&
               (bin[k+2]=='1')&&
               (bin[k+3]=='1'))
            {
                hex[i]='3';
            }
            else if((bin[k]=='0')&&
               (bin[k+1]=='1')&&
               (bin[k+2]=='0')&&
               (bin[k+3]=='0'))
            {
                hex[i]='4';
            }
            else if((bin[k]=='0')&&
               (bin[k+1]=='1')&&
               (bin[k+2]=='0')&&
               (bin[k+3]=='1'))
            {
                hex[i]='5';
            }
            else if((bin[k]=='0')&&
               (bin[k+1]=='1')&&
               (bin[k+2]=='1')&&
               (bin[k+3]=='0'))
            {
                hex[i]='6';
            }
            else if((bin[k]=='0')&&
               (bin[k+1]=='1')&&
               (bin[k+2]=='1')&&
               (bin[k+3]=='1'))
            {
                hex[i]='7';
            }
            else if((bin[k]=='1')&&
               (bin[k+1]=='0')&&
               (bin[k+2]=='0')&&
               (bin[k+3]=='0'))
            {
                hex[i]='8';
            }
            else if((bin[k]=='1')&&
               (bin[k+1]=='0')&&
               (bin[k+2]=='0')&&
               (bin[k+3]=='1'))
            {
                hex[i]='9';
            }
            else if((bin[k]=='1')&&
               (bin[k+1]=='0')&&
               (bin[k+2]=='1')&&
               (bin[k+3]=='0'))
            {
                hex[i]='a';
            }
            else if((bin[k]=='1')&&
               (bin[k+1]=='0')&&
               (bin[k+2]=='1')&&
               (bin[k+3]=='1'))
            {
                hex[i]='b';
            }
            else if((bin[k]=='1')&&
               (bin[k+1]=='1')&&
               (bin[k+2]=='0')&&
               (bin[k+3]=='0'))
            {
                hex[i]='c';
            }
            else if((bin[k]=='1')&&
               (bin[k+1]=='1')&&
               (bin[k+2]=='0')&&
               (bin[k+3]=='1'))
            {
                hex[i]='d';
            }
            else if((bin[k]=='1')&&
               (bin[k+1]=='1')&&
               (bin[k+2]=='1')&&
               (bin[k+3]=='0'))
            {
                hex[i]='e';
            }
            else if((bin[k]=='1')&&
               (bin[k+1]=='1')&&
               (bin[k+2]=='1')&&
               (bin[k+3]=='1'))
            {
                hex[i]='f';
            }
            i++;
        }
        cout<<"Hex: ";
        out<<"x\"";///////
        for(int k=0;k<8;k++)
        {
            cout<<hex[k];
            out<<hex[k];
        }
        cout<<endl;
        out<<"\"";//////
        out<<endl;
    cout<<"counter:"<<counter<<endl;
    counter++;
    }
    out.close();
    }
    in.close();
    }
    return 0;
}
