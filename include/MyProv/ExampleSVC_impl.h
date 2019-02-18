// -*-C++-*-
/*!
 * @file  ExampleSVC_impl.h
 * @brief Service implementation header of Example.idl
 *
 */

#include "ExampleSkel.h"

#ifndef EXAMPLESVC_IMPL_H
#define EXAMPLESVC_IMPL_H
 
/*!
 * @class ServiceExampleSVC_impl
 * Example class implementing IDL interface ssr::ServiceExample
 */
class ssr_ServiceExampleSVC_impl
 : public virtual POA_ssr::ServiceExample,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~ServiceExampleSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   ssr_ServiceExampleSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~ssr_ServiceExampleSVC_impl();

   // attributes and operations
   ::CORBA::Long open(const char* filename);
   ::CORBA::Long write(::CORBA::Long fp, ::CORBA::Long data);
   ::CORBA::Long read(::CORBA::Long fp);
   void fastwrite(::CORBA::Long fp, ::CORBA::Long data);

};



#endif // EXAMPLESVC_IMPL_H


