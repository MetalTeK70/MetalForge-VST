#pragma once
#include "PluginProcessor.h"
class MetalForgeEditor : public juce::AudioProcessorEditor {
public:
 explicit MetalForgeEditor(MetalForgeProcessor&);
 void paint(juce::Graphics&) override;
 void resized() override;
private:
 MetalForgeProcessor& processor;
 juce::Slider gain, tone, output;
 juce::Label gainLabel, toneLabel, outputLabel;
 std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gainAttachment, toneAttachment, outputAttachment;
 JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MetalForgeEditor)
};
