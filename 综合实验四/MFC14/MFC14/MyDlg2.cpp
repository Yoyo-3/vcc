// MyDlg2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC14.h"
#include "MyDlg2.h"
#include "afxdialogex.h"


// MyDlg2 �Ի���

IMPLEMENT_DYNAMIC(MyDlg2, CDialogEx)

MyDlg2::MyDlg2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, a(_T(""))
{

}

MyDlg2::~MyDlg2()
{
}

void MyDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
}


BEGIN_MESSAGE_MAP(MyDlg2, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// MyDlg2 ��Ϣ�������


void MyDlg2::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}
