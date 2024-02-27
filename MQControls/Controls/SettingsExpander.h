#pragma once
#include "SettingsExpander.g.h"

using namespace winrt::Microsoft::UI::Xaml;

namespace winrt::MQControls::implementation {
    struct SettingsExpander : SettingsExpanderT<SettingsExpander> {
        using MQControl = winrt::MQControls::SettingsExpander;

        SettingsExpander() {
            DefaultStyleKey(box_value(xaml_typename<MQControl>()));
        }

        inline static auto mHeaderProperty{ DependencyProperty::Register(
            L"Header", xaml_typename<IInspectable>(), xaml_typename<MQControl>(),
            { nullptr, nullptr }
        ) };
        static DependencyProperty HeaderProperty() { return mHeaderProperty; }
        IInspectable Header() const { return GetValue(mHeaderProperty); }
        void Header(IInspectable const& value) { SetValue(mHeaderProperty, value); }


        inline static auto mTitleProperty{ DependencyProperty::Register(
            L"Title", xaml_typename<hstring>(), xaml_typename<MQControl>(),
            { box_value(L""), nullptr }
        ) };
        static DependencyProperty TitleProperty() { return mTitleProperty; }
        hstring Title() const { return unbox_value<hstring>(GetValue(mTitleProperty)); }
        void Title(hstring const& value) { SetValue(mTitleProperty, box_value(value)); }


        inline static auto mMessageProperty{ DependencyProperty::Register(
            L"Message", xaml_typename<hstring>(), xaml_typename<MQControl>(),
            { box_value(L""), nullptr }
        ) };
        static DependencyProperty MessageProperty() { return mMessageProperty; }
        hstring Message() const { return unbox_value<hstring>(GetValue(mMessageProperty)); }
        void Message(hstring const& value) { SetValue(mMessageProperty, box_value(value)); }


        inline static auto mIconProperty{ DependencyProperty::Register(
            L"Icon", xaml_typename<hstring>(), xaml_typename<MQControl>(),
            { box_value(L""), nullptr }
        ) };
        static DependencyProperty IconProperty() { return mIconProperty; }
        hstring Icon() const { return unbox_value<hstring>(GetValue(mIconProperty)); }
        void Icon(hstring const& value) { SetValue(mIconProperty, box_value(value)); }


        inline static auto mIsExpandedProperty{ DependencyProperty::Register(
            L"IsExpanded", xaml_typename<bool>(), xaml_typename<MQControl>(),
            { box_value(false), nullptr }
        ) };
        static DependencyProperty IsExpandedProperty() { return mIsExpandedProperty; }
        bool IsExpanded() const { return unbox_value<bool>(GetValue(mIsExpandedProperty)); }
        void IsExpanded(bool value) { SetValue(mIsExpandedProperty, box_value(value)); }
    };
}

namespace winrt::MQControls::factory_implementation {
    struct SettingsExpander : SettingsExpanderT<SettingsExpander, implementation::SettingsExpander> { };
}
