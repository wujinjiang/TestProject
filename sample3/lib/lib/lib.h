#ifndef  _LIB_H_
#define  _LIB_H_

#include <string>

extern std::string g_strShare;

std::string& GetValue();
void SetValue(std::string& i);

class CPerson
{
public:
	typedef struct tagInfo
	{
		tagInfo()
		{
			id = "";
			name = "";
			index = 0;
		}
		std::string id;
		std::string name;
		int index;

	}Info;

	CPerson(std::string id = "per000",std::string name = "name000"):m_strID(id),m_strName(name){};
	~CPerson(){};
	static CPerson& instance();
	void GetInfo(Info* info);
	void SetInfo(Info&);


private:
	std::string m_strID;
	std::string m_strName;
	 static int Index;

};


class CBook
{
public:
	CBook(std::string code = "book000",std::string name = "bookfirst"):m_strCode(code),m_strName(name){};
	~CBook(){};
	typedef struct tagBookInfo
	{
		tagBookInfo()
		{
			code = "";
			name = "";
			index = 0;
		}
		std::string code;
		std::string name;
		int index;

	}BookInfo;
	void GetInfo(BookInfo* info);
	void SetInfo(BookInfo& info);
	static CBook& instance();
private:
	std::string m_strCode;
	std::string m_strName;
	static int Index;
};

#endif