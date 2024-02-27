#pragma once
#include "MarqueeText.g.h"

#include <winrt/Microsoft.UI.Xaml.Input.h>
#include <winrt/Microsoft.UI.Xaml.Media.Animation.h>

using namespace winrt::Microsoft::UI::Xaml;

namespace winrt::MQControls::implementation {
    struct MarqueeText : MarqueeTextT<MarqueeText> {
        using MQControl = winrt::MQControls::MarqueeText;

        MarqueeText() {
            DefaultStyleKey(box_value(xaml_typename<MQControl>()));
        }

        void UpdateAnimation(bool keepProgress);

        inline static auto mTextProperty{ DependencyProperty::Register(
            L"Text", xaml_typename<hstring>(), xaml_typename<MQControl>(),
            { box_value(L""), nullptr }
        ) };
        static DependencyProperty TextProperty() { return mTextProperty; }
        hstring Text() const { return unbox_value<hstring>(GetValue(mTextProperty)); }
        void Text(hstring const& value) { SetValue(mTextProperty, box_value(value)); }


        static void SpeedPropertyChanged(DependencyObject const&, DependencyPropertyChangedEventArgs const&);
        inline static auto mSpeedProperty{ DependencyProperty::Register(
            L"Speed", xaml_typename<double>(), xaml_typename<MQControl>(),
            { box_value(30.0), &SpeedPropertyChanged }
        ) };
        static DependencyProperty SpeedProperty() { return mSpeedProperty; }
        double Speed() const { return unbox_value<double>(GetValue(mSpeedProperty)); }
        void Speed(double value) { SetValue(mSpeedProperty, box_value(value)); }


        static void IntervalPropertyChanged(DependencyObject const&, DependencyPropertyChangedEventArgs const&);
        inline static auto mIntervalProperty{ DependencyProperty::Register(
            L"Interval", xaml_typename<double>(), xaml_typename<MQControl>(),
            { box_value(50.0), &IntervalPropertyChanged }
        ) };
        static DependencyProperty IntervalProperty() { return mIntervalProperty; }
        double Interval() const { return unbox_value<double>(GetValue(mIntervalProperty)); }
        void Interval(double value) { SetValue(mIntervalProperty, box_value(value)); }


        static void IsLoopingPropertyChanged(DependencyObject const&, DependencyPropertyChangedEventArgs const&);
        inline static auto mIsLoopingProperty{ DependencyProperty::Register(
            L"IsLooping", xaml_typename<bool>(), xaml_typename<MQControl>(),
            { box_value(false), &IsLoopingPropertyChanged }
        ) };
        static DependencyProperty IsLoopingProperty() { return mIsLoopingProperty; }
        bool IsLooping() const { return unbox_value<bool>(GetValue(mIsLoopingProperty)); }
        void IsLooping(bool value) { SetValue(mIsLoopingProperty, box_value(value)); }


        static void IsOnPropertyChanged(DependencyObject const&, DependencyPropertyChangedEventArgs const&);
        inline static auto mIsOnProperty{ DependencyProperty::Register(
            L"IsOn", xaml_typename<bool>(), xaml_typename<MQControl>(),
            { box_value(true), &IsOnPropertyChanged }
        ) };
        static DependencyProperty IsOnProperty() { return mIsOnProperty; }
        bool IsOn() const { return unbox_value<bool>(GetValue(mIsOnProperty)); }
        void IsOn(bool value) { SetValue(mIsOnProperty, box_value(value)); }


        inline static auto mIsHoverPauseProperty{ DependencyProperty::Register(
            L"IsHoverPause", xaml_typename<bool>(), xaml_typename<MQControl>(),
            { box_value(false), nullptr }
        ) };
        static DependencyProperty IsHoverPauseProperty() { return mIsHoverPauseProperty; }
        bool IsHoverPause() const { return unbox_value<bool>(GetValue(mIsHoverPauseProperty)); }
        void IsHoverPause(bool value) { SetValue(mIsHoverPauseProperty, box_value(value)); }


        event<RoutedEventHandler> mClick;
        event_token Click(RoutedEventHandler const& handler) { return mClick.add(handler); }
        void Click(winrt::event_token const& token) noexcept { mClick.remove(token); }

        Controls::Grid mContainer{ nullptr };
        Controls::TextBlock mText1{ nullptr };
        Shapes::Rectangle mIntervalSpace{ nullptr };
        Controls::TextBlock mText2{ nullptr };
        Media::TranslateTransform mTransform{ nullptr };
        Media::Animation::Storyboard mStoryboard{ nullptr };
        Media::Animation::DoubleAnimation mAnimation{ nullptr };
        bool isUpdateFirstly{ false };

        void OnPointerEntered(Input::PointerRoutedEventArgs const& args) {
            base_type::OnPointerEntered(args);
            if (IsHoverPause()) {
                mStoryboard.Pause();
            }
        }

        void OnPointerExited(Input::PointerRoutedEventArgs const& args) {
            base_type::OnPointerExited(args);
            if (IsHoverPause()) {
                mStoryboard.Resume();
            }
        }

        void OnTapped(Input::TappedRoutedEventArgs const& args) {
            base_type::OnTapped(args);
            mClick(*this, RoutedEventArgs{ });
        }

        void OnKeyboardAcceleratorInvoked(Input::KeyboardAcceleratorInvokedEventArgs const& args) {
            base_type::OnKeyboardAcceleratorInvoked(args);
            mClick(*this, RoutedEventArgs{ });
        }
        
        bool isInitialize{ false };
        void OnApplyTemplate();

        event_token mText1SizeChangedToken{ };
    };
}

namespace winrt::MQControls::factory_implementation {
    struct MarqueeText : MarqueeTextT<MarqueeText, implementation::MarqueeText> { };
}
