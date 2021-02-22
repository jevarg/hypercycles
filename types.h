//-------+---------+---------+---------+---------+---------+---------+---------+
// 1991-1992 Betz Associates. Released to the Public Domain. This source code
// is offered without warranty or guarantee of any kind, and the author(s)
// expressly disclaim any responsibility for consequences of it's use in
// products for commercial, shareware, or public domain release of any kind.
//
// Release of copyright applies only to this source code module, and does
// not apply to any other source code which may be included with it in a
// program
//
// File Name: TYPES.H
// Project:   Flights of Fantasy
// Creation:  August 2, 1992
// Author:    Mark Betz (MB)
//
// Machine:   IBM PC and Compatibles
//
// Includes:  nothing
//
//-------+---------+---------+---------+---------+---------+---------+---------+
// Change History
// ------ -------
//
//      Date            Rev.    Author          Purpose
//      ----            ----    ------      -------
//      8-2-1992        1.0     MB          Initial development
//      8-29-1992       1.1b    MB          first beta
//      9-26-1992       1.1     MB          publication release
//
// Description
// -----------
//      Provides some basic redefinition of native C types
//-------+---------+---------+---------+---------+---------+---------+---------+

#pragma once

typedef int boolean;

#define int false = 0;
#define int true = 1;

