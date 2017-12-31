#pragma once

class ComputerExamineUI : public CContainerUI
{
public:
	ComputerExamineUI()
	{
		CDialogBuilder builder;
		CContainerUI* pFlushExamine = static_cast<CContainerUI*>(builder.Create(_T("tab_flush.xml"), (UINT)0));
		CContainerUI* pToolsExamine = static_cast<CContainerUI*>(builder.Create(_T("tab_tools.xml"), (UINT)0));
		CContainerUI* pMoneyExamine = static_cast<CContainerUI*>(builder.Create(_T("tab_money.xml"), (UINT)0));
		CContainerUI* pAboutExamine = static_cast<CContainerUI*>(builder.Create(_T("tab_about.xml"), (UINT)0));
		if (pFlushExamine) {
			this->Add(pFlushExamine);
		}
		else if (pToolsExamine)
		{
			this->Add(pToolsExamine);
		}
		else if (pMoneyExamine)
		{
			this->Add(pMoneyExamine);
		}
		else if (pAboutExamine)
		{
			this->Add(pAboutExamine);
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
		if (_tcscmp(pstrClass, _T("tab_tools")) == 0) return new ComputerExamineUI;
		if (_tcscmp(pstrClass, _T("tab_money")) == 0) return new ComputerExamineUI;
		if (_tcscmp(pstrClass, _T("tab_about")) == 0) return new ComputerExamineUI;
		return NULL;
	}
};

