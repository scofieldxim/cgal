// Copyright (c) 2012, 2020 Tel-Aviv University (Israel).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org).
//
// $URL$
// $Id$
// SPDX-License-Identifier: GPL-3.0-or-later OR LicenseRef-Commercial
//
// Author(s): Alex Tsui <alextsui05@gmail.com>
//            Ahmed Essam <theartful.ae@gmail.com>

#ifndef ENVELOPE_CALLBACK_H
#define ENVELOPE_CALLBACK_H

#include "Callback.h"

namespace CGAL
{
namespace Qt
{
template <typename T>
class CurveGraphicsItem;
}
} // namespace CGAL

class EnvelopeCallbackBase : public CGAL::Qt::Callback
{
public:
  virtual void setEnvelopeEdgeColor( const QColor& color ) = 0;
  virtual const QColor& getEnvelopeEdgeColor( ) const = 0;
  virtual void setEnvelopeEdgeWidth( int width ) = 0;
  virtual int getEnvelopeEdgeWidth( ) const = 0;
  virtual void setEnvelopeVertexColor( const QColor& color ) = 0;
  virtual const QColor& getEnvelopeVertexColor( ) const = 0;
  virtual void setEnvelopeVertexRadius( int radius ) = 0;
  virtual int getEnvelopeVertexRadius( ) const = 0;
  virtual void showLowerEnvelope( bool b ) = 0;
  virtual void showUpperEnvelope( bool b ) = 0;
  virtual bool isUpperEnvelopeShown() = 0;
  virtual bool isLowerEnvelopeShown() = 0;

protected:
  EnvelopeCallbackBase( QObject* parent );
}; // class EnvelopeCallbackBase

/**
   Updates and draws the lower and upper envelopes of an observed arrangement.
*/
template < typename Arr_>
class EnvelopeCallback : public EnvelopeCallbackBase
{
public:
  typedef Arr_                                          Arrangement;
  typedef typename Arrangement::Geometry_traits_2       Traits;
  typedef typename Traits::X_monotone_curve_2           X_monotone_curve_2;
  typedef typename Traits::Point_2                      Point_2;

  EnvelopeCallback( Arrangement* arr_, QObject* parent );
  void showLowerEnvelope( bool show ) override;
  void showUpperEnvelope( bool show ) override;
  bool isUpperEnvelopeShown() override;
  bool isLowerEnvelopeShown() override;
  void reset( ) override;

  /**
     Slot: Update and redraw the envelopes.
  */
  void slotModelChanged( ) override;

  void setEnvelopeEdgeColor(const QColor& color) override;
  const QColor& getEnvelopeEdgeColor() const override;
  void setEnvelopeEdgeWidth(int width) override;
  int getEnvelopeEdgeWidth() const override;
  void setEnvelopeVertexColor(const QColor& color) override;
  const QColor& getEnvelopeVertexColor() const override;
  void setEnvelopeVertexRadius(int radius) override;
  int getEnvelopeVertexRadius() const override;

protected:
  void setScene( QGraphicsScene* scene_ ) override;
  void updateEnvelope( bool lower );

  Arrangement* arr;
  CGAL::Qt::CurveGraphicsItem< Traits >* lowerEnvelope;
  CGAL::Qt::CurveGraphicsItem< Traits >* upperEnvelope;
  bool showLower;
  bool showUpper;
}; // class EnvelopeCallback

#endif // ENVELOPE_CALLBACK_H
