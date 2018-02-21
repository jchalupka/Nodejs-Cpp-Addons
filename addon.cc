#include <node.h>

void Sum(const v8::FunctionCallbackInfo < v8::Value >& args) {
  v8::Isolate * isolate = args.GetIsolate(); 

  // Check the number of arguements passed
  if (args.Length() < 1) {
    isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
  }

  // Check the argument types
  if (!args[0]->IsNumber()) {
    isolate->ThrowException(v8::Exception::TypeError(
        v8::String::NewFromUtf8(isolate, "Wrong arguments")));
    return;
  }

  // Note long is needed for large iteration counts
  long int iterations = args[0]->NumberValue();

  double a = 3.1415926, b = 2.718; 
  for (int i = 0; i < iterations; i++) {
    a += b;
  }

  auto total = v8::Number::New(isolate, a);

  args.GetReturnValue().Set(total);
}

void Initialize(v8::Local<v8::Object> exports) {
  NODE_SET_METHOD(exports, "Sum", Sum);
}

NODE_MODULE(addon, Initialize);