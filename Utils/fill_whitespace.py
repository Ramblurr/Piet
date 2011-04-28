#!/usr/bin/env python
# Fills all whitespace in an image with random
# Piet-safe colors
# Piet safe colors are non black, white, nor any of the
# 18 colors used as commands in Piet
#
# This makes pretty pictures while not affecting the execution
# because piet interpreters should treat all unknown colors as white.
#
# usage: ./fill_whitespace.py program.png new_program.png
import Image, sys, random

if len(sys.argv) != 3:
    print("usage: %s image_name.png new_image.png" % sys.argv[0])

def rgb_to_hex(rgb):
    """Converts an rgb tuple to a hex string"""
    if len(rgb) <3:
        return rgb
    return '#%02x%02x%02x'.upper() % rgb

def hex_to_rgb(hex):
    """Converts a hex string to an rgb tuple"""
    return (int(hex[1:3],16),int(hex[3:5],16),int(hex[5:7],16))

colors = (
    "#FFC0C0",
    "#FF0000",
    "#C00000",
    "#FFFFC0",
    "#FFFF00",
    "#C0C000",
    "#C0FFC0",
    "#00FF00",
    "#00C000",
    "#C0FFFF",
    "#00FFFF",
    "#00C0C0",
    "#C0C0FF",
    "#0000FF",
    "#0000C0",
    "#FFC0FF",
    "#FF00FF",
    "#C000C0",
)

white = (255, 255, 255)
black = (0, 0, 0)

def random_safe_color():
    """Returns a random RGB color that is not in the colors list
        Will not be black or white """
    while True:
        r = random.randint(0,255)
        g = random.randint(0,255)
        b = random.randint(0,255)
        c = (r,g,b)
        if not(rgb_to_hex(c) in colors  or c == white or c == black):
            return c
    

image = Image.open(sys.argv[1])

if image.mode == 'RGBA':
    image = image.convert('RGB')
else:
    print("Image is not RGBA mode.")

pixels = image.load()
w = image.size[0]
h = image.size[1]

for x in range(w):
    for y in range(h):
        if pixels[x, y] == white:
            pixels[x, y] = random_safe_color()

image.save(sys.argv[2])