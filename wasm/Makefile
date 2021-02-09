EMSCR=em++

SRC=../Source/DSPCode
SRC_EM=open303.embind.cpp
# SRC_LIBS=../../../src/libs/*.cpp
# SRC_LIBS=../../src/libs/maxiSynths.cpp
SRC_LIBS= ../Source/DSPCode/GlobalFunctions.cpp  ../Source/DSPCode/rosic_AcidPattern.cpp ../Source/DSPCode/rosic_AcidSequencer.cpp ../Source/DSPCode/rosic_AnalogEnvelope.cpp ../Source/DSPCode/rosic_BlendOscillator.cpp ../Source/DSPCode/rosic_BiquadFilter.cpp ../Source/DSPCode/rosic_Complex.cpp ../Source/DSPCode/rosic_DecayEnvelope.cpp ../Source/DSPCode/rosic_FourierTransformerRadix2.cpp ../Source/DSPCode/rosic_EllipticQuarterBandFilter.cpp    ../Source/DSPCode/rosic_FunctionTemplates.cpp  ../Source/DSPCode/rosic_LeakyIntegrator.cpp ../Source/DSPCode/rosic_MidiNoteEvent.cpp ../Source/DSPCode/rosic_NumberManipulations.cpp ../Source/DSPCode/rosic_MipMappedWaveTable.cpp ../Source/DSPCode/rosic_OnePoleFilter.cpp ../Source/DSPCode/rosic_Open303.cpp ../Source/DSPCode/rosic_RealFunctions.cpp ../Source/DSPCode/rosic_TeeBeeFilter.cpp
C_SRC_LIBS=

BUILD_DIR=build
MKDIR_P = mkdir -p

# POST_JS – external js handling web audio etc
POST_JS=open303.post.js

OUTPUT=$(BUILD_DIR)/open303.wasmmodule.js


# AudioWorklet working configuration

CFLAGS=--bind -O3\
	-s WASM=1 \
	-s BINARYEN_ASYNC_COMPILATION=0 \
	-s SINGLE_FILE=1 \
	-s ALLOW_MEMORY_GROWTH=1 \
	-s ABORTING_MALLOC=0 \
	-s TOTAL_MEMORY=16Mb  \
	-s "EXPORT_NAME='Open303'" \
  -s "BINARYEN_METHOD='native-wasm'" \
  --js-opts 0 -g4 --source-map-base "${BUILD_DIR}/"


	# For optimisations and compiler settings

	# check https://emscripten.org/docs/optimizing/Optimizing-Code.html#optimizing-code
	# and https://emscripten.org/docs/tools_reference/emcc.html#emcc-compiler-optimization-options
	# and https://github.com/emscripten-core/emscripten/blob/master/src/settings.js

	# -s MODULARIZE=1
	# --js-opts 0 \  # Enables JavaScript optimizations, relevant when we generate JavaScript — 0 prevents optimizer from running
	# -g4 \ # Controls the level of debuggability. g4 value is the highest level, generates a source map using LLVM debug information, when linking
  # -s MODULARIZE=1 \ # Don't use this with --post-js, it will get messy. MODULARIZE puts all the output into a function. It minifies globals to names that might conflict with others in the global scope, including the name of Module itself. make sure a global variable called Module already exists before the closure-compiled code runs.



RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
CYAN=\033[0;36m
RESET=\x1b[0m

# --post-js $(POST_JS)

all: full

.PHONY: directory
directory: ${BUILD_DIR}
	@echo "Copying files"

${BUILD_DIR}:
	${MKDIR_P} ${BUILD_DIR}

full: directory
	@echo "${YELLOW}\r\nBuild for Web Audio API AudioWorklet (WebAssembly) – open303.wasmmodule.js \r\n ${RESET}"
	$(EMSCR) $(CFLAGS) --post-js $(POST_JS) -o $(OUTPUT)  -I $(SRC) $(SRC_EM) $(SRC_LIBS) $(C_SRC_LIBS)

clean:
	@echo "Cleaning up"
	rm -f $(BUILD_DIR)/open303.*
