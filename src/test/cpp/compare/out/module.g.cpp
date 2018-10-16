﻿// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.000000.0
#include "pch.h"
#include "Component.Class.h"

int32_t WINRT_CALL WINRT_CanUnloadNow() noexcept
{
#ifdef _WRL_MODULE_H_
    if (!::Microsoft::WRL::Module<::Microsoft::WRL::InProc>::GetModule().Terminate())
    {
        return 1;
    }
#endif

    if (winrt::get_module_lock())
    {
        return 1;
    }

    winrt::clear_factory_cache();
    return 0;
}

int32_t WINRT_CALL WINRT_GetActivationFactory(void* classId, void** factory) noexcept
{
    try
    {
        *factory = nullptr;
        uint32_t length{};
        wchar_t const* const buffer = WINRT_WindowsGetStringRawBuffer(classId, &length);
        std::wstring_view const name{ buffer, length };

        auto requal = [](std::wstring_view const& left, std::wstring_view const& right) noexcept
        {
            return std::equal(left.rbegin(), left.rend(), right.rbegin(), right.rend());
        };
        if (requal(name, L"Component.Class"))
        {
            *factory = winrt::detach_abi(winrt::make<winrt::Component::factory_implementation::Class>());
            return 0;
        }

#ifdef _WRL_MODULE_H_
        return ::Microsoft::WRL::Module<::Microsoft::WRL::InProc>::GetModule().GetActivationFactory(static_cast<HSTRING>(classId), reinterpret_cast<::IActivationFactory**>(factory));
#else
        return winrt::hresult_class_not_available(name).to_abi();
#endif
    }
    catch (...) { return winrt::to_hresult(); }
}
namespace winrt::Component
{
    Class::Class(Class const& other) noexcept : base_type(other)
    {
    }

    Class::~Class() noexcept
    {
    }

    Class::Class(construct_from_abi_t, void* ptr) noexcept : base_type(construct_from_abi, ptr)
    {
    }

    Class& Class::operator=(Class const& other) noexcept
    {
        if (this != &other)
        {
            base_type::operator=(other);
        }

        return*this;
    }

    Class& Class::operator=(Class&& other) noexcept
    {
        if (this != &other)
        {
            base_type::operator=(std::move(other));
        }

        return*this;
    }

    Class& Class::operator=(std::nullptr_t) noexcept
    {
        if (*this)
        {
            base_type::operator=(nullptr);
        }

        return*this;
    }

    void Class::attach_abi(void* ptr) noexcept
    {
        base_type::attach_abi(ptr);
    }

    void* Class::detach_abi() noexcept
    {
        return base_type::detach_abi();
    }
    hstring Class::Method() const
    {
        return get_self<implementation::Class>(*this)->Method();
    }
    hstring Class::Property() const
    {
        return get_self<implementation::Class>(*this)->Property();
    }
    void Class::Property(param::hstring const& value) const
    {
        get_self<implementation::Class>(*this)->Property(value);
    }
    Class::Class(param::hstring const& a) :
        Class(make<implementation::Class>(a))
    {}
    hstring Class::StaticMethod()
    {
        return implementation::Class::StaticMethod();
    }
}
