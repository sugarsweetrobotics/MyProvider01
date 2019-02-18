// -*-C++-*-
/*!
 * @file  ExampleSVC_impl.cpp
 * @brief Service implementation code of Example.idl
 *
 */

// #include <coil/Task.h>
#include <iostream>
#include <coil/Time.h>


#include "ExampleSVC_impl.h"

static ::CORBA::Long g_data = 0;
/*
 * Example implementational code for IDL interface ssr::ServiceExample
 */
ssr_ServiceExampleSVC_impl::ssr_ServiceExampleSVC_impl()
{
  // Please add extra constructor code here.
}


ssr_ServiceExampleSVC_impl::~ssr_ServiceExampleSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
::CORBA::Long ssr_ServiceExampleSVC_impl::open(const char* filename)
{
	std::cout << "MyProv.open(" << filename << ")" << std::endl;
	if (strcmp(filename, "hogehoge.txt") == 0) {
		std::cout << " - raise exception!" << std::endl;
		throw ssr::ServiceExample::NoSuchFileError("No Such File hogehoge.txt");
	}

    return 1234;
}

::CORBA::Long ssr_ServiceExampleSVC_impl::write(::CORBA::Long fp, ::CORBA::Long data)
{
	std::cout << "MyProv.write(" << fp << ", " << data << ")";
	coil::usleep(1000 * 1000);  /// Sleep 1 sec.
	if (fp != 1234) {
		std::cout << " - bad fp." << std::endl;
		return -1;
	}
	std::cout << " - Written" << std::endl;
	g_data = data;
    return 0;
}

::CORBA::Long ssr_ServiceExampleSVC_impl::read(::CORBA::Long fp)
{
	std::cout << "MyProv.read(" << fp << ")" << std::endl;
	if (fp != 1234) {
		std::cout << " - bad fp." << std::endl;
		return -1;
    }
	std::cout << " - returns " << g_data << std::endl;
	return g_data;
}

void ssr_ServiceExampleSVC_impl::fastwrite(::CORBA::Long fp, ::CORBA::Long data)
{
	std::cout << "MyProv.fastwrite(" << fp << ", " << data << ")";
	coil::usleep(1000 * 1000);  /// Sleep 1 sec.
	if (fp != 1234) {
		std::cout << " - bad fp. but can not reply error." << std::endl;
	}
	else {
		g_data = data;
    }
	std::cout << " - Written" << std::endl;
}



// End of example implementational code



