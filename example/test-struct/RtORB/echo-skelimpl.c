/*
 * Copyright (c) 2008, AIST.
 * All rights reserved. This program is made available under the terms of the
 * Eclipse Public License v1.0 which accompanies this distribution, and is
 * available at http://www.eclipse.org/legal/epl-v10.html
 * Contributors:
 * National Institute of Advanced Industrial Science and Technology (AIST)
 */
/* This is a template file generated by command */
/* rtorb-idl --skeleton-impl echo.idl */
/* User must edit this file, inserting servant  */
/* specific code between markers. */

#include "echo.h"

/*** App-specific servant structures ***/

typedef struct
{
   POA_Echo servant;
   PortableServer_POA poa;

   /* ------ add private attributes here ------ */
   /* ------ ---------- end ------------ ------ */
} impl_POA_Echo;

/*** Implementation stub prototypes ***/

static void impl_Echo__destroy(impl_POA_Echo * servant,
			       CORBA_Environment * ev);
static CORBA_string
impl_Echo_echoString(impl_POA_Echo * servant,
		     const CORBA_char * mesg, CORBA_Environment * ev);

static CORBA_string
impl_Echo_echoString2(impl_POA_Echo * servant,
		      const CORBA_char * mesg,
		      CORBA_string * res, CORBA_Environment * ev);

static CORBA_string
impl_Echo_echoString3(impl_POA_Echo * servant,
		      CORBA_string * mesg, CORBA_Environment * ev);

static CORBA_long
impl_Echo_plus(impl_POA_Echo * servant,
	       const CORBA_long x,
	       const CORBA_long y, CORBA_Environment * ev);

static void
impl_Echo_plus2(impl_POA_Echo * servant,
		const CORBA_long x,
		const CORBA_long y, CORBA_long * ans, CORBA_Environment * ev);

static CORBA_float
impl_Echo_divide(impl_POA_Echo * servant,
		 const CORBA_float x,
		 const CORBA_float y, CORBA_Environment * ev);

static void
impl_Echo_divide2(impl_POA_Echo * servant,
		  const CORBA_float x,
		  const CORBA_float y,
		  CORBA_float * ans, CORBA_Environment * ev);

static void
impl_Echo_bind(impl_POA_Echo * servant,
	       const Name * n,
	       const CORBA_Object obj, CORBA_Environment * ev);

/*** epv structures ***/

static PortableServer_ServantBase__epv impl_Echo_base_epv = {
   NULL,			/* _private data */
   (void *) &impl_Echo__destroy,	/* finalize routine */
   NULL,			/* default_POA routine */
};
static POA_Echo__epv impl_Echo_epv = {
   NULL,			/* _private */
   (void *) &impl_Echo_echoString,

   (void *) &impl_Echo_echoString2,

   (void *) &impl_Echo_echoString3,

   (void *) &impl_Echo_plus,

   (void *) &impl_Echo_plus2,

   (void *) &impl_Echo_divide,

   (void *) &impl_Echo_divide2,

   (void *) &impl_Echo_bind,

};

/*** vepv structures ***/

static POA_Echo__vepv impl_Echo_vepv = {
   &impl_Echo_base_epv,
   &impl_Echo_epv,
};

/*** Stub implementations ***/

Echo
impl_Echo__create(PortableServer_POA poa, CORBA_Environment * ev)
{
   Echo retval;
   impl_POA_Echo *newservant;
   PortableServer_ObjectId *objid;

   newservant = (impl_POA_Echo *) calloc(sizeof(impl_POA_Echo), 1);
   newservant->servant.vepv = &impl_Echo_vepv;
   newservant->poa = poa;
   POA_Echo__init((PortableServer_Servant) newservant, ev);
   /* Before servant is going to be activated all
    * private attributes must be initialized.  */

   /* ------ init private attributes here ------ */
   /* ------ ---------- end ------------- ------ */

   objid = PortableServer_POA_activate_object(poa, newservant, ev);
   free(objid);
   retval = PortableServer_POA_servant_to_reference(poa, newservant, ev);

   return retval;
}

static void
impl_Echo__destroy(impl_POA_Echo * servant, CORBA_Environment * ev)
{
   CORBA_Object_release((CORBA_Object) servant->poa, ev);

   /* No further remote method calls are delegated to 
    * servant and you may free your private attributes. */
   /* ------ free private attributes here ------ */
   /* ------ ---------- end ------------- ------ */

   POA_Echo__fini((PortableServer_Servant) servant, ev);

   free(servant);
}

static CORBA_string
impl_Echo_echoString(impl_POA_Echo * servant,
		     const CORBA_char * mesg, CORBA_Environment * ev)
{
   CORBA_string retval;

   /* ------   insert method code here   ------ */
   fprintf(stderr, "echoString: %s\n", mesg);
   retval = strdup("OK echoString");
   /* ------ ---------- end ------------ ------ */

   return retval;
}

static CORBA_string
impl_Echo_echoString2(impl_POA_Echo * servant,
		      const CORBA_char * mesg,
		      CORBA_string * res, CORBA_Environment * ev)
{
   CORBA_string retval;

   /* ------   insert method code here   ------ */
   fprintf(stderr, "echoString:2 %s\n", mesg);
   res = strdup("RESULT echoString2");
   retval = strdup("OK echoString2");
   /* ------ ---------- end ------------ ------ */

   return retval;
}

static CORBA_string
impl_Echo_echoString3(impl_POA_Echo * servant,
		      CORBA_string * mesg, CORBA_Environment * ev)
{
   CORBA_string retval;

   /* ------   insert method code here   ------ */
   fprintf(stderr, "echoString:3 %s\n", *mesg);
   retval = strdup("OK echoString3");
   strncpy(*mesg, "!", 1);
   /* ------ ---------- end ------------ ------ */

   return retval;
}

static CORBA_long
impl_Echo_plus(impl_POA_Echo * servant,
	       const CORBA_long x, const CORBA_long y, CORBA_Environment * ev)
{
   CORBA_long retval;

   /* ------   insert method code here   ------ */
	retval = x + y;
   /* ------ ---------- end ------------ ------ */

   return retval;
}

static void
impl_Echo_plus2(impl_POA_Echo * servant,
		const CORBA_long x,
		const CORBA_long y, CORBA_long * ans, CORBA_Environment * ev)
{
   /* ------   insert method code here   ------ */
	*ans = x + y;
   /* ------ ---------- end ------------ ------ */
}

static CORBA_float
impl_Echo_divide(impl_POA_Echo * servant,
		 const CORBA_float x,
		 const CORBA_float y, CORBA_Environment * ev)
{
   CORBA_float retval;

   /* ------   insert method code here   ------ */
	retval = x / y;
   /* ------ ---------- end ------------ ------ */

   return retval;
}

static void
impl_Echo_divide2(impl_POA_Echo * servant,
		  const CORBA_float x,
		  const CORBA_float y,
		  CORBA_float * ans, CORBA_Environment * ev)
{
   /* ------   insert method code here   ------ */
	*ans = x / y;
   /* ------ ---------- end ------------ ------ */
}

static void
impl_Echo_bind(impl_POA_Echo * servant,
	       const Name * n, const CORBA_Object obj, CORBA_Environment * ev)
{
   /* ------   insert method code here   ------ */
    int i;

    fprintf(stderr, "Object ref = %s\n\n", obj->_url->type_id);

    for(i=0; i< n->_length; i++){
      fprintf(stderr, "Name[%d] id = %s\n", i, n->_buffer[i].id);
      fprintf(stderr, "Name[%d] kind = %s\n\n", i, n->_buffer[i].kind);
    }
    
   /* ------ ---------- end ------------ ------ */
}