
// MFC14Set.cpp : CMFC14Set ���ʵ��
//

#include "stdafx.h"
#include "MFC14.h"
#include "MFC14Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC14Set ʵ��

// ���������� 2020��5��25��, 20:54

IMPLEMENT_DYNAMIC(CMFC14Set, CRecordset)

CMFC14Set::CMFC14Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = 0;
	m_2 = L"";
	m_3 = 0;
	m_11 = L"";
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFC14Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x5b66\x751f\x57fa\x672c\x4fe1\x606f;DBQ=C:\\Users\\\x9ec4\x65ed\x660e\\\x5b66\x751f\x57fa\x672c\x4fe1\x606f.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFC14Set::GetDefaultSQL()
{
	return _T("[ѧ��������Ϣ]");
}

void CMFC14Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[ѧ��]"), m_1);
	RFX_Text(pFX, _T("[����]"), m_2);
	RFX_Long(pFX, _T("[����]"), m_3);
	RFX_Text(pFX, _T("[ͼƬ·��]"), m_11);

}
/////////////////////////////////////////////////////////////////////////////
// CMFC14Set ���

#ifdef _DEBUG
void CMFC14Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFC14Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

