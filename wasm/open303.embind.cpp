/*
 contains all bindings for use with emscripten
 */
#ifndef open303_embind_h
#define open303_embind_h

#include <emscripten.h>
#include <emscripten/bind.h>
#include "rosic_Open303.h"

using namespace emscripten;
using namespace rosic;

EMSCRIPTEN_BINDINGS(Open303) {

    class_<Open303 >("Open303")
			.constructor<>()
			.function("play", &Open303::getSample)

			.function("setSampleRate", &Open303::setSampleRate)
			.function("setWaveform", &Open303::setWaveform)
			.function("setCutoff", &Open303::setCutoff)
			.function("setResonance", &Open303::setResonance)
			.function("setEnvMod", &Open303::setEnvMod)
			.function("setDecay", &Open303::setDecay)
			.function("setAccent", &Open303::setAccent)
			.function("setVolume", &Open303::setVolume)
			.function("setAmpSustain", &Open303::setAmpSustain)
			.function("setPreFilterHighpass", &Open303::setPreFilterHighpass)
			.function("setFeedbackHighpass", &Open303::setFeedbackHighpass)
			.function("setPostFilterHighpass", &Open303::setPostFilterHighpass)
			.function("setSquarePhaseShift", &Open303::setSquarePhaseShift)
			.function("setSlideTime", &Open303::setSlideTime)
			.function("setNormalAttack", &Open303::setNormalAttack)
			.function("setAccentAttack", &Open303::setAccentAttack)
			.function("setAccentDecay", &Open303::setAccentDecay)
			.function("setAmpDecay", &Open303::setAmpDecay)
			.function("setAmpRelease", &Open303::setAmpRelease)
			.function("triggerNote", &Open303::triggerNote)
			.function("slideToNote", &Open303::slideToNote)
			.function("releaseNote", &Open303::noteOn)
			.function("noteOn", &Open303::noteOn)
			.function("allNotesOff", &Open303::allNotesOff)
			.function("setPitchBend", &Open303::setPitchBend)
		;
};

#endif
