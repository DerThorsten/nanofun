#if defined(EMSCRIPTEN)
#  include <emscripten.h>
#endif

#include <iostream>
#include <string>

#include <nanogui/label.h>
#include <nanogui/screen.h>
#include <nanogui/window.h>
#include <nanogui/layout.h>
#include <nanogui/progressbar.h>
#include <nanogui/messagedialog.h>

int main(){
    using namespace nanogui;
    try {

        nanogui::init();
        Screen *screen = nullptr;


        screen = new Screen(Vector2i(500, 700), "NanoGUI test");
        

        Window *window = new Window(screen, "Please wait");
        // Label *label = new Label(window, " ");
        // window->set_layout(new BoxLayout(Orientation::Vertical, Alignment::Minimum, 15, 15));
        // ProgressBar *progress = new ProgressBar(window);
        // progress->set_fixed_width(250);
        window->center();


        screen->set_visible(true);
        screen->perform_layout();
        mainloop(-1);

        nanogui::shutdown();
    } catch (const std::exception &e) {
        std::string error_msg = std::string("Caught a fatal error: ") + std::string(e.what());
        std::cout<< error_msg <<std::endl;
        std::cerr << error_msg << std::endl;
        return -1;
    } catch (...) {
        std::cerr << "Caught an unknown error!" << std::endl;
        std::cout << "Caught an unknown error!" << std::endl;
    }

}