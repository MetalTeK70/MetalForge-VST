cmake_minimum_required(VERSION 3.22)
project(MetalForgeVST VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)
FetchContent_Declare(JUCE GIT_REPOSITORY https://github.com/juce-framework/JUCE.git GIT_TAG 8.0.10)
FetchContent_MakeAvailable(JUCE)
juce_add_plugin(MetalForgeVST COMPANY_NAME MetalForge PRODUCT_NAME "MetalForge VST"
  PLUGIN_MANUFACTURER_CODE MtFk PLUGIN_CODE Mf01
  FORMATS VST3 Standalone IS_SYNTH FALSE NEEDS_MIDI_INPUT FALSE
  NEEDS_MIDI_OUTPUT FALSE EDITOR_WANTS_KEYBOARD_FOCUS FALSE)
target_sources(MetalForgeVST PRIVATE Source/PluginProcessor.cpp Source/PluginProcessor.h Source/PluginEditor.cpp Source/PluginEditor.h)
target_compile_definitions(MetalForgeVST PUBLIC JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)
target_link_libraries(MetalForgeVST PRIVATE juce::juce_audio_utils juce::juce_dsp juce::juce_audio_processors juce::juce_audio_plugin_client)
juce_generate_juce_header(MetalForgeVST)
