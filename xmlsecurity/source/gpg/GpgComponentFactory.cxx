/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <sal/config.h>

#include <com/sun/star/lang/XSingleServiceFactory.hpp>

#include "xmlsignature_gpgimpl.hxx"

using namespace ::cppu;
using namespace ::com::sun::star::uno;
using namespace ::com::sun::star::lang;

extern "C"
{

SAL_DLLPUBLIC_EXPORT void* SAL_CALL xsec_gpg_component_getFactory( const char* pImplName , void* pServiceManager , void* /*pRegistryKey*/ )
{
    void* pRet = nullptr;
    Reference< XSingleServiceFactory > xFactory ;

    if( pImplName != nullptr && pServiceManager != nullptr )
    {
        if( XMLSignature_GpgImpl::impl_getImplementationName().equalsAscii( pImplName ) )
        {
            xFactory = XMLSignature_GpgImpl::impl_createFactory( static_cast< XMultiServiceFactory* >( pServiceManager ) ) ;
        }
    }

    if( xFactory.is() ) {
        xFactory->acquire() ;
        pRet = xFactory.get() ;
    }

    return pRet ;
}

}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
