/*
 * Copyright (c) 2008, AIST.
 * All rights reserved. This program is made available under the terms of the
 * Eclipse Public License v1.0 which accompanies this distribution, and is
 * available at http://www.eclipse.org/legal/epl-v10.html
 * Contributors:
 * National Institute of Advanced Industrial Science and Technology (AIST)
 */
/*
 * This file was generated by orbit-idl-2 - DO NOT EDIT!
 */

#include <string.h>
#define ORBIT2_STUBS_API
#include "echo.h"

void *
get_skel_small_Echo(POA_Echo * servant,
		    const char *opname, void **m_data, void **impl)
{
   switch (opname[0]) {
     case 'd':
	switch (opname[1]) {
	  case 'i':
	     switch (opname[2]) {
	       case 'v':
		  switch (opname[3]) {
		    case 'i':
		       switch (opname[4]) {
			 case 'd':
			    switch (opname[5]) {
			      case 'e':
				 switch (opname[6]) {
				   case '\0':
				      *impl =
					 (void *) servant->vepv->Echo_epv->
					 divide;
				      *m_data = &Echo__imp.methods[5];
				      return (void *) _RtORB_impl_Echo_divide;
				      break;
				   case '2':
				      if (strcmp((opname + 7), ""))
					 break;
				      *impl =
					 (void *) servant->vepv->Echo_epv->
					 divide2;
				      *m_data = &Echo__imp.methods[6];
				      return (void *)
					 _RtORB_impl_Echo_divide2;
				      break;
				   default:
				      break;
				 }
				 break;
			      default:
				 break;
			    }
			    break;
			 default:
			    break;
		       }
		       break;
		    default:
		       break;
		  }
		  break;
	       default:
		  break;
	     }
	     break;
	  default:
	     break;
	}
	break;
     case 'e':
	switch (opname[1]) {
	  case 'c':
	     switch (opname[2]) {
	       case 'h':
		  switch (opname[3]) {
		    case 'o':
		       switch (opname[4]) {
			 case 'S':
			    switch (opname[5]) {
			      case 't':
				 switch (opname[6]) {
				   case 'r':
				      switch (opname[7]) {
					case 'i':
					   switch (opname[8]) {
					     case 'n':
						switch (opname[9]) {
						  case 'g':
						     switch (opname[10]) {
						       case '\0':
							  *impl =
							     (void *)
							     servant->vepv->
							     Echo_epv->
							     echoString;
							  *m_data =
							     &Echo__imp.
							     methods[0];
							  return (void *)
							     _RtORB_impl_Echo_echoString;
							  break;
						       case '2':
							  if (strcmp
							      ((opname + 11),
							       ""))
							     break;
							  *impl =
							     (void *)
							     servant->vepv->
							     Echo_epv->
							     echoString2;
							  *m_data =
							     &Echo__imp.
							     methods[1];
							  return (void *)
							     _RtORB_impl_Echo_echoString2;
							  break;
						       case '3':
							  if (strcmp
							      ((opname + 11),
							       ""))
							     break;
							  *impl =
							     (void *)
							     servant->vepv->
							     Echo_epv->
							     echoString3;
							  *m_data =
							     &Echo__imp.
							     methods[2];
							  return (void *)
							     _RtORB_impl_Echo_echoString3;
							  break;
						       default:
							  break;
						     }
						     break;
						  default:
						     break;
						}
						break;
					     default:
						break;
					   }
					   break;
					default:
					   break;
				      }
				      break;
				   default:
				      break;
				 }
				 break;
			      default:
				 break;
			    }
			    break;
			 default:
			    break;
		       }
		       break;
		    default:
		       break;
		  }
		  break;
	       default:
		  break;
	     }
	     break;
	  default:
	     break;
	}
	break;
     case 'p':
	switch (opname[1]) {
	  case 'l':
	     switch (opname[2]) {
	       case 'u':
		  switch (opname[3]) {
		    case 's':
		       switch (opname[4]) {
			 case '\0':
			    *impl = (void *) servant->vepv->Echo_epv->plus;
			    *m_data = &Echo__imp.methods[3];
			    return (void *) _RtORB_impl_Echo_plus;
			    break;
			 case '2':
			    if (strcmp((opname + 5), ""))
			       break;
			    *impl = (void *) servant->vepv->Echo_epv->plus2;
			    *m_data = &Echo__imp.methods[4];
			    return (void *) _RtORB_impl_Echo_plus2;
			    break;
			 default:
			    break;
		       }
		       break;
		    default:
		       break;
		  }
		  break;
	       default:
		  break;
	     }
	     break;
	  default:
	     break;
	}
	break;
     default:
	break;
   }
   return NULL;
}

void
POA_Echo__init(PortableServer_Servant servant, CORBA_Environment * env)
{
   static PortableServer_ClassInfo class_info =
      { NULL, (void *(*)()) &get_skel_small_Echo, "IDL:Echo:1.0",
&Echo__classid, &Echo__imp };
   PortableServer_ServantBase__init(((PortableServer_ServantBase *) servant),
				    env);
   RtORB_POA_Object__create(&class_info, servant, NULL, NULL);
}

void
POA_Echo__fini(PortableServer_Servant servant, CORBA_Environment * env)
{
   PortableServer_ServantBase__fini(servant, env);
}
