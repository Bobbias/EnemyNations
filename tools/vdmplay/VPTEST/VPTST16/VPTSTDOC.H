// vptstdoc.h : interface of the CVptst16Doc class
//
/////////////////////////////////////////////////////////////////////////////

class CVptst16Doc : public CDocument
{
protected: // create from serialization only
	CVptst16Doc();
	DECLARE_DYNCREATE(CVptst16Doc)

// Attributes
public:
// Operations
public:

// Implementation
public:
	virtual ~CVptst16Doc();
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual BOOL OnNewDocument();

// Generated message map functions
protected:
	//{{AFX_MSG(CVptst16Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
