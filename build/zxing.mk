# zxing-cpp decodes the QR codes scanned by the task QR scanner.  Only
# the mobile ports have a camera to feed it; the decoder itself is
# portable, so this is deliberately not guarded by anything but
# availability.
ZXING ?= $(call bool_or,$(TARGET_IS_ANDROID),$(TARGET_IS_IOS))

ifeq ($(ZXING),y)

$(eval $(call pkg-config-library,ZXING,zxing))

ZXING_CPPFLAGS += -DHAVE_ZXING

# Every port that can decode a QR code also has a camera to point at
# one, so this doubles as the switch that Task/QRScanner.hpp and the
# task manager ask for.  It has to be visible to every translation
# unit, not just the decoder's.
TARGET_CPPFLAGS += -DHAVE_QR_SCANNER

endif
