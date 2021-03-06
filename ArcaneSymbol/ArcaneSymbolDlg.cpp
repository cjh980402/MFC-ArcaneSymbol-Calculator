
// ArcaneSymbolDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ArcaneSymbol.h"
#include "ArcaneSymbolDlg.h"
#include "afxdialogex.h"
#include "afxwin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CFont m_font;
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_font.CreatePointFont(80, _T("맑은 고딕"));
	GetDlgItem(IDC_PRODUCER)->SetFont(&m_font);
	GetDlgItem(IDOK)->SetFont(&m_font);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

// CArcaneSymbolDlg 대화 상자



CArcaneSymbolDlg::CArcaneSymbolDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ARCANESYMBOL, pParent)
	, m_fill()
	, m_nowlevnum()
	, m_goallevnum()
	, m_meso()
	, m_time()
	, m_day()
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_YEORO);
	for (int i = 0; i < 6; i++) {
		m_fill[i] = 1;
		m_nowlevnum[i] = 1;
		m_goallevnum[i] = 2;
		m_day[i] = 1;
	}
}

void CArcaneSymbolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	for (int i = 0; i < 6; i++) {
		DDX_Control(pDX, IDC_NOWLEV1 + 17 * i, m_nowlev[i]);
		DDX_Text(pDX, IDC_FILL1 + 17 * i, m_fill[i]);
		DDV_MinMaxInt(pDX, m_fill[i], 0, m_nowlevnum[i] * m_nowlevnum[i] + 11);
		DDX_Control(pDX, IDC_GOALLEV1 + 17 * i, m_goallev[i]);
		DDX_Text(pDX, IDC_DAY1 + 17 * i, m_day[i]);
		DDV_MinMaxInt(pDX, m_day[i], 1, 20);
	}
}

BEGIN_MESSAGE_MAP(CArcaneSymbolDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_NOWLEV1, &CArcaneSymbolDlg::OnCbnSelchangeNowlev1)
	ON_EN_CHANGE(IDC_FILL1, &CArcaneSymbolDlg::OnEnChangeFill1)
	ON_CBN_SELCHANGE(IDC_GOALLEV1, &CArcaneSymbolDlg::OnCbnSelchangeGoallev1)
	ON_BN_CLICKED(IDC_CALCUL, &CArcaneSymbolDlg::OnBnClickedCalcul)
	ON_EN_CHANGE(IDC_DAY1, &CArcaneSymbolDlg::OnEnChangeDay1)
	ON_BN_CLICKED(IDC_INFO, &CArcaneSymbolDlg::OnBnClickedInfo)
	ON_BN_CLICKED(IDC_FIELD1, &CArcaneSymbolDlg::OnBnClickedField1)
	ON_BN_CLICKED(IDC_FIELD2, &CArcaneSymbolDlg::OnBnClickedField2)
	ON_BN_CLICKED(IDC_FIELD3, &CArcaneSymbolDlg::OnBnClickedField3)
	ON_BN_CLICKED(IDC_FIELD4, &CArcaneSymbolDlg::OnBnClickedField4)
	ON_BN_CLICKED(IDC_FIELD5, &CArcaneSymbolDlg::OnBnClickedField5)
	ON_BN_CLICKED(IDC_FIELD6, &CArcaneSymbolDlg::OnBnClickedField6)
	ON_CBN_SELCHANGE(IDC_NOWLEV2, &CArcaneSymbolDlg::OnCbnSelchangeNowlev2)
	ON_EN_CHANGE(IDC_FILL2, &CArcaneSymbolDlg::OnEnChangeFill2)
	ON_EN_CHANGE(IDC_DAY2, &CArcaneSymbolDlg::OnEnChangeDay2)
	ON_CBN_SELCHANGE(IDC_GOALLEV2, &CArcaneSymbolDlg::OnCbnSelchangeGoallev2)
	ON_CBN_SELCHANGE(IDC_NOWLEV3, &CArcaneSymbolDlg::OnCbnSelchangeNowlev3)
	ON_EN_CHANGE(IDC_FILL3, &CArcaneSymbolDlg::OnEnChangeFill3)
	ON_EN_CHANGE(IDC_DAY3, &CArcaneSymbolDlg::OnEnChangeDay3)
	ON_CBN_SELCHANGE(IDC_GOALLEV3, &CArcaneSymbolDlg::OnCbnSelchangeGoallev3)
	ON_CBN_SELCHANGE(IDC_NOWLEV4, &CArcaneSymbolDlg::OnCbnSelchangeNowlev4)
	ON_EN_CHANGE(IDC_FILL4, &CArcaneSymbolDlg::OnEnChangeFill4)
	ON_EN_CHANGE(IDC_DAY4, &CArcaneSymbolDlg::OnEnChangeDay4)
	ON_CBN_SELCHANGE(IDC_GOALLEV4, &CArcaneSymbolDlg::OnCbnSelchangeGoallev4)
	ON_CBN_SELCHANGE(IDC_NOWLEV5, &CArcaneSymbolDlg::OnCbnSelchangeNowlev5)
	ON_EN_CHANGE(IDC_FILL5, &CArcaneSymbolDlg::OnEnChangeFill5)
	ON_EN_CHANGE(IDC_DAY5, &CArcaneSymbolDlg::OnEnChangeDay5)
	ON_CBN_SELCHANGE(IDC_GOALLEV5, &CArcaneSymbolDlg::OnCbnSelchangeGoallev5)
	ON_CBN_SELCHANGE(IDC_NOWLEV6, &CArcaneSymbolDlg::OnCbnSelchangeNowlev6)
	ON_EN_CHANGE(IDC_FILL6, &CArcaneSymbolDlg::OnEnChangeFill6)
	ON_EN_CHANGE(IDC_DAY6, &CArcaneSymbolDlg::OnEnChangeDay6)
	ON_CBN_SELCHANGE(IDC_GOALLEV6, &CArcaneSymbolDlg::OnCbnSelchangeGoallev6)
END_MESSAGE_MAP()


// CArcaneSymbolDlg 메시지 처리기

BOOL CArcaneSymbolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	for (int i = 1; i <= 20; i++) {
		CString temp;
		for (int j = 0; j < 6; j++) {
			temp.Format(_T("%d"), i);
			m_nowlev[j].AddString(temp);
			if (i != 1) {
				m_goallev[j].AddString(temp);
			}
		}
	}
	for (int i = 0; i < 6; i++) {
		m_nowlev[i].SetCurSel(0);
		m_goallev[i].SetCurSel(0);
		CheckDlgButton(IDC_FIELD1 + 17 * i, TRUE);
		// ((CButton*)GetDlgItem(IDC_FIELD1 + 17 * i))->SetCheck(TRUE);
		// 밑에 방법 경우 전체 괄호 필수
	}

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CArcaneSymbolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CArcaneSymbolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CArcaneSymbolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL CArcaneSymbolDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_ESCAPE)
			return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CArcaneSymbolDlg::OnCbnSelchangeNowlev1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString strData;
	m_nowlev[0].GetLBText(m_nowlev[0].GetCurSel(), strData);
	m_nowlevnum[0] = _ttoi(strData);
	int temp1 = m_nowlevnum[0] * m_nowlevnum[0] + 11;
	int temp2 = (m_fill[0] * 100) / temp1;
	strData.Format(_T("%d (%d%%)"), temp1, temp2);
	SetDlgItemText(IDC_PERCENT1, strData);

	UpdateData(FALSE);
}


void CArcaneSymbolDlg::OnEnChangeFill1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString strData;
	strData.Format(_T("%d /"), m_fill[0]);
	SetDlgItemText(IDC_NOWNUM1, strData);

	int temp1 = m_nowlevnum[0] * m_nowlevnum[0] + 11;
	int temp2 = (m_fill[0] * 100) / temp1;
	strData.Format(_T("%d (%d%%)"), temp1, temp2);
	SetDlgItemText(IDC_PERCENT1, strData);

	UpdateData(FALSE);
}



void CArcaneSymbolDlg::OnCbnSelchangeGoallev1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CString strData;
	m_goallev[0].GetLBText(m_goallev[0].GetCurSel(), strData);
	m_goallevnum[0] = _ttoi(strData);
	if (m_goallevnum[0] < m_nowlevnum[0]) {
		AfxMessageBox(_T("목표 레벨은 현재 레벨 이상이어야 합니다."));
		GetDlgItem(IDC_GOALLEV1)->SetFocus();
	}
	UpdateData(FALSE);
}

int CArcaneSymbolDlg::levsb(int lev)
{
	return lev * lev + 11;
}

int CArcaneSymbolDlg::sumsymbol(int lev)
{
	int sum = 0;
	for (int count = 1; count < lev; count++)
	{
		sum += levsb(count);
	}
	return sum;

}

int CArcaneSymbolDlg::summeso(int lev, int type)
{
	int mesoconsts[6] = { 3110000, 6220000, 9330000, 11196000, 11196000 , 11196000 };
	int plusconsts[6] = { 3960000, 4620000, 5280000, 5940000, 5940000 , 5940000 };
	int sum = 0;
	for (int count = 1; count < lev; count++)
	{
		sum += mesoconsts[type] + plusconsts[type] * count;
	}
	return sum;

}

CString CArcaneSymbolDlg::InsertCm(unsigned long long i)
{
	CString B;
	B.Format(_T("%llu"), i);
	int count = 1;
	int len = B.GetLength();
	int temp = 0;
	while (count <= len)
	{
		if (count == len)
			break;
		if ((len - count) % 3 == 0) {
			B.Insert(count + temp, _T(","));
			temp++;
		}
		count++;
	}
	return B;
}

void CArcaneSymbolDlg::OnEnChangeDay1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
}

void CArcaneSymbolDlg::OnBnClickedCalcul()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString s;
	unsigned long long sum = 0;
	int temp = 0;
	for (int i = 0; i < 6; i++) {
		if (m_goallevnum[i] <= m_nowlevnum[i] || IsDlgButtonChecked(IDC_FIELD1 + 17 * i) == FALSE) {
			m_meso[i] = 0;
			m_time[i] = 0;
			if (m_goallevnum[i] < m_nowlevnum[i] && IsDlgButtonChecked(IDC_FIELD1 + 17 * i) == TRUE) {
				AfxMessageBox(_T("목표 레벨은 현재 레벨 이상이어야 합니다."));
				GetDlgItem(IDC_GOALLEV1 + 17 * i)->SetFocus();
			}
		}
		else {
			m_meso[i] = summeso(m_goallevnum[i], i) - summeso(m_nowlevnum[i], i);
			m_time[i] = ceil(((sumsymbol(m_goallevnum[i]) - sumsymbol(m_nowlevnum[i])) - m_fill[i]) / (double)m_day[i]);
		}
		s = InsertCm(m_meso[i]);
		s = s + _T(" 메소");
		SetDlgItemText(IDC_MESO1 + 17 * i, s);

		s = InsertCm(m_time[i]);
		s = s + _T(" 일");
		SetDlgItemText(IDC_TIME1 + 17 * i, s);

		sum = sum + m_meso[i];
		if (temp < m_time[i]) {
			temp = m_time[i];
		}
	}
	s = InsertCm(sum);
	s = s + _T(" 메소");
	SetDlgItemText(IDC_SUMMESO2, s);
	s = InsertCm(temp);
	s = s + _T(" 일");
	SetDlgItemText(IDC_SUMDAY2, s);
}

void CArcaneSymbolDlg::OnBnClickedInfo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CArcaneSymbolDlg::OnBnClickedField1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL check = IsDlgButtonChecked(IDC_FIELD1);

	// 버튼이 눌려 있다면
	if (check == TRUE)
	{
		for (int i = 0; i < 16; i++) {
			GetDlgItem(IDC_NAME1 + i)->EnableWindow(TRUE);
		}
	}
	else
	{
		m_meso[0] = 0;
		m_time[0] = 0;

		CString s;
		s = InsertCm(m_meso[0]);
		s = s + _T(" 메소");
		SetDlgItemText(IDC_MESO1, s);

		s.Format(_T("%d 일"), m_time[0]);
		SetDlgItemText(IDC_TIME1, s);

		for (int i = 0; i < 16; i++) {
			GetDlgItem(IDC_NAME1 + i)->EnableWindow(FALSE);
		}
	}
}

void CArcaneSymbolDlg::OnBnClickedField2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL check = IsDlgButtonChecked(IDC_FIELD2);

	// 버튼이 눌려 있다면
	if (check == TRUE)
	{
		for (int i = 0; i < 16; i++) {
			GetDlgItem(IDC_NAME2 + i)->EnableWindow(TRUE);
		}
	}
	else
	{
		m_meso[1] = 0;
		m_time[1] = 0;

		CString s;
		s = InsertCm(m_meso[1]);
		s = s + _T(" 메소");
		SetDlgItemText(IDC_MESO2, s);

		s.Format(_T("%d 일"), m_time[1]);
		SetDlgItemText(IDC_TIME2, s);

		for (int i = 0; i < 16; i++) {
			GetDlgItem(IDC_NAME2 + i)->EnableWindow(FALSE);
		}
	}
}


void CArcaneSymbolDlg::OnBnClickedField3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL check = IsDlgButtonChecked(IDC_FIELD3);

	// 버튼이 눌려 있다면
	if (check == TRUE)
	{
		for (int i = 0; i < 16; i++) {
			GetDlgItem(IDC_NAME3 + i)->EnableWindow(TRUE);
		}
	}
	else
	{
		m_meso[2] = 0;
		m_time[2] = 0;

		CString s;
		s = InsertCm(m_meso[2]);
		s = s + _T(" 메소");
		SetDlgItemText(IDC_MESO3, s);

		s.Format(_T("%d 일"), m_time[2]);
		SetDlgItemText(IDC_TIME3, s);

		for (int i = 0; i < 16; i++) {
			GetDlgItem(IDC_NAME3 + i)->EnableWindow(FALSE);
		}
	}
}


void CArcaneSymbolDlg::OnBnClickedField4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL check = IsDlgButtonChecked(IDC_FIELD4);

	// 버튼이 눌려 있다면
	if (check == TRUE)
	{
		for (int i = 0; i < 16; i++) {
			GetDlgItem(IDC_NAME4 + i)->EnableWindow(TRUE);
		}
	}
	else
	{
		m_meso[3] = 0;
		m_time[3] = 0;

		CString s;
		s = InsertCm(m_meso[3]);
		s = s + _T(" 메소");
		SetDlgItemText(IDC_MESO4, s);

		s.Format(_T("%d 일"), m_time[3]);
		SetDlgItemText(IDC_TIME4, s);

		for (int i = 0; i < 16; i++) {
			GetDlgItem(IDC_NAME4 + i)->EnableWindow(FALSE);
		}
	}
}


void CArcaneSymbolDlg::OnBnClickedField5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL check = IsDlgButtonChecked(IDC_FIELD5);

	// 버튼이 눌려 있다면
	if (check == TRUE)
	{
		for (int i = 0; i < 16; i++) {
			GetDlgItem(IDC_NAME5 + i)->EnableWindow(TRUE);
		}
	}
	else
	{
		m_meso[4] = 0;
		m_time[4] = 0;

		CString s;
		s = InsertCm(m_meso[4]);
		s = s + _T(" 메소");
		SetDlgItemText(IDC_MESO5, s);

		s.Format(_T("%d 일"), m_time[1]);
		SetDlgItemText(IDC_TIME5, s);

		for (int i = 0; i < 16; i++) {
			GetDlgItem(IDC_NAME5 + i)->EnableWindow(FALSE);
		}
	}
}


void CArcaneSymbolDlg::OnBnClickedField6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL check = IsDlgButtonChecked(IDC_FIELD6);

	// 버튼이 눌려 있다면
	if (check == TRUE)
	{
		for (int i = 0; i < 16; i++) {
			GetDlgItem(IDC_NAME6 + i)->EnableWindow(TRUE);
		}
	}
	else
	{
		m_meso[5] = 0;
		m_time[5] = 0;

		CString s;
		s = InsertCm(m_meso[5]);
		s = s + _T(" 메소");
		SetDlgItemText(IDC_MESO6, s);

		s.Format(_T("%d 일"), m_time[5]);
		SetDlgItemText(IDC_TIME6, s);

		for (int i = 0; i < 16; i++) {
			GetDlgItem(IDC_NAME6 + i)->EnableWindow(FALSE);
		}
	}
}


void CArcaneSymbolDlg::OnCbnSelchangeNowlev2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString strData;
	m_nowlev[1].GetLBText(m_nowlev[1].GetCurSel(), strData);
	m_nowlevnum[1] = _ttoi(strData);
	int temp1 = m_nowlevnum[1] * m_nowlevnum[1] + 11;
	int temp2 = (m_fill[1] * 100) / temp1;
	strData.Format(_T("%d (%d%%)"), temp1, temp2);
	SetDlgItemText(IDC_PERCENT2, strData);

	UpdateData(FALSE);
}


void CArcaneSymbolDlg::OnEnChangeFill2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString strData;
	strData.Format(_T("%d /"), m_fill[1]);
	SetDlgItemText(IDC_NOWNUM2, strData);

	int temp1 = m_nowlevnum[1] * m_nowlevnum[1] + 11;
	int temp2 = (m_fill[1] * 100) / temp1;
	strData.Format(_T("%d (%d%%)"), temp1, temp2);
	SetDlgItemText(IDC_PERCENT2, strData);

	UpdateData(FALSE);
}


void CArcaneSymbolDlg::OnEnChangeDay2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
}


void CArcaneSymbolDlg::OnCbnSelchangeGoallev2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CString strData;
	m_goallev[1].GetLBText(m_goallev[1].GetCurSel(), strData);
	m_goallevnum[1] = _ttoi(strData);
	if (m_goallevnum[1] < m_nowlevnum[1]) {
		AfxMessageBox(_T("목표 레벨은 현재 레벨 이상이어야 합니다."));
		GetDlgItem(IDC_GOALLEV2)->SetFocus();
	}
	UpdateData(FALSE);
}


void CArcaneSymbolDlg::OnCbnSelchangeNowlev3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString strData;
	m_nowlev[2].GetLBText(m_nowlev[2].GetCurSel(), strData);
	m_nowlevnum[2] = _ttoi(strData);
	int temp1 = m_nowlevnum[2] * m_nowlevnum[2] + 11;
	int temp2 = (m_fill[2] * 100) / temp1;
	strData.Format(_T("%d (%d%%)"), temp1, temp2);
	SetDlgItemText(IDC_PERCENT3, strData);

	UpdateData(FALSE);
}


void CArcaneSymbolDlg::OnEnChangeFill3()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString strData;
	strData.Format(_T("%d /"), m_fill[2]);
	SetDlgItemText(IDC_NOWNUM3, strData);

	int temp1 = m_nowlevnum[2] * m_nowlevnum[2] + 11;
	int temp2 = (m_fill[2] * 100) / temp1;
	strData.Format(_T("%d (%d%%)"), temp1, temp2);
	SetDlgItemText(IDC_PERCENT3, strData);

	UpdateData(FALSE);
}


void CArcaneSymbolDlg::OnEnChangeDay3()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
}


void CArcaneSymbolDlg::OnCbnSelchangeGoallev3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CString strData;
	m_goallev[2].GetLBText(m_goallev[2].GetCurSel(), strData);
	m_goallevnum[2] = _ttoi(strData);
	if (m_goallevnum[2] < m_nowlevnum[2]) {
		AfxMessageBox(_T("목표 레벨은 현재 레벨 이상이어야 합니다."));
		GetDlgItem(IDC_GOALLEV3)->SetFocus();
	}
	UpdateData(FALSE);
}


void CArcaneSymbolDlg::OnCbnSelchangeNowlev4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString strData;
	m_nowlev[3].GetLBText(m_nowlev[3].GetCurSel(), strData);
	m_nowlevnum[3] = _ttoi(strData);
	int temp1 = m_nowlevnum[3] * m_nowlevnum[3] + 11;
	int temp2 = (m_fill[3] * 100) / temp1;
	strData.Format(_T("%d (%d%%)"), temp1, temp2);
	SetDlgItemText(IDC_PERCENT4, strData);

	UpdateData(FALSE);
}


void CArcaneSymbolDlg::OnEnChangeFill4()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString strData;
	strData.Format(_T("%d /"), m_fill[3]);
	SetDlgItemText(IDC_NOWNUM4, strData);

	int temp1 = m_nowlevnum[3] * m_nowlevnum[3] + 11;
	int temp2 = (m_fill[3] * 100) / temp1;
	strData.Format(_T("%d (%d%%)"), temp1, temp2);
	SetDlgItemText(IDC_PERCENT4, strData);

	UpdateData(FALSE);
}


void CArcaneSymbolDlg::OnEnChangeDay4()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
}


void CArcaneSymbolDlg::OnCbnSelchangeGoallev4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CString strData;
	m_goallev[3].GetLBText(m_goallev[3].GetCurSel(), strData);
	m_goallevnum[3] = _ttoi(strData);
	if (m_goallevnum[3] < m_nowlevnum[3]) {
		AfxMessageBox(_T("목표 레벨은 현재 레벨 이상이어야 합니다."));
		GetDlgItem(IDC_GOALLEV4)->SetFocus();
	}
	UpdateData(FALSE);
}


void CArcaneSymbolDlg::OnCbnSelchangeNowlev5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString strData;
	m_nowlev[4].GetLBText(m_nowlev[4].GetCurSel(), strData);
	m_nowlevnum[4] = _ttoi(strData);
	int temp1 = m_nowlevnum[4] * m_nowlevnum[4] + 11;
	int temp2 = (m_fill[4] * 100) / temp1;
	strData.Format(_T("%d (%d%%)"), temp1, temp2);
	SetDlgItemText(IDC_PERCENT5, strData);

	UpdateData(FALSE);
}


void CArcaneSymbolDlg::OnEnChangeFill5()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString strData;
	strData.Format(_T("%d /"), m_fill[4]);
	SetDlgItemText(IDC_NOWNUM5, strData);

	int temp1 = m_nowlevnum[4] * m_nowlevnum[4] + 11;
	int temp2 = (m_fill[4] * 100) / temp1;
	strData.Format(_T("%d (%d%%)"), temp1, temp2);
	SetDlgItemText(IDC_PERCENT5, strData);

	UpdateData(FALSE);
}


void CArcaneSymbolDlg::OnEnChangeDay5()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
}


void CArcaneSymbolDlg::OnCbnSelchangeGoallev5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CString strData;
	m_goallev[4].GetLBText(m_goallev[4].GetCurSel(), strData);
	m_goallevnum[4] = _ttoi(strData);
	if (m_goallevnum[4] < m_nowlevnum[4]) {
		AfxMessageBox(_T("목표 레벨은 현재 레벨 이상이어야 합니다."));
		GetDlgItem(IDC_GOALLEV5)->SetFocus();
	}
	UpdateData(FALSE);
}


void CArcaneSymbolDlg::OnCbnSelchangeNowlev6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString strData;
	m_nowlev[5].GetLBText(m_nowlev[5].GetCurSel(), strData);
	m_nowlevnum[5] = _ttoi(strData);
	int temp1 = m_nowlevnum[5] * m_nowlevnum[5] + 11;
	int temp2 = (m_fill[5] * 100) / temp1;
	strData.Format(_T("%d (%d%%)"), temp1, temp2);
	SetDlgItemText(IDC_PERCENT6, strData);

	UpdateData(FALSE);
}


void CArcaneSymbolDlg::OnEnChangeFill6()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString strData;
	strData.Format(_T("%d /"), m_fill[5]);
	SetDlgItemText(IDC_NOWNUM6, strData);

	int temp1 = m_nowlevnum[5] * m_nowlevnum[5] + 11;
	int temp2 = (m_fill[5] * 100) / temp1;
	strData.Format(_T("%d (%d%%)"), temp1, temp2);
	SetDlgItemText(IDC_PERCENT6, strData);

	UpdateData(FALSE);
}


void CArcaneSymbolDlg::OnEnChangeDay6()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
}


void CArcaneSymbolDlg::OnCbnSelchangeGoallev6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CString strData;
	m_goallev[5].GetLBText(m_goallev[5].GetCurSel(), strData);
	m_goallevnum[5] = _ttoi(strData);
	if (m_goallevnum[5] < m_nowlevnum[5]) {
		AfxMessageBox(_T("목표 레벨은 현재 레벨 이상이어야 합니다."));
		GetDlgItem(IDC_GOALLEV6)->SetFocus();
	}
	UpdateData(FALSE);
}



void CArcaneSymbolDlg::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	// CDialogEx::OnOK();
}
