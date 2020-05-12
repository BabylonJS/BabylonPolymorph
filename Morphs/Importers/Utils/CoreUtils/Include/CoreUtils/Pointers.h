/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <memory>

// Examples:
// MyClassPtr = std::shared_ptr<MyClass>        (suitable for storage and passing as argument to function that needs to extend lifetime)
// SceneCPtr = std::shared_ptr<const Scene>     (suitable for storage and passing as const argument to function that needs to extend lifetime)
// SceneWeakPtr = std::weak_ptr<Scene>          (suitable for storage when you don't want to extend lifetime or incur circular references)
// SceneWeakCPtr = std::weak_ptr<const Scene>   (suitable for storage and passing as const argument to function when you don't want to extend lifetime)
#define Babylon_SMART_POINTER_(TYPE, CLASS)             \
    TYPE CLASS;                                         \
    using CLASS##Ptr = std::shared_ptr<CLASS>;          \
    using CLASS##CPtr = std::shared_ptr<const CLASS>;   \
    using CLASS##WeakPtr = std::weak_ptr<CLASS>;        \
    using CLASS##WeakCPtr = std::weak_ptr<const CLASS>

#define Babylon_SMART_POINTER(CLASS) Babylon_SMART_POINTER_(class, CLASS)

namespace Babylon
{
    namespace Utils
    {
        Babylon_SMART_POINTER(ICancellationToken);
        Babylon_SMART_POINTER(IConfigurationManager);
        Babylon_SMART_POINTER(RequestManager);

        namespace Tweening
        {
            Babylon_SMART_POINTER(Tween);
            Babylon_SMART_POINTER(TweenManager);
        }
    }
}
