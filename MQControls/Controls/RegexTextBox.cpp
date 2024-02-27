#include "pch.h"
#include "RegexTextBox.h"
#include "RegexTextBox.g.cpp"

#include <regex>

namespace winrt::MQControls::implementation {
    void RegexTextBox::CheckRegex() {
        bool result{ };
        try {
            result = std::regex_match(Text().data(), std::wregex{ Regex().data() });
        }
        catch (...) { }
        SetValue(mIsMatchedProperty, box_value(result));
    }
   
    void RegexTextBox::OnApplyTemplate() {
        base_type::OnApplyTemplate();

        if (mTextChangedToken) TextChanged(mTextChangedToken);
        mTextChangedToken = TextChanged([this] (auto...) {
            CheckRegex();
        });
        
        CheckRegex();
    }
}