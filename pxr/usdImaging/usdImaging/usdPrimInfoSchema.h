//
// Copyright 2023 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/* ** This file is generated by a script.  Do not edit directly.  Edit     ** */
/* ** defs.py or the (*)Schema.template.h files to make changes.           ** */
/* ************************************************************************** */

#ifndef PXR_USD_IMAGING_USD_IMAGING_USD_PRIM_INFO_SCHEMA_H
#define PXR_USD_IMAGING_USD_IMAGING_USD_PRIM_INFO_SCHEMA_H

#include "pxr/usdImaging/usdImaging/api.h"

#include "pxr/imaging/hd/schema.h" 

PXR_NAMESPACE_OPEN_SCOPE

//-----------------------------------------------------------------------------

#define USDIMAGINGUSDPRIMINFO_SCHEMA_TOKENS \
    (__usdPrimInfo) \
    (niPrototypePath) \
    (isNiPrototype) \
    (specifier) \
    (def) \
    (over) \
    ((class_, "class")) \

TF_DECLARE_PUBLIC_TOKENS(UsdImagingUsdPrimInfoSchemaTokens, USDIMAGING_API,
    USDIMAGINGUSDPRIMINFO_SCHEMA_TOKENS);

//-----------------------------------------------------------------------------

class UsdImagingUsdPrimInfoSchema : public HdSchema
{
public:
    UsdImagingUsdPrimInfoSchema(HdContainerDataSourceHandle container)
    : HdSchema(container) {}

    //ACCESSORS

    USDIMAGING_API
    HdPathDataSourceHandle GetNiPrototypePath();
    USDIMAGING_API
    HdBoolDataSourceHandle GetIsNiPrototype();
    USDIMAGING_API
    HdTokenDataSourceHandle GetSpecifier();

    // RETRIEVING AND CONSTRUCTING

    /// Builds a container data source which includes the provided child data
    /// sources. Parameters with nullptr values are excluded. This is a
    /// low-level interface. For cases in which it's desired to define
    /// the container with a sparse set of child fields, the Builder class
    /// is often more convenient and readable.
    USDIMAGING_API
    static HdContainerDataSourceHandle
    BuildRetained(
        const HdPathDataSourceHandle &niPrototypePath,
        const HdBoolDataSourceHandle &isNiPrototype,
        const HdTokenDataSourceHandle &specifier
    );

    /// \class UsdImagingUsdPrimInfoSchema::Builder
    /// 
    /// Utility class for setting sparse sets of child data source fields to be
    /// filled as arguments into BuildRetained. Because all setter methods
    /// return a reference to the instance, this can be used in the "builder
    /// pattern" form.
    class Builder
    {
    public:
        USDIMAGING_API
        Builder &SetNiPrototypePath(
            const HdPathDataSourceHandle &niPrototypePath);
        USDIMAGING_API
        Builder &SetIsNiPrototype(
            const HdBoolDataSourceHandle &isNiPrototype);
        USDIMAGING_API
        Builder &SetSpecifier(
            const HdTokenDataSourceHandle &specifier);

        /// Returns a container data source containing the members set thus far.
        USDIMAGING_API
        HdContainerDataSourceHandle Build();

    private:
        HdPathDataSourceHandle _niPrototypePath;
        HdBoolDataSourceHandle _isNiPrototype;
        HdTokenDataSourceHandle _specifier;
    };

    /// Retrieves a container data source with the schema's default name token
    /// "__usdPrimInfo" from the parent container and constructs a
    /// UsdImagingUsdPrimInfoSchema instance.
    /// Because the requested container data source may not exist, the result
    /// should be checked with IsDefined() or a bool comparison before use.
    USDIMAGING_API
    static UsdImagingUsdPrimInfoSchema GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer);

    /// Returns an HdDataSourceLocator (relative to the prim-level data source)
    /// where the container representing this schema is found by default.
    USDIMAGING_API
    static const HdDataSourceLocator &GetDefaultLocator();


    /// Returns an HdDataSourceLocator (relative to the prim-level data source)
    /// where the niprototypepath data source can be found.
    /// This is often useful for checking intersection against the
    /// HdDataSourceLocatorSet sent with HdDataSourceObserver::PrimsDirtied.
    USDIMAGING_API
    static const HdDataSourceLocator &GetNiPrototypePathLocator();

};

PXR_NAMESPACE_CLOSE_SCOPE

#endif
