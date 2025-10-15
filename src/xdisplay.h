#pragma once
#ifndef XDISPLAY_H
#define XDISPLAY_H

#include <X11/Xlib.h>

/* Returns the main display, closed either on exit or when closeMainDisplay()
 * is invoked. This removes a bit of the overhead of calling XOpenDisplay() &
 * XCloseDisplay() everytime the main display needs to be used.
 *
 * Note that this is almost certainly not thread safe. */
Display *XGetMainDisplay(void);

/* Closes the main display if it is open, or does nothing if not. */
void XCloseMainDisplay(void);

/* Opens a display by name for one-time use (caller must close with XCloseDisplay)
 * This is thread-safe as it doesn't use global state. */
Display *XOpenDisplayByName(const char *displayName);

#ifdef __cplusplus
extern "C"
{
#endif

char *getXDisplay(void);
void setXDisplay(const char *name);

#ifdef __cplusplus
}
#endif

#endif /* XDISPLAY_H */
