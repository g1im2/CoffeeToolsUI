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
	
		if (pFlushExamine) 
		{
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
		else if (_tcscmp(pstrClass, _T("tab_about")) == 0) 
		{
			CDialogBuilder builder;
			CContainerUI* pAboutExamine = static_cast<CContainerUI*>(builder.Create(_T("tab_about.xml"), (UINT)0));
			return pAboutExamine;
		}
		else if (_tcscmp(pstrClass, _T("tab_money")) == 0)
		{
			CDialogBuilder builder;
			CContainerUI* pMoneyExamine = static_cast<CContainerUI*>(builder.Create(_T("tab_money.xml"), (UINT)0));
			return pMoneyExamine;
		}
		else if (_tcscmp(pstrClass, _T("tab_tools")) == 0)
		{
			CDialogBuilder builder;
			CContainerUI* pToolsExamine = static_cast<CContainerUI*>(builder.Create(_T("tab_tools.xml"), (UINT)0));
			return pToolsExamine;
		}

		return NULL;
	}
};