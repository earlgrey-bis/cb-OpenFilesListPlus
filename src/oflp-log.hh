/*
 * This file is licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef __OFLP_PLUGIN_LOG_HH__
#define __OFLP_PLUGIN_LOG_HH__
//  ################################################################################################
//  logs enabled
//  ################################################################################################
#ifdef  OFLP_EMBED__LOG
//  ================================================================================================
//  log frame
//  ================================================================================================
#include    "oflp-log-frame.hh"

class   wxWindow;

namespace   oflp
{

extern  wxColour    A_colour_fun_ent;

extern  wxColour    A_colour_log_inf;
extern  wxColour    A_colour_log_wng;
extern  wxColour    A_colour_log_err;
extern  wxColour    A_colour_log_tki;
extern  wxColour    A_colour_log_tkw;
extern  wxColour    A_colour_log_tke;
//  ................................................................................................
extern          void            Log_spc_inc();
extern          void            Log_spc_dec();
extern  const   wxChar      *   Log_spc_wxc();

extern          void            Log_function_mark   (const wxChar*);
extern          void            Log_function_enter  (const wxChar*);
extern          void            Log_function_exit   ();

extern          void            Log_window_open             (wxWindow*);
extern          void            Log_window_close            ();

extern          void            Log_console                 (wxString&);
extern          void            Log_window                  (wxString&);
extern          void            Log_window_set_text_col_fg  (wxColour&);
extern          void            Log_window_set_text_attr    (wxTextAttr&);

}
//  ================================================================================================
//  log macros
//  ================================================================================================
#define     ERGCB_LOG(WXFORMAT, ...)                                            \
{                                                                               \
    wxString tmp =                                                              \
        wxString::Format(                                                       \
            WXFORMAT                    ,                                       \
            oflp::Log_spc_wxc()         ,                                       \
            __VA_ARGS__                 );                                      \
                                                                                \
        oflp::Log_console  ( tmp );                                             \
        oflp::Log_window   ( tmp );                                             \
}
//  ................................................................................................
#define ERGCB_FNE(FORMAT, ...)                                                  \
{                                                                               \
    oflp::Log_window_set_text_col_fg(oflp::A_colour_fun_ent);                   \
    ERGCB_LOG(wxS("%s"        FORMAT), __VA_ARGS__);                            \
}

#define ERGCB_TKI(FORMAT, ...)                                                  \
{                                                                               \
    oflp::Log_window_set_text_col_fg(oflp::A_colour_log_tki);                   \
    ERGCB_LOG(wxS("%s" "tki:" FORMAT), __VA_ARGS__);                            \
}
#define ERGCB_TKW(FORMAT, ...)                                                  \
{                                                                               \
    oflp::Log_window_set_text_col_fg(oflp::A_colour_log_tkw);                   \
    ERGCB_LOG(wxS("%s" "tkw:" FORMAT), __VA_ARGS__);                            \
}
#define ERGCB_TKE(FORMAT, ...)                                                  \
{                                                                               \
    oflp::Log_window_set_text_col_fg(oflp::A_colour_log_tke);                   \
    ERGCB_LOG(wxS("%s" "tke:" FORMAT), __VA_ARGS__);                            \
}
#define ERGCB_INF(FORMAT, ...)                                                  \
{                                                                               \
    oflp::Log_window_set_text_col_fg(oflp::A_colour_log_inf);                   \
    ERGCB_LOG(wxS("%s" "inf:" FORMAT), __VA_ARGS__);                            \
}
#define ERGCB_WNG(FORMAT, ...)                                                  \
{                                                                               \
    oflp::Log_window_set_text_col_fg(oflp::A_colour_log_wng);                   \
    ERGCB_LOG(wxS("%s" "wng:" FORMAT), __VA_ARGS__);                            \
}
#define ERGCB_ERR(FORMAT, ...)                                                  \
{                                                                               \
    oflp::Log_window_set_text_col_fg(oflp::A_colour_log_err);                   \
    ERGCB_LOG(wxS("%s" "err:" FORMAT), __VA_ARGS__);                            \
}

//  ................................................................................................
#ifdef  OFLP_LOG_FUNCTIONS

#define OFLP_LOG_FUNC_ENTER(FUNCNAME)                                           \
        oflp::Log_function_enter(wxS(FUNCNAME));

#define OFLP_LOG_FUNC_EXIT()                                                    \
        oflp::Log_function_exit();

#define OFLP_LOG_FUNC_INC()                                                     \
        oflp::Log_spc_inc();

#define OFLP_LOG_FUNC_DEC()                                                     \
        oflp::Log_spc_dec();

#define OFLP_FUNC_ENTER_MARK(FUNCNAME)                                          \
        oflp::Log_function_mark(wxS(FUNCNAME));

#else

#define OFLP_LOG_FUNC_ENTER(FUNCNAME)
#define OFLP_LOG_FUNC_EXIT()
#define OFLP_FUNC_ENTER_MARK(FUNCNAME)

#endif                                                                                              //  OFLP_LOG_FUNCTIONS

#endif                                                                                              //  OFLP_EMBED__LOG
//  ################################################################################################
//  logs disabled
//  ################################################################################################
#ifndef OFLP_EMBED__LOG
//  ================================================================================================
//  log frame
//  ================================================================================================
class   wxWindow;

namespace oflp
{

extern  void        Log_window_open             (wxWindow*);
//extern  void        Log_window_open             ();
extern  void        Log_window_close            ();

}
//  ================================================================================================
//  log macros
//  ================================================================================================
#define ERGCB_LOG(WXFORMAT, ...)
//  ................................................................................................
#define ERGCB_TCS(FORMAT, ...)

#define ERGCB_TKI(FORMAT, ...)
#define ERGCB_TKW(FORMAT, ...)
#define ERGCB_TKE(FORMAT, ...)

#define ERGCB_INF(FORMAT, ...)
#define ERGCB_WNG(FORMAT, ...)
#define ERGCB_ERR(FORMAT, ...)
//  ................................................................................................
#define OFLP_LOG_FUNC_ENTER(FUNCNAME)
#define OFLP_LOG_FUNC_EXIT()
#define OFLP_LOG_FUNC_INC()
#define OFLP_LOG_FUNC_DEC()
#define OFLP_FUNC_ENTER_MARK(FUNCNAME)


#endif                                                                                              //  OFLP_EMBED__LOG

#endif                                                                                              //  __OFLP_PLUGIN_LOG_HH__
