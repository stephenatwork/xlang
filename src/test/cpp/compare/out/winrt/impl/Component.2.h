﻿// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.000000.0
#pragma once
#include "winrt/impl/Component.1.h"
namespace winrt::Component
{
    struct Delegate : Windows::Foundation::IUnknown
    {
        Delegate(std::nullptr_t = nullptr) noexcept {}
        template <typename L> Delegate(L lambda);
        template <typename F> Delegate(F* function);
        template <typename O, typename M> Delegate(O* object, M method);
        template <typename O, typename M> Delegate(com_ptr<O>&& object, M method);
        template <typename O, typename M> Delegate(weak_ref<O>&& object, M method);
        void operator()(param::hstring const& arg) const;
    };
    struct WINRT_EBO Class :
        Component::IClass
    {
        Class(std::nullptr_t) noexcept {}
        Class(param::hstring const& a);
    Class();
    static hstring StaticMethod();
};
}
