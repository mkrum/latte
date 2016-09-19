#! /usr/bin/env python

from layer import Layer

class Model:
    def __init__(self, ptx_file):
        self.layers = []
        self.input = []
        self.output = []
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
        for i in range(len(lines)):
            if lines[i] == '{':
                section = []
            elif lines[i] == '}':
                self.layers.append(Layer(section))
                section = []
            else:
                section.append(lines[i])

    def compose(self):
        '''
        Compose the layers into a model
        '''
