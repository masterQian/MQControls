#pragma once
#include "RegexTextBox.g.h"

using namespace winrt::Microsoft::UI::Xaml;

namespace winrt::MQControls::implementation {
    struct RegexTextBox : RegexTextBoxT<RegexTextBox> {
        using MQControl = winrt::MQControls::RegexTextBox;

        RegexTextBox() {
            DefaultStyleKey(box_value(xaml_typename<MQControl>()));
        }

        void CheckRegex();

        inline static auto mRegexProperty{ DependencyProperty::Register(
            L"Regex", xaml_typename<hstring>(), xaml_typename<MQControl>(),
            { box_value(L".*"), nullptr }
        ) };
        static DependencyProperty RegexProperty() { return mRegexProperty; }
        hstring Regex() const { return unbox_value<hstring>(GetValue(mRegexProperty)); }
        void Regex(hstring const& value) { SetValue(mRegexProperty, box_value(value)); }


        inline static auto mMismatchedBrushProperty{ DependencyProperty::Register(
            L"MismatchedBrush", xaml_typename<Media::Brush>(), xaml_typename<MQControl>(),
            { Media::SolidColorBrush{ Windows::UI::Colors::Red() }, nullptr }
        ) };
        static DependencyProperty MismatchedBrushProperty() { return mMismatchedBrushProperty; }
        Media::Brush MismatchedBrush() const { return unbox_value<Media::Brush>(GetValue(mMismatchedBrushProperty)); }
        void MismatchedBrush(Media::Brush const& value) { SetValue(mMismatchedBrushProperty, box_value(value)); }

        inline static auto mIsMatchedProperty{ DependencyProperty::Register(
            L"IsMatched", xaml_typename<bool>(), xaml_typename<MQControl>(),
            { box_value(true), nullptr }
        ) };
        static DependencyProperty IsMatchedProperty() { return mIsMatchedProperty; }
        bool IsMatched() const { return unbox_value<bool>(GetValue(mIsMatchedProperty)); }

        void OnApplyTemplate();

        event_token mTextChangedToken{ };
    };
}

namespace winrt::MQControls::factory_implementation {
    struct RegexTextBox : RegexTextBoxT<RegexTextBox, implementation::RegexTextBox> { };
}
