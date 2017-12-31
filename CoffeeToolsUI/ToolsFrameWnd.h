#pragma once

#include <UIlib.h>
using namespace DuiLib;

class ComputerExamineUI : public CContainerUI
{
public:
	ComputerExamineUI()
	{
		CDialogBuilder builder;
		CContainerUI* pFlushExamine = static_cast<CContainerUI*>(builder.Create(_T("tab_flush.xml"), (UINT)0));
	
		if (pFlushExamine) {
			this->Add(pFlushExamine);
		}
		
		else {
			this->RemoveAll();
			return;
		}
	}
};

class CDialogBuilderCallbackEx : public IDialogBuilderCallback
{
public:
	CControlUI* CreateControl(LPCTSTR pstrClass)
	{
		if (_tcscmp(pstrClass, _T("tab_flush")) == 0) return new ComputerExamineUI;

		return NULL;
	}
};