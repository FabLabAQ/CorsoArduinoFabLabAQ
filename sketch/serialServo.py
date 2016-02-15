#!/usr/bin/env python
# coding: UTF-8

"""
 serialServo
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

def update(var):												# function connected to scale0
	arduino.write(chr(int(var)))								# I know, a bit confusing, we want to write to the serial port a byte representing the scale value

scale0 = tk.Scale(window, from_=180, to=0, command=update)		# create scale object, use 255-0 values (unsigned 8-bit integer), set which command to execute when moved
label0 = tk.Label(window, text='Channel 0')						# create label object to recognize channel
scale0.grid(column=0, row=0)									# place scale0 in column 0, row 0
label0.grid(column=0, row=1)									# place label0 under scale0

window.title("serialServo")										# give a title to the window
window.geometry("80x160+0+0")									# set a dimension
window.mainloop()												# finally, run it