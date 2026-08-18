// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The XCSoar Project

#pragma once

/**
 * Scanning a task QR code with the built-in camera.  Only the mobile
 * ports can do this, so the rest of the code asks HaveQRScanner()
 * before offering it and gets a compile-time "no" everywhere else.
 *
 * HAVE_QR_SCANNER comes from build/zxing.mk, i.e. it is set for the
 * ports that have both a camera and the zxing-cpp decoder: Android
 * (Android/QRScanner.cpp) and iOS (Apple/QRScanner.cpp).
 */

#ifdef HAVE_QR_SCANNER

/**
 * Is a camera-based QR scanner available right now?  False when the UI
 * is not up yet or the device has no camera at all, so a menu binding
 * cannot fire into nothing.
 */
[[gnu::pure]]
bool
HaveQRScanner() noexcept;

/**
 * Open the camera and scan one task QR code.
 *
 * This returns immediately: the scanner runs outside the XCSoar
 * window and hands its result to ReceiveTaskQRCode(), which posts
 * UI::Event::TASK_RECEIVED.  Nothing happens if the user cancels or
 * denies the camera permission.
 */
void
ScanTaskQRCode() noexcept;

#else

constexpr bool
HaveQRScanner() noexcept
{
  return false;
}

inline void
ScanTaskQRCode() noexcept
{
}

#endif
