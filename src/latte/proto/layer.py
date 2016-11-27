#! /usr/bin/env python2.7

'''
Layer class, only to hold information
'''

class Layer:
    def __init__(self, name):
        self.args    =  []
        self.values  =  []
        self.source_file = "-1"
        self.name = name
        self.path = ""

    def __init__(self, name, lines):
        self.args    =  []
        self.values  =  []
        self.source_file = "-1"
        self.name = name
        self.read(lines)
        self.path = ""

    def __init__(self):
        self.name = ""
        self.args    =  []
        self.values  =  []
        self.source_file = "-1"

    def read_path(self, path):
        self.path = path
        #TODO better python exceptions, this is poor form, and should be fixed
        try:
            lines = open(path, 'r').readlines()
        except IOError:
            print "Unable to read layer def at :"+path
            raise
        self.read(lines, path)

    def read(self, lines, path):
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
            if spl[0] == 'source':
                self.source_file = spl[1]
            self.args.append(spl[0])
            self.values.append(spl[1])
        else:
            raise IOError("line in layer def incorrectly formatted: "+line)

    def debug_print(self):
        print self.name 
        for i in range(len(self.args)):
            print self.args[i] + ' ' +  self.values[i]
   
    def get_source(self):
        if self.source_file == '-1':
            self.debug_print()
            if self.path != "":
                raise ValueError("source file not defined for layer "+self.path)
            elif self.name != "":
                raise ValueError("soure file not defined for layer "+self.name)
            else:
                raise ValueError("File not properly defined")
        else:
            return self.source_file
