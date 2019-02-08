
// BtnLoadDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CBtnLoadDlg ��ȭ ����
class CBtnLoadDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CBtnLoadDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_BTNLOAD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnLoad();
	// �߰� ������ 
	// Folder path
	CString m_strPath;
	CString m_strFolderPath;
	CString m_strStatus;

	CString m_strPath_1;
	CString m_strFolderPath_1;
	CString m_strStatus_1;

	CString m_strPath_2;
	CString m_strFolderPath_2;
	CString m_strStatus_2;
	
	// File
	FILE *ifp;
	
	afx_msg void OnIdclose();
	afx_msg void OnClose();
	int **data;
	CEdit m_ctrlStatus;
	afx_msg void OnBnClickedBtnSave();
	CEdit m_ctrlStatus_1;
	afx_msg void OnBnClickedBtnLoad3();
	afx_msg void OnBnClickedBtnLoad4();

	afx_msg void OnBnClickedBtnLoad5();
	CEdit m_ctrlStatus_2;
	
	//afx_msg void OnBnClickedButton1();
	CString m_Edit;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit1();
	CStatic m_Text;
	CStatic m_image;
	CStatic m_Edit_10;
	CStatic m_Text1;
	CButton m_RadioButton_1;
	CButton m_RadioButton_2;
	int m_RadioButton_3;
	int m_Radio1;
};
