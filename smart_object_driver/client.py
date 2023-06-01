#!/usr/bin/env python3

import argparse
import textwrap
import socket
import sys

IP = "Your IP"
port= 3500

def main(args):
	# Create a TCP/IP socket with fixed IP and port
	sock = socket.create_connection((IP, port))
	try:
		sock.sendall(args.action.encode('ascii'))
		if args.action == '4' or args.action == '5':
			sock.sendall(args.message.encode('ascii'))
	finally:
		sock.close()

if __name__ == '__main__':
	parser = argparse.ArgumentParser(
		formatter_class=argparse.RawTextHelpFormatter,
		description='''Interaction with the BRIC through TCP connection''',
		epilog=textwrap.dedent('''\
			The action parameter indicates the action to take:
			 1  Start the BRIC
			 2  Stop
			 3  Restart the BRIC
			 4  Test the LEDs
			 5  Mission configuration 
			 6 Calibration configuration

			The message value is only relevant for actions 4 and 5. If another
			action is specified, the message value is ignored.
			 Action 4  Up to 5 integers. The first integer specifies the colour
			           (1: red, 2: green, 3: blue), the second integer specifies
			           which sectors of the LEDs to light up (1: all, 2: three sectors,
			           3: half) and the last three specify the intensity of
			           the colour [0-255]
			           Examples:
			            125511111111 -> Red, all LEDs, full brightness
			            212711110000 -> Green, half of the LEDs, half brightness
			            306300001111  -> Blue, other half of the LEDs, low brightness
			 Action 5  One or two integers. 1x to launch example 1, where the 'x'
			           determines the initial colour (1: red, 2: green, 3: blue),
			           {2,3} to launch examples {2,3}, 4 to stop the currently
			           running software, 5 to calibrate for white colour, 6 to
			           calibrate for black colour
			'''))
	parser.add_argument(
		'-a',
		'--action',
		default = "0",
		type = str,
		choices = ["1", "2", "3", "4", "5","6"],
		help = "Action to be executed")
	parser.add_argument(
		'-m',
		'--message',
		type=str,
		default="0",
		help=textwrap.dedent('''\
			Message value. Takes 12 integers if the action is bigger it is ignored,
			if it is lower, the socket will wait the next characters.
			'''))
	args = parser.parse_args()

	main(args)
