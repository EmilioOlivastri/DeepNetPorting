#include "utils.hpp"
#include "torch_tensorrt/torch_tensorrt.h"

int main(int argc, const char* argv[]) 
{
  if (argc != 2) 
  {
    std::cerr << "usage: example-app <path-to-exported-script-module>\n";
    return -1;
  }


  torch::jit::script::Module module;
  try 
  {
    // Deserialize the ScriptModule from a file using torch::jit::load().
    module = torch::jit::load(argv[1]);
  }
  catch (const c10::Error& e) 
  {
    std::cerr << "error loading the model\n";
    return -1;
  }

  std::cout << "ok\n";

  module.to(at::kCUDA);
  module.eval();

  std::vector<torch_tensorrt::Input> inputs_specs;
  std::vector<int64_t> shape;
  shape.push_back(1); shape.push_back(3);
  shape.push_back(224); shape.push_back(224);
  torch_tensorrt::Input input_info(shape, torch::kFloat32);


  inputs_specs.push_back(input_info);

  torch_tensorrt::ts::CompileSpec info(inputs_specs);
  info.truncate_long_and_double = true;
  
  auto trt_mod = torch_tensorrt::ts::compile(module, info);

  trt_mod.save("mod_trt.ts");

  return 0;  
}
