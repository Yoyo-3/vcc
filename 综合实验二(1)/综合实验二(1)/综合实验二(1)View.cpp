
// 综合实验二(1)View.cpp : C综合实验二1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "综合实验二(1).h"
#endif

#include "综合实验二(1)Set.h"
#include "综合实验二(1)Doc.h"
#include "综合实验二(1)View.h"
#include "MyDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C综合实验二1View

IMPLEMENT_DYNCREATE(C综合实验二1View, CRecordView)

BEGIN_MESSAGE_MAP(C综合实验二1View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &C综合实验二1View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C综合实验二1View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C综合实验二1View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C综合实验二1View::OnRecordLast)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &C综合实验二1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// C综合实验二1View 构造/析构

C综合实验二1View::C综合实验二1View()
	: CRecordView(IDD_MY1_FORM)
	, x(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("C:\\Users\\lijie13347586275\\Pictures\\Saved Pictures\\");
}

C综合实验二1View::~C综合实验二1View()
{
}

void C综合实验二1View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL C综合实验二1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C综合实验二1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_综合实验二1Set;
	CRecordView::OnInitialUpdate();

}


// C综合实验二1View 诊断

#ifdef _DEBUG
void C综合实验二1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C综合实验二1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C综合实验二1Doc* C综合实验二1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C综合实验二1Doc)));
	return (C综合实验二1Doc*)m_pDocument;
}
#endif //_DEBUG


// C综合实验二1View 数据库支持
CRecordset* C综合实验二1View::OnGetRecordset()
{
	return m_pSet;
}



// C综合实验二1View 消息处理程序


void C综合实验二1View::OnRecordFirst()
{
	m_pSet->MoveFirst();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	//draw_pic(filename);
	InvalidateRect(&picRect);
	// TODO: 在此添加命令处理程序代码
}


void C综合实验二1View::OnRecordPrev()
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


void  C综合实验二1View::OnRecordNext()
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
	// TODO: 在此添加命令处理程序代码
}


void  C综合实验二1View::OnRecordLast()
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

void  C综合实验二1View::draw_pic(CString file)
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

void C综合实验二1View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
	GetDlgItem(IDC_STATIC)->GetClientRect(&picRect);
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	draw_pic(filename);						   // 不为绘图消息调用 CRecordView::OnPaint()
}


void C综合实验二1View::OnBnClickedButton1()
{
	MyDlg dlg;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	dlg.str = filename;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
	}
	// TODO: 在此添加控件通知处理程序代码
}
