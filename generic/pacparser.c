/*
 * tclpacparser
 */

#include "tclpacparser.h"



/*
 *----------------------------------------------------------------------
 *
 * tclpacparser_pacparserObjCmd --
 *
 *      This procedure is invoked to process the "pacparser" command.
 *      See the user documentation for details on what it does.
 *
 * Results:
 *      A standard Tcl result.
 *
 * Side effects:
 *      See the user documentation.
 *
 *----------------------------------------------------------------------
 */

    /* ARGSUSED */
int
tclpacparser_pacparserObjCmd(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
{
    int                 optIndex;

    static CONST char *options[] = {
        "init",
        "parse_pac",
        "find_proxy",
        "set_my_ip",
        "cleanup",
        NULL
    };

    enum options {
        OPT_INIT,
		OPT_PARSE_PAC,
		OPT_FIND_PROXY,
		OPT_SET_MY_IP,
		OPT_CLEANUP
    };

    // basic command line processing
    if (objc < 2) {
        Tcl_WrongNumArgs (interp, 1, objv, "subopt");
        return TCL_ERROR;
    }

    // argument must be one of the subOptions defined above
    if (Tcl_GetIndexFromObj (interp, objv[1], options, "option",
        TCL_EXACT, &optIndex) != TCL_OK) {
        return TCL_ERROR;
    }

	switch ((enum options)optIndex ) {
		case OPT_INIT: {
			if (!pacparser_init()) {
				Tcl_SetObjResult (interp, Tcl_NewStringObj ("pacparser init failed", -1));
				return TCL_ERROR;
			}
			break;
		}

		case OPT_PARSE_PAC: {
			if (objc != 3) {
				Tcl_WrongNumArgs (interp, 2, objv, "string");
				return TCL_ERROR;
			}

			if (!pacparser_parse_pac_string (Tcl_GetString (objv[2]))) {
				Tcl_SetObjResult (interp, Tcl_NewStringObj ("pacparser parse failed", -1));
				return TCL_ERROR;
			}

			break;
		}

		case OPT_FIND_PROXY: {
			char *string;

			if (objc != 4) {
				Tcl_WrongNumArgs (interp, 2, objv, "url host");
				return TCL_ERROR;
			}

			string = pacparser_find_proxy (Tcl_GetString (objv[2]), Tcl_GetString (objv[3]));
			// set the string if we got one else let it return an empty string
			if (string != NULL) {
				Tcl_SetObjResult (interp, Tcl_NewStringObj (string, -1));
			}

			break;
		}

		case OPT_SET_MY_IP: {
			if (objc != 3) {
				Tcl_WrongNumArgs (interp, 2, objv, "ip");
				return TCL_ERROR;
			}
			
			pacparser_setmyip (Tcl_GetString (objv[2]));
			break;
		}

		case OPT_CLEANUP: {
			pacparser_cleanup();
			break;
		}
	}

    return TCL_OK;
}
