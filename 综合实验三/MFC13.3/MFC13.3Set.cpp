
// MFC13.3Set.cpp : CMFC133Set ���ʵ��
//

#include "stdafx.h"
#include "MFC13.3.h"
#include "MFC13.3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC133Set ʵ��

// ���������� 2020��5��19��, 19:42

IMPLEMENT_DYNAMIC(CMFC133Set, CRecordset)

CMFC133Set::CMFC133Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = 0;
	m_2 = 0;
	m_3 = 0;
	m_4 = 0;
	m_5 = 0;
	m_nFields = 6;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFC133Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x7efc\x5408\x5b9e\x9a8c\x4e09;DBQ=C:\\Users\\\x9ec4\x65ed\x660e\\\x7efc\x5408\x5b9e\x9a8c\x4e09.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFC133Set::GetDefaultSQL()
{
	return _T("[�ۺ�ʵ����]");
}

void CMFC133Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Long(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Long(pFX, _T("[�ֶ�3]"), m_3);
	RFX_Long(pFX, _T("[�ֶ�4]"), m_4);
	RFX_Long(pFX, _T("[�ֶ�5]"), m_5);

}
/////////////////////////////////////////////////////////////////////////////
// CMFC133Set ���

#ifdef _DEBUG
void CMFC133Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFC133Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

