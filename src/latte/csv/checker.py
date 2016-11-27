#! /usr/bin/env python2.7

import sys
import os


def csv_check(path):
    csv_file = open_file(path)   
    return check_lines(path, csv_file)

def find_seperator(line):
    for i in line:
        if i not in '.0123456789':
            return i 

def check_lines(path, lines):
    sep = find_seperator(lines[0])
    width = len(lines[0].split(sep))
    length = len(lines)
    for line in lines:    
        line = line.rstrip()
        line = line.split(sep)
        if len(line) != width:
            raise ValueError("Inconsistent number of entries per line in "+path+": "+sep.join(line))

        for l in line:
            try:
                l = float(l)
            except:
                raise ValueError("Non-Numeric value found in "+path+": "+l)
                
    return width, length
                    
def open_file(path):
    try:
        fil = open(path, 'r')
        lines = fil.readlines()
        if len(lines) == 0:
            raise ValueError
        return lines
    except IOError:
        print 'Unable to open file: '+path
    except ValueError:
        print 'File Empty: '+path
