#include"myhead.h"
class CMyString{

//友元函数
friend std::ostream & operator <<(ostream &os,const CMyString &str);

public:
	
	CMyString(char *pData = NULL);
	CMyString(const CMyString &str);
	CMyString& operator =(char *pData);
	CMyString& operator =(const CMyString &str);

	~CMyString(void);
private:
	char * m_pData;
};

//构造函数没有返回
CMyString::CMyString(char *pData 	){};
CMyString::CMyString(const CMyString &str){};
CMyString::~CMyString(void){
	delete[] m_pData;
};
//重载输出
ostream& operator <<(ostream &os,const CMyString &str){
	os<<strlen(str.m_pData)<<endl;;
	//os<<str.m_pData<<endl;
}

//重载赋值
CMyString& CMyString::operator=(const CMyString &str){
	if(this==&str)
		return *this;
	delete [] m_pData;
	m_pData=NULL;
	m_pData=new char[strlen(str.m_pData)+1];
	strcpy(m_pData,str.m_pData);
	return *this;
}

CMyString& CMyString::operator=(char *pData){
	delete []m_pData;
	m_pData=NULL;
	m_pData=new char[strlen(pData)+1];
	strcpy(m_pData,pData);
	return *this;
}

int main(){
	CMyString mstr;
	char s[]={'h','l','w','d'};
	mstr=s;
	CMyString mstr1;
	mstr1=mstr;
	cout<<mstr<<endl<<mstr1<<endl;	
	
	
}
