#ifndef _DLL1_H_
#define _DLL1_H_

#include <string>

#ifdef EXPORT_DLL
#define   AFX_EXT  __declspec(dllexport)
#else
#define   AFX_EXT  __declspec(dllimport)
#endif


typedef struct  tagCusInfo
{
	tagCusInfo()
	{
		id = "";
		name = "";
		index = 0;
	}
	std::string id;
	std::string name;
	int index;

}CusInfo;





#ifdef __cplusplus
extern "C"{
#endif

 AFX_EXT void GetPersonInfo(CusInfo*  info);
  AFX_EXT void  SetPersonInfo(CusInfo& info);
  AFX_EXT void  GetBookInfo(CusInfo* info);
  AFX_EXT void  SetBookInfo(CusInfo& info);

AFX_EXT std::string&  GetFullValue();
  AFX_EXT void  SetFullValue(std::string& str);


#ifdef __cplusplus
};
#endif










#endif