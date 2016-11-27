#! /usr/bin/env python

from layer import Layer

class PTX:
    def __init__(self, ptx_file):
        self.layers = []
        self.ptx_open(ptx_file)
        self.compose()

    def ptx_open(self, ptx_file):
        '''
        opens and reads a ptx file
        '''

        try:
            lines = open(ptx_file).read().splitlines()
            lines = [ l.replace(" ", "") for l in lines ] 
        except IOError:
            print "Cannot read file: "+ptx_file
            raise

        section = []
        for line in lines:
            if '{' in line:
                name = line[:-1]
                section = []
            elif line == '}':
                self.layers.append(Layer(name, section))
                section = []
            else:
                section.append(line)

    def compose(self):
        '''
        Compose the layers into a model
        '''
        for lay in self.layers:
            lay.debug_print()
