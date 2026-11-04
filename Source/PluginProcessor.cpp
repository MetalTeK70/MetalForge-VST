#include "PluginProcessor.h"
#include <cmath>

MetalForgeProcessor::MetalForgeProcessor()
    : juce::AudioProcessor(juce::AudioProcessor::BusesProperties()
        .withInput("Input", juce::AudioChannelSet::stereo(), true)
        .withOutput("Output", juce::AudioChannelSet::stereo(), true)),
      parameters(*this, nullptr, "PARAMETERS", makeParameters()) {}

juce::AudioProcessorValueTreeState::ParameterLayout MetalForgeProcessor::makeParameters()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    layout.add(std::make_unique<juce::AudioParameterFloat>(
        juce::ParameterID{"drive", 1}, "Drive", 0.0f, 30.0f, 8.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>(
        juce::ParameterID{"output", 1}, "Output", -36.0f, 12.0f, -6.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>(
        juce::ParameterID{"mix", 1}, "Mix", 0.0f, 1.0f, 1.0f));
    return layout;
}

void MetalForgeProcessor::prepareToPlay(double, int) {}

void MetalForgeProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&)
{
    juce::ScopedNoDenormals noDenormals;
    const float drive = juce::Decibels::decibelsToGain(parameters.getRawParameterValue("drive")->load());
    const float output = juce::Decibels::decibelsToGain(parameters.getRawParameterValue("output")->load());
    const float mix = parameters.getRawParameterValue("mix")->load();
    for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
    {
        auto* samples = buffer.getWritePointer(channel);
        for (int i = 0; i < buffer.getNumSamples(); ++i)
        {
            const float dry = samples[i];
            const float wet = std::tanh(dry * drive);
            samples[i] = output * (dry * (1.0f - mix) + wet * mix);
        }
    }
}

juce::AudioProcessorEditor* MetalForgeProcessor::createEditor()
{
    return new juce::GenericAudioProcessorEditor(*this);
}

void MetalForgeProcessor::getStateInformation(juce::MemoryBlock& dest)
{
    if (auto xml = parameters.copyState().createXml())
        copyXmlToBinary(*xml, dest);
}

void MetalForgeProcessor::setStateInformation(const void* data, int size)
{
    if (auto xml = getXmlFromBinary(data, size))
        if (xml->hasTagName(parameters.state.getType()))
            parameters.replaceState(juce::ValueTree::fromXml(*xml));
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MetalForgeProcessor();
}
