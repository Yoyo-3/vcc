
// MFC14View.cpp : CMFC14View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC14.h"
#endif

#include "MFC14Set.h"
#include "MFC14Doc.h"
#include "MFC14View.h"
#include "MyDlg.h"
#include "MyDlg2.h"
#include "MyDlg3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC14View

IMPLEMENT_DYNCREATE(CMFC14View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC14View, CRecordView)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &CMFC14View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFC14View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFC14View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFC14View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC14View::OnBnClickedButton1)
	ON_COMMAND(ID_sort, &CMFC14View::Onsort)
	ON_COMMAND(ID_inquire, &CMFC14View::Oninquire)
	ON_COMMAND(ID_add, &CMFC14View::Onadd)
	ON_COMMAND(ID_delect, &CMFC14View::Ondelect)
	ON_COMMAND(ID_alter, &CMFC14View::Onalter)
	ON_COMMAND(ID_recordset, &CMFC14View::Onrecordset)
END_MESSAGE_MAP()

// CMFC14View ����/����

CMFC14View::CMFC14View()
	: CRecordView(IDD_MFC14_FORM)
	, ID(0)
	, number(0)
	, name(_T(""))
	, age(0)
	, address(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	path = _T("E:\\��Ƭ\\");

}

CMFC14View::~CMFC14View()
{
}

void CMFC14View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_11);
}

BOOL CMFC14View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFC14View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC14Set;
	CRecordView::OnInitialUpdate();

}


// CMFC14View ���

#ifdef _DEBUG
void CMFC14View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC14View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC14Doc* CMFC14View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC14Doc)));
	return (CMFC14Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC14View ���ݿ�֧��
CRecordset* CMFC14View::OnGetRecordset()
{
	return m_pSet;
}

void CMFC14View::draw_pic(CString file)
{
	CImage img;
	img.Load(file);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}

// CMFC14View ��Ϣ�������


void CMFC14View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItemText(IDC_EDIT5, s);
	filename = path + s;
	Invalidate();
}


void CMFC14View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
	}
	GetDlgItemText(IDC_EDIT5, s);
	filename = path + s;
	Invalidate();
	UpdateData(false);
}


void CMFC14View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveLast();
	}
	GetDlgItemText(IDC_EDIT5, s);
	filename = path + s;
	Invalidate();
	UpdateData(false);
}


void CMFC14View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	GetDlgItemText(IDC_EDIT5, s);
	filename = path + s;
	Invalidate();
	UpdateData(false);
}

void CMFC14View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	GetDlgItemText(IDC_EDIT5, s);
	filename = path + s;
	draw_pic(filename);
}


void CMFC14View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MyDlg dlg;
	GetDlgItemText(IDC_EDIT5, s);
	filename = path + s;
	dlg.str = filename;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
	}
}


void CMFC14View::Onsort()
{
	// TODO: �ڴ���������������
	MyDlg2 dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		this->UpdateData(false);
		m_pSet->m_strSort = dlg.a;
		m_pSet->Requery();
		Invalidate();
	}

}


void CMFC14View::Oninquire()
{
	// TODO: �ڴ���������������
	MyDlg2 dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		this->UpdateData(false);
		m_pSet->m_strFilter = dlg.a;
		m_pSet->Requery();
		Invalidate();
	}
	
}


void CMFC14View::Onadd()
{
	// TODO: �ڴ���������������
}


void CMFC14View::Ondelect()
{
	// TODO: �ڴ���������������
}


void CMFC14View::Onalter()
{
	// TODO: �ڴ���������������
}


void CMFC14View::Onrecordset()
{
	// TODO: �ڴ���������������
	MyDlg3 dlg3;
	CString str;int i;
	m_pSet->MoveFirst();
	while (!(m_pSet->IsEOF())) {
		for (i = 1; i < m_pSet->GetODBCFieldCount(); i++) {
			m_pSet->GetFieldValue((short)i, str);
			dlg3.str3 = dlg3.str3 + ' '+' ';
			dlg3.str3 = dlg3.str3 + str;
		}
		m_pSet->MoveNext();
	}
	int r = dlg3.DoModal();
}
