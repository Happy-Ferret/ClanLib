/*
**  ClanLib SDK
**  Copyright (c) 1997-2013 The ClanLib Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Magnus Norddahl
*/

#include "GL/precomp.h"
#include "opengl_window_provider_osx.h"
#include "API/Core/Math/rect.h"
#include "API/Display/Window/display_window_description.h"
#include "API/Display/display.h"
#include "API/Display/display_target.h"
#include "API/Display/TargetProviders/display_window_provider.h"
#include "API/Display/Window/display_window.h"
#include "API/Display/Render/shared_gc_data.h"
#include "API/Display/Image/pixel_buffer.h"
#include "API/GL/opengl.h"
#include "API/GL/opengl_wrap.h"
#include "API/GL/opengl_window_description.h"
#include "API/Core/Text/logger.h"
#include "../opengl_window_description_impl.h"
#include "../GL3/gl3_graphic_context_provider.h"

namespace clan
{

/////////////////////////////////////////////////////////////////////////////
// OpenGLWindowProvider Construction:

OpenGLWindowProvider::OpenGLWindowProvider(OpenGLWindowDescription &opengl_desc)
: site(0), opengl_desc(opengl_desc)
{
}

OpenGLWindowProvider::~OpenGLWindowProvider()
{
}

/////////////////////////////////////////////////////////////////////////////
// OpenGLWindowProvider Attributes:

ProcAddress *OpenGLWindowProvider::get_proc_address(const std::string& function_name) const
{
	return (void (*)())0;
}

Rect OpenGLWindowProvider::get_geometry() const
{
	return Rect();
}

Rect OpenGLWindowProvider::get_viewport() const
{
	return Rect();
}

bool OpenGLWindowProvider::is_fullscreen() const
{
	return false;
}

bool OpenGLWindowProvider::has_focus() const
{
	return true;
}

bool OpenGLWindowProvider::is_minimized() const
{
	return false;
}

bool OpenGLWindowProvider::is_maximized() const
{
	return false;
}

bool OpenGLWindowProvider::is_visible() const
{
	return true;
}

Size OpenGLWindowProvider::get_minimum_size(bool client_area) const
{
	return Size();
}

Size OpenGLWindowProvider::get_maximum_size(bool client_area) const
{
	return Size(32768, 32768);
}

std::string OpenGLWindowProvider::get_title() const
{
	return window_title;
}

bool OpenGLWindowProvider::is_clipboard_text_available() const
{
	return false;
}

bool OpenGLWindowProvider::is_clipboard_image_available() const
{
	return false;
}

/////////////////////////////////////////////////////////////////////////////
// OpenGLWindowProvider Operations:

void OpenGLWindowProvider::make_current() const
{
}

Point OpenGLWindowProvider::client_to_screen(const Point &client)
{
	return client;
}

Point OpenGLWindowProvider::screen_to_client(const Point &screen)
{
	return screen;
}

void OpenGLWindowProvider::create(DisplayWindowSite *new_site, const DisplayWindowDescription &desc)
{
	site = new_site;

}

void OpenGLWindowProvider::show_system_cursor()
{
}

CursorProvider *OpenGLWindowProvider::create_cursor(const CursorDescription &cursor_description, const Point &hotspot)
{
	throw Exception("Custom cursors not supported yet by OS X target");
}

void OpenGLWindowProvider::set_cursor(CursorProvider *cursor)
{
}

void OpenGLWindowProvider::set_cursor(StandardCursor type)
{
}

void OpenGLWindowProvider::hide_system_cursor()
{
}

void OpenGLWindowProvider::set_title(const std::string &new_title)
{
	window_title = new_title;
}

void OpenGLWindowProvider::set_position(const Rect &pos, bool client_area)
{
}

void OpenGLWindowProvider::set_size(int width, int height, bool client_area)
{
}

void OpenGLWindowProvider::set_minimum_size( int width, int height, bool client_area )
{
}

void OpenGLWindowProvider::set_maximum_size( int width, int height, bool client_area )
{
}

void OpenGLWindowProvider::set_enabled(bool enable)
{
}

void OpenGLWindowProvider::minimize()
{
}

void OpenGLWindowProvider::restore()
{
}

void OpenGLWindowProvider::maximize()
{
}

void OpenGLWindowProvider::show(bool activate)
{
}

void OpenGLWindowProvider::hide()
{
}

void OpenGLWindowProvider::bring_to_front()
{
}

void OpenGLWindowProvider::flip(int interval)
{
	OpenGL::set_active(get_gc());
	
	// To do: swap buffers
	
	OpenGL::check_error();
}

void OpenGLWindowProvider::update(const Rect &_rect)
{
	OpenGL::set_active(gc);
	
	// To do: copy rect from back to front buffer
	
	OpenGL::check_error();
}

void OpenGLWindowProvider::capture_mouse(bool capture)
{
}

void OpenGLWindowProvider::set_clipboard_text(const std::string &text)
{
}

std::string OpenGLWindowProvider::get_clipboard_text() const
{
	return std::string();
}

void OpenGLWindowProvider::request_repaint(const Rect &rect)
{
}

void OpenGLWindowProvider::set_large_icon(const PixelBuffer &image)
{
}

void OpenGLWindowProvider::set_small_icon(const PixelBuffer &image)
{
}

void OpenGLWindowProvider::enable_alpha_channel(const Rect &blur_rect)
{
}

void OpenGLWindowProvider::extend_frame_into_client_area(int height)
{
}

void OpenGLWindowProvider::set_clipboard_image(const PixelBuffer &buf)
{
}

PixelBuffer OpenGLWindowProvider::get_clipboard_image() const
{
	return PixelBuffer();
}

/////////////////////////////////////////////////////////////////////////////
// OpenGLWindowProvider Implementation:

}
