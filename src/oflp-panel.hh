/*
 * This file is part of the Code::Blocks IDE and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef __OFLP_PANEL_HH__
#define __OFLP_PANEL_HH__
//  ................................................................................................
#include    <wx/dnd.h>                                                                              //  for OpenFilesListPlusPanelDropTarget
//  ................................................................................................
#include    <wx/dynarray.h>

#include    "oflp-util-uid.hh"
/// ************************************************************************************************
//! \class  OpenFilesListPlusPanel
//!
//! \brief  wxPanel containing a OpenFilesListPlusPanelHeader and a wxTreeCtrl
/// ************************************************************************************************
class OpenFilesListPlusPanel              : public wxPanel
{
    friend class    OpenFilesListPlus;
    friend class    OflpModPanels;
    //  --------------------------------------------------------------------------------------------
  protected:
    oflp::UID                           a_uid;
    bool                                a_bulk;
    bool                                a_allow_kill_focus_event;
    static  wxTreeItemId                A_last_wxTreeItemId_dragged_and_dropped;

    OflpPanelHeader                 *   dw_header;
    wxTreeCtrl                      *   d_tree;
    wxBoxSizer                      *   dw_sizer;

    EditorArray                         a_editors_array;                                            //  speed up finding editors

    OpenFilesListPlusPanelDropTarget*   d_drop_target;
    //  ............................................................................................
  public:
    oflp::UID                       uid()                       const   { return a_uid;                 }
    bool                            is_bulk()                   const   { return a_bulk;                }
    EditorArray const   *           get_editors()               const   { return &a_editors_array;      }
    wxTreeCtrl  const   *   const   tree()                      const   { return d_tree;                }
    wxString    const   &           title()                     const;
    //  --------------------------------------------------------------------------------------------
    static      wxString            stringize_drag_result(wxDragResult _dres);
    //  --------------------------------------------------------------------------------------------
  protected:
    void                    z_create_tree       ();

    wxTreeItemId            item_append         (EditorBase*);                  //  x
    wxTreeItemId            item_find           (EditorBase*);                  //  x
    bool                    item_del            (EditorBase*);                  //  x
    bool                    item_select         (EditorBase*);
    bool                    item_selected       (EditorBase*);

    void                    items_deselect      ();
    void                    items_del           ();
    //  --------------------------------------------------------------------------------------------
  protected:
    bool                    editor_add      (EditorBase*);                      //  x
    bool                    editor_del      (EditorBase*);                      //  x
    void                    editor_select   (EditorBase*);
    bool                    editor_selected (EditorBase*);
    void                    editor_sync     (EditorBase*);

    void                    editors_del     ();
    void                    editors_deselect();

    wxButton        *       button(int _ix);
    wxBitmapButton  *       bitmap_button(int _ix);

    void                    minimize();
    void                    maximize();
    //  ............................................................................................
  public:
    void                    dump();

    bool                    editor_has                      (EditorBase*);
    bool                    is_minimized                    ();
    //  --------------------------------------------------------------------------------------------
  private:
    void                    z_set_col_bg                    (wxColour& _c);
    //void                    x_set_col_bg     (wxColour& _c);
    //  --------------------------------------------------------------------------------------------
  protected:
    void                    OnSelect    (wxCommandEvent&);
    void                    OnDragInit  (wxTreeEvent&);
    void                    OnDragEnd   (wxTreeEvent&);
    //  --------------------------------------------------------------------------------------------
  private:
            void            z_event_allow__kill_focus                       (bool);
    static  void            Z_set_last_wxTreeItemId_dragged_and_dropped     (wxTreeItemId);
public:
            bool            x_event_allowed__kill_focus             ()  { return a_allow_kill_focus_event;                  }
    static  wxTreeItemId    X_last_wxTreeItemId_dragged_and_dropped ()  { return A_last_wxTreeItemId_dragged_and_dropped;   }
  public:
    void                    evh_title_static_LEFT_DOWN              (wxMouseEvent   &);
    void                    evh_title_dynamic_TEXT_ENTER            (wxCommandEvent &);
    void                    evh_title_dynamic_KILL_FOCUS            (wxFocusEvent   &);
    //  --------------------------------------------------------------------------------------------
  public:
             OpenFilesListPlusPanel(wxWindow* _parent, wxString _title, oflp::UID _uid, bool _bulk);
    virtual ~OpenFilesListPlusPanel();
};
/// ************************************************************************************************
//! \class  OpenFilesListPlusPanelBulk
//!
//! \brief  Like OpenFilesListPlusPanel, but not deletable, not renamable,
//!     and containg the options menu
/// ************************************************************************************************
class OpenFilesListPlusPanelBulk          : public OpenFilesListPlusPanel
{
    //  --------------------------------------------------------------------------------------------
  public:
             OpenFilesListPlusPanelBulk(wxWindow* _parent, wxString _title);
    virtual ~OpenFilesListPlusPanelBulk();
};

#endif                                                                                              // __OFLP_PANEL_HH__

