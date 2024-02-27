#pragma once
#include "SettingsCard.g.h"

#include <winrt/Microsoft.UI.Xaml.Input.h>

using namespace winrt::Microsoft::UI::Xaml;

namespace winrt::MQControls::implementation {
    struct SettingsCard : SettingsCardT<SettingsCard> {
        using MQControl = winrt::MQControls::SettingsCard;
        
        SettingsCard() {
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


        inline static auto mIconProperty{ DependencyProperty::Register(
            L"Icon", xaml_typename<hstring>(), xaml_typename<MQControl>(),
            { box_value(L""), nullptr }
        ) };
        static DependencyProperty IconProperty() { return mIconProperty; }
        hstring Icon() const { return unbox_value<hstring>(GetValue(mIconProperty)); }
        void Icon(hstring const& value) { SetValue(mIconProperty, box_value(value)); }
        
        event<RoutedEventHandler> mClick;
        event_token Click(RoutedEventHandler const& handler) { return mClick.add(handler); }
        void Click(event_token const& token) noexcept { mClick.remove(token); }

        void OnPointerEntered(Input::PointerRoutedEventArgs const& args) {
            base_type::OnPointerEntered(args);
            VisualStateManager::GoToState(*this, L"PointerOver", true);
        }

        void OnPointerExited(Input::PointerRoutedEventArgs const& args) {
            base_type::OnPointerExited(args);
            VisualStateManager::GoToState(*this, L"Normal", true);
        }

        void OnPointerPressed(Input::PointerRoutedEventArgs const& args) {
            base_type::OnPointerPressed(args);
            VisualStateManager::GoToState(*this, L"Pressed", true);
        }

        void OnPointerReleased(Input::PointerRoutedEventArgs const& args) {
            base_type::OnPointerReleased(args);
            VisualStateManager::GoToState(*this, L"PointerOver", true);
        }

        void OnTapped(Input::TappedRoutedEventArgs const& args) {
            base_type::OnTapped(args);
            if (isInitialize) {
                auto point{ args.GetPosition(mHeader) };
                if (!(point.X >= 0.0f && point.X <= static_cast<float>(mHeader.ActualWidth())
                    && point.Y >= 0.0f && point.Y <= static_cast<float>(mHeader.ActualHeight()))) {
                    // ·ÇHeader·¶Î§ÄÚµã»÷
                    mClick(*this, RoutedEventArgs{ });
                }
            }
        }

        void OnKeyboardAcceleratorInvoked(Input::KeyboardAcceleratorInvokedEventArgs const& args) {
            base_type::OnKeyboardAcceleratorInvoked(args);
            mClick(*this, RoutedEventArgs{ });
        }
        
        Controls::ContentPresenter mHeader{ nullptr };

        bool isInitialize{ false };
        void OnApplyTemplate() {
            base_type::OnApplyTemplate();

            mHeader = GetTemplateChild(L"mHeader").as<decltype(mHeader)>();

            isInitialize = true;

            VisualStateManager::GoToState(*this, IsEnabled() ? L"Normal" : L"Disabled", true);
        }
    };
}

namespace winrt::MQControls::factory_implementation {
    struct SettingsCard : SettingsCardT<SettingsCard, implementation::SettingsCard> { };
}
