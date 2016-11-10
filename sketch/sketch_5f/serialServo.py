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

import Tkinter as tk											# Tkinter library used for GUI
import serial, serial.tools.list_ports							# import pyserial library

VID_PID_Genuino = "2341:0243"									# Genuino UNO vid:pid
VID_PID_Arduino = "2341:0043"									# Arduino UNO vid:pid
BAUD = 9600														# select baudrate

window = tk.Tk()												# GUI window object declaration
window.title("serialRGB")										# give a title to the window
window.geometry("80x160+0+0")									# set a dimension

try:
	PORT = list(serial.tools.list_ports.grep(VID_PID_Genuino))[0][0]	# find the serial port
	arduino = serial.Serial(PORT, BAUD)									# open the serial port
except:
	try:
		PORT = list(serial.tools.list_ports.grep(VID_PID_Arduino))[0][0]	# find the serial port
		arduino = serial.Serial(PORT, BAUD)									# open the serial port
	except:
		window.geometry("250x250+0+0")
		text = tk.Text(window)
		text.grid(column=0, row=0)
		text.insert(tk.INSERT, "Errore porta seriale")
		window.mainloop()

def update(var):												# function connected to scale0
	#arduino.write(chr(int(var)))								# I know, a bit confusing, we want to write to the serial port a byte representing the scale value
	arduino.write("S"+var)										# Not needed if you are using integer parsing on Arduino/MCU
	#print var													# for debugging purposes

scale0 = tk.Scale(window, from_=180, to=0, command=update)		# create scale object, use 255-0 values (unsigned 8-bit integer), set which command to execute when moved
label0 = tk.Label(window, text='Channel 0')						# create label object to recognize channel
scale0.grid(column=0, row=0)									# place scale0 in column 0, row 0
label0.grid(column=0, row=1)									# place label0 under scale0

window.mainloop()												# finally, run it