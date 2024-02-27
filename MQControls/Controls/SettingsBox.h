#pragma once
#include "SettingsBox.g.h"

using namespace winrt::Microsoft::UI::Xaml;

namespace winrt::MQControls::implementation {
    struct SettingsBox : SettingsBoxT<SettingsBox> {
        using MQControl = winrt::MQControls::SettingsBox;

        SettingsBox() {
            DefaultStyleKey(box_value(xaml_typename<MQControl>()));
        }

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

        inline static auto mTypeProperty{ DependencyProperty::Register(
            L"Type", xaml_typename<Controls::InfoBarSeverity>(), xaml_typename<MQControl>(),
            { box_value(Controls::InfoBarSeverity::Informational), nullptr }
        ) };
        static DependencyProperty TypeProperty() { return mTypeProperty; }
        Controls::InfoBarSeverity Type() const { return unbox_value<Controls::InfoBarSeverity>(GetValue(mTypeProperty)); }
        void Type(Controls::InfoBarSeverity value) { SetValue(mTypeProperty, box_value(value)); }

        void OnApplyTemplate() {
            base_type::OnApplyTemplate();
            VisualStateManager::GoToState(*this, IsEnabled() ? L"Enabled" : L"Disabled", true);
        }
    };
}

namespace winrt::MQControls::factory_implementation {
    struct SettingsBox : SettingsBoxT<SettingsBox, implementation::SettingsBox> { };
}
