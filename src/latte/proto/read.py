#! /usr/bin/env python

from layer import Layer

class PTX:
    def __init__(self, ptx_file):
        self.layers = []
        self.ptx_open(ptx_file)

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
        c_form = []
        for lay in self.layers:
            c_form.append([lay.type, lay.name, lay.input, lay.output, lay.values])

        return c_form
