#pragma once
#include "IconButton.g.h"

#include <winrt/Microsoft.UI.Xaml.Input.h>

using namespace winrt::Microsoft::UI::Xaml;

namespace winrt::MQControls::implementation {
	struct IconButton : IconButtonT<IconButton> {
		using MQControl = winrt::MQControls::IconButton;

		IconButton() {
			DefaultStyleKey(box_value(xaml_typename<MQControl>()));
		}

		inline static auto mIconProperty{ DependencyProperty::Register(
			L"Icon", xaml_typename<hstring>(), xaml_typename<MQControl>(),
			{ box_value(L""), nullptr }
		) };
		static DependencyProperty IconProperty() { return mIconProperty; }
		hstring Icon() const { return unbox_value<hstring>(GetValue(mIconProperty)); }
		void Icon(hstring const& value) { SetValue(mIconProperty, box_value(value)); }


		inline static auto mLabelProperty{ DependencyProperty::Register(
			L"Label", xaml_typename<hstring>(), xaml_typename<MQControl>(),
			{ box_value(L""), nullptr }
		) };
		static DependencyProperty LabelProperty() { return mLabelProperty; }
		hstring Label() const { return unbox_value<hstring>(GetValue(mLabelProperty)); }
		void Label(hstring const& value) { SetValue(mLabelProperty, box_value(value)); }


		inline static auto mOrientationProperty{ DependencyProperty::Register(
			L"Orientation", xaml_typename<Controls::Orientation>(), xaml_typename<MQControl>(),
			{ box_value(Controls::Orientation::Horizontal), nullptr }
		) };
		static DependencyProperty OrientationProperty() { return mOrientationProperty; }
		Controls::Orientation Orientation() const { return unbox_value<Controls::Orientation>(GetValue(mOrientationProperty)); }
		void Orientation(Controls::Orientation value) { SetValue(mOrientationProperty, box_value(value)); }


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
			mClick(*this, RoutedEventArgs{ });
		}

		void OnKeyboardAcceleratorInvoked(Input::KeyboardAcceleratorInvokedEventArgs const& args) {
			base_type::OnKeyboardAcceleratorInvoked(args);
			mClick(*this, RoutedEventArgs{ });
		}

		void OnApplyTemplate() {
			base_type::OnApplyTemplate();
			VisualStateManager::GoToState(*this, IsEnabled() ? L"Normal" : L"Disabled", true);
		}
	};
}

namespace winrt::MQControls::factory_implementation {
    struct IconButton : IconButtonT<IconButton, implementation::IconButton> { };
}