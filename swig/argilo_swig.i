/* -*- c++ -*- */

#define ARGILO_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "argilo_swig_doc.i"


%{
#include "argilo_queue_ff.h"
%}

GR_SWIG_BLOCK_MAGIC(argilo,queue_ff);
%include "argilo_queue_ff.h"
