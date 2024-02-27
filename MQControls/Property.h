#pragma once
#include "Property.g.h"

#include <winrt/Microsoft.UI.Xaml.Input.h>

using namespace winrt::Microsoft::UI::Xaml;
using MQControl = winrt::MQControls::Property;

namespace winrt::MQControls::implementation {
    struct Property : PropertyT<Property> {
        Property() = default;

        static void ShortCutKeyPropertyChanged(DependencyObject const& d, DependencyPropertyChangedEventArgs const& args);
        inline static auto mShortCutKeyProperty{ DependencyProperty::RegisterAttached(
            L"ShortCutKey", xaml_typename<Input::KeyboardAccelerator>(), xaml_typename<MQControls::Property>(),
            { nullptr, &ShortCutKeyPropertyChanged }
        ) };
        static DependencyProperty ShortCutKeyProperty() { return mShortCutKeyProperty; }
        static Input::KeyboardAccelerator GetShortCutKey(UIElement const& obj) { return unbox_value<Input::KeyboardAccelerator>(obj.GetValue(mShortCutKeyProperty)); }
        static void SetShortCutKey(UIElement const& obj, Input::KeyboardAccelerator const& value) { obj.SetValue(mShortCutKeyProperty, value); }


        static void ClipToBoundsPropertyChanged(DependencyObject const& d, DependencyPropertyChangedEventArgs const& args);
        inline static auto mClipToBoundsProperty{ DependencyProperty::RegisterAttached(
            L"ClipToBounds", xaml_typename<bool>(), xaml_typename<MQControl>(),
            { box_value(false), &ClipToBoundsPropertyChanged }
        ) };
        static DependencyProperty ClipToBoundsProperty() { return mClipToBoundsProperty; }
        static bool GetClipToBounds(UIElement const& obj){ return unbox_value<bool>(obj.GetValue(mClipToBoundsProperty)); }
        static void SetClipToBounds(UIElement const& obj, bool value){ obj.SetValue(mClipToBoundsProperty, box_value(value)); }
    };
}

namespace winrt::MQControls::factory_implementation {
    struct Property : PropertyT<Property, implementation::Property> { };
}
