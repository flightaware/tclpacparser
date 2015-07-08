/*
 * pacparser_Init and pacparser_SafeInit
 *
 * Copyright (C) 2015 FlightAware
 *
 * Freely redistributable under the Berkeley copyright.  See license.terms
 * for details.
 */

#include "tclpacparser.h"

#undef TCL_STORAGE_CLASS
#define TCL_STORAGE_CLASS DLLEXPORT


/*
 *----------------------------------------------------------------------
 *
 * pacparser_Init --
 *
 *	Initialize the pacparser extension.  The string "pacparser" 
 *      in the function name must match the PACKAGE declaration at the top of
 *	configure.in.
 *
 * Results:
 *	A standard Tcl result
 *
 * Side effects:
 *	One new command "pacparser" is added to the Tcl interpreter.
 *
 *----------------------------------------------------------------------
 */

EXTERN int
Tclpacparser_Init(Tcl_Interp *interp)
{
    /*
     * This may work with 8.0, but we are using strictly stubs here,
     * which requires 8.1.
     */
    if (Tcl_InitStubs(interp, "8.1", 0) == NULL) {
	return TCL_ERROR;
    }

    if (Tcl_PkgRequire(interp, "Tcl", "8.1", 0) == NULL) {
	return TCL_ERROR;
    }

    if (Tcl_PkgProvide(interp, "pacparser", PACKAGE_VERSION) != TCL_OK) {
	return TCL_ERROR;
    }

    /* Create the pacparser command  */
    Tcl_CreateObjCommand(interp, "pacparser", (Tcl_ObjCmdProc *) tclpacparser_pacparserObjCmd, (ClientData)NULL, (Tcl_CmdDeleteProc *)NULL);

    return TCL_OK;
}


/*
 *----------------------------------------------------------------------
 *
 * pacparser_SafeInit --
 *
 *	Initialize the pacparser in a safe interpreter.
 *
 *      This should be totally safe.
 *
 * Results:
 *	A standard Tcl result
 *
 * Side effects:
 *	One new command "pacparser" is added to the Tcl interpreter.
 *
 *----------------------------------------------------------------------
 */

EXTERN int
Tclpacparser_SafeInit(Tcl_Interp *interp)
{
    /*
     * This may work with 8.0, but we are using strictly stubs here,
     * which requires 8.1.
     */
    if (Tcl_InitStubs(interp, "8.1", 0) == NULL) {
	return TCL_ERROR;
    }

    if (Tcl_PkgRequire(interp, "Tcl", "8.1", 0) == NULL) {
	return TCL_ERROR;
    }

    if (Tcl_PkgProvide(interp, "pacparser", PACKAGE_VERSION) != TCL_OK) {
	return TCL_ERROR;
    }

    /* Create the pacparser command  */
    Tcl_CreateObjCommand(interp, "pacparser", (Tcl_ObjCmdProc *) tclpacparser_pacparserObjCmd, (ClientData)NULL, (Tcl_CmdDeleteProc *)NULL);

    return TCL_OK;
}

