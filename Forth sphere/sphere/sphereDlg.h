
// sphereDlg.h : ͷ�ļ�
//

#pragma once


// CsphereDlg �Ի���
class CsphereDlg : public CDialogEx
{
// ����
public:
	CsphereDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SPHERE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	float my_r;
	float my_s;
	float my_v;
	afx_msg void OnClickedSet();
};
