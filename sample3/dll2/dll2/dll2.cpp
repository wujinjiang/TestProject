// dll2.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#define  EXPORT_DLL

#include "dll2.h"
#include "lib.h"


#ifdef _MANAGED
#pragma managed(push, off)
#endif

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

#ifdef _MANAGED
#pragma managed(pop)
#endif


void GetPersonInfo1(CusInfo1*  info)
{
	CPerson::Info temp;
	CPerson::instance().GetInfo(&temp);
	info->id = temp.id;
	info->name = temp.name;
	info->index = temp.index;

}
void SetPersonInfo1(CusInfo1& info)
{
	CPerson::Info temp;
	temp.id = info.id;
	temp.name = info.name;
	temp.index = info.index;
	CPerson::instance().SetInfo(temp);

}
void GetBookInfo1(CusInfo1* info)
{
	CBook::BookInfo temp;
	CBook::instance().GetInfo(&temp);
	info->id = temp.code;
	info->name = temp.name;
	info->index = temp.index;
}
void SetBookInfo1(CusInfo1& info)
{
	CBook::BookInfo temp;
	temp.code = info.id;
	temp.name = info.name;
	temp.index = info.index;
	CBook::instance().SetInfo(temp);

}

std::string& GetFullValue1()
{
	return GetValue();

}
void SetFullValue1(std::string& str)
{
	SetValue(str);
}


