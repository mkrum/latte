#include "layers/output.h"

//Display output
#include <iostream>
using std::cout;

Output::Output(string in_name, vector<string> in, vector<string> out, vector<string> in_args) : name(in_name), prev(in), next(out), path(in_args[2])  {}

Matrix &Output::forward(Matrix &inputs) {    
	FILE *f = fopen("output.txt", "w");
	if (F == NULL)
	{
		std::cout << "Error opening file" << std::endl;
	}

  if (inputs.shape.size() < 3) {
    for (int i = 0; i < inputs.shape[0]; i++) {
      for (int j = 0; j < inputs.shape[1]; j++) {
	      fprintf(f, "%s ", inputs[i][j]);
        std::cout << std::setprecision(5) << inputs[i](j) << " ";
      }
      fprintf(f, "\n");
      std::cout << std::endl;
    }
  } else {
    std::cout << "Multi-dimensional output is not avaiable";
  }

  fclose(f);
  return inputs;
}

Matrix &Output::backward(Matrix &inputs) {    
  return inputs;
}



