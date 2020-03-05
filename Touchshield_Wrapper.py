#!/usr/bin/env python3

import subprocess
import sys
import time
import pynput

touchshield_output = subprocess.Popen(["./TouchberryPiShield/bin/touchshield"], stdout=subprocess.PIPE, shell=True, bufsize=-1)

if __name__ == '__main__':
	mouse = pynput.mouse.Controller()
	keyboard = pynput.keyboard.Controller()
	toggle_mode = True #True = mouse mode/False = keyboard mode
	increment = 2
	threshold = 50
	dx = 0
	dy = 0

	while True:
		line_out = touchshield_output.stdout.readline().decode('utf-8')
		sys.stdout.flush()
		char = line_out[0]
		if char.isalpha():
			if char == 's':
				if toggle_mode:
					if dy < 0:
						dy = 0
					if abs(dy) < threshold:
						dy = dy + increment
					mouse.move(dx, dy)
				else:
					keyboard.press(pynput.keyboard.Key.down)
					keyboard.release(pynput.keyboard.Key.down)
			elif char == 'a':
				if toggle_mode:
					if dx > 0:
						dx = 0
					if abs(dx) < threshold:
						dx = dx - increment
					mouse.move(dx, dy)
				else:
					keyboard.press(pynput.keyboard.Key.left)
					keyboard.release(pynput.keyboard.Key.left)
			elif char == 'w':
				if toggle_mode:
					if dy > 0:
						dy = 0
					if abs(dy) < threshold:
						dy = dy - increment
					mouse.move(dx, dy)
				else:
					keyboard.press(pynput.keyboard.Key.up)
					keyboard.release(pynput.keyboard.Key.up)
			elif char == 'd':
				if toggle_mode:
					if dx < 0:
						dx = 0
					if abs(dx) < threshold:
						dx = dx + increment
					mouse.move(dx, dy)
				else:
					keyboard.press(pynput.keyboard.Key.right)
					keyboard.release(pynput.keyboard.Key.right)
			elif char == 'X':
				if toggle_mode:
					mouse.press(pynput.mouse.Button.left)
					mouse.release(pynput.mouse.Button.left)
					time.sleep(1)
				else:
					keyboard.press('X')
					keyboard.release('X')
			elif char == 'A':
				if toggle_mode:
					mouse.press(pynput.mouse.Button.right)
					mouse.release(pynput.mouse.Button.right)
					time.sleep(1)
				else:
					keyboard.press('A')
					keyboard.release('A')
			elif char == 'B':
				#toggle_keyboard-mouse mode
				keyboard.type('switch')
				toggle_mode = not(toggle_mode)
				time.sleep(1)
			else:
				mouse.move(0,0)
				dx = 0
				dy = 0
