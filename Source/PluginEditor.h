#pragma once
#include "PluginProcessor.h"
class MetalForgeEditor : public juce::AudioProcessorEditor {
public:
 explicit MetalForgeEditor(MetalForgeProcessor&);
 void paint(juce::Graphics&) override;
 void resized() override;
private:
 MetalForgeProcessor& processor;
 juce::Slider drive, mix, output;
 juce::Label driveLabel, mixLabel, outputLabel;
 std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> driveAttachment, mixAttachment, outputAttachment;
 JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MetalForgeEditor)
};
