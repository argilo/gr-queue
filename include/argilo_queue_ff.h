/* -*- c++ -*- */
/*
 * Copyright 2004 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */
#ifndef INCLUDED_ARGILO_QUEUE_FF_H
#define INCLUDED_ARGILO_QUEUE_FF_H

#include <argilo_api.h>
#include <gr_sync_block.h>
#include <vector>
#include <queue>
using namespace std;

class argilo_queue_ff;

/*
 * We use boost::shared_ptr's instead of raw pointers for all access
 * to gr_blocks (and many other data structures).  The shared_ptr gets
 * us transparent reference counting, which greatly simplifies storage
 * management issues.  This is especially helpful in our hybrid
 * C++ / Python system.
 *
 * See http://www.boost.org/libs/smart_ptr/smart_ptr.htm
 *
 * As a convention, the _sptr suffix indicates a boost::shared_ptr
 */
typedef boost::shared_ptr<argilo_queue_ff> argilo_queue_ff_sptr;

/*!
 * \brief Return a shared_ptr to a new instance of argilo_queue_ff.
 *
 * To avoid accidental use of raw pointers, argilo_queue_ff's
 * constructor is private.  argilo_make_queue_ff is the public
 * interface for creating new instances.
 */
ARGILO_API argilo_queue_ff_sptr argilo_make_queue_ff ();

/*!
 * \brief queue float multiple simultaneous floats into a single stream
 * \ingroup block
 *
 * This uses the preferred technique: subclassing gr_sync_block.
 */
class ARGILO_API argilo_queue_ff : public gr_sync_block
{
private:
  // The friend declaration allows argilo_make_queue_ff to
  // access the private constructor.

  friend ARGILO_API argilo_queue_ff_sptr argilo_make_queue_ff ();

  argilo_queue_ff ();  	// private constructor

  vector<int> zeros_so_far;
  vector<queue<float>*> current_channel_queue;
  queue<queue<float>*> queued_audio_segments;  

 public:
  ~argilo_queue_ff ();	// public destructor

  // Where all the action really happens

  int work (int noutput_items,
	    gr_vector_const_void_star &input_items,
	    gr_vector_void_star &output_items);
};

#endif /* INCLUDED_ARGILO_QUEUE_FF_H */
