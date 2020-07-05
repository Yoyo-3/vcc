
// MFC14View.h : CMFC14View ��Ľӿ�
//

#pragma once

class CMFC14Set;

class CMFC14View : public CRecordView
{
protected: // �������л�����
	CMFC14View();
	DECLARE_DYNCREATE(CMFC14View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC14_FORM };
#endif
	CMFC14Set* m_pSet;

// ����
public:
	CMFC14Doc* GetDocument() const;

// ����
public:
	CString filename,path,s;

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFC14View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
	void draw_pic(CString file);
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	long number;
	CString name;
	long age;
	CString address;
	afx_msg void OnPaint();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnBnClickedButton1();
	afx_msg void Onsort();
	afx_msg void Oninquire();
	afx_msg void Onadd();
	afx_msg void Ondelect();
	afx_msg void Onalter();
	afx_msg void Onrecordset();
};

#ifndef _DEBUG  // MFC14View.cpp �еĵ��԰汾
inline CMFC14Doc* CMFC14View::GetDocument() const
   { return reinterpret_cast<CMFC14Doc*>(m_pDocument); }
#endif

