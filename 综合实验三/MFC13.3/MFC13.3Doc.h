
// MFC13.3Doc.h : CMFC133Doc ��Ľӿ�
//


#pragma once
#include "MFC13.3Set.h"


class CMFC133Doc : public CDocument
{
protected: // �������л�����
	CMFC133Doc();
	DECLARE_DYNCREATE(CMFC133Doc)

// ����
public:
	CMFC133Set m_MFC133Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFC133Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
