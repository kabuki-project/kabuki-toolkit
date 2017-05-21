/*
    nanogui/glcanvas.h -- Canvas widget for rendering OpenGL content

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#pragma once

#include <iostream>

#include <nanogui/widget.hpp>
#include <nanogui/opengl.hpp>
#include <nanogui/glutil.hpp>

NAMESPACE_BEGIN(nanogui)

class NANOGUI_EXPORT GLCanvas : public Widget 
/*< Canvas widget for rendering OpenGL content
  
    Canvas widget that can be used to display arbitrary OpenGL content. This is
    useful to display and manipulate 3D objects as part of an interactive
    application. The implementation uses scissoring to ensure that rendered
    objects don't spill into neighboring widgets.
  
    Usage: override `drawGL` in subclasses to provide custom drawing code.
 */
{
    public:
    
    GLCanvas(Widget *parent);

    /// Return the background color
    const Color &backgroundColor() const { return mBackgroundColor; }
    /// Set the background color
    void setBackgroundColor(const Color &backgroundColor) { mBackgroundColor = backgroundColor; }

    /// Set whether to draw the widget border or not
    void setDrawBorder(const bool bDrawBorder) { mDrawBorder = bDrawBorder; }
    /// Return whether the widget border gets drawn or not
    const bool &drawBorder() const { return mDrawBorder; }

    /// Draw the canvas
    virtual void draw(NVGcontext *ctx) override;

    /// Draw the GL scene. Override this method to draw the actual GL
    /// content.
    virtual void drawGL() {}

    /// Save and load widget properties
    virtual void save(Serializer &s) const override;
    virtual bool load(Serializer &s) override;

    protected:
    
    /// Internal helper function for drawing the widget border
    void drawWidgetBorder(NVGcontext* ctx) const;

    protected:
    
    Color mBackgroundColor;
    bool mDrawBorder;
};

NAMESPACE_END(nanogui)
