#pragma once
#include "ValueStateTrigger.g.h"

using namespace winrt::Microsoft::UI::Xaml;
using MQControl = winrt::MQControls::ValueStateTrigger;

namespace winrt::MQControls::implementation {
    struct ValueStateTrigger : ValueStateTriggerT<ValueStateTrigger> {
        ValueStateTrigger() = default;
        static void UpdateTrigger(DependencyObject const& d, DependencyPropertyChangedEventArgs const& args);

        inline static auto mStringValue1Property{ DependencyProperty::Register(
            L"StringValue1", xaml_typename<hstring>(), xaml_typename<MQControl>(),
            { box_value(L"|?StringValue1?|"), &ValueStateTrigger::UpdateTrigger }
        ) };
        inline static auto mStringValue2Property{ DependencyProperty::Register(
            L"StringValue2", xaml_typename<hstring>(), xaml_typename<MQControl>(),
            { box_value(L"|?StringValue2?|"), &ValueStateTrigger::UpdateTrigger }
        ) };
        static DependencyProperty StringValue1Property() { return mStringValue1Property; }
        static DependencyProperty StringValue2Property() { return mStringValue2Property; }
        hstring StringValue1() const { return unbox_value<hstring>(GetValue(mStringValue1Property)); }
        void StringValue1(hstring const& value) { SetValue(mStringValue1Property, box_value(value)); }
        hstring StringValue2() const { return unbox_value<hstring>(GetValue(mStringValue2Property)); }
        void StringValue2(hstring const& value) { SetValue(mStringValue2Property, box_value(value)); }

        inline static auto mBoolValue1Property{ DependencyProperty::Register(
            L"BoolValue1", xaml_typename<bool>(), xaml_typename<MQControl>(),
            { box_value(false), &ValueStateTrigger::UpdateTrigger }
        ) };
        static DependencyProperty BoolValue1Property() { return mBoolValue1Property; }
        bool mBoolValue2{ true };
        bool BoolValue1() const { return unbox_value<bool>(GetValue(mBoolValue1Property)); }
        void BoolValue1(bool value) { SetValue(mBoolValue1Property, box_value(value)); }
        bool BoolValue2() const { return mBoolValue2; }
        void BoolValue2(bool value) { mBoolValue2 = value; }

        inline static auto mOrientationValue1Property{ DependencyProperty::Register(
            L"OrientationValue1", xaml_typename<Controls::Orientation>(), xaml_typename<MQControl>(),
            { box_value(Controls::Orientation::Horizontal), &ValueStateTrigger::UpdateTrigger }
        ) };
        static DependencyProperty OrientationValue1Property() { return mOrientationValue1Property; }
        Controls::Orientation mOrientationValue2{ Controls::Orientation::Vertical };
        Controls::Orientation OrientationValue1() const { return unbox_value<Controls::Orientation>(GetValue(mOrientationValue1Property)); }
        void OrientationValue1(Controls::Orientation value) { SetValue(mOrientationValue1Property, box_value(value)); }
        Controls::Orientation OrientationValue2() const { return mOrientationValue2; }
        void OrientationValue2(Controls::Orientation value) { mOrientationValue2 = value; }
    };
}

namespace winrt::MQControls::factory_implementation {
    struct ValueStateTrigger : ValueStateTriggerT<ValueStateTrigger, implementation::ValueStateTrigger> { };
}
