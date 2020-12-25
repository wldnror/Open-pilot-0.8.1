#pragma once
#include <map>
#include "cereal/gen/cpp/log.capnp.h"

typedef cereal::CarControl::HUDControl::AudibleAlert AudibleAlert;

static std::map<AudibleAlert, std::pair<const char *, int>> sound_map {
  // AudibleAlert, (file path, loop count)
  {AudibleAlert::CHIME_DISENGAGE, {"../assets/sounds/disengaged.wav", 0}},
  {AudibleAlert::CHIME_ENGAGE, {"../assets/sounds/engaged.wav", 0}},
  {AudibleAlert::CHIME_WARNING1, {"../assets/sounds/warning_1.wav", 0}},
  {AudibleAlert::CHIME_WARNING2, {"../assets/sounds/warning_2.wav", 0}},
  {AudibleAlert::CHIME_WARNING2_REPEAT, {"../assets/sounds/warning_2.wav", 3}},
  {AudibleAlert::CHIME_WARNING_REPEAT, {"../assets/sounds/warning_repeat.wav", -1}},
  {AudibleAlert::CHIME_ERROR, {"../assets/sounds/error.wav", 0}},
  {AudibleAlert::CHIME_PROMPT, {"../assets/sounds/error.wav", 0}},
  {AudibleAlert::CHIME_SLOWING_DOWN_SPEED, {"../assets/sounds/slowing_down_speed.wav", 0}},
  {AudibleAlert::CHIME_GEARD, {"../assets/sounds/geard.wav", 0}},
  {AudibleAlert::CHIME_ALCA, {"../assets/sounds/alca.wav", 1}},
  {AudibleAlert::CHIME_SEATBELT, {"../assets/sounds/seatbelt.wav", 0}},
  {AudibleAlert::CHIME_VISION, {"../assets/sounds/vision.wav", 0}},
  {AudibleAlert::CHIME_DISTRACTED, {"../assets/sounds/distracted.wav", 1}},
  {AudibleAlert::CHIME_CALIBRATION1, {"../assets/sounds/calibration1.wav", 1}},
  {AudibleAlert::CHIME_CALIBRATION2, {"../assets/sounds/calibration2.wav", 1}}
  
};

class Sound {
public:
  virtual bool play(AudibleAlert alert) = 0;
  virtual void stop() = 0;
  virtual void setVolume(int volume) = 0;
};
