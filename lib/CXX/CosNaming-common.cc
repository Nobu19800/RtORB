/*
 * This file was generated by orbit-idl-2 - DO NOT EDIT!
 */

#include <string.h>
#include <RtORB/cdrStream.h>
#define CONST const
#define CosNaming_COMMON
#include "CosNaming.h"

/** Interface Module definitions in CosNaming */
/* C++ Methods */
#ifdef __cplusplus /* cc_output_methods */
#ifndef Defined_cdr_CosNaming_NameComponent
#define Defined_cdr_CosNaming_NameComponent TRUE
 void CosNaming_NameComponent::operator>>=(cdrStream &_n) CONST 
{
  id >>= _n;
  kind >>= _n;
}
 void CosNaming_NameComponent::operator<<=(cdrStream &_n) {
  id <<= _n;
  kind <<= _n;
}
#endif /* Defined_cdr_CosNaming_NameComponent */
#ifndef Defined_CORBA_sequence_CosNaming_NameComponent
#define Defined_CORBA_sequence_CosNaming_NameComponent TRUE
 CORBA_sequence_CosNaming_NameComponent::CppSeq::ElemRef 
CORBA_sequence_CosNaming_NameComponent::operator[](CORBA::ULong n)
{
  return CORBA_sequence_CosNaming_NameComponent::CppSeq::element(this, (int)n);
}


#endif /* Defined_CORBA_sequence_CosNaming_NameComponent */
#ifndef Defined_cdr_CosNaming_Binding
#define Defined_cdr_CosNaming_Binding TRUE
 void CosNaming_Binding::operator>>=(cdrStream &_n) CONST 
{
  binding_name >>= _n;
  binding_type >>= _n;
}
 void CosNaming_Binding::operator<<=(cdrStream &_n) {
  binding_name <<= _n;
  binding_type <<= _n;
}
#endif /* Defined_cdr_CosNaming_Binding */
#ifndef Defined_CORBA_sequence_CosNaming_Binding
#define Defined_CORBA_sequence_CosNaming_Binding TRUE

 CORBA_sequence_CosNaming_Binding_type & 
CORBA_sequence_CosNaming_Binding::operator=(const CORBA_sequence_CosNaming_Binding_type &o)
{
  CppSeq::copy(o, *this);
  return *this;
}

#endif /* Defined_CORBA_sequence_CosNaming_Binding */
#endif /* __cplusplus */
