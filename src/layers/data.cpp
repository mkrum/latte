#include <layers/data.h>

Data::Data(string in_path, bool in_ran) : path(in_path), is_random(in_ran) { }

void Data::csv_read() {
  double *csv_data = new double[width * length];  
  vector<size_t> data_shape;
  data_shape.push_back(width);
  data_shape.push_back(length);
  int i = 0;
  string line;
  std::fstream f_stream(path.c_str());

  assert(f_stream.is_open());

  string val;

  while(f_stream >> line) {
    //better error handling would be great, on this whole thing really
    std::stringstream stream(line);
    while(std::getline(stream, val, seperator)) {
      csv_data[i] = utils::string_to_double(val);
      i++;
    }
  }
  data = Matrix(csv_data, data_shape);

}

Matrix Data::forward(Matrix inputs) {
  width = 4;
  length = 150;
  seperator = ',';
  csv_read();
  if (is_random) {
    std::cout <<  "sure" << std::endl;
  }
  return data;    
}
