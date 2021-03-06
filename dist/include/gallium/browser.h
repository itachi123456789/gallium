#ifndef GALLIUM_API_GALLIUM_H_
#define GALLIUM_API_GALLIUM_H_

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define GALLIUM_EXPORT __attribute__ ((visibility ("default")))

// gallium_error represents an error
typedef struct GALLIUM_EXPORT gallium_error {
	const char* msg;
} gallium_error_t;

// gallium_window represents a window
typedef struct GALLIUM_EXPORT gallium_window gallium_window_t;

// GalliumLoop runs the chromium browser loop
GALLIUM_EXPORT int GalliumLoop(
	int app_id,
	const char* argv0,
	void(*on_ready)(int),
	struct gallium_error** err);

// GalliumCreateWindow creates a window pointed at the given url
GALLIUM_EXPORT gallium_window_t* GalliumOpenWindow(const char* url,
                                      const char* title,
                                      int width,
                                      int height,
                                      int x,
                                      int y,
                                      bool titleBar,
                                      bool frame,
                                      bool resizable,
                                      bool closeButton,
                                      bool minButton,
                                      bool fullScreenButton);

  
// GalliumWindowGetWidth gets the width of a window
GALLIUM_EXPORT int GalliumWindowGetWidth(gallium_window_t* window);

// GalliumWindowGetWidth gets the width of a window
GALLIUM_EXPORT int GalliumWindowGetHeight(gallium_window_t* window);

// GalliumWindowGetWidth gets the width of a window
GALLIUM_EXPORT int GalliumWindowGetLeft(gallium_window_t* window);

// GalliumWindowGetWidth gets the width of a window
GALLIUM_EXPORT int GalliumWindowGetTop(gallium_window_t* window);

// GalliumWindowGetWidth gets the width of a window
GALLIUM_EXPORT void GalliumWindowSetShape(gallium_window_t* window,
                                          int width,
                                          int height,
                                          int left,
                                          int top);

// GalliumWindowGetURL gets the URL that the window is currently at
GALLIUM_EXPORT const char* GalliumWindowGetURL(gallium_window_t* window);

// GalliumWindowLoadURL causes the window to load the given URL
GALLIUM_EXPORT void GalliumWindowLoadURL(gallium_window_t* window, const char* url);

// GalliumWindowReload reloads the current page
GALLIUM_EXPORT void GalliumWindowReload(gallium_window_t* window);

// GalliumWindowReload reloads the current page, ignoring any cached resources
GALLIUM_EXPORT void GalliumWindowReloadNoCache(gallium_window_t* window);

// GalliumWindowOpen opens the window (only for use after GalliumWindowClose)
GALLIUM_EXPORT void GalliumWindowOpen(gallium_window_t* window);

// GalliumWindowClose closes the window
GALLIUM_EXPORT void GalliumWindowClose(gallium_window_t* window);

// GalliumWindowClose miniaturizes the window
GALLIUM_EXPORT void GalliumWindowMiniaturize(gallium_window_t* window);

// GalliumWindowOpenDevTools opens the developer tools for the given window
GALLIUM_EXPORT void GalliumWindowOpenDevTools(gallium_window_t* window);

// GalliumWindowCloseDevTools closes the developer tools for the given window
GALLIUM_EXPORT void GalliumWindowCloseDevTools(gallium_window_t* window);

// GalliumWindowDevToolsVisible returns true if the developer tools are currently visible for the given window
GALLIUM_EXPORT bool GalliumWindowDevToolsAreOpen(gallium_window_t* window);
  
#ifdef __cplusplus
}
#endif

#endif
