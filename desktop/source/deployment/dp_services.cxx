/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */


#include <comphelper/servicedecl.hxx>

#include <dp_services.hxx>

using namespace com::sun::star;
namespace sdecl = comphelper::service_decl;

extern "C" {

SAL_DLLPUBLIC_EXPORT void * deployment_component_getFactory(
    char const * pImplName, void *, void *)
{
    return sdecl::component_getFactoryHelper(
        pImplName,
        {&dp_registry::backend::configuration::serviceDecl,
         &dp_registry::backend::component::serviceDecl,
         &dp_registry::backend::help::serviceDecl,
         &dp_registry::backend::script::serviceDecl,
         &dp_registry::backend::sfwk::serviceDecl,
         &dp_registry::backend::executable::serviceDecl,
         &dp_manager::factory::serviceDecl,
         &dp_log::serviceDecl,
         &dp_info::serviceDecl,
         &dp_manager::serviceDecl});
}

} // extern "C"

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
