#include <Ultralight/Ultralight.h>
 
int main () {
  // Setup our Platform
  Platform& platform = Platform::instance();
  platform.set_config(Config());
  platform.set_gpu_driver(new GPUDriverD3D(new D3DRenderer()));
  platform.set_font_loader(new FontLoaderWin());
 
  // Create the Renderer
  Ref<Renderer> renderer = Renderer::Create();
 
  // Create the View
  Ref<View> view = renderer->CreateView(800, 600, false);
  view->LoadHTML("<h1>Hello World!</h1>");
 
  return 0;
}
