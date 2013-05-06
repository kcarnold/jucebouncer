cmake_minimum_required(VERSION 2.6)
project(jucebouncer)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
add_executable(jucebouncer
  src/main.cpp
  lib/juce/modules/juce_core/juce_core.cpp
  lib/juce/modules/juce_audio_basics/juce_audio_basics.cpp
  lib/juce/modules/juce_audio_devices/juce_audio_devices.cpp
  lib/juce/modules/juce_audio_formats/juce_audio_formats.cpp
  lib/juce/modules/juce_audio_processors/juce_audio_processors.cpp
  lib/juce/modules/juce_audio_utils/juce_audio_utils.cpp
  lib/juce/modules/juce_data_structures/juce_data_structures.cpp
  lib/juce/modules/juce_events/juce_events.cpp
  lib/juce/modules/juce_graphics/juce_graphics.cpp
  lib/juce/modules/juce_gui_basics/juce_gui_basics.cpp
  lib/juce/modules/juce_gui_extra/juce_gui_extra.cpp
  )

include_directories(lib/juce lib/vstsdk2.4 JuceLibraryCode)
add_definitions(-DNDEBUG)

if(APPLE)
  set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-ObjC++ -mmacosx-version-min=10.6 --sysroot=/Developer/SDKs/MacOSX10.7.sdk")
  INCLUDE_DIRECTORIES ( /System/Library/Frameworks )
  FIND_LIBRARY(ACCEL_LIBRARY Accelerate)
  FIND_LIBRARY(AUDIOTB_LIBRARY AudioToolbox)
  FIND_LIBRARY(AUDIOUNIT_LIBRARY AudioUnit) # for _AudioUnitGetProperty
  FIND_LIBRARY(CARBON_LIBRARY Carbon)
  FIND_LIBRARY(COCOA_LIBRARY Cocoa)
  FIND_LIBRARY(CORE_SERVICE_LIBRARY CoreServices)
  FIND_LIBRARY(CORE_AUDIO_LIBRARY CoreAudio)
  FIND_LIBRARY(CORE_AUDIO_KIT_LIBRARY CoreAudioKit) # for _AUGenericView
  FIND_LIBRARY(CORE_MIDI_LIBRARY CoreMidi)
  FIND_LIBRARY(DISC_LIBRARY DiscRecording)
  FIND_LIBRARY(IOKIT_LIBRARY IOKit)
  FIND_LIBRARY(QUARTZ_LIBRARY QuartzCore)
  FIND_LIBRARY(WEBKIT_LIBRARY WebKit)
  FIND_LIBRARY(GLUT_LIBRARY GLUT)
  FIND_LIBRARY(OpenGL_LIBRARY OpenGL)
  SET(MAC_LIBS ${ACCEL_LIBRARY} ${AUDIOTB_LIBRARY} ${CARBON_LIBRARY} ${COCOA_LIBRARY}
               ${AUDIOUNIT_LIBRARY} ${CORE_SERVICE_LIBRARY}
               ${CORE_AUDIO_KIT_LIBRARY} ${CORE_AUDIO_LIBRARY} ${CORE_MIDI_LIBRARY}
               ${DISC_LIBRARY} ${IOKIT_LIBRARY} ${QUARTZ_LIBRARY} ${WEBKIT_LIBRARY}
               ${GLUT_LIBRARY} ${OpenGL_LIBRARY})
  # MARK_AS_ADVANCED() # to ignore in CMake gui
  SET(EXTRA_LIBS ${MAC_LIBS})
endif(APPLE)

target_link_libraries(jucebouncer ${EXTRA_LIBS})