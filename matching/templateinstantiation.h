/*
 * This file is part of BBP Pairings, a Swiss-system chess tournament engine
 * Copyright (C) 2016  Jeremy Bierema
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 3.0, as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef MATCHINGTEMPLATEINSTANTIATION_H
#define MATCHINGTEMPLATEINSTANTIATION_H

#include <swisssystems/burstein.h>
#include <swisssystems/dutch.h>

#ifdef OMIT_BURSTEIN
#define MATCHING_EDGE_WEIGHT_BURSTEIN(a)
#else
#define MATCHING_EDGE_WEIGHT_BURSTEIN(a) \
a(swisssystems::burstein::matching_computer::edge_weight)
#endif

#ifdef OMIT_DUTCH
#define MATCHING_EDGE_WEIGHTS_DUTCH(a)
#else
#define MATCHING_EDGE_WEIGHTS_DUTCH(a) \
a(swisssystems::dutch::validity_matching_computer::edge_weight) \
a(swisssystems::dutch::optimality_matching_computer::edge_weight)
#endif

// This macro is called in the cpp files of the matching code to instantiate the
// templates needed for the Swiss systems.

#define INSTANTIATE_MATCHING_EDGE_WEIGHT_TEMPLATES(a) \
MATCHING_EDGE_WEIGHT_BURSTEIN(a) MATCHING_EDGE_WEIGHTS_DUTCH(a)

#endif
