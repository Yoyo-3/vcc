
// MFC13.3View.h : CMFC133View ��Ľӿ�
//

#pragma once

class CMFC133Set;

class CMFC133View : public CRecordView
{
protected: // �������л�����
	CMFC133View();
	DECLARE_DYNCREATE(CMFC133View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC133_FORM };
#endif
	CMFC133Set* m_pSet;

// ����
public:
	CMFC133Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFC133View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString s;
	afx_msg void OnBnClickedButtonDelect();
	afx_msg void OnBnClickedButton1Add();
	long s1;
	afx_msg void OnBnClickedButtonRevise();
};

#ifndef _DEBUG  // MFC13.3View.cpp �еĵ��԰汾
inline CMFC133Doc* CMFC133View::GetDocument() const
   { return reinterpret_cast<CMFC133Doc*>(m_pDocument); }
#endif

