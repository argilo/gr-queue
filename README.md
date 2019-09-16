gr-queue
========

Author: Clayton Smith  
Email: <argilo@gmail.com>

When using GNU Radio to listen to trunked radio systems, one problem
that comes up is that multiple channels may be transmitting at once, in
which case you will hear multiple voices over top of each other if you
combine the channels with an Add block.  This block solves that problem
by queueing transmissions so they play back one after the other.

Whenever a non-zero sample arrives on any channel, that channel will be
considered active and its samples will start flowing through to the
output.  If non-zero samples start to arrive on other channels, they
will be queued for playback once the first channel returns to zero.
The block will consider a transmission finished once it receives a
number of consecutive zero samples on an active channel.  This number
is configurable, with the default being 4000.

Transmissions are played back in order of when they began.

Since the block uses zeros to determine whether a channel is active or
not, it is important to squelch the inputs to this block.

Build instructions:

    cmake .
    make
    sudo make install
    sudo ldconfig

If your GNU Radio is installed in `/usr` (rather than `/usr/local`), then
replace the first line above with:

    cmake -DCMAKE_INSTALL_PREFIX=/usr .

After running the above commands, "Queue" should appear under the
"Operators" category in GNU Radio Companion, and "queue_ff" will be
available in the "argilo" Python package.

Contributions are welcome!
