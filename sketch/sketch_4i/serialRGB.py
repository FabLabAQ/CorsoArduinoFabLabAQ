#!/usr/bin/env python
# coding: UTF-8

"""
 serialRGB
 Copyright (C) 2015
 Luca Anastasio <anastasio.lu@gmail.com>

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
"""

import Tkinter as tk											# Tkinter library used for GUI
import serial													# import pyserial library

PORT = '/dev/ttyACM0'											# select serial port, Arduinos with ATmega16U2 default to ttyACM0
BAUD = 9600														# select baudrate

arduino = serial.Serial(PORT, BAUD)								# open the serial port
window = tk.Tk()												# GUI window object declaration

def update0(var):
	arduino.write("L0 "+var)

def update1(var):
	arduino.write("L1 "+var)

def update2(var):
	arduino.write("L2 "+var)

scale0 = tk.Scale(window, from_=255, to=0, command=update0)		# create scale object, use 255-0 values (unsigned 8-bit integer), set which command to execute when moved
label0 = tk.Label(window, text='Red')							# create label object to recognize channel
scale0.grid(column=0, row=0)									# place scale0 in column 0, row 0
label0.grid(column=0, row=1)									# place label0 under scale0

scale1 = tk.Scale(window, from_=255, to=0, command=update1)
label1 = tk.Label(window, text='Green')
scale1.grid(column=1, row=0)
label1.grid(column=1, row=1)

scale2 = tk.Scale(window, from_=255, to=0, command=update2)
label2 = tk.Label(window, text='Blue')
scale2.grid(column=2, row=0)
label2.grid(column=2, row=1)

window.title("serialRGB")										# give a title to the window
window.geometry("180x160+0+0")									# set a dimension
window.mainloop()												# finally, run it