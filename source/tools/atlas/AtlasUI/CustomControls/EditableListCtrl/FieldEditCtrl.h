class EditableListCtrl;

class FieldEditCtrl
{
	friend class EditableListCtrl;

public:
	virtual ~FieldEditCtrl() {};

protected:
	virtual void StartEdit(wxWindow* parent, wxRect rect, long row, int col)=0;
};

//////////////////////////////////////////////////////////////////////////

class FieldEditCtrl_Text : public FieldEditCtrl
{
protected:
	void StartEdit(wxWindow* parent, wxRect rect, long row, int col);
};

//////////////////////////////////////////////////////////////////////////

class FieldEditCtrl_List : public FieldEditCtrl
{
public:
	// listType must remain valid at least until StartEdit has been called
	FieldEditCtrl_List(const char* listType);

protected:
	void StartEdit(wxWindow* parent, wxRect rect, long row, int col);

private:
	const char* m_ListType;
};

//////////////////////////////////////////////////////////////////////////

class FieldEditCtrl_Dialog : public FieldEditCtrl
{
public:
	FieldEditCtrl_Dialog(const wxString& dialogType);

protected:
	void StartEdit(wxWindow* parent, wxRect rect, long row, int col);

private:
	wxString m_DialogType;
};

//////////////////////////////////////////////////////////////////////////


class FieldEditCtrl_File : public FieldEditCtrl
{
public:
	// rootDir is relative to mods/official, and must end with a /
	FieldEditCtrl_File(const wxString& rootDir, const wxString& fileMask);

protected:
	void StartEdit(wxWindow* parent, wxRect rect, long row, int col);

private:
	wxString m_RootDir;
	wxString m_FileMask;
	wxString m_RememberedDir;
};
