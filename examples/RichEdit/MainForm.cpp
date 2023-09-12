#include "MainForm.h"
#include "FindForm.h"
#include "ReplaceForm.h"
#include "MainThread.h"
#include <ShellApi.h>
#include <commdlg.h>
#include <fstream>

const std::wstring MainForm::kClassName = L"MainForm";

MainForm::MainForm():
	m_pRichEdit(nullptr),
	m_pFindForm(nullptr),
	m_pReplaceForm(nullptr)
{
}

MainForm::~MainForm()
{
}

std::wstring MainForm::GetSkinFolder()
{
	return L"rich_edit";
}

std::wstring MainForm::GetSkinFile()
{
	return L"rich_edit.xml";
}

std::wstring MainForm::GetWindowClassName() const
{
	return kClassName;
}

void MainForm::OnInitWindow()
{
	ui::RichEdit* pRichEdit = dynamic_cast<ui::RichEdit*>(FindControl(L"test_url"));
	if (pRichEdit != nullptr) {
		pRichEdit->AttachCustomLinkClick([this, pRichEdit](const ui::EventArgs& args) {
				//点击了超级链接
				if (args.pSender == pRichEdit) {
					const wchar_t* pUrl = (const wchar_t*)args.wParam;
					if (pUrl != nullptr) {
						::ShellExecute(GetHWND(), L"open", pUrl, NULL, NULL, SW_SHOWNORMAL);
					}
				}
				return true;
			});
	}
	m_pRichEdit = dynamic_cast<ui::RichEdit*>(FindControl(L"rich_edit"));
	ASSERT(m_pRichEdit != nullptr);
	m_findReplace.SetRichEdit(m_pRichEdit);
	LoadRichEditData();

	//文件操作：打开、保存、另存
	ui::Button* pButton = dynamic_cast<ui::Button*>(FindControl(L"open_file"));
	if (pButton != nullptr) {
		pButton->AttachClick([this, pButton](const ui::EventArgs& args) {
				if (args.pSender == pButton) {
					this->OnOpenFile();
				}
				return true;
			});
	}
	pButton = dynamic_cast<ui::Button*>(FindControl(L"save_file"));
	if (pButton != nullptr) {
		m_saveBtnText = pButton->GetText();
		pButton->AttachClick([this, pButton](const ui::EventArgs& args) {
				if (args.pSender == pButton) {
					this->OnSaveFile();
				}
				return true;
			});
	}
	pButton = dynamic_cast<ui::Button*>(FindControl(L"save_as_file"));
	if (pButton != nullptr) {
		pButton->AttachClick([this, pButton](const ui::EventArgs& args) {
				if (args.pSender == pButton) {
					this->OnSaveAsFile();
				}
				return true;
			});
	}

	//编辑操作
	pButton = dynamic_cast<ui::Button*>(FindControl(L"btn_copy"));
	if (pButton != nullptr) {
		pButton->AttachClick([this, pButton](const ui::EventArgs& args) {
			if (args.pSender == pButton) {
				if (m_pRichEdit != nullptr) {
					m_pRichEdit->Copy();
					UpdateSaveStatus();
				}
			}
			return true;
			});
	}
	pButton = dynamic_cast<ui::Button*>(FindControl(L"btn_cut"));
	if (pButton != nullptr) {
		pButton->AttachClick([this, pButton](const ui::EventArgs& args) {
			if (args.pSender == pButton) {
				if (m_pRichEdit != nullptr) {
					m_pRichEdit->Cut();
					UpdateSaveStatus();
				}
			}
			return true;
			});
	}
	pButton = dynamic_cast<ui::Button*>(FindControl(L"btn_paste"));
	if (pButton != nullptr) {
		pButton->AttachClick([this, pButton](const ui::EventArgs& args) {
			if (args.pSender == pButton) {
				if (m_pRichEdit != nullptr) {
					m_pRichEdit->Paste();
					UpdateSaveStatus();
				}
			}
			return true;
			});
	}
	pButton = dynamic_cast<ui::Button*>(FindControl(L"btn_delete"));
	if (pButton != nullptr) {
		pButton->AttachClick([this, pButton](const ui::EventArgs& args) {
			if (args.pSender == pButton) {
				if (m_pRichEdit != nullptr) {
					m_pRichEdit->Clear();
					UpdateSaveStatus();
				}
			}
			return true;
			});
	}
	pButton = dynamic_cast<ui::Button*>(FindControl(L"btn_sel_all"));
	if (pButton != nullptr) {
		pButton->AttachClick([this, pButton](const ui::EventArgs& args) {
			if (args.pSender == pButton) {
				if (m_pRichEdit != nullptr) {
					m_pRichEdit->SetSelAll();
					UpdateSaveStatus();
				}
			}
			return true;
			});
	}
	pButton = dynamic_cast<ui::Button*>(FindControl(L"btn_sel_none"));
	if (pButton != nullptr) {
		pButton->AttachClick([this, pButton](const ui::EventArgs& args) {
			if (args.pSender == pButton) {
				if (m_pRichEdit != nullptr) {
					m_pRichEdit->SetSelNone();
					UpdateSaveStatus();
				}
			}
			return true;
			});
	}
	pButton = dynamic_cast<ui::Button*>(FindControl(L"btn_undo"));
	if (pButton != nullptr) {
		pButton->AttachClick([this, pButton](const ui::EventArgs& args) {
			if (args.pSender == pButton) {
				if (m_pRichEdit != nullptr) {
					m_pRichEdit->Undo();
					UpdateSaveStatus();
				}
			}
			return true;
			});
	}
	pButton = dynamic_cast<ui::Button*>(FindControl(L"btn_redo"));
	if (pButton != nullptr) {
		pButton->AttachClick([this, pButton](const ui::EventArgs& args) {
			if (args.pSender == pButton) {
				if (m_pRichEdit != nullptr) {
					m_pRichEdit->Redo();
					UpdateSaveStatus();
				}
			}
			return true;
			});
	}

	//查找操作
	pButton = dynamic_cast<ui::Button*>(FindControl(L"btn_find_text"));
	if (pButton != nullptr) {
		pButton->AttachClick([this, pButton](const ui::EventArgs& args) {
			if (args.pSender == pButton) {
				OnFindText();
			}
			return true;
			});
	}
	pButton = dynamic_cast<ui::Button*>(FindControl(L"btn_find_next"));
	if (pButton != nullptr) {
		pButton->AttachClick([this, pButton](const ui::EventArgs& args) {
			if (args.pSender == pButton) {
				OnFindNext();
			}
			return true;
			});
	}
	pButton = dynamic_cast<ui::Button*>(FindControl(L"btn_replace_text"));
	if (pButton != nullptr) {
		pButton->AttachClick([this, pButton](const ui::EventArgs& args) {
			if (args.pSender == pButton) {
				OnReplaceText();
			}
			return true;
			});
	}

	//设置字体
	pButton = dynamic_cast<ui::Button*>(FindControl(L"set_font"));
	if (pButton != nullptr) {
		pButton->AttachClick([this, pButton](const ui::EventArgs& args) {
			if (args.pSender == pButton) {
				OnSetFont();
			}
			return true;
			});
	}

	//初始化字体信息
	ui::Combo* pFontNameCombo = dynamic_cast<ui::Combo*>(FindControl(L"combo_font_name")); 
	if (pFontNameCombo != nullptr) {		
		GetSystemFontList(m_fontList);
		for (size_t nIndex = 0; nIndex < m_fontList.size(); ++nIndex) {
			const FontInfo& font = m_fontList[nIndex];
			size_t nItemIndex = pFontNameCombo->AddTextItem(font.lf.lfFaceName);
			if (ui::Box::IsValidItemIndex(nItemIndex)) {
				pFontNameCombo->SetItemData(nItemIndex, nIndex);
			}
		}
		pFontNameCombo->AttachSelect([this, pFontNameCombo](const ui::EventArgs& args) {
			//pFontNameCombo->GetCurSel
			return true;
			});
	}
	ui::Combo* pFontSizeCombo = dynamic_cast<ui::Combo*>(FindControl(L"combo_font_size"));
	if (pFontSizeCombo != nullptr) {
		GetFontSizeList(m_fontSizeList);
		for (size_t nIndex = 0; nIndex < m_fontSizeList.size(); ++nIndex) {
			const FontSizeInfo& fontSize = m_fontSizeList[nIndex];
			size_t nItemIndex = pFontSizeCombo->AddTextItem(fontSize.fontSizeName);
			if (ui::Box::IsValidItemIndex(nItemIndex)) {
				pFontSizeCombo->SetItemData(nItemIndex, nIndex);
			}
		}
	}

	//更新字体按钮的状态
	UpdateFontStatus();
}

void MainForm::UpdateFontStatus()
{
	ui::RichEdit* pRichEdit = GetRichEdit();
	if (pRichEdit == nullptr) {
		return;
	}
	//文本颜色
	ui::UiColor textColor = pRichEdit->GetTextColorValue();

	LOGFONT logFont = {};
	GetRichEditLogFont(logFont);

	ui::Combo* pFontNameCombo = dynamic_cast<ui::Combo*>(FindControl(L"combo_font_name"));
	if (pFontNameCombo != nullptr) {
		pFontNameCombo->SelectTextItem(logFont.lfFaceName);
	}
	ui::Combo* pFontSizeCombo = dynamic_cast<ui::Combo*>(FindControl(L"combo_font_size"));
	if (pFontSizeCombo != nullptr) {
		int32_t fHeight = -logFont.lfHeight;
		size_t maxItemIndex = 0;
		for (size_t nIndex = 0; nIndex < m_fontSizeList.size(); ++nIndex) {
			if (nIndex == (m_fontSizeList.size() - 1)) {
				break;
			}
			if (m_fontSizeList[nIndex].fontSize > m_fontSizeList[nIndex + 1].fontSize) {
				maxItemIndex = nIndex;
				break;
			}
		}

		bool bSelected = false;
		for (size_t nIndex = maxItemIndex; nIndex < m_fontSizeList.size(); ++nIndex) {
			//优先选择汉字的字号
			const FontSizeInfo& fontSize = m_fontSizeList[nIndex];
			if (fHeight == fontSize.fontSize) {
				if (pFontSizeCombo->SelectTextItem(fontSize.fontSizeName) != ui::Box::InvalidIndex) {
					bSelected = true;
				}
				break;
			}
		}
		if (!bSelected) {
			for (size_t nIndex = 0; nIndex < maxItemIndex; ++nIndex) {
				//选择数字的字号
				const FontSizeInfo& fontSize = m_fontSizeList[nIndex];
				if (fontSize.fontSize >= fHeight) {
					if (pFontSizeCombo->SelectTextItem(fontSize.fontSizeName) != ui::Box::InvalidIndex) {
						bSelected = true;
						break;
					}					
				}
			}
		}
	}
}

LRESULT MainForm::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled)
{
	PostQuitMessage(0L);
	return __super::OnClose(uMsg, wParam, lParam, bHandled);
}

LRESULT MainForm::OnKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled)
{
	LRESULT lResult = __super::OnKeyUp(uMsg, wParam, lParam, bHandled);
	bool bControlDown = ::GetKeyState(VK_CONTROL) < 0;
	bool bShiftDown = ::GetKeyState(VK_SHIFT) < 0;
	if (bControlDown) {
		if ((wParam == 'O') && !bShiftDown){
			//打开
			OnOpenFile();
		}
		else if (wParam == 'S') {
			if (bShiftDown) {
				//另存为
				OnSaveAsFile();				
			}
			else {
				//保存
				OnSaveFile();
			}
		}
		if (!bShiftDown) {
			if (wParam == 'F') {
				//查找
				OnFindText();
			}
			else if (wParam == 'H') {
				//替换
				OnReplaceText();
			}
		}
	}
	if (!bControlDown && !bShiftDown && (::GetKeyState(VK_F3) < 0)) {
		//查找下一个
		OnFindNext();
	}
	return lResult;
}

LRESULT MainForm::OnKeyUp(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled)
{
	LRESULT lResult = __super::OnKeyUp(uMsg, wParam, lParam, bHandled);
	UpdateSaveStatus();
	return lResult;
}

void MainForm::UpdateSaveStatus()
{
	if (m_pRichEdit != nullptr) {
		ui::Button* pButton = dynamic_cast<ui::Button*>(FindControl(L"save_file"));
		if (m_pRichEdit->GetModify()) {
			if (pButton != nullptr) {
				pButton->SetText(m_saveBtnText + L"*");
			}
		}
		else {
			if (pButton != nullptr) {
				pButton->SetText(m_saveBtnText);
			}
		}
	}
}

void MainForm::LoadRichEditData()
{
	std::streamoff length = 0;
	std::string xml;
	std::wstring controls_xml = ui::GlobalManager::Instance().GetResourcePath() + GetResourcePath() + GetSkinFile();

	std::ifstream ifs(controls_xml.c_str());
	if (ifs.is_open()) {
		ifs.seekg(0, std::ios_base::end);
		length = ifs.tellg();
		ifs.seekg(0, std::ios_base::beg);

		xml.resize(static_cast<unsigned int>(length) + 1);
		ifs.read(&xml[0], length);
		ifs.close();
	}
	std::wstring xmlU;
	ui::StringHelper::MBCSToUnicode(xml.c_str(), xmlU, CP_UTF8);

	if (m_pRichEdit != nullptr) {
		m_pRichEdit->SetText(xmlU);
		m_pRichEdit->SetFocus();
		m_pRichEdit->HomeUp();
		m_pRichEdit->SetModify(false);
		m_filePath = controls_xml;
	}
}

LPCTSTR g_defualtFilter = L"所有文件 (*.*)\0*.*\0"
						  L"文本文件 (*.txt)\0*.txt\0"
						  L"RTF文件 (*.rtf)\0*.rtf\0"
						  L"";

void MainForm::OnOpenFile()
{
	TCHAR szFileTitle[_MAX_FNAME] = {0,};   // contains file title after return
	TCHAR szFileName[_MAX_PATH] = {0,};     // contains full path name after return

	OPENFILENAME ofn = {0, };
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = GetHWND();

	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = _MAX_PATH;
	ofn.lpstrFileTitle = szFileTitle;
	ofn.nMaxFileTitle = _MAX_FNAME;
	ofn.Flags = OFN_HIDEREADONLY | OFN_FILEMUSTEXIST | OFN_EXPLORER | OFN_ENABLESIZING;
	ofn.lpstrFilter = g_defualtFilter;
	ofn.hInstance = ::GetModuleHandle(NULL);

	BOOL bRet = ::GetOpenFileName(&ofn);
	if (bRet) {
		if (LoadFile(szFileName)) {
			m_filePath = szFileName;
			if (m_pRichEdit != nullptr) {
				m_pRichEdit->SetModify(false);
				UpdateSaveStatus();
			}
		}
	}
}

void MainForm::OnSaveFile()
{
	if (m_pRichEdit != nullptr) {
		if (m_pRichEdit->GetModify()) {
			if (SaveFile(m_filePath)) {
				m_pRichEdit->SetModify(false);
				UpdateSaveStatus();
			}
		}
	}
}

void MainForm::OnSaveAsFile()
{
	TCHAR szFileTitle[_MAX_FNAME] = { 0, };   // contains file title after return
	TCHAR szFileName[_MAX_PATH] = { 0, };     // contains full path name after return
	wcscpy_s(szFileName, m_filePath.c_str());

	OPENFILENAME ofn = { 0, };
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = GetHWND();

	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = _MAX_PATH;
	ofn.lpstrFileTitle = szFileTitle;
	ofn.nMaxFileTitle = _MAX_FNAME;
	ofn.Flags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER | OFN_ENABLESIZING;
	ofn.lpstrFilter = g_defualtFilter;
	ofn.hInstance = ::GetModuleHandle(NULL);

	BOOL bRet = ::GetSaveFileName(&ofn);
	if (bRet) {
		if (SaveFile(szFileName)) {
			m_filePath = szFileName;
			if (m_pRichEdit != nullptr) {
				m_pRichEdit->SetModify(false);
				UpdateSaveStatus();
			}
		}
	}
}

bool MainForm::LoadFile(const std::wstring& filePath)
{
	if (m_pRichEdit == nullptr) {
		return false;
	}
	HANDLE hFile = ::CreateFile(filePath.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		return false;
	}

	EDITSTREAM es;
	es.dwCookie = (DWORD_PTR)hFile;
	es.dwError = 0;
	es.pfnCallback = StreamReadCallback;
	UINT nFormat = IsRtfFile(filePath) ? SF_RTF : SF_TEXT;
	m_pRichEdit->StreamIn(nFormat, es);
	::CloseHandle(hFile);
	return !(BOOL)es.dwError;
}

bool MainForm::SaveFile(const std::wstring& filePath)
{
	if (m_pRichEdit == nullptr) {
		return false;
	}
	HANDLE hFile = ::CreateFile(filePath.c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		return false;
	}

	EDITSTREAM es;
	es.dwCookie = (DWORD_PTR)hFile;
	es.dwError = 0;
	es.pfnCallback = StreamWriteCallback;
	UINT nFormat = IsRtfFile(filePath) ? SF_RTF : SF_TEXT;
	m_pRichEdit->StreamOut(nFormat, es);
	::CloseHandle(hFile);
	return !(BOOL)es.dwError;
}

bool MainForm::IsRtfFile(const std::wstring& filePath) const
{
	std::wstring fileExt;
	size_t pos = filePath.find_last_of(L".");
	if (pos != std::wstring::npos) {
		fileExt = filePath.substr(pos);
		fileExt = ui::StringHelper::MakeLowerString(fileExt);
	}
	return fileExt == L".rtf";
}

DWORD MainForm::StreamReadCallback(DWORD_PTR dwCookie, LPBYTE pbBuff, LONG cb, LONG FAR* pcb)
{
	ASSERT(dwCookie != 0);
	ASSERT(pcb != NULL);

	return !::ReadFile((HANDLE)dwCookie, pbBuff, cb, (LPDWORD)pcb, NULL);
}

DWORD MainForm::StreamWriteCallback(DWORD_PTR dwCookie, LPBYTE pbBuff, LONG cb, LONG FAR* pcb)
{
	ASSERT(dwCookie != 0);
	ASSERT(pcb != NULL);

	return !::WriteFile((HANDLE)dwCookie, pbBuff, cb, (LPDWORD)pcb, NULL);
}

void MainForm::OnFindText()
{
	if (m_pFindForm == nullptr) {
		m_pFindForm = new FindForm(this);
		m_pFindForm->CreateWnd(GetHWND(), FindForm::kClassName, WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX, WS_EX_LAYERED);
		m_pFindForm->CenterWindow();
		m_pFindForm->ShowWindow();

		m_pFindForm->AttachWindowClose([this](const ui::EventArgs& args) {
				m_pFindForm = nullptr;
				return true;
			});
	}
	else {
		m_pFindForm->ActiveWindow();
	}
}

void MainForm::OnFindNext()
{
	m_findReplace.FindNext();
}

void MainForm::OnReplaceText()
{
	if (m_pReplaceForm == nullptr) {
		m_pReplaceForm = new ReplaceForm(this);
		m_pReplaceForm->CreateWnd(GetHWND(), ReplaceForm::kClassName, WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX, WS_EX_LAYERED);
		m_pReplaceForm->CenterWindow();
		m_pReplaceForm->ShowWindow();
		m_pReplaceForm->AttachWindowClose([this](const ui::EventArgs& args) {
				m_pReplaceForm = nullptr;
				return true;
			});
	}
	else {
		m_pReplaceForm->ActiveWindow();
	}
}

void MainForm::FindRichText(const std::wstring& findText, bool bFindDown, bool bMatchCase, bool bMatchWholeWord, HWND hWndDialog)
{
	m_findReplace.FindRichText(findText, bFindDown, bMatchCase, bMatchWholeWord, hWndDialog);
}

void MainForm::ReplaceRichText(const std::wstring& findText, const std::wstring& replaceText, bool bFindDown, bool bMatchCase, bool bMatchWholeWord, HWND hWndDialog)
{
	if (m_findReplace.ReplaceRichText(findText, replaceText, bFindDown, bMatchCase, bMatchWholeWord, hWndDialog)) {
		if (m_pRichEdit != nullptr) {
			m_pRichEdit->SetModify(true);
			UpdateSaveStatus();
		}
	}
}

void MainForm::ReplaceAllRichText(const std::wstring& findText, const std::wstring& replaceText, bool bFindDown, bool bMatchCase, bool bMatchWholeWord, HWND hWndDialog)
{
	if (m_findReplace.ReplaceAllRichText(findText, replaceText, bFindDown, bMatchCase, bMatchWholeWord, hWndDialog)) {
		if (m_pRichEdit != nullptr) {
			m_pRichEdit->SetModify(true);
			UpdateSaveStatus();
		}
	}
}

ui::RichEdit* MainForm::GetRichEdit() const
{
	return m_pRichEdit;
}

void MainForm::GetSystemFontList(std::vector<FontInfo>& fontList) const
{
	ui::RichEdit* pRichEdit = GetRichEdit();
	if (pRichEdit == nullptr) {
		return;
	}

	fontList.clear();
	LOGFONT logfont = {};
	logfont.lfCharSet = DEFAULT_CHARSET;
	logfont.lfFaceName[0] = L'\0';
	logfont.lfPitchAndFamily = 0;
	::EnumFontFamiliesEx(pRichEdit->GetWindowDC(), &logfont, EnumFontFamExProc, (LPARAM)&fontList, 0);

	//字体名称列表
	std::map<std::wstring, FontInfo> fontMap;
	for (auto font : fontList) {
		if (font.lf.lfWeight != FW_NORMAL) {
			continue;
		}
		if (font.lf.lfFaceName[0] == L'@') {
			continue;
		}
		fontMap[font.lf.lfFaceName] = font;
	}

	fontList.clear();
	for (auto iter : fontMap) {
		fontList.push_back(iter.second);
	}
}

void MainForm::GetFontSizeList(std::vector<FontSizeInfo>& fontSizeList) const
{
	fontSizeList.clear();
	fontSizeList.push_back({ L"8",  8.0f, 0});
	fontSizeList.push_back({ L"9",  9.0f, 0 });
	fontSizeList.push_back({ L"10", 10.0f, 0 });
	fontSizeList.push_back({ L"11", 11.0f, 0 });
	fontSizeList.push_back({ L"12", 12.0f, 0 });
	fontSizeList.push_back({ L"14", 14.0f, 0 });
	fontSizeList.push_back({ L"16", 16.0f, 0 });
	fontSizeList.push_back({ L"18", 18.0f, 0 });
	fontSizeList.push_back({ L"20", 20.0f, 0 });
	fontSizeList.push_back({ L"22", 22.0f, 0 });
	fontSizeList.push_back({ L"24", 24.0f, 0 });
	fontSizeList.push_back({ L"26", 26.0f, 0 });
	fontSizeList.push_back({ L"28", 28.0f, 0 });
	fontSizeList.push_back({ L"32", 32.0f, 0 });
	fontSizeList.push_back({ L"36", 36.0f, 0 });
	fontSizeList.push_back({ L"48", 48.0f, 0 });
	fontSizeList.push_back({ L"72", 72.0f, 0 });
	fontSizeList.push_back({ L"1英寸", 95.6f, 0 });
	fontSizeList.push_back({ L"大特号", 83.7f, 0 });
	fontSizeList.push_back({ L"特号", 71.7f, 0 });
	fontSizeList.push_back({ L"初号", 56.0f, 0 });
	fontSizeList.push_back({ L"小初", 48.0f, 0 });
	fontSizeList.push_back({ L"一号", 34.7f, 0 });
	fontSizeList.push_back({ L"小一", 32.0f, 0 });
	fontSizeList.push_back({ L"二号", 29.3f, 0 });
	fontSizeList.push_back({ L"小二", 24.0f, 0 });
	fontSizeList.push_back({ L"三号", 21.3f, 0 });
	fontSizeList.push_back({ L"小三", 20.0f, 0 });
	fontSizeList.push_back({ L"四号", 18.7f, 0 });
	fontSizeList.push_back({ L"小四", 16.0f, 0 });
	fontSizeList.push_back({ L"五号", 14.0f, 0 });
	fontSizeList.push_back({ L"小五", 12.0f, 0 });
	fontSizeList.push_back({ L"六号", 10.0f, 0 });
	fontSizeList.push_back({ L"小六", 8.7f, 0 });
	fontSizeList.push_back({ L"七号", 7.3f, 0 });
	fontSizeList.push_back({ L"八号", 6.7f, 0 });

	//更新DPI自适应值
	for (FontSizeInfo& fontSize : fontSizeList) {
		int32_t nSize = static_cast<int32_t>(fontSize.fFontSize * 1000);
		ui::GlobalManager::Instance().Dpi().ScaleInt(nSize);
		fontSize.fontSize = nSize / 1000;
	}
}

#ifndef LY_PER_INCH
	#define LY_PER_INCH 1440
#endif

bool MainForm::GetRichEditLogFont(LOGFONT& lf) const
{
	ui::RichEdit* pRichEdit = GetRichEdit();
	if (pRichEdit == nullptr) {
		return false;
	}

	CHARFORMAT2 cf = {};
	pRichEdit->GetDefaultCharFormat(cf);

	if (cf.dwMask & CFM_SIZE) {
		lf.lfHeight = -MulDiv(cf.yHeight, ::GetDeviceCaps(pRichEdit->GetWindowDC(), LOGPIXELSY), LY_PER_INCH);
		lf.lfWidth = 0;
	}

	if (cf.dwMask & CFM_BOLD) {
		lf.lfWeight = cf.dwEffects & CFE_BOLD ? FW_BOLD : 0;
	}

	if (cf.dwMask & CFM_WEIGHT) {
		lf.lfWeight = cf.wWeight;
	}

	if (cf.dwMask & CFM_ITALIC) {
		lf.lfItalic = cf.dwEffects & CFE_ITALIC ? TRUE : FALSE;
	}

	if (cf.dwMask & CFM_UNDERLINE) {
		lf.lfUnderline = cf.dwEffects & CFE_UNDERLINE ? TRUE : FALSE;
	}

	if (cf.dwMask & CFM_STRIKEOUT) {
		lf.lfStrikeOut = cf.dwEffects & CFE_STRIKEOUT ? TRUE : FALSE;
	}

	if (cf.dwMask & CFM_CHARSET) {
		lf.lfCharSet = cf.bCharSet;
	}

	if (cf.dwMask & CFM_FACE) {
		lf.lfPitchAndFamily = cf.bPitchAndFamily;

		//替换为系统字体名称
		std::wstring fontName = ui::FontManager::GetFontSystemName(cf.szFaceName);
		wcscpy_s(lf.lfFaceName, LF_FACESIZE, fontName.c_str());
	}
	return true;
}

void MainForm::InitCharFormat(const LOGFONT& lf, CHARFORMAT2& charFormat) const
{
	//字体字号需要转换, 否则字体大小显示异常
	bool bGetDC = false;
	HDC hDC = nullptr;
	if (m_pRichEdit != nullptr) {
		hDC = m_pRichEdit->GetWindowDC();
	}
	if (hDC == nullptr) {
		hDC = ::GetDC(nullptr);
		bGetDC = true;
	}
	LONG yPixPerInch = ::GetDeviceCaps(hDC, LOGPIXELSY);
	if (bGetDC && (hDC != nullptr)) {
		::ReleaseDC(nullptr, hDC);
		hDC = nullptr;
	}
	if (yPixPerInch == 0) {
		yPixPerInch = 96;
	}
	LONG lfHeight = lf.lfHeight * LY_PER_INCH / yPixPerInch;

	charFormat.cbSize = sizeof(CHARFORMAT2W);
	charFormat.dwMask = CFM_SIZE | CFM_OFFSET | CFM_FACE | CFM_CHARSET | CFM_BOLD | CFM_ITALIC | CFM_UNDERLINE | CFM_STRIKEOUT;
	charFormat.yHeight = -lfHeight;
	if (lf.lfWeight >= FW_BOLD) {
		charFormat.dwEffects |= CFE_BOLD;
	}
	else {
		charFormat.dwEffects &= ~CFE_BOLD;
	}
	if (lf.lfItalic) {
		charFormat.dwEffects |= CFE_ITALIC;
	}
	else {
		charFormat.dwEffects &= ~CFE_ITALIC;
	}
	if (lf.lfUnderline) {
		charFormat.dwEffects |= CFE_UNDERLINE;
	}
	else {
		charFormat.dwEffects &= ~CFE_UNDERLINE;
	}
	if (lf.lfStrikeOut) {
		charFormat.dwEffects |= CFE_STRIKEOUT;
	}
	else {
		charFormat.dwEffects &= ~CFE_STRIKEOUT;
	}
	charFormat.bCharSet = lf.lfCharSet;
	charFormat.bPitchAndFamily = lf.lfPitchAndFamily;
	wcscpy_s(charFormat.szFaceName, lf.lfFaceName);
}

void MainForm::OnSetFont()
{
	ui::RichEdit* pRichEdit = GetRichEdit();
	if (pRichEdit == nullptr) {
		return;
	}
	//文本颜色
	ui::UiColor textColor = pRichEdit->GetTextColorValue();

	LOGFONT logFont = {};
	GetRichEditLogFont(logFont);

	CHOOSEFONT cf;
	TCHAR szStyleName[64];  // contains style name after return
	LOGFONT lf;			    // default LOGFONT to store the info

	HWND hWndParent = GetHWND();
	LPLOGFONT lplfInitial = &logFont;
	DWORD dwFlags = CF_EFFECTS | CF_SCREENFONTS;
	memset(&cf, 0, sizeof(cf));
	memset(&lf, 0, sizeof(lf));
	memset(&szStyleName, 0, sizeof(szStyleName));

	cf.lStructSize = sizeof(cf);
	cf.hwndOwner = hWndParent;
	cf.rgbColors = textColor.ToCOLORREF();
	cf.lpszStyle = (LPTSTR)&szStyleName;
	cf.Flags = dwFlags;

	if (lplfInitial != NULL) {
		cf.lpLogFont = lplfInitial;
		cf.Flags |= CF_INITTOLOGFONTSTRUCT;
		lf = *lplfInitial;
	}
	else {
		cf.lpLogFont = &lf;
	}

	BOOL bRet = ::ChooseFont(&cf);
	if (bRet) {
		memcpy_s(&lf, sizeof(lf), cf.lpLogFont, sizeof(lf));

		//设置RichEdit字体
		CHARFORMAT2 charFormat = {};
		charFormat.cbSize = sizeof(CHARFORMAT2);
		pRichEdit->GetDefaultCharFormat(charFormat);
		InitCharFormat(lf, charFormat);
		pRichEdit->SetDefaultCharFormat(charFormat);

		//设置字体颜色
		textColor.SetFromCOLORREF(cf.rgbColors);
		std::wstring textColorString = ui::StringHelper::Printf(L"#%02X%02X%02X%02X", textColor.GetA(), textColor.GetR(), textColor.GetG(), textColor.GetB());
		pRichEdit->SetTextColor(textColorString);
	}
}

int MainForm::EnumFontFamExProc(const LOGFONT* lpelfe, const TEXTMETRIC* /*lpntme*/, DWORD fontType, LPARAM lParam)
{
	std::vector<FontInfo>* pFontList = (std::vector<FontInfo>*)lParam;
	if (pFontList != nullptr) {
		FontInfo fontInfo;
		if (lpelfe != nullptr) {
			fontInfo.lf = *lpelfe;
		}
		else {
			fontInfo.lf = {};
		}
		fontInfo.fontType = fontType;
		pFontList->emplace_back(std::move(fontInfo));
		return 1;
	}
	else {
		return 0;
	}
}
