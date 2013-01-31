#include "stdafx.h"
#include "lib.h"




std::string g_strShare = "100";

 int CPerson::Index = 10;
 int CBook::Index = 20;

std::string& GetValue()
{
   std::string *pstr = &g_strShare;
   return g_strShare;
}
void SetValue(std::string& i)
{
   g_strShare = i;
}


CPerson& CPerson::instance()
{
	static CPerson  person;

	CPerson  *pPer = &person;

	return person;
}

void CPerson::GetInfo(Info* info)
{
	info->id = m_strID;
	info->name = m_strName;
	info->index = CPerson::Index;

}

void CPerson::SetInfo(Info& info)
{
	m_strID = info.id;
	m_strName = info.name;
	CPerson::Index = info.index;
}


void CBook::SetInfo(BookInfo& info)
{
	m_strCode = info.code;
	m_strName = info.name;
	CBook::Index = info.index;

}

void CBook::GetInfo(BookInfo* info)
{
	info->code = m_strCode;
	info->name = m_strName;
	info->index = CBook::Index;

}

CBook& CBook::instance()
 {
	 CBook  *pBook = new CBook;
	 return *pBook;
 }