/*
** Copyright (C) University of Virginia, Massachusetts Institue of Technology 1994-2000.
** See ../LICENSE for license information.
**
*/
/*
** context.h
*/

# ifndef CONTEXT_H
# define CONTEXT_H

extern void context_pushLoc (void);
extern void context_popLoc (void);

extern bool context_doMerge (void);
extern bool context_doDump (void);

extern void context_resetAllFlags (void);

extern /*@unused@*/ cstring context_unparseFlagMarkers (void) /*@*/ ;

extern void context_enterDoWhileClause (void) /*@modifies internalState@*/ ;

extern bool context_hasMods (void);

extern bool context_isSystemDir (cstring p_dir) /*@*/ ;

extern /*@observer@*/ char *context_selectedLibrary (void) /*@*/ ;
extern bool context_usingPosixLibrary (void) /*@*/ ;
extern bool context_usingAnsiLibrary (void) /*@*/ ;
extern flagcode context_getLibrary (void) /*@*/ ;
extern void context_setLibrary (flagcode) /*@modifies internalState@*/ ;

extern void context_setPreprocessing (void) /*@modifies internalState@*/;
extern void context_clearPreprocessing (void) /*@modifies internalState@*/;
extern bool context_isPreprocessing (void) /*@*/;

extern void context_setInCommandLine (void) /*@modifies internalState@*/ ;
extern void context_clearInCommandLine (void) /*@modifies internalState@*/ ;
extern bool context_isInCommandLine (void) /*@*/ ;

extern void context_resetErrors (void);

extern int context_getLinesProcessed (void) /*@*/ ;
extern int context_getSpecLinesProcessed (void) /*@*/ ;

extern bool context_setBoolName (void) /*@*/ ;
extern /*@observer@*/ cstring context_getBoolName (void) /*@*/ ;
extern /*@observer@*/ cstring context_printBoolName (void) /*@*/ ;
extern /*@observer@*/ cstring context_getFalseName (void) /*@*/ ;
extern /*@observer@*/ cstring context_getTrueName (void) /*@*/ ;
extern /*@observer@*/ cstring context_getLarchPath (void) /*@*/ ;
extern /*@observer@*/ cstring context_getLCLImportDir (void) /*@*/ ;

extern bool context_checkExport (uentry p_e) /*@*/ ;
extern bool context_checkGlobMod (sRef p_el) /*@*/ ;
extern bool context_checkGlobUse (uentry p_glob);
extern bool context_checkAliasGlob (uentry p_glob);
extern bool context_checkInternalUse (void);
extern void context_recordFileModifies (/*@dependent@*/ sRefSet p_mods);
extern void context_clearJustPopped (void);
extern bool context_justPopped (void);

extern void context_enterTrueClause (exprNode p_e);
extern void context_enterFalseClause (exprNode p_e);
extern void context_exitClause (exprNode p_pred, 
				exprNode p_tbranch, exprNode p_fbranch);
extern void context_exitInnerSafe (void);
extern void context_exitInnerPlain (void) /*@modifies internalState@*/ ;

extern bool context_inGlobalScope (void);
extern bool context_inInnerScope (void);
extern void context_setProtectVars (void);

extern int context_getLimit (void) /*@*/ ;
extern bool context_unlimitedMessages (void) /*@*/ ;

extern void context_releaseVars (void);
extern void context_sizeofReleaseVars (void);
extern bool context_inProtectVars (void);

extern bool context_hasFileAccess (typeId p_t);

extern void context_hideShowscan (void);
extern void context_unhideShowscan (void);

extern void context_setMode (cstring p_s);
extern void context_exitAllClauses (void);
extern bool context_inHeader (void);

extern /*@dependent@*/ /*@exposed@*/ fileTable context_fileTable (void) /*@*/ ;

extern /*@exposed@*/ messageLog context_messageLog (void);
extern /*@dependent@*/ /*@observer@*/ cstring context_tmpdir (void);

# ifndef NOLCL
extern void context_enterLCLfile (void);
extern void context_exitLCLfile (void);
extern void context_enterImport (void) ;
extern void context_leaveImport (void) ;
extern void context_processedSpecLine (void) /*@modifies internalState@*/ ;
extern int context_getLCLExpect (void) /*@*/ ;
extern bool context_msgLh (void) /*@*/ ;
extern bool context_inLCLLib (void) /*@globals internalState@*/ ;
extern bool context_inImport (void) /*@globals internalState@*/ ;
extern void context_resetSpecLines (void) /*@modifies internalState@*/ ;
# endif

extern void context_exitMacroCache (void);
extern void context_enterSuppressRegion (void);
extern void context_exitSuppressRegion (void);
extern void context_enterMacroFile (void);
extern typeIdSet context_fileAccessTypes (void);
extern void context_addFileAccessType (typeId p_t);
extern void context_removeFileAccessType (typeId p_t);
extern /*@observer@*/ uentryList context_getParams (void);

extern bool context_isSpecialFile (cstring p_fname);
extern /*@observer@*/ cstring context_inFunctionName (void) /*@*/ ;
extern ctype context_currentFunctionType (void) /*@*/ ;
extern void context_exitFile (void);
extern void context_enterConstantMacro (/*@dependent@*/ /*@exposed@*/ uentry p_e);
extern void context_enterMacro (/*@observer@*/ uentry p_e);
extern void context_enterFunction (/*@exposed@*/ uentry p_e);
extern void context_exitFunction (void);
extern void context_initMod (void) /*@modifies internalState@*/ ;
extern void context_enterInnerContext(void);
extern void context_exitInner (exprNode p_exp);
extern bool context_globAccess (sRef p_s);
extern /*@observer@*/ globSet context_getUsedGlobs (void);
extern bool context_hasAccess (typeId p_t);
extern bool context_couldHaveAccess (typeId p_t);
extern /*@only@*/ cstring context_unparse (void);
extern void context_setFunctionDefined (fileloc p_loc);
extern void context_setFlagTemp (flagcode p_f, bool p_b);

extern /*@unused@*/ void context_showFilelocStack (void) ;

extern bool context_getFlag (flagcode p_d) /*@*/ ;
extern int context_getLineLen (void) /*@*/ ;
# define context_getLineLen()  ((int)context_getValue(FLG_LINELEN))

extern int context_getValue (flagcode p_flag) /*@*/ ;
extern void context_setValueAndFlag (flagcode p_flag, int p_val) 
   /*@modifies internalState@*/ ;

extern /*@unused@*/ int context_getCounter (flagcode p_flag) /*@*/ ;
extern /*@unused@*/ void context_incCounter (flagcode p_flag) 
   /*@modifies internalState@*/ ;
extern /*@unused@*/ void context_decCounter (flagcode p_flag) 
   /*@modifies internalState@*/ ;

extern bool context_maybeSet (flagcode p_d) /*@*/ ;

extern /*@observer@*/ cstring context_getString (flagcode p_flag) /*@*/ ;
extern void context_setString (flagcode p_flag, /*@only@*/ cstring p_val)
   /*@modifies internalState@*/ ;

extern bool context_getDebug (flagcode p_d);
# define context_getDebug(p_d) context_getFlag(p_d)

extern void context_userSetFlag (flagcode p_f, bool p_b);

extern int context_getExpect (void) /*@*/ ;

extern /*@observer@*/ sRefSet context_modList(void);
extern /*@exposed@*/ uentry context_getHeader(void) /*@*/;
extern void context_usedGlobal (sRef p_el);
extern void context_resetModeFlags (void);
extern ctype context_typeofZero (void);
extern ctype context_typeofOne (void);
extern void context_enterFile (void);
extern void context_enterUnknownMacro (/*@dependent@*/ /*@observer@*/ uentry p_e);
extern char context_getCommentMarkerChar (void);
extern void context_setCommentMarkerChar (char p_c);
extern bool context_inMacroConstant (void) /*@*/ ;
extern void context_returnFunction (void);
extern bool context_processingMacros (void);

extern void context_saveLocation (void);
extern /*@only@*/ fileloc context_getSaveLocation (void);

extern void context_setFileId (fileId p_s);
extern void context_setFilename(fileId p_fid, int p_lineno) 
   /*@globals fileloc g_currentloc; @*/  
   /*@modifies g_currentloc@*/ ;

extern void context_fileSetFlag (flagcode p_f, ynm p_set);

extern /*@unused@*/ /*@only@*/ cstring context_unparseAccess (void) /*@*/ ;
extern bool context_inFunction(void) /*@*/ ;
extern bool context_inFunctionLike (void) /*@*/ ;

extern void context_setMacroMissingParams (void);
extern void context_resetMacroMissingParams (void);
extern bool context_isMacroMissingParams (void) /*@*/ ;
extern bool context_inMacroUnknown (void) /*@*/ ;

/*@observer@*/ cstring context_getDump (void) /*@*/ ;
/*@observer@*/ cstring context_getMerge (void) /*@*/ ;

extern void context_incLineno (void);
extern bool context_inSuppressRegion (void) /*@*/ ;
extern void context_exitTrueClause (exprNode p_pred, exprNode p_tbranch);
extern void context_destroyMod (void) /*@modifies internalState@*/ ;
extern void context_addMacroCache (/*@only@*/ cstring p_def);
extern void context_processAllMacros (void);
extern void context_addComment (/*@only@*/ cstring p_def);
extern void context_enterSuppressLine (int p_count);
extern bool context_inSuppressZone (fileloc p_fl) /*@*/ ;
extern void context_dumpModuleAccess (FILE *p_fout);
extern void context_loadModuleAccess (FILE *p_in);
extern bool context_inIterDef (void) /*@*/ ;
extern bool context_inMacro (void) /*@*/ ;
extern bool context_inIterEnd (void) /*@*/ ;
extern ctype context_getRetType (void) /*@*/ ;

extern void context_enterIterDef (/*@observer@*/ uentry p_le);
extern void context_enterIterEnd (/*@observer@*/ uentry p_le);
extern void context_addBoolAccess (void);
extern bool context_canAccessBool (void);
extern void context_quietExitFunction (void);

/* speedy shortcuts for frequently used flags */

extern bool context_msgBoolInt (void) /*@*/ ;
extern bool context_msgCharInt (void) /*@*/ ;
extern bool context_msgEnumInt (void) /*@*/ ;
extern bool context_msgPointerArith (void) /*@*/ ;
extern bool context_msgStrictOps (void) /*@*/ ;

extern void context_exitStructInnerContext (void);
extern void context_enterStructInnerContext (void);
extern bool context_inRealFunction (void) /*@*/ ;
extern void context_exitOrClause (exprNode p_pred, exprNode p_tbranch);
extern void context_exitAndClause (exprNode p_pred, exprNode p_tbranch);
extern void context_enterOrClause (exprNode p_e);
extern void context_enterAndClause (exprNode p_e);

extern void context_enterForClause (exprNode p_e);
extern void context_enterWhileClause (exprNode p_e);

extern void context_enterIterClause (void);
extern void context_exitIterClause (exprNode p_body);

extern void context_exitWhileClause (exprNode p_pred, exprNode p_body);
extern void context_exitDoWhileClause (exprNode p_pred);
extern void context_exitForClause (exprNode p_forPred, exprNode p_body);

extern /*@only@*/ cstring context_unparseClauses (void) /*@*/ ;
extern /*@observer@*/ globSet context_getGlobs (void) /*@*/ ;

extern /*@only@*/ cstring context_getMessageAnnote (void);
extern void context_clearMessageAnnote (void);
extern bool context_hasMessageAnnote (void);
extern void context_setMessageAnnote (/*@only@*/ cstring p_s);
extern bool context_suppressFlagMsg (flagcode p_flag, fileloc p_fl);
extern bool context_suppressNotFlagMsg (flagcode p_flag, fileloc p_fl);
extern void context_enterCaseClause (exprNode p_e);
extern void context_enterSwitch (exprNode p_e);
extern void context_exitSwitch (exprNode p_e, bool p_allpaths);

extern bool context_showFunction (void);
extern void context_setShownFunction (void);

extern void context_clearAliasAnnote (void);
extern cstring context_getAliasAnnote (void);
extern bool context_hasAliasAnnote (void);
extern void context_setAliasAnnote (/*@observer@*/ sRef p_s, /*@observer@*/ sRef p_t);

extern bool context_inDeepLoop (void) /*@globals internalState@*/ ;
extern bool context_inDeepLoopSwitch (void) /*@globals internalState@*/ ;
extern bool context_inConditional (void) /*@globals internalState@*/ ;
extern bool context_inDeepSwitch (void) /*@globals internalState@*/ ;

extern clause context_breakClause (void);
extern clause context_nextBreakClause (void);

extern bool context_anyErrors (void) /*@globals internalState@*/ ;
extern void context_hasError (void) /*@modifies internalState@*/ ;
extern int context_numErrors (void) /*@globals internalState@*/ ;
extern bool context_neednl (void);
extern void context_setNeednl (void);

extern bool context_inGlobalContext (void) /*@globals internalState@*/ ;
extern bool context_inMacroFunction (void) /*@globals internalState@*/ ;

extern /*@observer@*/ cstring context_moduleName (void) /*@*/ ;
extern void context_recordFileGlobals (/*@dependent@*/ globSet p_mods);
extern void context_checkSuppressCounts (void) /*@modifies g_msgstream@*/ ;

extern bool context_inFunctionDecl (void) /*@globals internalState@*/ ;
extern void context_enterFunctionDecl (void) /*@modifies internalState@*/ ;
extern void context_exitFunctionDecl (void) /*@modifies internalState@*/ ;

extern ctype context_boolImplementationType (void) /*@*/ ;

# else
# error "Multiple include"
# endif







