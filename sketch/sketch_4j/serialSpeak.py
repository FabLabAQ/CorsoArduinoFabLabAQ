#!/usr/bin/env python
# coding: UTF-8

"""
 serialSpeak
 Copyright (C) 2016
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
import serial, serial.tools.list_ports							# import pyserial library
import subprocess

dafault_voice = "it"
def say(text):
    subprocess.call(["espeak", "-v", dafault_voice, text])

VID_PID = "2341:0243"											# Genuino UNO vid:pid
BAUD = 9600														# select baudrate

window = tk.Tk()												# GUI window object declaration
scroll = tk.Scrollbar(window)
text = tk.Text(window)

scroll.pack(side=tk.RIGHT, fill=tk.Y)
scroll.config(command=text.yview)
text.pack(side=tk.LEFT, fill=tk.Y)
text.config(yscrollcommand=scroll.set)

window.title("serialSpeak")										# give a title to the window
window.geometry("320x240+0+0")									# set a dimension

try:
	PORT = list(serial.tools.list_ports.grep(VID_PID))[0][0]		# find the serial port
	arduino = serial.Serial(PORT, BAUD)								# open the serial port
except:
	text.insert(tk.INSERT, "Errore porta seriale")
	window.mainloop()

window.update_idletasks()
window.update()													# finally, run it

go = False

while True:

	if arduino.in_waiting > 0:
		line = arduino.readline()
		text.insert(tk.INSERT, line)
		go = True

	window.update_idletasks()
	window.update()

	if go:
		say(line)
		go = False