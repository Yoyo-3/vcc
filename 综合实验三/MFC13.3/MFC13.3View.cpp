
// MFC13.3View.cpp : CMFC133View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC13.3.h"
#endif

#include "MFC13.3Set.h"
#include "MFC13.3Doc.h"
#include "MFC13.3View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC133View

IMPLEMENT_DYNCREATE(CMFC133View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC133View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC133View::OnBnClickedButtonDelect)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC133View::OnBnClickedButton1Add)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC133View::OnBnClickedButtonRevise)
END_MESSAGE_MAP()

// CMFC133View ����/����

CMFC133View::CMFC133View()
	: CRecordView(IDD_MFC133_FORM)
	, s(_T(""))
	, s1(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMFC133View::~CMFC133View()
{
}

void CMFC133View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, s);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
}

BOOL CMFC133View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFC133View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC133Set;
	CRecordView::OnInitialUpdate();

}


// CMFC133View ���

#ifdef _DEBUG
void CMFC133View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC133View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC133Doc* CMFC133View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC133Doc)));
	return (CMFC133Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC133View ���ݿ�֧��
CRecordset* CMFC133View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC133View ��Ϣ�������


void CMFC133View::OnBnClickedButtonDelect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
	{
		m_pSet->MoveFirst();
	}
	UpdateData(false);
}


void CMFC133View::OnBnClickedButton1Add()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MyDlg dlg;
	int r = dlg.DoModal();
	if (r==IDOK) 
	{
		long ii = dlg.i;
		m_pSet->AddNew();
		m_pSet->m_1 = ii;
		m_pSet->Update();
		UpdateData(false);
	}
}


void CMFC133View::OnBnClickedButtonRevise()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MyDlg dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		long ii = dlg.i;
		m_pSet->Edit();
		m_pSet->m_1 = ii;
		m_pSet->Update();
		UpdateData(false);
	}
}
