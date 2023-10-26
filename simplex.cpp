#include <iostream>
#include<algorithm>
using namespace std;

class basic
{
public : 
int n,i,j;              
int con;
int len;
float x[100][200];
float zj_cj[100];
float zj[100];
float xb[100][200];
float ratios[100];
float cbi[100];
int max,min;
float cnt,solution;
float minres;
int xvalue,slackvalue=1;
 
        void input()
        {
             cout<<"enter number of variables";
            cin>>n;
            cout<<"enter number of constraints";
            cin>>con;
              
             for(i=0;i<con+1;i++)
             {
                 for(j=0;j<n+con;j++)
                 {  
                     xvalue=j;
                     xvalue+=1;
                     if(j<n)
                     {

                         cout<<"enter x"<<xvalue<<"value" ;
                         cin>>x[i][j];
                     }
                     else{
                         slackvalue= j-n+1;
                     cout<<"enter slack variable S"<<slackvalue;
                     cin>>x[i][j];
                     
                     }
                 }  
             }
             for(i=1;i<=con;i++)
             {
                 for(j=n+con;j<=n+con;j++)
                 {
                     cout<<"enter solution s"<<i; 
                     cin>>x[i][j];
                     
                 }
                 
             }
    
        }
        void output()
        {
               for(i=0;i<con+1;i++)
               {
                   for(j=0;j<n+con+1;j++)
                   {
                 
                       cout<<"\t" <<x[i][j];
                      
                     
                   }
               cout<<endl;
                   }
               
        
        }
        void firstiter()
        {
            for(j=0;j<n+con;j++)
            {
                zj_cj[j]=x[0][j];
            }
            // len = sizeof(zj_cj);
            cout<<"\nZj-Cj=";
            for(i=0;i<n+con;i++)
            {
                cout<<"\t "<<zj_cj[i];
            }
             
                for(int k=0;k<n+con;k++)
                {
                    if(zj_cj[0]<zj_cj[k])
                        {
                          
                            zj_cj[0] = zj_cj[k];
                           max =k;  
                           cnt =1;
                        }
                        
                }
                if(cnt==1){
            cout<<"\nMaximum element in Zj-Cj is"<<zj_cj[0];
            cout<<"\nMaximum element in Zj-Cj at"<<max;
                }
                else{
                    max=0;
            cout<<"\nMaximum element in Zj-Cj is"<<zj_cj[0];
            cout<<"\nMaximum element in Zj-Cj at"<<max;
                    
                }
            
        }
        void  keyrow()
        {
                    for(int k=0;k<n+con;k++)
                {
                    if(zj_cj[0]<zj_cj[k])
                        {
                          
                            zj_cj[0] = zj_cj[k];
                           max =k;  
                           cnt =1;
                        }
                        
                }
                if(cnt==1){
            cout<<"\nMaximum element in Zj-Cj is"<<zj_cj[0];
            cout<<"\nMaximum element in Zj-Cj at"<<max;
                }
                else{
                    max=0;
            cout<<"\nMaximum element in Zj-Cj is"<<zj_cj[0];
            cout<<"\nMaximum element in Zj-Cj at"<<max;
                    
                }
                
            
        }
        void  keycol()
        {
            cout<<"\n The key col elements are";
            for(i=max;i<=max;i++)
            {
                for(j=1;j<=con;j++)
                {
                    cout<<"\t"<<x[j][i];
                }
                cout<<"\n";
            }
            int outmax = max;
            outmax +=1;
            cout<<"The entering variable is x"<<outmax;
        }
        void  ratio()
        {
            for(i=1;i<=con;i++)
            {
                for(j=n+con;j<=n+con;j++)
                {
                    xb[i][j]=x[i][j];
                 }
             
            }
            for(i=1;i<=con;)
            {
                if(x[i][max]==0){
                    i++;
                }
                else{
                ratios[i-1]=(xb[i][n+con]) / (x[i][max]);
                  cout<<"\nvalues"<<ratios[i-1];
                  i++;
                }
           }
           for(int k=0;k<con;k++)
           {
               
               if(ratios[k]<ratios[0] && ratios[k]!=0)
               {
                    ratios[0]=ratios[k];
                   min=k;
                }
               else{
                   
                    min=k;
                
               }
           }
          
          cout<<"\nMinimum ratio is "<<ratios[0]<<"at "<<min;            
         
        }
        int keyele(){
            cout<<"\nthe Key element is "<<x[min][max]<<"at["<<min<<"]["<<max<<"]";
        }
        int iter()
        {
            //CB values assigned based on leaving and entering variables and the entering variable row is computed
            cbi[min]=x[0][max];
            //cout<<"\nThe new computed values of x"<<min<<"are";
             cout<<"\ncbi value is"<<cbi[min];
             cout<<"\n";
                for(j=0;j<n+con+1;j++)
                {
                    x[min][j]=   (x[min][j]) / (x[min][max]);
                       cout<<"\t"<<x[min][j];      
                }
            
             
        //For computing New values for other rows  based on the entering variable
            for(i=1;i<=con;)
            {
                for(j=0;j<=n+con+1;j++)
                {
                if(i==min)
                {
                i++;
               }
               else
               {
                   x[i][j]=(x[i][j])- (x[min][max]*x[i-1][j]);
                   i++;
                }
              }
            }
            //calculation of zj values
            for(i=1;i<=con;i++)
            {
                for(j=0;j<=n+con;j++)
                {
                    zj[i-1]=(cbi[i-1])*(x[i][j]);
                }
            }
            //calculation of zj-cj values
            
                for(j=0;j<=n+con;j++)
                {
                    zj_cj[j]=(zj[j])-(x[0][j]);
                    cout<<"\nZj-Cj = "<<zj_cj[j];
                }
            
        }
        //for retierating the whole process till the condition is met
        int condition()
        {

                  
                iter();
                keyrow();
                keycol();
                ratio();
                keyele();
                output();
                control();
                

            
            
        }  
        // condition of getting negative of zero values at cj-zj 
        int control()
        {
            for(i=0;i<n+con;i++)
            {
                 if(zj_cj[i]<zj_cj[0])
               {
                    zj_cj[0]=zj_cj[i];
                    minres=zj_cj[i];
                }
               else{
                   
                    minres=zj_cj[i];
                }

            }
            if(minres<=0)
            {
                cout<<"The final table is ";
                output();

            }
            else{
                condition();
            }
        }
};

int main()
{
            
basic b;
b.input();
cout<<"\n The inital table is \n";
b.output();
b.firstiter();
cout<<"\nThe table after first iteration is ";
cout<<"\n";
b.output();
b.firstiter();
b.keycol();
b.ratio();
b.keyele();
b.iter();
b.output();
b.condition();
// b.control();
// b.condition();
return 0;
}
          