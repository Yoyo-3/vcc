
// MFC13.2Dlg.h : ͷ�ļ�
//

#pragma once


// CMFC132Dlg �Ի���
class CMFC132Dlg : public CDialogEx
{
// ����
public:
	CMFC132Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	CString s;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC132_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
