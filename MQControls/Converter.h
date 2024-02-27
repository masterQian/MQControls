#pragma once
#include "BoolToVisibilityConverter.g.h"
#include "BoolReverseConverter.g.h"

using namespace winrt::Microsoft::UI::Xaml;
using TypeName = winrt::Windows::UI::Xaml::Interop::TypeName;

namespace winrt::MQControls::implementation {
    struct BoolToVisibilityConverter : BoolToVisibilityConverterT<BoolToVisibilityConverter> {
        bool mReverse;
        BoolToVisibilityConverter() : mReverse{ } { }
        bool Reverse() const { return mReverse; }
        void Reverse(bool value) { mReverse = value; }

        IInspectable Convert(IInspectable const& value, TypeName const&, IInspectable const&, hstring const&) {
            // value    reverse     result
            // 0        0           0
            // 0        1           1
            // 1        0           1
            // 1        1           0
            return box_value(static_cast<bool>(unbox_value<bool>(value) ^ mReverse) ? Visibility::Visible : Visibility::Collapsed);
        }

        IInspectable ConvertBack(IInspectable const&, TypeName const&, IInspectable const&, hstring const&) {
            throw hresult_not_implemented{ L"BoolToVisibilityConverter ConvertBack not implemented" };
        }
    };

    struct BoolReverseConverter : BoolReverseConverterT<BoolReverseConverter> {
        BoolReverseConverter() = default;

        IInspectable Convert(IInspectable const& value, TypeName const&, IInspectable const&, hstring const&) {
            return box_value(!unbox_value<bool>(value));
        }

        IInspectable ConvertBack(IInspectable const&, TypeName const&, IInspectable const&, hstring const&) {
            throw hresult_not_implemented{ L"BoolReverseConverter ConvertBack not implemented" };
        }
    };
}

namespace winrt::MQControls::factory_implementation {
    struct BoolToVisibilityConverter : BoolToVisibilityConverterT<BoolToVisibilityConverter, implementation::BoolToVisibilityConverter> { };
    struct BoolReverseConverter : BoolReverseConverterT<BoolReverseConverter, implementation::BoolReverseConverter> { };
}
