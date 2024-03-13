#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<fstream>
using namespace std;
int main()
    {
        double c=0.1;
        double deltaX=0.01;
        double t=0.01;
        double deltaT=c*deltaX*deltaX;
        int const M=100;
        int N=t/deltaT;
        double T[M+1];
        double result[M+1];
        int i,j;
            
        for(i=1;i<M;i++)
        {
            if(i*deltaX<0.3)
            {
                T[i]=0;
            }
            else if(i*deltaX<0.7)
            {
                T[i]=1;
            }
            else 
            {
                T[i]=10/3*(1-i*deltaX);
            }
        T[0]=0;
        T[M]=0;

        }

        for(i=1;i<=N+1;i++)
        {
            T[0]=0;
            T[M]=0;
            for(j=0;j<=M;j++)
            {
                result[j]=T[j];
            }

        
        std::ofstream outfile("FTCS.txt");//创建输出流对象

        for(j=1;j<100;j++)
        {
            T[j]=result[j]+deltaT*(result[j+1]-2*result[j]+result[j-1])/deltaX/deltaX;
            outfile << T[j] << std::endl;//向文件输出当前元素并换行
        }
            outfile.close();//关闭文件
        if(i*deltaX==t)
        {
            cout<<"FTCS"<<" "<<endl;
            cout<<"Time="<< t <<endl;
            cout<<"sigma="<< c <<endl<<endl;
        for(j=0;j<=M;j++)
        {
                             
                cout<< T[j] <<endl;
                               
         }
            
            cout<<endl<<endl;
        
        }
        
        }
               system("pause");
                return 0;
    }