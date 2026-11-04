#pragma once
#include <JuceHeader.h>

class MetalForgeProcessor final : public juce::AudioProcessor
{
public:
    MetalForgeProcessor();
    void prepareToPlay(double sampleRate, int maximumExpectedSamplesPerBlock) override;
    void releaseResources() override {}
    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }
    const juce::String getName() const override { return "MetalForge VST"; }
    bool acceptsMidi() const override { return false; }
    bool producesMidi() const override { return false; }
    bool isMidiEffect() const override { return false; }
    double getTailLengthSeconds() const override { return 0.0; }
    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram(int) override {}
    const juce::String getProgramName(int) override { return {}; }
    void changeProgramName(int, const juce::String&) override {}
    void getStateInformation(juce::MemoryBlock&) override;
    void setStateInformation(const void*, int) override;
    juce::AudioProcessorValueTreeState parameters;
private:
    static juce::AudioProcessorValueTreeState::ParameterLayout makeParameters();
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MetalForgeProcessor)
};
