#include "PluginEditor.h"
MetalForgeEditor::MetalForgeEditor(MetalForgeProcessor& p) : AudioProcessorEditor(&p), processor(p) {
 auto setup = [this](juce::Slider& slider, juce::Label& label, const juce::String& title) {
  slider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
  slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 22);
  slider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colour(0xff168cff));
  label.setText(title, juce::dontSendNotification);
  label.setJustificationType(juce::Justification::centred);
  label.setColour(juce::Label::textColourId, juce::Colours::white);
  addAndMakeVisible(slider); addAndMakeVisible(label);
 };
 setup(drive, driveLabel, "DRIVE (dB)");
 setup(mix, mixLabel, "MIX");
 setup(output, outputLabel, "OUTPUT (dB)");
 driveAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(p.parameters, "drive", drive);
 mixAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(p.parameters, "mix", mix);
 outputAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(p.parameters, "output", output);
 setSize(760, 400);
}
void MetalForgeEditor::paint(juce::Graphics& g) {
 g.fillAll(juce::Colour(0xff0b101b));
 g.setColour(juce::Colour(0xff168cff)); g.fillRect(0, 0, getWidth(), 4);
 g.setColour(juce::Colours::white);
 g.setFont(juce::Font(juce::FontOptions(34.0f, juce::Font::bold)));
 g.drawFittedText("METALFORGE VST", 20, 30, getWidth()-40, 50, juce::Justification::centred, 1);
 g.setColour(juce::Colours::lightgrey); g.setFont(16.0f);
 g.drawFittedText("Early prototype - advanced amps, IRs and presets in development", 20, 90, getWidth()-40, 28, juce::Justification::centred, 1);
 g.setColour(juce::Colour(0xff192332));
 g.fillRoundedRectangle(50.0f, 145.0f, float(getWidth()-100), 215.0f, 12.0f);
}
void MetalForgeEditor::resized() {
 juce::Slider* sliders[] = { &drive, &mix, &output };
 juce::Label* labels[] = { &driveLabel, &mixLabel, &outputLabel };
 for (int i=0; i<3; ++i) {
  const int x = 110 + i*195;
  labels[i]->setBounds(x, 155, 150, 28);
  sliders[i]->setBounds(x, 188, 150, 145);
 }
}
