
// �ۺ�ʵ��һSet.cpp : C�ۺ�ʵ��һSet ���ʵ��
//

#include "stdafx.h"
#include "�ۺ�ʵ��һ.h"
#include "�ۺ�ʵ��һSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ۺ�ʵ��һSet ʵ��

// ���������� 2020��6��13��, 22:49

IMPLEMENT_DYNAMIC(C�ۺ�ʵ��һSet, CRecordset)

C�ۺ�ʵ��һSet::C�ۺ�ʵ��һSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_nFields = 2;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString C�ۺ�ʵ��һSet::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x5b66\x751f\x4fe1\x606f;DBQ=C:\\Users\\lijie13347586275\\Documents\\Database1.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString C�ۺ�ʵ��һSet::GetDefaultSQL()
{
	return _T("[ͼƬ]");
}

void C�ۺ�ʵ��һSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// C�ۺ�ʵ��һSet ���

#ifdef _DEBUG
void C�ۺ�ʵ��һSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void C�ۺ�ʵ��һSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

