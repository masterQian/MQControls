#include "pch.h"
#include "Trigger.h"
#include "ValueStateTrigger.g.cpp"

namespace winrt::MQControls::implementation {
	void ValueStateTrigger::UpdateTrigger(DependencyObject const& d, DependencyPropertyChangedEventArgs const& args) {
		auto trigger{ get_self<ValueStateTrigger>(d.as<MQControls::ValueStateTrigger>()) };
		auto prop{ args.Property() };
		if (prop == mStringValue1Property || prop == mStringValue2Property) {
			trigger->SetActive(trigger->StringValue1() == trigger->StringValue2());
		}
		else if (prop == mBoolValue1Property) {
			trigger->SetActive(trigger->BoolValue1() == trigger->BoolValue2());
		}
		else if (prop == mOrientationValue1Property) {
			trigger->SetActive(trigger->OrientationValue1() == trigger->OrientationValue2());
		}
	}
}
