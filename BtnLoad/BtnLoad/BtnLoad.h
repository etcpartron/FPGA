
// BtnLoad.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CBtnLoadApp:
// �� Ŭ������ ������ ���ؼ��� BtnLoad.cpp�� �����Ͻʽÿ�.
//

class CBtnLoadApp : public CWinApp
{
public:
	CBtnLoadApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CBtnLoadApp theApp;