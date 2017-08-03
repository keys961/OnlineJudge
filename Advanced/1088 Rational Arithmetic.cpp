#include <iostream>
#include <string>
using namespace std;

typedef struct fenshu{
	int sign ;//分数的符号 sign=-1表示负数
	long int z;//分数的整数部分
	long int up;//分子
	long int down;//分母
	fenshu():sign(1),z(0),up(0),down(1){};
}FenShu;

bool operator==(FenShu &f,long int x)
{//判断是否等于某个整数
	return f.up==0 && f.z*f.sign==x;
}

long int getPub(long int up,long int down)
{//最大公约数
	long int t=1;
	while(down){
		t = up % down ;
		up = down;
		down = t;
	}
	return up;
}

long int fab(long int x)
{//绝对值
    if(x<0) return -x;
	else return x;
}

FenShu getFenShu(long int up,long int down)
{//化简分数
     FenShu f;
	
	 if(up * down == 0){//分数表示0
		 return f;
	 }
	 //以下表示分数非0

	 if(up * down < 0) {//确定符号
		 f.sign =-1;
		 up = fab(up);
		 down = fab(down);
	 }
	 
	 f.z=up/down;   
	 up=up%down;
	 if(up==0){//分数是一个整数
		 return f;
	 }
	 long int pub=getPub(up,down);//正宗的分数
	 f.up = up/pub;
	 f.down = down/pub;
	 return f;
}

void printFenShu(FenShu &f)
{//输出分数
	if(f==0) {//分数表示0
		cout<<"0";
	    return ;
	}
	if(f.sign==-1) cout<<"(-";
	if(f.z){//有整数
		cout<<f.z;
	    if(f.up){
			cout<<" "<<f.up<<"/"<<f.down;
		}
	}
	else if(f.up){
		cout<<f.up<<"/"<<f.down;
	}
	if(f.sign==-1) cout<<")";
}

void printExpress(FenShu &f1,FenShu &f2,FenShu &f3,char op)
{//输出表达式
	printFenShu(f1);
	cout<<" "<<op<<" ";
	printFenShu(f2);
	cout<<" = ";
	printFenShu(f3);
	cout<<endl;
}

void printError(FenShu &f1,FenShu &f2,string &errorInf,char op)
{//错误的表达式输出
	printFenShu(f1);
	cout<<" "<<op<<" ";
	printFenShu(f2);
	cout<<" = ";
	cout<<errorInf;
	cout<<endl;
}

FenShu cal(long int a,long int b,long int c,long int d,char op)
{//计算+ - * /
	long int up = 0;
	long int down  = b*d;
	switch(op){
	case '+':
		up = a*d+b*c;
		break;
	case '-':
		up = a*d - b*c;
		break;
	case '*':
		up = a*c;
		break;
	case '/':
		up = a*d;
		down = b*c;
		break;
	}
	FenShu f = getFenShu(up,down); 
	return f;
}

int main()
{
	long int a,b,c,d;
	char op;
	cin>>a>>op>>b>>c>>op>>d;


	FenShu f1 = getFenShu(a,b);
	FenShu f2 = getFenShu(c,d);


	a = f1.sign * (f1.z * f1.down + f1.up);
	b = f1.down;
	c = f2.sign * (f2.z * f2.down + f2.up);
	d = f2.down;

	FenShu f3 = cal(a,b,c,d,'+');
	printExpress(f1,f2,f3,'+');
   

    f3 = cal(a,b,c,d,'-');
	printExpress(f1,f2,f3,'-');
	 
	f3 = cal(a,b,c,d,'*');
	printExpress(f1,f2,f3,'*'); 
 
	if(f2==0){
		string error("Inf");
		printError(f1,f2,error,'/');
	}else{
		f3 = cal(a,b,c,d,'/');
		printExpress(f1,f2,f3,'/');
	}
	return 0;
}

