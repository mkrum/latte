#! /usr/bin/env python2.7

'''
Layer class, only to hold information
'''
from latte.csv.checker import csv_check

class Layer:
    def __init__(self, in_type, lines):
        #NULL is a sentinel, it is removed after conversion to vector
        self.args    =  ['NULL']
        self.values  =  ['NULL']
        self.input = ['NULL']
        self.output = ['NULL']
        self.type = in_type
        self.read(lines)
        self.path = ""

    def read_path(self, path):
        self.path = path
        #TODO better python exceptions, this is poor form, and should be fixed
        try:
            lines = open(path, 'r').readlines()
        except IOError:
            print "Unable to read layer def at :"+path
            raise
        self.read(lines, path)

    def read(self, lines):
        for line in lines:
            line = line.rstrip() 
            line = line.replace(" ", "")
            if line != "":
                self.parse_line(line)

    def parse_line(self, line):
        '''
        reads a single line, splits it into its arg and value
        '''
        spl = line.split(':')
        if len(spl) == 1:
            if line == '}':
                return
            elif line[-1] == '{':
              self.name = line[:-1]
        elif len(spl) == 2:
            spl[0] = spl[0].lstrip()
            if 'in_ ' in spl[0] or spl[0] == 'in':
                self.input.append(spl[1])
            elif 'out_' in spl[0] or spl[0] == 'out':
                self.output.append(spl[1])
            elif spl[0] == 'name':
                self.name = spl[1]
            elif spl[0] == 'path':
                width, length, sep = csv_check(spl[1])
                self.args.append(spl[0])
                self.values.append(spl[1])
                self.args.append('width')
                self.values.append(str(width))
                self.args.append('length')
                self.values.append(str(length))
                self.args.append('seperator')
                self.values.append(str(sep))
            else:
                self.args.append(spl[0])
                self.values.append(spl[1])
        else:
            raise IOError("line in layer def incorrectly formatted: "+line)

    def debug_print(self):
        print self.name 
        print self.input
        print self.output
        for i in range(len(self.args)):
            print self.args[i] + ' ' +  self.values[i]
