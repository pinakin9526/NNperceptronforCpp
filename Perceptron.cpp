#include<iostream>
using namespace std;


class perceptron
{
    public:
    double Weights[3]={1,1,1};
    int k,n;

    double training(double tinput[4][3],double toutput[4])
    {
        for(int it= 0 ; it < 10000;it++)
        {
            for(int j = 0;j<4;j++)
        {
            double inpt;
            repeat:
            double l=0;
            double yout[3];

            for(int i =0; i <3;i++)
            {
                l = l + tinput[j][i]*Weights[i];
            }
            if(l>0)
            {
                l=1;
            }
            else
            {
                l=0;
            }
            
        
            if(toutput[j] != l)
            {
                for(int i = 0;i<3;i++)
                {
                cout<<"Current weight are "<<Weights[i]<<endl;
                Weights[i]=Weights[i]+0.5*(toutput[j]-l)*tinput[j][i];
                cout<<"Updated weights are "<<Weights[i]<<endl;
                }
                goto repeat;
            }
            else
            {
                cout<<"Updated Weights are: "<<endl;
                for(int i =0;i<3;i++)
                {
                    cout<<Weights[i]<<endl;
                }
            
            }
        }

        }
        
        return 0;
    }
    double runnet(double inp[3])
    {
        double l =0;
        for(int i = 0; i<3;i++)
        {
            l = l + inp[i]*Weights[i];
        }
        if(l > 0)
        {
            cout<<"Class1: "<<l<<endl;
        }
        else
        {
            cout<<"Class2: "<<l<<endl;
        }
        return 0;
        
    }

};
int main()
{
    int k,n;
    perceptron per;
    double tinput[4][3]={
    {1,121,16.8},
    {1,114,15.2},
    {1,210,9.4},
    {1,195,8.1}};
    double c1[3]={1,121,16.8};
    double c11[3]={1,114,15.2};
    double c2[3]={1,210,9.4};
    double c22[3]={1,195,8.1};
    double c21[3];

    double tout[4]={1,1,0,0};
    per.training(tinput,tout);
    cout<<"Putdata";
   
    per.runnet(c1);
    per.runnet(c11);
    per.runnet(c2);
    per.runnet(c22);
    

    cout<<"\nand Unkownfruit belongs to ";
    per.runnet(c21);
    return 0;

}