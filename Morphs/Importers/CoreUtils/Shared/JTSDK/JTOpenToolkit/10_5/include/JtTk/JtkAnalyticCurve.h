////////////////////////////////////////////////////////////////////////////////
// Copyright 2005 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_ANALYTIC_CURVE_H
#define JTK_ANALYTIC_CURVE_H

#include <JtTk/JtkXYZCurve.h>
#include <JtTk/JtkPoint.h>

///////%{
//
// Class          : JtkAnalyticCurve
//
// Description    : The Analytic curve object.
//
// Enums          :
//
// Includes       : JtkAnalyticCurve.h
//
// Inheritance    : JtkCurve > JtkAnalyticCurve
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkAnalyticCurve : public JtkCurve
{
   JTK_OBJECT_HEADER( JtkAnalyticCurve )

public:
   static int getCurve( JtkXYZCurve *xyzCurve, JtkAnalyticCurve* &aCurve );
   virtual int getXYZCurve(JtkXYZCurve*&)=0;
   
protected:
   JtkAnalyticCurve();
   virtual ~JtkAnalyticCurve();
};

///////%{
//
// Class          : JtkLineCurve
//
// Description    : The Line curve object.
//
// Enums          :
//
// Includes       : JtkAnalyticCurve.h
//
// Inheritance    : JtkAnalyticCurve > JtkLineCurve
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkLineCurve : public JtkAnalyticCurve
{
   JTK_OBJECT_HEADER( JtkLineCurve )

public:
   virtual void getInternals(JtkPoint * &stPt, JtkPoint * &endPt) = 0;
 
protected:
   JtkLineCurve ();
   virtual  ~JtkLineCurve ();
};

///////%{
//
// Class          : JtkCircleCurve
//
// Description    : The Circle curve object.
//
// Enums          :
//
// Includes       : JtkAnalyticCurve.h
//
// Inheritance    : JtkAnalyticCurve > JtkCircleCurve
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkCircleCurve : public JtkAnalyticCurve
{
   JTK_OBJECT_HEADER( JtkCircleCurve )

public:
   virtual void getInternals( JtkPoint * &stPt, JtkPoint * &endPt,
                              JtkPoint * &centerPt, double* &normal) = 0;
protected:
   JtkCircleCurve ();
   virtual  ~JtkCircleCurve ();
};

///////%{
//
// Class          : JtkEllipseCurve
//
// Description    : The Ellipse curve object.
//
// Enums          :
//
// Includes       : JtkAnalyticCurve.h
//
// Inheritance    : JtkAnalyticCurve > JtkEllipseCurve
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkEllipseCurve : public JtkAnalyticCurve
{
   JTK_OBJECT_HEADER( JtkEllipseCurve )

public:
   virtual void getInternals( JtkPoint * &stPt, JtkPoint * &endPt,
                              JtkPoint * &centerPt, double &majRadius,
                              double &minRadius, double* &normal, double* &majAxis) = 0;

protected:
   JtkEllipseCurve ();
   virtual  ~JtkEllipseCurve ();
};

///////%{
//
// Class          : JtkParabolaCurve
//
// Description    : The Parabola curve object.
//
// Enums          :
//
// Includes       : JtkAnalyticCurve.h
//
// Inheritance    : JtkAnalyticCurve > JtkParabolaCurve
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkParabolaCurve : public JtkAnalyticCurve
{
   JTK_OBJECT_HEADER( JtkParabolaCurve )

public:
   virtual void getInternals() = 0;

protected:
   JtkParabolaCurve ();
   virtual  ~JtkParabolaCurve ();
};

///////%{
//
// Class          : JtkHyperbolaCurve
//
// Description    : The Hyperbola curve object.
//
// Enums          :
//
// Includes       : JtkAnalyticCurve.h
//
// Inheritance    : JtkAnalyticCurve > JtkHyperbolaCurve
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkHyperbolaCurve : public JtkAnalyticCurve
{
   JTK_OBJECT_HEADER( JtkHyperbolaCurve )

public:
   virtual void getInternals() = 0;

protected:
   JtkHyperbolaCurve ();
   virtual  ~JtkHyperbolaCurve ();
};

#endif

