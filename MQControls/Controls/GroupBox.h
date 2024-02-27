#pragma once
#include "GroupBox.g.h"

using namespace winrt::Microsoft::UI::Xaml;

namespace winrt::MQControls::implementation {
    struct GroupBox : GroupBoxT<GroupBox> {
        using MQControl = winrt::MQControls::GroupBox;

        GroupBox() {
            DefaultStyleKey(box_value(xaml_typename<MQControl>()));
        }

        inline static auto mTitleProperty{ DependencyProperty::Register(
            L"Title", xaml_typename<hstring>(), xaml_typename<MQControl>(),
            { box_value(L""), nullptr }
        ) };
        static DependencyProperty TitleProperty() { return mTitleProperty; }
        hstring Title() const { return unbox_value<hstring>(GetValue(mTitleProperty)); }
        void Title(hstring const& value) { SetValue(mTitleProperty, box_value(value)); }


        inline static auto mIsIconVisibleProperty{ DependencyProperty::Register(
            L"IsIconVisible", xaml_typename<Microsoft::UI::Xaml::Visibility>(), xaml_typename<MQControl>(),
            { box_value(Microsoft::UI::Xaml::Visibility::Collapsed), nullptr }
        ) };
        static DependencyProperty IsIconVisibleProperty() { return mIsIconVisibleProperty; }
        Microsoft::UI::Xaml::Visibility IsIconVisible() const { return unbox_value<Microsoft::UI::Xaml::Visibility>(GetValue(mIsIconVisibleProperty)); }
        void IsIconVisible(Microsoft::UI::Xaml::Visibility value) { SetValue(mIsIconVisibleProperty, box_value(value)); }


        inline static auto mIconProperty{ DependencyProperty::Register(
            L"Icon", xaml_typename<hstring>(), xaml_typename<MQControl>(),
            { box_value(L""), nullptr }
        ) };
        static DependencyProperty IconProperty() { return mIconProperty; }
        hstring Icon() const { return unbox_value<hstring>(GetValue(mIconProperty)); }
        void Icon(hstring const& value) { SetValue(mIconProperty, box_value(value)); }

        void OnApplyTemplate() {
            base_type::OnApplyTemplate();
            VisualStateManager::GoToState(*this, IsEnabled() ? L"Enabled" : L"Disabled", true);
        }
    };
}

namespace winrt::MQControls::factory_implementation {
    struct GroupBox : GroupBoxT<GroupBox, implementation::GroupBox> { };
}
