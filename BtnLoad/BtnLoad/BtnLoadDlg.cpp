
// BtnLoadDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "BtnLoad.h"
#include "BtnLoadDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int doc_idx, word_idx, nr_word, test;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U;
char temp_text[53][1000];
CFont m_font;
CString m_Edit_buf;
CString PASS_FAIL;

int GetDirFilesNum(CString dirName);


//void FindSubDir(CString strDir, CStringArray &FileArray);

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBtnLoadDlg 대화 상자



CBtnLoadDlg::CBtnLoadDlg(CWnd* pParent /*=NULL*/): CDialogEx(CBtnLoadDlg::IDD, pParent), m_strStatus(_T(""))
, m_Edit(_T(""))
, m_RadioButton_3(0)
, m_Radio1(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBtnLoadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONSOLE, m_strStatus);
	DDX_Control(pDX, IDC_EDIT_CONSOLE, m_ctrlStatus);
	DDX_Text(pDX, IDC_EDIT_CONSOLE2, m_strStatus_1);
	DDX_Control(pDX, IDC_EDIT_CONSOLE2, m_ctrlStatus_1);
	////DDX_Control(pDX, IDC_EDIT_CONSOLE3, m_ctrlStatus_2);
	////DDX_Control(pDX, IDC_EDIT1, m_ctrlStatus_2);
	DDX_Text(pDX, IDC_EDIT2, m_Edit);
	//DDX_Control(pDX, IDC_TEXT, m_Text);
	//DDX_Control(pDX, IDC_PICVIEW, m_image);

	DDX_Control(pDX, IDC_TEXT1, m_Text1);
	DDX_Control(pDX, IDC_RADIO1, m_RadioButton_1);
	DDX_Control(pDX, IDC_RADIO2, m_RadioButton_2);
	//((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(1);

	DDX_Radio(pDX, IDC_RADIO1, m_Radio1);
}

BEGIN_MESSAGE_MAP(CBtnLoadDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CBtnLoadDlg::OnBnClickedOk)
	//ON_BN_CLICKED(ID_BTN_LOAD, &CBtnLoadDlg::OnBnClickedBtnLoad)
	ON_COMMAND(IDCLOSE, &CBtnLoadDlg::OnIdclose)
	ON_WM_CLOSE()
	//ON_BN_CLICKED(ID_BTN_SAVE, &CBtnLoadDlg::OnBnClickedBtnSave)
	//ON_BN_CLICKED(ID_BTN_LOAD3, &CBtnLoadDlg::OnBnClickedBtnLoad3)
	ON_BN_CLICKED(ID_BTN_LOAD4, &CBtnLoadDlg::OnBnClickedBtnLoad4)
	//ON_BN_CLICKED(ID_BTN_LOAD5, &CBtnLoadDlg::OnBnClickedBtnLoad5)
	//ON_BN_CLICKED(IDC_BUTTON1, &CBtnLoadDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CBtnLoadDlg::OnBnClickedButton2)
	//ON_EN_CHANGE(IDC_EDIT1, &CBtnLoadDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CBtnLoadDlg 메시지 처리기

BOOL CBtnLoadDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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
	m_font.CreateFontW(50, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, 0, 0, 0, 0, 0, _T("굴림"));

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CBtnLoadDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBtnLoadDlg::OnPaint()
{
	//CStatic* m_image = (CStatic*)GetDlgItem(IDC_PICVIEW);
	CBitmap image;
	image.LoadBitmapW(IDB_BITMAP3);
	//m_image->SetBitmap(image);

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
HCURSOR CBtnLoadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBtnLoadDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}
void CBtnLoadDlg::OnClose()
{
	CDialogEx::OnOK();
	CDialogEx::OnClose();
}


void CBtnLoadDlg::OnBnClickedBtnLoad()
{
	printf("[OnBnClickedBtnOpen] \n");
	CStdioFile ftxt;
	int i = 0;
	int j;

	char str_text4;

		
	CFileException kEx;
	CFileDialog dlg(TRUE, _T("*.csv"), NULL, OFN_FILEMUSTEXIST, _T("CSV Files(*.csv)|*.csv|"), NULL);
	if (dlg.DoModal() == IDOK)
	{
		// Get file name 
		m_strPath = dlg.GetPathName();
		char charPtr[500];
		sprintf(charPtr, "%S", m_strPath);
		//sprintf(charPtr, "%S", "C:\\Users\\user\\Desktop\\Master\\20181205_112222.csv");
	
		CString file_name = dlg.GetFileName();
		CString m_strStatus_temp;
		CString TEST;
		
		m_strStatus += "File name: ";
		m_strStatus += file_name;
		m_strStatus += "\r\n";
		TEST = file_name.Left(8);
		// Set path to load 
		m_strStatus += "File path: ";
		m_strStatus += m_strPath;
		m_strStatus += "\r\n";
		ifp = fopen(charPtr, "r");
		
		
		
		// Save folder path for further saving 
		m_strFolderPath = m_strPath.Left(m_strPath.GetLength() - file_name.GetLength());
		m_strStatus += "Folder path: ";
		m_strStatus += m_strFolderPath;
		m_strStatus += "\r\n";

		// Load file using ifp
		// 1. Count number of items
		/*int nr_data = 0; 
		for (int i = 0;; i++){
			int doc_idx, word_idx, nr_word;
			if (fscanf(ifp, "%d,%d,%d", &doc_idx, &word_idx, &nr_word) == EOF)
				break;
			// count number of items
			nr_data++;
		}
		CString strTemp; strTemp.Format(L"nr_data: %d \r\n", nr_data);
		m_strStatus += strTemp;*/

		int nr_data = 60;
		char NULL_count = 0;
		char flag = 0;
		char str_temp[1000];
		char str_temp1[1000];
		char *pstr;
		memset(str_temp, NULL, 1000);
		memset(str_temp1, NULL, 1000);

		/*while (!feof(ifp)){
			pstr = fgets(str_temp, sizeof(str_temp), ifp);
			//pstr1 = fgets(str_temp1, sizeof(str_temp1), ifp);
		}*/
		while (!feof(ifp))
		{
			pstr = fgets(str_temp, sizeof(str_temp), ifp);
			/*TEST.Format(L"[%d/] // %s\r\n", 1, pstr);
			m_strStatus += TEST;*/
			for (j = 0; j < 1000; j++){
				if (str_temp[j] == NULL){
					break;
				}
				temp_text[i][j] = str_temp[j];
			}
			if ((i > 1)&&(j > 2) ){

				str_text4 = temp_text[i][j - 4];

			TEST.Format(L"%c\r\n", str_text4);
			m_strStatus += TEST;
			}

			i++;

			//len = strlen(temp_text[i][]);

		}

		/*for (int i = 0;; i++){
			
			//fscanf(ifp, "%d,%d,%d,%d", &doc_idx, &word_idx, &nr_word, &test);
			if ((fscanf(ifp, "%s,%s,%s,%s", doc_idx, word_idx, nr_word, test) == EOF) && ((ifp && " L & C (ABOVE 1UF) DISCHARGE") == true));
				break;


			// count number of items
					//else
			nr_data++;
		}*/


		CString strTemp; strTemp.Format(L"nr_data: %d \r\n", nr_data);
		m_strStatus += strTemp;

		// 2. Allocate memory & Load
		/*rewind(ifp);
		data = (int**)malloc(nr_data*sizeof(int*));
		for (int i = 0; i < nr_data; i++) {
			data[i] = (int*)malloc(3 * sizeof(int));
			
			if (fscanf(ifp, "%d,%d,%d", &data[i][0], &data[i][1], &data[i][2]) == EOF)
				break;
			else
			{
				printf("%d: %d / %d / %d \n", i, data[i][0], data[i][1], data[i][2]);
			}
		}*/
		/*rewind(ifp);
		data = (int**)malloc(nr_data*sizeof(int*));
		for (int i = 3; i < nr_data; i++) {
			data[i] = (int*)malloc(4 * sizeof(int));

			if (fscanf(ifp, "%C,%C,%C,%C", &data[i][0], &data[i][1], &data[i][2], &data[i][3]) == EOF)
				break;
			else
			{
				printf("%d: %d / %d / %d // %d\n", i, data[i][0], data[i][1], data[i][2], data[i][3]);
			}
		}*/

		/*while (!feof(ifp))
		{
			pstr = fgets(str_temp, sizeof(str_temp), ifp);
			TEST.Format(L"[%d/] // %s\r\n", 1, pstr);
			m_strStatus += TEST;
		}*/

		// 3. Show data loaded 
		/*for (int i = 3; i < nr_data; i++)
		{
			CString strTemp; 
			//strTemp.Format(L"[%d/%d] / %d %d %d / %d\r\n" , i + 1, nr_data, data[i][0], data[i][1], data[i][2], data[i][3]);
			strTemp.Format(L"[%d/%d] // %d\r\n", i + 1, nr_data, data[i][3]);
			m_strStatus += strTemp;
		}*/
				
		// 가장 최근 줄에 focus가 가도록 한다. (왜 잘 동작안할까..)
		int str_len = m_ctrlStatus.GetLineCount();
		m_ctrlStatus.LineScroll(str_len);
		// Update text
		UpdateData(FALSE);

	}
}

void CBtnLoadDlg::OnBnClickedBtnSave()
{
	printf("[OnBnClickedBtnSave] \n");
	CString m_strPath;
	CStdioFile file;
	// CFile file;
	CFileException ex;
	CFileDialog dlg(FALSE, _T("*.txt"), NULL, OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT, _T("TXT Files(*.txt)|*.txt|"), NULL);
	if (dlg.DoModal() == IDOK)
	{
		m_strPath = dlg.GetPathName();
		if (m_strPath.Right(4) != ".txt")
		{
			m_strPath += ".txt";
		}
		file.Open(m_strPath, CFile::modeCreate | CFile::modeReadWrite, &ex);
		// 에디트 박스에 있는 것을 저장한다. 
		UpdateData(TRUE);
		file.WriteString(m_strStatus);
		// 종료한다. 
		file.Close();
	}
}


void CBtnLoadDlg::OnIdclose()
{
	
}






void CBtnLoadDlg::OnBnClickedBtnLoad3()
{
	//CFileDialog dlg(TRUE, _T("*.csv"), NULL, OFN_FILEMUSTEXIST, _T("CSV Files(*.csv)|*.csv|"), NULL);

	TCHAR szBuf[MAX_PATH] = { 0, };
	TCHAR szBuf_File_Address[MAX_PATH] = { 0, };
	CString strInIPath(_T("D:\\ICT_Inspection_Log\\FCM-30S-IMAGER\\Main.ini"));
	CString strSection, strKey, strValue;

	CString Filename, file_name;
	CString str_default;
	CString test_flag, test_flag_1, test_flag_2;
	CString str_default_1, str_default_2;
	CString PASS_FAIL_TEST;

	CString Address_buf;
	CFileFind finder;

	BOOL bWorking;

	char str_temp[200];
	char *pstr;

	strSection = _T("Main");
	strKey = _T("Main_File_Address");
	GetPrivateProfileString(strSection, strKey, _T(""), szBuf_File_Address, MAX_PATH, strInIPath);
	strValue.Format(_T("%s"), szBuf_File_Address);

	Address_buf = szBuf_File_Address;

	bWorking = finder.FindFile(Address_buf + _T("\\*"));
	while (bWorking){
		bWorking = finder.FindNextFile();
		if ((finder.GetFileName() == ".") || (finder.GetFileName() == "..") || (finder.GetFileName() == "Main.ini"))
			continue;
		else{
			Filename = finder.GetFileName();
			//m_strStatus_1 += finder.GetFileName();
			//m_strStatus_1 += "\r\n";
		}


		m_strPath_1 = szBuf_File_Address + Filename;
		char charPtr[500];
		sprintf(charPtr, "%S", m_strPath_1);

		ifp = fopen(charPtr, "r");

		memset(str_temp, NULL, 200);
		
		while (!feof(ifp))
		{
			pstr = fgets(str_temp, sizeof(str_temp), ifp);
			str_default = (LPSTR)str_temp;

			AfxExtractSubString(test_flag, str_default, 0, ',');

			if (AfxExtractSubString(test_flag_1, test_flag, 1, '#')){
				//count = test_flag.Find('#');
				//st = LPSTR(LPCTSTR(test_flag_1));

				test_flag_2 = '#' + test_flag_1;
				test_flag = test_flag.Left(test_flag.GetLength() - test_flag_2.GetLength());

			}
			if (((test_flag.Compare(L" L3001/NP")) == 0) || ((test_flag.Compare(L" L3002/NP")) == 0) || ((test_flag.Compare(L" C3005/C")) == 0)){
				continue;
			}
			else{
				AfxExtractSubString(str_default_1, str_default, 13, ',');
				AfxExtractSubString(str_default_2, str_default_1, 1, ' ');
				//m_strStatus_1 += test_flag;
				//m_strStatus_1 += "\t";
				m_strStatus_1 += str_default_2;
				PASS_FAIL_TEST += str_default_2;

			}
			
		}
		m_strStatus_1 += "\r\n";
	}
}


void CBtnLoadDlg::OnBnClickedBtnLoad4()
{
	CString Module_Selection;
	UpdateData(true);

	switch (m_Radio1){
	case 0:
		Module_Selection = "FCM-30S";
		MessageBox(TEXT("1번"));
		break;
	case 1:
		Module_Selection = "FCM-30W";
		MessageBox(TEXT("2번"));
		break;
	case 2:
		Module_Selection = "FCM-20";
		MessageBox(TEXT("3번"));
		break;
	}

	TCHAR szBuf[MAX_PATH] = { 0, };
	TCHAR szBuf_File_Address[MAX_PATH] = { 0, };
	CString strInIPath(_T("D:\\ICT_Inspection_Log\\FCM-30S-IMAGER\\Main.ini"));
	CString strSection, strKey, strValue;
	//CString Default

	printf("[OnBnClickedBtnOpen] \n");
	CStdioFile ftxt;
	int i = 0;
	int de_i = 0;
	int de_i_test = 0;

	int nr_data = -1;

	char flag = 0;
	char str_temp[200];
	char PASS_FAIL_temp[60][80];
	char* st;
	int count;
	char *pstr;

	char compare_flag = 0;
	char short_compare_count = 0;
	char open_compare_count = 0;
	char PASS_compare_count = 0;
	//int compare_count = 0;
	int num_i = 0;

	CString str_default, str_default_1, str_default_2;
	CString test_flag, test_flag_1, test_flag_2;
	CString test;

	CString PASS_FAIL_TEST;
	CString One_Line_Data;

	CString m_strPath_test;
	CString Address_buf;
	CString Filename;

	CString file_name;
	CString m_strStatus_temp;
	CString TEST;

	CStringArray strArray;
	CStringArray strArray_Compare;
	CString arrat_buf;
	CString arrat_buf_1;

	CFileFind finder;
	BOOL bWorking;
	CFileException kEx;
	CFileDialog dlg(TRUE, _T("*.csv"), NULL, OFN_FILEMUSTEXIST, _T("CSV Files(*.csv)|*.csv|"), NULL);


	//----------------------------Master File------------------------------------//
	strSection = _T("Main");

	strKey = _T("Main_File_Address");
	GetPrivateProfileString(strSection, strKey, _T(""), szBuf_File_Address, MAX_PATH, strInIPath);
	strValue.Format(_T("%s"), szBuf_File_Address);

	Address_buf = szBuf_File_Address; // Master forder name Setch

	bWorking = finder.FindFile(Address_buf + _T("\\*"));
	while (bWorking){
		bWorking = finder.FindNextFile();
		if ((finder.GetFileName() == ".") || (finder.GetFileName() == "..") || (finder.GetFileName() == "Main.ini"))
			continue;
		else{
			Filename = finder.GetFileName();
			//m_strStatus_1 += finder.GetFileName();
			//m_strStatus_1 += "\r\n";
		}


		m_strPath_1 = szBuf_File_Address + Filename;
		char charPtr[500];
		sprintf(charPtr, "%S", m_strPath_1);

		file_name = dlg.GetFileName();

		/*m_strStatus_1 += "File name: ";
		m_strStatus_1 += file_name;
		m_strStatus_1 += "\r\n";*/
		AfxExtractSubString(TEST, Filename, 0, '-');
		// Set path to load 
		/*m_strStatus_1 += "File path: ";
		m_strStatus_1 += m_strPath_1;
		m_strStatus_1 += "\r\n";*/
		ifp = fopen(charPtr, "r");

		// Save folder path for further saving 
		m_strFolderPath_1 = m_strPath_1.Left(m_strPath_1.GetLength() - file_name.GetLength());
		/*m_strStatus_1 += "Folder path: ";
		m_strStatus_1 += m_strFolderPath_1;
		m_strStatus_1 += "\r\n";*/




		memset(str_temp, NULL, 200);
		de_i_test = 1;
		while (!feof(ifp))
		{
			pstr = fgets(str_temp, sizeof(str_temp), ifp);
			str_default = (LPSTR)str_temp;

			AfxExtractSubString(test_flag, str_default, 0, ',');

			if (AfxExtractSubString(test_flag_1, test_flag, 1, '#')){
				count = test_flag.Find('#');
				st = LPSTR(LPCTSTR(test_flag_1));

				test_flag_2 = '#' + test_flag_1;
				test_flag = test_flag.Left(test_flag.GetLength() - test_flag_2.GetLength());

			}
			// 불필요한 부분 제거
			if (((test_flag.Compare(L" L3001/NP")) == 0) || ((test_flag.Compare(L" L3002/NP")) == 0) || ((test_flag.Compare(L" C3005/C")) == 0)){
				continue;
			}
			else{
				AfxExtractSubString(str_default_1, str_default, 13, ',');
				AfxExtractSubString(str_default_2, str_default_1, 1, ' ');
				//m_strStatus_1 += test_flag;
				//m_strStatus_1 += "\t";
				//m_strStatus_1 += str_default_2;
				One_Line_Data += str_default_2;
				PASS_FAIL_TEST += str_default_2;
				
			}

			de_i_test++;
		}
		//m_strStatus_1 = m_strStatus_1.Left(m_strStatus_1.GetLength() - 2);
		//if ()
		PASS_FAIL_TEST = TEST + _T("+") + PASS_FAIL_TEST;
		sprintf(PASS_FAIL_temp[num_i], "%S", PASS_FAIL_TEST);
		PASS_FAIL_TEST.Empty();
		num_i++;

		int ttest;
		ttest = One_Line_Data.GetLength();
		if (ttest == 47)
			One_Line_Data = One_Line_Data.Left(One_Line_Data.GetLength() - 1);
		else if (ttest == 55)
			One_Line_Data = One_Line_Data.Left(One_Line_Data.GetLength() - 2);

		CString One_Line_Data_buf;
		strArray.SetSize(60);
		//m_strStatus_1 += One_Line_Data;
		One_Line_Data_buf = TEST + _T("+") + One_Line_Data;
		//strArray[i] = One_Line_Data;
		strArray.SetAt(i, One_Line_Data_buf);
		arrat_buf = strArray.GetAt(i);
		
		int array_test = strArray.GetSize();
		One_Line_Data.Empty();
		One_Line_Data_buf.Empty();
		//m_strStatus_1 += "\r\n";
		de_i++;
		i++;
	}
	

	PASS_FAIL = PASS_FAIL_TEST;

	PASS_FAIL_TEST.Empty();
	//m_strStatus_1 += "\r\n";
	CString strTemp;
	strTemp.Format(L"nr_data: %d , %d\r\n", i, de_i);
	//m_strStatus_1 += strTemp;

	//----------------------------Master File------------------------------------//





	//----------------------------Compare File------------------------------------//

	m_Edit_buf.Empty();
	UpdateData(TRUE);
	m_Edit_buf = m_Edit;
	UpdateData(FALSE);

	printf("[OnBnClickedBtnOpen] \n");

	strSection = _T("Main");
	strKey = _T("Main_File_Address");
  	GetPrivateProfileString(strSection, strKey, _T(""), szBuf_File_Address, MAX_PATH, strInIPath);
	strValue.Format(_T("%s"), szBuf_File_Address);


	Address_buf = szBuf_File_Address;

	
	Address_buf = Address_buf.Left(Address_buf.GetLength() - 12);
	bWorking = finder.FindFile(Address_buf + _T("\\*"));

	m_strStatus.Empty();

	while (bWorking){
		bWorking = finder.FindNextFile();
		if ((finder.GetFileName() == ".") || (finder.GetFileName() == "..") || (finder.GetFileName() == "Main.ini"))
			continue;
		else{
			Filename = finder.GetFileName();
			//m_strStatus_1 += finder.GetFileName();
			//m_strStatus_1 += "\r\n";
			if (m_Edit_buf.Compare(Filename) == 0){
				compare_flag = 1;
				break;
			}
		}
		m_strStatus.Empty();
	}

	if (compare_flag == 0){
		MessageBox(_T("No comparison target"), _T("ERROR"), MB_ICONERROR);
	}
	else{
		strSection = _T("Main");

		strKey = _T("Main_File_Address");
		GetPrivateProfileString(strSection, strKey, _T(""), szBuf_File_Address, MAX_PATH, strInIPath);
		strValue.Format(_T("%s"), szBuf_File_Address);

		Address_buf = szBuf_File_Address;
		Address_buf = Address_buf.Left(Address_buf.GetLength() - 10);

		bWorking = finder.FindFile(Address_buf + _T("\\*"));

		m_strStatus.Empty();
		strSection = _T("Main");
		strKey = _T("Main_File_Address");
		GetPrivateProfileString(strSection, strKey, _T(""), szBuf_File_Address, MAX_PATH, strInIPath);
		strValue.Format(_T("%s"), szBuf_File_Address);

		Address_buf = szBuf_File_Address;
		Address_buf = Address_buf.Left(Address_buf.GetLength() - 12);
		Address_buf = Address_buf + _T("\\") + m_Edit_buf;
		bWorking = finder.FindFile(Address_buf + _T("\\*"));
		i = 0;
		int compare_count = 0;
		while (bWorking){
			bWorking = finder.FindNextFile();
			if ((finder.GetFileName() == ".") || (finder.GetFileName() == "..") || (finder.GetFileName() == "Main.ini"))
				continue;
			else{
				Filename = finder.GetFileName();
				//m_strStatus_1 += finder.GetFileName();
				//m_strStatus_1 += "\r\n";
			}
			
			m_strPath_1 = Address_buf + _T("\\") + Filename;
			char charPtr[500];
			sprintf(charPtr, "%S", m_strPath_1);

			file_name = dlg.GetFileName();

			/*m_strStatus_1 += "File name: ";
			m_strStatus_1 += file_name;
			m_strStatus_1 += "\r\n";*/
			AfxExtractSubString(TEST, Filename, 0, '-');

			// Set path to load 
			/*m_strStatus_1 += "File path: ";
			m_strStatus_1 += m_strPath_1;
			m_strStatus_1 += "\r\n";*/
			ifp = fopen(charPtr, "r");

			// Save folder path for further saving 
			m_strFolderPath_1 = m_strPath_1.Left(m_strPath_1.GetLength() - file_name.GetLength());
			/*m_strStatus_1 += "Folder path: ";
			m_strStatus_1 += m_strFolderPath_1;
			m_strStatus_1 += "\r\n";*/

			memset(str_temp, NULL, 200);
			de_i_test = 1;
			while (!feof(ifp))
			{
				pstr = fgets(str_temp, sizeof(str_temp), ifp);
				str_default = (LPSTR)str_temp;

				AfxExtractSubString(test_flag, str_default, 0, ',');

				if (AfxExtractSubString(test_flag_1, test_flag, 1, '#')){
					count = test_flag.Find('#');
					//st = LPSTR(LPCTSTR(test_flag_1));

					test_flag_2 = '#' + test_flag_1;
					test_flag = test_flag.Left(test_flag.GetLength() - test_flag_2.GetLength());

				}
				if (((test_flag.Compare(L" L3001/NP")) == 0) || ((test_flag.Compare(L" L3002/NP")) == 0) || ((test_flag.Compare(L" C3005/C")) == 0)){
					continue;
				}
				else{
					AfxExtractSubString(str_default_1, str_default, 13, ',');
					AfxExtractSubString(str_default_2, str_default_1, 1, ' ');
					//m_strStatus_1 += test_flag;
					//m_strStatus_1 += "\t";
					//m_strStatus_1 += str_default_2;
					One_Line_Data += str_default_2;
					PASS_FAIL_TEST += str_default_2;

				}

				de_i_test++;
			}
			//m_strStatus_1 = m_strStatus_1.Left(m_strStatus_1.GetLength() - 2);
			//if ()
			int ttest;
			ttest = One_Line_Data.GetLength();
			if (ttest == 47)
				One_Line_Data = One_Line_Data.Left(One_Line_Data.GetLength() - 1);
			else if (ttest == 55)
				One_Line_Data = One_Line_Data.Left(One_Line_Data.GetLength() - 2);

			CString One_Line_Data_buf;
			//---------------- 배열 size 문제 

			strArray_Compare.SetSize(GetDirFilesNum(Address_buf));
			//m_strStatus_1 += One_Line_Data;
			One_Line_Data_buf = TEST + _T("+") + One_Line_Data;
			//strArray[i] = One_Line_Data;
			strArray_Compare.SetAt(i, One_Line_Data_buf);
			arrat_buf_1 = strArray_Compare.GetAt(i);

			int array_test = strArray_Compare.GetSize();
			One_Line_Data.Empty();
			One_Line_Data_buf.Empty();
			//m_strStatus_1 += "\r\n";
			de_i++;
			i++;

		}

		//----------------------------Compare File------------------------------------//
		
		//----------------------------Compare------------------------------------//
		i = 0;
		
		while (!(i == 60)){
			CString compare_1 = strArray.GetAt(i);
			CString compare_2 = strArray_Compare.GetAt(i);

			int compare_test = compare_1.Compare(compare_2);
			if ((compare_test != 0) && i < 20)
				open_compare_count++;
			else if ((compare_test != 0) && (i >= 20) && (i < 40))
				short_compare_count++;
			else if ((compare_test != 0) && (i >= 40))
				PASS_compare_count++;
			i++;
		}
		m_strStatus_1.SetString(_T(""));

		if ((open_compare_count == 0) && (short_compare_count == 0) && (PASS_compare_count > 0)){
			m_strStatus_1 += _T("PBDBH0001 Master PASS");
			m_strStatus_1 += "\r\n";
			m_strStatus_1 += _T("PBDBH0141 Master PASS");
			m_strStatus_1 += "\r\n";
			m_strStatus_1 += _T("PBDCA0681 Master FAIL");
			m_strStatus_1 += "\r\n";
		}
		else if ((open_compare_count == 0) && (short_compare_count > 0) && (PASS_compare_count == 0)){
			m_strStatus_1 += _T("PBDBH0001 Master PASS");
			m_strStatus_1 += "\r\n";
			m_strStatus_1 += _T("PBDBH0141 Master FAIL");
			m_strStatus_1 += "\r\n";
			m_strStatus_1 += _T("PBDCA0681 Master PASS");
			m_strStatus_1 += "\r\n";
		}
		else if ((open_compare_count == 0) && (short_compare_count > 0) && (PASS_compare_count > 0)){
			m_strStatus_1 += _T("PBDBH0001 Master PASS");
			m_strStatus_1 += "\r\n";
			m_strStatus_1 += _T("PBDBH0141 Master FAIL");
			m_strStatus_1 += "\r\n";
			m_strStatus_1 += _T("PBDCA0681 Master FAIL");
			m_strStatus_1 += "\r\n";
		}
		else if ((open_compare_count > 0) && (short_compare_count == 0) && (PASS_compare_count == 0)){
			m_strStatus_1 += _T("PBDBH0001 Master FAIL");
			m_strStatus_1 += "\r\n";
			m_strStatus_1 += _T("PBDBH0141 Master PASS");
			m_strStatus_1 += "\r\n";
			m_strStatus_1 += _T("PBDCA0681 Master PASS");
			m_strStatus_1 += "\r\n";
		}
		else if ((open_compare_count > 0) && (short_compare_count == 0) && (PASS_compare_count > 0)){
			m_strStatus_1 += _T("PBDBH0001 Master FAIL");
			m_strStatus_1 += "\r\n";
			m_strStatus_1 += _T("PBDBH0141 Master PASS");
			m_strStatus_1 += "\r\n";
			m_strStatus_1 += _T("PBDCA0681 Master FAIL");
			m_strStatus_1 += "\r\n";
		}
		else if ((open_compare_count > 0) && (short_compare_count > 0) && (PASS_compare_count == 0)){
			m_strStatus_1 += _T("PBDBH0001 Master FAIL");
			m_strStatus_1 += "\r\n";
			m_strStatus_1 += _T("PBDBH0141 Master FAIL");
			m_strStatus_1 += "\r\n";
			m_strStatus_1 += _T("PBDCA0681 Master PASS");
			m_strStatus_1 += "\r\n";
		}
		else if ((open_compare_count > 0) && (short_compare_count > 0) && (PASS_compare_count > 0)){
			m_strStatus_1 += _T("PBDBH0001 Master FAIL");
			m_strStatus_1 += "\r\n";
			m_strStatus_1 += _T("PBDBH0141 Master FAIL");
			m_strStatus_1 += "\r\n";
			m_strStatus_1 += _T("PBDCA0681 Master FAIL");
			m_strStatus_1 += "\r\n";
		}
		else{
			m_strStatus_1 += _T("PBDBH0001 Master PASS");
			m_strStatus_1 += "\r\n";
			m_strStatus_1 += _T("PBDBH0141 Master PASS");
			m_strStatus_1 += "\r\n";
			m_strStatus_1 += _T("PBDCA0681 Master PASS");
			m_strStatus_1 += "\r\n";
		}

		

	}
	GetDlgItem(IDC_EDIT_CONSOLE2)->SetFont(&m_font);
	GetDlgItem(IDC_EDIT_CONSOLE2)->SetFocus();

	UpdateData(FALSE);

	//}

}


void CBtnLoadDlg::OnBnClickedBtnLoad5()
{
	/*TCHAR szBuf[MAX_PATH] = { 0, };
	TCHAR szBuf_File_Address[MAX_PATH] = { 0, };
	CString strInIPath(_T("D:\\ICT_Inspection_Log\\FCM-30S-IMAGER\\Main.ini"));
	CString strSection, strKey, strValue;

	BOOL bWorking;
	CFileFind finder;
	CString Filename;

	CString Address_buf;

	strSection = _T("Main");

	strKey = _T("Main_File_Address");
	GetPrivateProfileString(strSection, strKey, _T(""), szBuf_File_Address, MAX_PATH, strInIPath);
	strValue.Format(_T("%s"), szBuf_File_Address);

	Address_buf = szBuf_File_Address;
	Address_buf = Address_buf.Left(Address_buf.GetLength() - 10);

	bWorking = finder.FindFile(Address_buf + _T("\\*"));

	while (bWorking){
	bWorking = finder.FindNextFile();
	if ((finder.GetFileName() == ".") || (finder.GetFileName() == "..") || (finder.GetFileName() == "Main.ini"))
	continue;
	else{
	Filename = finder.GetFileName();
	m_strStatus += finder.GetFileName();
	m_strStatus += "\r\n";
	}
	}
	UpdateData(FALSE);*/

	printf("[OnBnClickedBtnOpen] \n");
	TCHAR szBuf[MAX_PATH] = { 0, };
	TCHAR szBuf_File_Address[MAX_PATH] = { 0, };
	CString strInIPath(_T("D:\\ICT_Inspection_Log\\FCM-30S-IMAGER\\Main.ini"));
	CString strSection, strKey, strValue;

	CString Address_buf;
	CString Filename;
	CFileFind finder;
	BOOL bWorking;

	CStdioFile ftxt;

	CStringArray strArray;
	CStringArray strArray_Compare;

	int i = 0;
	int de_i = 0;
	int de_i_test = 0;

	int nr_data = -1;

	char flag = 0;
	char str_temp[200];
	int count;
	char *pstr;

	CString str_default, str_default_1, str_default_2;
	CString test_flag, test_flag_1, test_flag_2;
	CString test;

	CString PASS_FAIL_TEST;
	CString One_Line_Data;

	CString m_strPath_test;

	CString file_name;
	CString m_strStatus_temp;
	CString TEST;

	char compare_flag = 0;
	
	CFileException kEx;
	CFileDialog dlg(TRUE, _T("*.csv"), NULL, OFN_FILEMUSTEXIST, _T("CSV Files(*.csv)|*.csv|"), NULL);
	
	UpdateData(TRUE);
	m_Edit_buf = m_Edit;
	UpdateData(FALSE);

	strSection = _T("Main");

	strKey = _T("Main_File_Address");
	GetPrivateProfileString(strSection, strKey, _T(""), szBuf_File_Address, MAX_PATH, strInIPath);
	strValue.Format(_T("%s"), szBuf_File_Address);

	Address_buf = szBuf_File_Address;
	Address_buf = Address_buf.Left(Address_buf.GetLength() - 10);
	bWorking = finder.FindFile(Address_buf + _T("\\*"));

	m_strStatus.Empty();

	while (bWorking){
		bWorking = finder.FindNextFile();
		if ((finder.GetFileName() == ".") || (finder.GetFileName() == "..") || (finder.GetFileName() == "Main.ini"))
			continue;
		else{
			Filename = finder.GetFileName();
			//m_strStatus_1 += finder.GetFileName();
			//m_strStatus_1 += "\r\n";
			if (m_Edit_buf.Compare(Filename) == 0){
				compare_flag = 1;
				break;
			}
		}
		m_strStatus.Empty();
	}
	
	if (compare_flag == 0){
		MessageBox(_T("No comparison target"), _T("ERROR"), MB_ICONERROR);
	}
	else{
		strSection = _T("Main");

		strKey = _T("Main_File_Address");
		GetPrivateProfileString(strSection, strKey, _T(""), szBuf_File_Address, MAX_PATH, strInIPath);
		strValue.Format(_T("%s"), szBuf_File_Address);

		Address_buf = szBuf_File_Address;
		Address_buf = Address_buf.Left(Address_buf.GetLength() - 10);

		bWorking = finder.FindFile(Address_buf + _T("\\*"));

		m_strStatus.Empty();
		strSection = _T("Main");
		strKey = _T("Main_File_Address");
		GetPrivateProfileString(strSection, strKey, _T(""), szBuf_File_Address, MAX_PATH, strInIPath);
		strValue.Format(_T("%s"), szBuf_File_Address);

		Address_buf = szBuf_File_Address;
		Address_buf = Address_buf.Left(Address_buf.GetLength() - 10);
		Address_buf = Address_buf + _T("\\") + m_Edit_buf;
		bWorking = finder.FindFile(Address_buf + _T("\\*"));

		while (bWorking){
			bWorking = finder.FindNextFile();
			if ((finder.GetFileName() == ".") || (finder.GetFileName() == "..") || (finder.GetFileName() == "Main.ini"))
				continue;
			else{
				Filename = finder.GetFileName();
				//m_strStatus_1 += finder.GetFileName();
				//m_strStatus_1 += "\r\n";
			}


			m_strPath_1 = Address_buf + _T("\\") + Filename;
			char charPtr[500];
			sprintf(charPtr, "%S", m_strPath_1);

			file_name = dlg.GetFileName();

			/*m_strStatus_1 += "File name: ";
			m_strStatus_1 += file_name;
			m_strStatus_1 += "\r\n";*/
			AfxExtractSubString(TEST, Filename, 0, '-');

			// Set path to load 
			/*m_strStatus_1 += "File path: ";
			m_strStatus_1 += m_strPath_1;
			m_strStatus_1 += "\r\n";*/
			ifp = fopen(charPtr, "r");

			// Save folder path for further saving 
			m_strFolderPath_1 = m_strPath_1.Left(m_strPath_1.GetLength() - file_name.GetLength());
			/*m_strStatus_1 += "Folder path: ";
			m_strStatus_1 += m_strFolderPath_1;
			m_strStatus_1 += "\r\n";*/




			memset(str_temp, NULL, 200);
			de_i_test = 1;
			while (!feof(ifp))
			{
				pstr = fgets(str_temp, sizeof(str_temp), ifp);
				str_default = (LPSTR)str_temp;

				AfxExtractSubString(test_flag, str_default, 0, ',');

				if (AfxExtractSubString(test_flag_1, test_flag, 1, '#')){
					count = test_flag.Find('#');
					//st = LPSTR(LPCTSTR(test_flag_1));

					test_flag_2 = '#' + test_flag_1;
					test_flag = test_flag.Left(test_flag.GetLength() - test_flag_2.GetLength());

				}
				if (((test_flag.Compare(L" L3001/NP")) == 0) || ((test_flag.Compare(L" L3002/NP")) == 0) || ((test_flag.Compare(L" C3005/C")) == 0)){
					continue;
				}
				else{
					AfxExtractSubString(str_default_1, str_default, 13, ',');
					AfxExtractSubString(str_default_2, str_default_1, 1, ' ');
					//m_strStatus_1 += test_flag;
					//m_strStatus_1 += "\t";
					//m_strStatus_1 += str_default_2;
					One_Line_Data += str_default_2;
					PASS_FAIL_TEST += str_default_2;

				}

				de_i_test++;
			}
			//m_strStatus_1 = m_strStatus_1.Left(m_strStatus_1.GetLength() - 2);
			//if ()
			int ttest;
			ttest = One_Line_Data.GetLength();
			if (ttest == 47)
				One_Line_Data = One_Line_Data.Left(One_Line_Data.GetLength() - 1);
			else if (ttest == 55)
				One_Line_Data = One_Line_Data.Left(One_Line_Data.GetLength() - 2);

			CString One_Line_Data_buf;
			strArray_Compare.SetSize(60);
			m_strStatus_1 += One_Line_Data;
			One_Line_Data_buf = TEST + _T("+") + One_Line_Data;
			//strArray[i] = One_Line_Data;
			strArray_Compare.SetAt(i, One_Line_Data_buf);
			CString arrat_buf = strArray_Compare.GetAt(i);

			int array_test = strArray_Compare.GetSize();
			One_Line_Data.Empty();
			One_Line_Data_buf.Empty();
			m_strStatus_1 += "\r\n";
			de_i++;
			i++;

		}
		i = 0;
		int compare_count = 0;
		while (!(i == 60)){
			CString compare_1 = strArray.GetAt(i);
			CString compare_2 = strArray_Compare.GetAt(i);

			int compare_test = compare_1.Compare(compare_2);
			if (compare_test != 0)
				compare_count++;
			i++;
		}
	}
	UpdateData(FALSE);
}

/*
void FindSubDir(CString strDir, CStringArray &FileArray)
{
	strDir += "\\*.*";

	CFileFind ff;
	BOOL bFound = ff.FindFile(strDir);

	while (bFound)
	{
		bFound = ff.FindNextFile();

		if (ff.IsDots()) continue;
		if (ff.IsDirectory())
			FindSubDir(ff.GetFilePath(), FileArray);
		else
			FileArray.Add(ff.GetFilePath());
	}
}*/


void CBtnLoadDlg::OnBnClickedButton2() //file Setch
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.



	TCHAR szBuf[MAX_PATH] = { 0, };
	TCHAR szBuf_File_Address[MAX_PATH] = { 0, };
	CString strInIPath(_T("D:\\ICT_Inspection_Log\\FCM-30S-IMAGER\\Main.ini"));
	CString strSection, strKey, strValue;

	BOOL bWorking;
	CFileFind finder;
	CString Filename;

	CString Address_buf;

	m_Text1.SetWindowTextW(strInIPath);

	strSection = _T("Main");

	strKey = _T("Main_File_Address");
	GetPrivateProfileString(strSection, strKey, _T(""), szBuf_File_Address, MAX_PATH, strInIPath);
	strValue.Format(_T("%s"), szBuf_File_Address);

	Address_buf = szBuf_File_Address;
	Address_buf = Address_buf.Left(Address_buf.GetLength() - 12);

	bWorking = finder.FindFile(Address_buf + _T("\\*"));

	m_strStatus.Empty();

	while (bWorking){
		bWorking = finder.FindNextFile();
		if ((finder.GetFileName() == ".") || (finder.GetFileName() == "..") || (finder.GetFileName() == "Main.ini"))
			continue;
		else{
			Filename = finder.GetFileName();
			m_strStatus += finder.GetFileName();
			m_strStatus += "\r\n";
		}
	}
	Address_buf.Empty();
	Filename.Empty();
	UpdateData(FALSE);
}

//----------- forder 내 file 갯수 확인 -------------
int GetDirFilesNum(CString dirName){
	int file_count = 0;
	CFileFind file_number;

	BOOL bWorking = file_number.FindFile(dirName + "/*.*");

	while (bWorking){
		bWorking = file_number.FindNextFile();
		if (file_number.IsDots()){
			continue;
		}

		file_count++;
	}
	file_number.Close();
	return file_count;
}