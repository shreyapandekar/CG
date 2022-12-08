#include <iostream>
#include <graphics.h>
#include<math.h>
using namespace std;

void Matrix(int m1[3][3],int m2[3][3]){
    int mult[3][3];
    int i,j,k;

    for(int i=0;i<3;i++)    
    {    
        for(j=0;j<3;j++)    
        {    
            mult[i][j]=0;    
            for(k=0;k<3;k++)    
                {    
                mult[i][j]+=m1[i][k]*m2[k][j];    
                }    
        }    
    }  
   
    line(mult[0][0],mult[0][1],mult[1][0],mult[1][1]);
    line(mult[1][0],mult[1][1],mult[2][0],mult[2][1]);
    line(mult[2][0],mult[2][1],mult[0][0],mult[0][1]);
    delay(10000);
};
/*void translation(int cord_mat[3][3]){
    float tx,ty;
    cout<<"Enter Translation factors"<<endl;
    cin>>tx>>ty;
    setcolor(RED);
    int trans_mat[3][3]={{1,0,0},{0,1,0},{tx,ty,1}};
    Matrix(cord_mat,trans_mat);
}   
void scaling(int cord_mat[3][3]){
    float sx,sy;
    cout<<"Enter Scaling factors"<<endl;
    cin>>sx>>sy;
    setcolor(GREEN);
    int scal_mat[3][3]={{sx,0,0},{0,sy,0},{0,0,1}};
    Matrix(cord_mat,scal_mat);
}
*/
void anticlockwise(float cord_mat[3][3]){
    float rad,theta;
    cout<<"Enter anticlockwise rotation factors"<<endl;
    cin>>theta;
    rad=(3.14/180)*theta;
    float anticlk[3][3]={{cos(rad),-sin(rad),0},{sin(rad),cos(rad),0},{0,0,1}};
    Matrix(cord_mat,anticlk);
}  
/*
void clockwise(int cord_mat[3][3]){
    float rad,theta;
    cout<<"Enter clockwise rotation factors"<<endl;
    cin>>theta;
    rad=(3.14/180)*theta;
    int clk[3][3]={{cos(rad),sin(rad),0},{-sin(rad),cos(rad),0},{0,0,1}};
    Matrix(cord_mat,clk); 
    */ 	
int main()
{
    int gdriver=DETECT, gmode;
    initgraph(&gdriver,&gmode,NULL);
    int x1,y1,x2,y2,x3,y3;
    int x1_,y1_,x2_,y2_,x3_,y3_;
    cout<<"enter x1 and y1= ";
    cin>>x1>>y1;
    cout<<"enter x2 and y2= ";
    cin>>x2>>y2;
    cout<<"enter x3 and y3= ";
    cin>>x3>>y3;

    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);
    int cord_mat[3][3]={{x1,y1,1},{x2,y2,1},{x3,y3,1}};
 //   translation(cord_mat);
   // scaling(cord_mat);
    anticlockwise(cord_mat);
    closegraph();
    return 0;
}


