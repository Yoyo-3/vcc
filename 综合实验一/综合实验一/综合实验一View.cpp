
// 综合实验一View.cpp : C综合实验一View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "综合实验一.h"
#endif

#include "综合实验一Set.h"
#include "综合实验一Doc.h"
#include "综合实验一View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C综合实验一View

IMPLEMENT_DYNCREATE(C综合实验一View, CRecordView)

BEGIN_MESSAGE_MAP(C综合实验一View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &C综合实验一View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C综合实验一View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C综合实验一View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C综合实验一View::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// C综合实验一View 构造/析构

C综合实验一View::C综合实验一View()
	: CRecordView(IDD_MY_FORM)
	, x(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("C:\\Users\\lijie13347586275\\Pictures\\Saved Pictures\\");
}

C综合实验一View::~C综合实验一View()
{
}

void C综合实验一View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL C综合实验一View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C综合实验一View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_综合实验一Set;
	CRecordView::OnInitialUpdate();

}


// C综合实验一View 诊断

#ifdef _DEBUG
void C综合实验一View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C综合实验一View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C综合实验一Doc* C综合实验一View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C综合实验一Doc)));
	return (C综合实验一Doc*)m_pDocument;
}
#endif //_DEBUG


// C综合实验一View 数据库支持
CRecordset* C综合实验一View::OnGetRecordset()
{
	return m_pSet;
}



// C综合实验一View 消息处理程序


void C综合实验一View::OnRecordFirst()
{
	m_pSet->MoveFirst();
	UpdateData(false);
	CString filename,s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path +s;
	//draw_pic(filename);
	InvalidateRect(&picRect);
	// TODO: 在此添加命令处理程序代码
}


void C综合实验一View::OnRecordPrev()
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
	// TODO: 在此添加命令处理程序代码
}


void C综合实验一View::OnRecordNext()
{
	m_pSet->MoveNext();
	if(m_pSet->IsBOF())
		m_pSet->MoveLast();
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	//draw_pic(filename);
	InvalidateRect(&picRect);
	UpdateData(false);
	// TODO: 在此添加命令处理程序代码
}


void C综合实验一View::OnRecordLast()
{
	m_pSet->MoveLast();
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	//draw_pic(filename);
	InvalidateRect(&picRect);
	UpdateData(false);
	// TODO: 在此添加命令处理程序代码
}

void C综合实验一View::draw_pic(CString file)
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

void C综合实验一View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
		   // TODO: 在此处添加消息处理程序代码
	GetDlgItem(IDC_STATIC)->GetClientRect(&picRect);
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	draw_pic(filename);			   // 不为绘图消息调用 CRecordView::OnPaint()
}
