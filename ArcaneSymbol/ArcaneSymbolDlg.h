
// ArcaneSymbolDlg.h: 헤더 파일
//

#pragma once
#include "afxwin.h"


// CArcaneSymbolDlg 대화 상자
class CArcaneSymbolDlg : public CDialogEx
{
// 생성입니다.
public:
	CArcaneSymbolDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ARCANESYMBOL };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CComboBox m_nowlev[6];
	afx_msg void OnCbnSelchangeNowlev1();
	afx_msg void OnEnChangeFill1();
	int m_fill[6];
	int m_nowlevnum[6];
	int m_goallevnum[6];
	CComboBox m_goallev[6];
	afx_msg void OnCbnSelchangeGoallev1();
	int m_meso[6];
	int m_time[6];
	int levsb(int lev);
	int sumsymbol(int lev);
	int summeso(int lev, int type);
	CString InsertCm(unsigned long long i);
	int m_day[6];
	afx_msg void OnBnClickedCalcul();
	afx_msg void OnEnChangeDay1();
	afx_msg void OnBnClickedInfo();
	afx_msg void OnBnClickedField1();
	afx_msg void OnBnClickedField2();
	afx_msg void OnBnClickedField3();
	afx_msg void OnBnClickedField4();
	afx_msg void OnBnClickedField5();
	afx_msg void OnBnClickedField6();
	
	afx_msg void OnCbnSelchangeNowlev2();
	afx_msg void OnEnChangeFill2();
	afx_msg void OnEnChangeDay2();
	afx_msg void OnCbnSelchangeGoallev2();
	afx_msg void OnCbnSelchangeNowlev3();
	afx_msg void OnEnChangeFill3();
	afx_msg void OnEnChangeDay3();
	afx_msg void OnCbnSelchangeGoallev3();
	afx_msg void OnCbnSelchangeNowlev4();
	afx_msg void OnEnChangeFill4();
	afx_msg void OnEnChangeDay4();
	afx_msg void OnCbnSelchangeGoallev4();
	afx_msg void OnCbnSelchangeNowlev5();
	afx_msg void OnEnChangeFill5();
	afx_msg void OnEnChangeDay5();
	afx_msg void OnCbnSelchangeGoallev5();
	afx_msg void OnCbnSelchangeNowlev6();
	afx_msg void OnEnChangeFill6();
	afx_msg void OnEnChangeDay6();
	afx_msg void OnCbnSelchangeGoallev6();
	virtual void OnOK();
};
