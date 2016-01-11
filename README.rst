===========================================================================
convert_bmp_to_arduino_multiarray: Converts BMP into an arduino multiarray.
===========================================================================

.. image:: https://travis-ci.org/phillipgreenii/convert_bmp_to_arduino_multiarray.svg
    :target: https://travis-ci.org/phillipgreenii/convert_bmp_to_arduino_multiarray
    :alt: Build Status

This project converts a BMP into a multi array that can be used on an arduino.

Overview
--------

The python code is to convert a BMP into a C array to load into arduino.
Since the memory is so limited on arduino's, images need to be very small.
Copy and paste the generated multi array into `bmp.ino`.

References
^^^^^^^^^^

Displaying Pixels: https://learn.adafruit.com/adafruit-gfx-graphics-library/coordinate-system-and-units

Arduino Code to Run SPFD5408: https://github.com/JoaoLopesF/SPFD5408

Motivation: http://www.instructables.com/id/HackerBoxes-0002-Stepping-Up-to-ARM32-MCU-Video-Wi/?ALLSTEPS

Usage
-----

.. code-block:: bash

  $ convert_bmp_to_arduino_multiarray


Development
-----------

Run Tests
^^^^^^^^^

.. code-block:: bash

  $ python setup.py test

Install
^^^^^^^

.. code-block:: bash

  $ python setup.py develop

Copyright & License
-------------------

  - Copyright 2016, Phillip Green II
  - License: MIT
