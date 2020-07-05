
// �ۺ�ʵ���(1)View.cpp : C�ۺ�ʵ���1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ۺ�ʵ���(1).h"
#endif

#include "�ۺ�ʵ���(1)Set.h"
#include "�ۺ�ʵ���(1)Doc.h"
#include "�ۺ�ʵ���(1)View.h"
#include "MyDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ۺ�ʵ���1View

IMPLEMENT_DYNCREATE(C�ۺ�ʵ���1View, CRecordView)

BEGIN_MESSAGE_MAP(C�ۺ�ʵ���1View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &C�ۺ�ʵ���1View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C�ۺ�ʵ���1View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C�ۺ�ʵ���1View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C�ۺ�ʵ���1View::OnRecordLast)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &C�ۺ�ʵ���1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// C�ۺ�ʵ���1View ����/����

C�ۺ�ʵ���1View::C�ۺ�ʵ���1View()
	: CRecordView(IDD_MY1_FORM)
	, x(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	path = _T("C:\\Users\\lijie13347586275\\Pictures\\Saved Pictures\\");
}

C�ۺ�ʵ���1View::~C�ۺ�ʵ���1View()
{
}

void C�ۺ�ʵ���1View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL C�ۺ�ʵ���1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C�ۺ�ʵ���1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_�ۺ�ʵ���1Set;
	CRecordView::OnInitialUpdate();

}


// C�ۺ�ʵ���1View ���

#ifdef _DEBUG
void C�ۺ�ʵ���1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C�ۺ�ʵ���1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C�ۺ�ʵ���1Doc* C�ۺ�ʵ���1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ۺ�ʵ���1Doc)));
	return (C�ۺ�ʵ���1Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ۺ�ʵ���1View ���ݿ�֧��
CRecordset* C�ۺ�ʵ���1View::OnGetRecordset()
{
	return m_pSet;
}



// C�ۺ�ʵ���1View ��Ϣ�������


void C�ۺ�ʵ���1View::OnRecordFirst()
{
	m_pSet->MoveFirst();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	//draw_pic(filename);
	InvalidateRect(&picRect);
	// TODO: �ڴ���������������
}


void C�ۺ�ʵ���1View::OnRecordPrev()
{
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	//draw_pic(filename);
	InvalidateRect(&picRect);
	UpdateData(false);
	// TODO: �ڴ���������������
}


void  C�ۺ�ʵ���1View::OnRecordNext()
{
	m_pSet->MoveNext();
	if (m_pSet->IsBOF())
		m_pSet->MoveLast();
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	//draw_pic(filename);
	InvalidateRect(&picRect);
	UpdateData(false);
	// TODO: �ڴ���������������
}


void  C�ۺ�ʵ���1View::OnRecordLast()
{
	m_pSet->MoveLast();
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	//draw_pic(filename);
	InvalidateRect(&picRect);
	UpdateData(false);
	// TODO: �ڴ���������������
}

void  C�ۺ�ʵ���1View::draw_pic(CString file)
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

void C�ۺ�ʵ���1View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
	GetDlgItem(IDC_STATIC)->GetClientRect(&picRect);
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	draw_pic(filename);						   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
}


void C�ۺ�ʵ���1View::OnBnClickedButton1()
{
	MyDlg dlg;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	dlg.str = filename;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
