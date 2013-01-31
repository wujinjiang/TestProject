#ifndef _DLL2_H_
#define _DLL2_H_

#include <string>

#ifdef EXPORT_DLL
#define   AFX_EXT  __declspec(dllexport)
#else
#define   AFX_EXT  __declspec(dllimport)
#endif


typedef struct  tagCusInfo1
{
	tagCusInfo1()
	{
		id = "";
		name = "";
		index = 0;
	}
	std::string id;
	std::string name;
	int index;

}CusInfo1;





#ifdef __cplusplus
extern "C"{
#endif

	AFX_EXT void GetPersonInfo1(CusInfo1*  info);
	AFX_EXT void  SetPersonInfo1(CusInfo1& info);
	AFX_EXT void  GetBookInfo1(CusInfo1* info);
	AFX_EXT void  SetBookInfo1(CusInfo1& info);

	AFX_EXT std::string&  GetFullValue1();
	AFX_EXT void  SetFullValue1(std::string& str);


#ifdef __cplusplus
};
#endif

#endif