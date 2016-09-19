'''
Layer class, only to hold information
'''

class Layer:
    def __init__(self, lines):
        self.args    =  []
        self.values  =  []
        self.inputs  =  []
        self.outputs =  []
        for line in lines:
            if line == '}' or line == '{':
                raise IOError("PTX file not properly formatted")
            self.parse_line(line)

    def parse_line(self, line):
        '''
        reads a single line, splits it into its arg and value
        '''
        try:
            spl = line.split(':')
            if spl[0] == 'in':
                self.inputs.append(spl[1])
            elif spl[0] == 'out':
                self.outputs.append(spl[1])
            else:
                self.args.append(spl[0])
                self.values.append(spl[1])
        except IOError:
            print "Line not properly formatted:"
            print line
            raise

    def debug_print(self):
        for i in range(len(self.args)):
            print self.args[i] + ' ' +  self.values[i]

    def get_inputs(self):
        return self.inputs

    def get_outputs(self):
        return self.outputs

